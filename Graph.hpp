#pragma once

#include "Vertex.hpp"
#include "Edge.hpp"
#include <unordered_map>
#include <vector>

constexpr double MAX_DISTANCE = 1e9;

template <typename V, typename E>
class Graph
{
private:
    const size_t m_num_vertices;
    const size_t m_num_edges;
    V* const m_arr_vertices;
    E* const m_arr_edges;
    bool* const m_arr_visited; // visited[i] = if the vertex with index i has been visited

public:
    // constructor
    Graph(const size_t n, const size_t m);

    // methods

    // get methods

    size_t get_num_vertices() const {return this->m_num_vertices;}

    size_t get_num_edges() const {return this->m_num_edges;}

    V* get_vertex(const size_t idx) {return &this->m_arr_vertices[idx];}
    const V* get_vertex(const size_t idx) const {return &this->m_arr_vertices[idx];}

    E* get_edge(const size_t idx) {return &this->m_arr_edges[idx];}
    const E* get_edge(const size_t idx) const {return &this->m_arr_edges[idx];}

    bool* get_visited_arr() {return this->m_arr_visited;}
    const bool* get_visited_arr() const {return this->m_arr_visited;}

    // set methods

    // void setup_V(V* const v) {}
    void setup_E(E* const e, V* const orig, V* const dest);

    // other methods

    // Check if there exists a path from vertex a to vertex b.
    bool connected(V* a, V* b);

    // Compute the shortest path from vertex a to every vertex in the graph (or infinity if a vertex is not reachable from a).
    void Dijkstra(const V* const p_src, double a_dist[], const E* a_pred[]);
    
    void retrieve_shortest_path(const V* const p_src, const V* const p_dest, double a_dist[], const E* a_pred[], std::vector<const E*>& shortest_path);

    // virtual methods
    virtual void display_shortest_path(std::vector<const E*>& shortest_path) const = 0;

    // destructor
    ~Graph();
};
#include "Graph.hxx"
