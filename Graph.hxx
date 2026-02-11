#include "Graph.hpp"

// template <typename V, typename E>
// void Graph<V, E>::setup_V(V* const v)
// {

// }

template <typename V, typename E>
void Graph<V, E>::setup_E(E* const e, V* const orig, V* const dest)
{
    e->set_orig(orig);
    e->set_dest(dest);
    orig->add_outgoing_edge(e);
}

