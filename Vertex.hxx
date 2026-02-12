#include "Vertex.hpp"

// methods

// Add edge e as an outgoing edge of the vertex.
template<typename E>
void Vertex<E>::add_outgoing_edge(E* const e)
{
    e->set_next_of_orig(this->get_adj_list_head());
    this->set_adj_list_head(e);
    this->m_orig_edge_count++;
}