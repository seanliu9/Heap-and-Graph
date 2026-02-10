#pragma once

template<typename V> class Edge;

template<typename E>
class Vertex
{
private:
    size_t orig_edge_count;
    E* p_adj_list_head; // head of the vertex's outgoing adjacency list

public:
    // constructors

    // default constructor
    Vertex() : orig_edge_count(0), p_adj_list_head(nullptr) {}; 

    // methods

    // get methods

    size_t get_orig_edge_count() const {return this->orig_edge_count;}
    
    const E* get_adj_list_head() const {return this->p_adj_list_head;}
    E* get_adj_list_head() {return this->p_adj_list_head;}

    // set methods

    void set_adj_list_head(const E* const e) {this->p_adj_list_head = e;}

    // other methods

    // Add edge e as an outgoing edge of the vertex.
    void add_outgoing_edge(E* e);

    // destructor
    ~Vertex();
};
// #include "Vertex.hxx"
