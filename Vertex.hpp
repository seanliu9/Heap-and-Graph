#pragma once
#include <cstddef>
#include "Edge.hpp"

template<typename V> class Edge;
template <typename V, typename E> class Graph;

template<typename E>
class Vertex
{
friend class Graph<Vertex<E>, E>;

private:
    size_t m_orig_edge_count = 0; // number of outgoing edges from the vertex
    E* m_p_adj_list_head = nullptr; // head of the vertex's outgoing adjacency list
    size_t m_idx = 0; // index of the vertex

public:
    // methods

    // get methods

    size_t get_orig_edge_count() const {return this->m_orig_edge_count;}
    
    const E* get_adj_list_head() const {return this->m_p_adj_list_head;}
    E* get_adj_list_head() {return this->m_p_adj_list_head;}

    size_t get_idx() const {return this->m_idx;}

    // set methods

    void set_adj_list_head(E* const e) {this->m_p_adj_list_head = e;}

    void set_idx(const size_t idx) {this->m_idx = idx;}

    // other methods

    // Add edge e as an outgoing edge of the vertex.
    void add_outgoing_edge(E* const e);

    // virtual methods

    virtual void display() const = 0;
};
#include "Vertex.hxx"
