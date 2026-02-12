#pragma once

#include "Vertex.hpp"
#include "Edge.hpp"

template <typename V, typename E>
class Graph
{
private:
    const size_t m_num_vertices;
    const size_t m_num_edges;
    V* const m_arr_vertices;
    E* const m_arr_edges;

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

    // set methods

    // void setup_V(V* const v) {}
    void setup_E(E* const e, V* const orig, V* const dest);

    // other methods

    // Check if there exists a path from vertex a to vertex b.
    bool connected(const V* const a, const V* const b) const;

    // destructor
    ~Graph();

    // virtual methods
    virtual void display() const = 0;
};
#include "Graph.hxx"
