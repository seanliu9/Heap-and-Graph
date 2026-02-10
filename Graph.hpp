#pragma once

#include "Vertex.hpp"
#include "Edge.hpp"

template <typename V, typename E>
class Graph
{
private:
    V* arr_vertices;
    E* arr_edges;

public:
    // constructors

    // default constructor
    Graph() : arr_vertices(nullptr), arr_edges(nullptr) {}

    Graph(const V* const vertices, const E* const edges);

    // methods

    // get methods

    const V* get_vertices() const {return this->arr_vertices;}
    V* get_vertices() {return this->arr_vertices;}

    const E* get_edges() const {return this->arr_edges;}
    E* get_edges() {return this->arr_edges;}
};
