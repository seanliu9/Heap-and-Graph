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
    // constructors
    Graph(const size_t n, const size_t m) : m_num_vertices(n), m_num_edges(m), m_arr_vertices(new V[n]), m_arr_edges(new E[m]) {}

    // methods

    // get methods

    size_t get_num_vertices() const {return this->m_num_vertices;}

    size_t get_num_edges() const {return this->m_num_edges;}

    V* get_vertex(const size_t idx) {return this->m_arr_vertices[idx];}
    E* get_edge(const size_t idx) {return this->m_arr_edges[idx];}

    virtual void setup();
};
