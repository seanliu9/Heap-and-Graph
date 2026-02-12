#include "Graph.hpp"
#include <queue>

// constructor
template <typename V, typename E>
Graph<V, E>::Graph(const size_t n, const size_t m) : m_num_vertices(n), m_num_edges(m), m_arr_vertices(new V[n]), m_arr_edges(new E[m]) 
{
    // Assign an index to each vertex.
    for (size_t i = 0; i < n; i++)
    {
        this->m_arr_vertices[i].set_idx(i);
    }

    // Assign an index to each edge.
    for (size_t i = 0; i < m; i++)
    {
        this->m_arr_edges[i].set_idx(i);
    }
}

// methods

template <typename V, typename E>
void Graph<V, E>::setup_E(E* const e, V* const orig, V* const dest)
{
    e->set_orig(orig);
    e->set_dest(dest);
    orig->add_outgoing_edge(e);
}

// Check if there exists a path from vertex a to vertex b.
template <typename V, typename E>
bool Graph<V, E>::connected(const V* const a, const V* const b) const
{
    if (a == b)
    {
        return true;
    }

    // Perform BFS from a to find a path to b.
    bool visited [this->get_num_vertices()]= {false}; // visited[i] = if the vertex with index i has been visited
    std::queue<const V*> q;
    const V* curr_vtx;
    const Edge<V>* curr_outgoing_edge;
    const V* curr_dest_vtx;
    q.push(a);
    visited[a->get_idx()] = true;

    while (!q.empty())
    {
        curr_vtx = q.front();
        q.pop();

        // Visit all the unvisited neighbors of curr_vtx.
        curr_outgoing_edge = curr_vtx->get_adj_list_head();
        while (curr_outgoing_edge != nullptr)
        {
            curr_dest_vtx = curr_outgoing_edge->get_dest();
            if (curr_dest_vtx == b) // if we have found vertex b
            {
                return true;
            }
            if (!visited[curr_dest_vtx->get_idx()])
            {
                visited[curr_dest_vtx->get_idx()] = true;
                q.push(curr_dest_vtx);
            }
            // Examine the next edge in curr_vtx's adjacency list.
            curr_outgoing_edge = curr_outgoing_edge->get_next_of_orig();
        }
    }
    return false;
}

// destructor

template <typename V, typename E>
Graph<V, E>::~Graph()
{
    delete[] this->m_arr_vertices;
    delete[] this->m_arr_edges;
}

