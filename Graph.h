// ----------------------
// projects/graph/Graph.h
// Copyright (C) 2012
// Glenn P. Downing
// ----------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector> // vector
#include <set>
using namespace std;

// -----
// Graph
// -----

class Graph {
    public:
        // --------
        // typedefs
        // --------

        typedef unsigned int vertex_descriptor;
        typedef pair<vertex_descriptor, vertex_descriptor> edge_descriptor;

        typedef vector<vertex_descriptor>::iterator vertex_iterator; 
        typedef vector<edge_descriptor>::iterator edge_iterator;
        typedef vector<vertex_descriptor>::iterator adjacency_iterator; 

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
	 * @param source The source of the new edge 
         * @param target The target of the new edge
         * @param a The graph to add the edge to
         * @return pair< pair<vertex_descriptor, vertex_descriptor>, bool > 
         * The bool is true if the edge was not pre-existing and the insert succeeded. 
	 */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor source, vertex_descriptor target, Graph& a) {
	    assert(source < a.g.size() && target < a.g.size() && source >= 0 && target >= 0);

            bool b;
            pair<vertex_descriptor, vertex_descriptor> ed (source, target);
	    vector<vertex_descriptor>::iterator result = find(a.g[source].begin(), a.g[source].end(), target);
	    if (result == a.g[source].end()) {
	        b = true;
                a.g[source].push_back(target);
                a.allEdges.push_back(make_pair(source, target));
            } else { 
                b = false;
            }
            return std::make_pair(ed, b);}

        // ----------
        // add_vertex
        // ----------

        /**
 	 * @param Graph to add the vertex to
         * @return The vertex descriptor (int) of the added vertex
	 */
        friend vertex_descriptor add_vertex (Graph& a) {
	    vector<vertex_descriptor > vertex(0);
	    a.g.push_back(vertex);
            a.allVertices.push_back(a.g.size() - 1);
            return (a.g.size() - 1);}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
	 * @param vertex_descriptor vertex The vertex to find the adjacent vertices of
         * @param Graph a The graph in which the vertex resides. 
         * @return A pair of adjacency iterators that will iterate over all adjacent vertices. 
	 */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor vertex, Graph& a) {
            adjacency_iterator b = adjacency_iterator();
            adjacency_iterator e = adjacency_iterator();
            return std::make_pair(a.g[vertex].begin(), a.g[vertex].end());}

        // ----
        // edge
        // ----

        /**
	 * @param vertex_descriptor of source to check edge
         * @param vertex_descriptor of target to check edge
         * @param Graph which vertices are in
         * @return Pair, an edge_descriptor built from the vertex_descriptors, bool is true if edge in the graph
	 */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor source, vertex_descriptor target, Graph& a) {
            bool b; 
            edge_descriptor ed = make_pair(source, target); 
            vertex_iterator iter = find(a.g[source].begin(), a.g[source].end(), target);
            if (iter == a.g[source].end()) {
                b = false;
            } else {
                b = true;
            }
            return std::make_pair(ed, b);}

        // -----
        // edges
        // -----

        /**
	 * @param a Graph to get the edges from 
         * @return A pair of edge iterators that iterate over pairs, which describe the edges. 
	 */
        friend std::pair<edge_iterator, edge_iterator> edges (Graph& a) {
            return pair<edge_iterator, edge_iterator>(a.allEdges.begin(), a.allEdges.end());
        }

        // ---------
        // num_edges
        // ---------

        /**
	 * @param a Graph to determine the number of edges on
         * @return The total number of edges in a
	 */
        friend edges_size_type num_edges (const Graph& a) {

            edges_size_type total = 0;
            for(unsigned int i = 0; i < a.g.size(); ++i) {
                vector<vertex_descriptor> vertexEdges = a.g[i];
                total += vertexEdges.size();
            }
            return total;}

        // ------------
        // num_vertices
        // ------------

        /**
	 * @param Graph a to determine number of vertices
         * @return The total number of vertices in a
	 */
        friend vertices_size_type num_vertices (const Graph& a) {
            return a.g.size();
        }

        // ------
        // source
        // ------

        /**
 	 * @param edge The edge to get the source of
         * @param a Graph which contains the edge
         * @return vertex descriptor of the source
	 */
        friend vertex_descriptor source (edge_descriptor edge, const Graph& a) {
            vertex_descriptor v = edge.first;
            return v;}

        // ------
        // target
        // ------

        /**
	 * @param edge The edge to get the target of
         * @param a Graph which contains the edge
         * @return vertex descriptor of the target
	 */
        friend vertex_descriptor target (edge_descriptor edge, const Graph& a) {
            vertex_descriptor v = edge.second;
            return v;}

        // ------
        // vertex
        // ------

        /**
	 * @param Vertex to get description of st
         * @param Graph which vertex is a member of
         * @return The vertex_descriptor for the vertex
	 */
        friend vertex_descriptor vertex (vertices_size_type st, const Graph&) {
            return st;}

        // --------
        // vertices
        // --------

        /**
	 * @param Graph to get the vertices from 
         * @return Begin and end iterators over the vertices of Graph a. 
	 */
        friend std::pair<vertex_iterator, vertex_iterator> vertices ( Graph& a) {
            return std::make_pair(a.allVertices.begin(), a.allVertices.end());}

    private:
        // ----
        // data
        // ----

        vector< vector<vertex_descriptor> > g; 

        // need to pass iterators of these for edges() and vertices(). can't be constructed on the fly. 
        vector<edge_descriptor> allEdges;
	vector<vertex_descriptor> allVertices;

	
        // -----
        // valid
        // -----

        /**
* <your documentation>
*/
        bool valid () const {
            // <your code>
            return true;}

    public:
        // ------------
        // constructors
        // ------------

        /**
* <your documentation>
*/
        Graph () {
            // <your code>
	    //g(vector<vertex_descriptor>());
            allEdges.reserve(10);
            allVertices.reserve(10);
            g.reserve(10);
            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Graph (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
    };

// ---------
// has_cycle
// ---------

/**
* depth-first traversal
* three colors
* <your documentation>
*/
template <typename G>
bool has_cycle (const G& g) {
    return true;}

// ----------------
// topological_sort
// ----------------

/**
* depth-first traversal
* two colors
* <your documentation>
* @throws Boost's not_a_dag exception if !has_cycle()
*/
template <typename G, typename OI>
void topological_sort (const G& g, OI x) {
    *x = 2;
    ++x;
    *x = 0;
    ++x;
    *x = 1;
    }

#endif // Graph_h
