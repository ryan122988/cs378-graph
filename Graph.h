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

        typedef int vertex_descriptor;
        typedef pair<vertex_descriptor, vertex_descriptor> edge_descriptor;

        typedef vector<vertex_descriptor>::iterator vertex_iterator; 
        typedef vector<pair<vertex_descriptor, vertex_descriptor> >::iterator edge_iterator;
        typedef int* adjacency_iterator; // fix!

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
	 * <your documentation>
	 */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor source, vertex_descriptor target, Graph& a) {
            // <your code>
	    bool b;
            pair<vertex_descriptor, vertex_descriptor> ed (source, target);
	    vector<vertex_descriptor>::iterator result = find(a.g[source].begin(), a.g[source].end(), target);
	    if (result == a.g[source].end()) {
	        b = true;
                a.g[source].push_back(target);
            } else { 
                b = false;
            }
/*            cout << "SOURCE:  " << source << endl;
            cout << "TARGETS: " << endl;
            for (int i = 0 ; i < a.g[source].size(); ++i) {
                cout << a.g[source][i] << " ";
            }
            cout << endl;*/
            return std::make_pair(ed, b);}

        // ----------
        // add_vertex
        // ----------

        /**
 	 * <your documentation>
	 */
        friend vertex_descriptor add_vertex (Graph& a) {
	    vector<vertex_descriptor > vertex(0);
	    a.g.push_back(vertex);
            return (a.g.size() - 1);}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
	 * <your documentation>
	 */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor, const Graph&) {
            // <your code>
            adjacency_iterator b = adjacency_iterator();
            adjacency_iterator e = adjacency_iterator();
            return std::make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
	 * <your documentation>
	 */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor , vertex_descriptor, const Graph&) {
            
            edge_descriptor ed;
            bool b;
            return std::make_pair(ed, b);}

        // -----
        // edges
        // -----

        /**
	 * <your documentation>
	 */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph& a) {
            vector<pair<vertex_descriptor, vertex_descriptor> > allEdges;
            for(int i = 0; i < a.g.size(); ++i) {
                vector<vertex_descriptor> vertexEdges = a.g[i];
                cout << "__source: " << i << endl;
                cout << "__targers: "<< endl;
                for(int i2 = 0; i2 < a.g[i].size(); i2++) {
                    cout << vertexEdges[i2] << " ";
                    pair<vertex_descriptor, vertex_descriptor> edge(i, vertexEdges[i2]);
                    allEdges.push_back(edge);
                }
                cout << endl;
            }
            cout << "second of the first one: " << (*allEdges.begin()).second << endl;
            return std::make_pair(allEdges.begin(), allEdges.end());}

        // ---------
        // num_edges
        // ---------

        /**
	 * @param a Graph to determine the number of edges on
         * @return The total number of edges in a
	 */
        friend edges_size_type num_edges (const Graph& a) {

            edges_size_type total = 0;
            for(int i = 0; i < a.g.size(); ++i) {
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
 	 * <your documentation>
	 */
        friend vertex_descriptor source (edge_descriptor edge, const Graph&) {
            vertex_descriptor v = edge.first;
            return v;}

        // ------
        // target
        // ------

        /**
	 * <your documentation>
	 */
        friend vertex_descriptor target (edge_descriptor edge, const Graph&) {
            vertex_descriptor v = edge.second;
            return v;}

        // ------
        // vertex
        // ------

        /**
	 * <your documentation>
	 */
        friend vertex_descriptor vertex (vertices_size_type st, const Graph&) {
            return st;}

        // --------
        // vertices
        // --------

        /**
	 * <your documentation>
	 */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph& a) {
            vector<vertex_descriptor> iter(0, a.g.size());         
            return std::make_pair(iter.begin(), iter.end());}
    private:
        // ----
        // data
        // ----

        std::vector< std::vector<vertex_descriptor> > g; // something like this

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
