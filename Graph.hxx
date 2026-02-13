#include "Graph.hpp"
#include "MinHeap.hpp"
#include <unordered_map>
#include <cstring>

// constructor
// Note that by default, a bool variable is false.
template <typename V, typename E>
Graph<V, E>::Graph(const size_t n, const size_t m) : m_num_vertices(n), m_num_edges(m), m_arr_vertices(new V[n]), m_arr_edges(new E[m]), m_arr_visited(new bool[n]{}) 
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
bool Graph<V, E>::connected(V* a, V* b)
{
    if (a == b)
    {
        return true;
    }

    // Perform BFS from a to find a path to b.

    // Set everything in visited to false.
    std::memset(this->get_visited_arr(), false, this->get_num_vertices() * sizeof(bool));
    
    // Enqueue a. 
    Vertex<E>* queue_head = a;
    Vertex<E>* queue_tail = a;
    a->set_next_in_list(nullptr);
    a->set_prev_in_list(nullptr);
    this->get_visited_arr()[a->get_idx()] = true;

    Vertex<E>* curr_vtx;
    Edge<V>* curr_outgoing_edge;
    Vertex<E>* neighbor_vtx;
    while (queue_head != nullptr)
    {
        curr_vtx = queue_head;

        // Dequeue queue_head.
        queue_head = curr_vtx->get_next_in_list();
        curr_vtx->set_next_in_list(nullptr);
        if (queue_head != nullptr)
        {
            queue_head->set_prev_in_list(nullptr);
        }
        else
        {
            queue_tail = nullptr;
        }

        // Visit all the unvisited outgoing neighbors of curr_vtx.
        curr_outgoing_edge = curr_vtx->get_adj_list_head();
        while (curr_outgoing_edge != nullptr)
        {
            neighbor_vtx = curr_outgoing_edge->get_dest();
            if (neighbor_vtx == b) // if we have found vertex b
            {
                return true;
            }
            if (!this->get_visited_arr()[neighbor_vtx->get_idx()])
            {
                this->get_visited_arr()[neighbor_vtx->get_idx()] = true;
                // Enqueue neighbor_vtx.
                if (queue_tail == nullptr)
                {
                    queue_head = neighbor_vtx;
                    queue_tail = neighbor_vtx;
                    neighbor_vtx->set_prev_in_list(nullptr);
                    neighbor_vtx->set_next_in_list(nullptr);
                }
                else
                {
                    queue_tail->set_next_in_list(neighbor_vtx);
                    neighbor_vtx->set_prev_in_list(queue_tail);
                    neighbor_vtx->set_next_in_list(nullptr);
                    queue_tail = neighbor_vtx;
                }
            }
            // Examine the next edge in curr_vtx's adjacency list.
            curr_outgoing_edge = curr_outgoing_edge->get_next_of_orig();
        }
    }
    return false;
}

// Compute the shortest path from vertex a to every vertex in the graph (or infinity if a vertex is not reachable from a).
// a_dist and a_pred are passed in by the user. 
// After calling the function, a_dist[i] = shortest distance from source to vertex with index i, and a_pred[i] = pointer to the predecessor edge of vertex i in the shortest path
template<typename V, typename E>
void Graph<V, E>::Dijkstra(const V* const p_src, double* a_dist, const Edge<V>** a_pred)
{
    size_t n = this->get_num_vertices();

    // Set everything in visited to false. The visited array will serve as the permanent array for Dijkstra's.
    std::memset(this->get_visited_arr(), false, n * sizeof(bool));

    // Set the dist_label of every vertex to positive infinity.
    std::fill(a_dist, a_dist + n, 1000000);

    // Set the predecessor of every vertex to nullptr.
    std::fill(a_pred, a_pred + n, nullptr);

    MinHeap<const V*, double> pq;
    const V* curr_vtx;
    const Edge<V>* curr_outgoing_edge;
    const V* neighbor_vtx;
    double new_dist_label;
    size_t neighbor_vtx_idx;

    a_dist[p_src->get_idx()] = 0.0;
    pq.add(std::make_pair(p_src, 0.0));
    while (!pq.empty())
    {
        curr_vtx = pq.pop().first;
        if (!this->get_visited_arr()[curr_vtx->get_idx()])
        {
            this->get_visited_arr()[curr_vtx->get_idx()] = true;
            // Scan all the outgoing unvisited (non-permanent) vertices of curr_vtx.
            curr_outgoing_edge = curr_vtx->get_adj_list_head();
            while (curr_outgoing_edge != nullptr)
            {
                neighbor_vtx = curr_outgoing_edge->get_dest();
                neighbor_vtx_idx = neighbor_vtx->get_idx();
                if (!this->get_visited_arr()[neighbor_vtx->get_idx()])
                {
                    new_dist_label = a_dist[curr_vtx->get_idx()] + curr_outgoing_edge->get_weight();
                    if (new_dist_label < a_dist[neighbor_vtx_idx])
                    {
                        a_dist[neighbor_vtx_idx] = new_dist_label;
                        a_pred[neighbor_vtx_idx] = curr_outgoing_edge;
                        pq.add(std::make_pair(neighbor_vtx, new_dist_label));
                    }
                }
                // Examine the next edge in curr_vtx's adjacency list.
                curr_outgoing_edge = curr_outgoing_edge->get_next_of_orig();
            }
        }
    }
}

// destructor

template <typename V, typename E>
Graph<V, E>::~Graph()
{
    delete[] this->m_arr_vertices;
    delete[] this->m_arr_edges;
}

