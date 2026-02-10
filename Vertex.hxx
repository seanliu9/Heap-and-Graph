#include "Vertex.hpp"

// methods

// Add edge e as an outgoing edge of the vertex.

template<typename E>
void Vertex<E>::add_outgoing_edge(E* e)
{
    Vertex<E>* orig = e->get_orig();
    e->set_next_of_orig(orig->get_adj_list_head());
    orig->set_adj_list_head(e);
    this->orig_edge_count++;
}