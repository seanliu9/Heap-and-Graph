#pragma once

template<typename E> class Vertex;
template<typename V, typename E> class Graph;

template<typename V>
class Edge
{
// friend class Graph<V, Edge<V>>; 
template<typename E> friend class Vertex;
friend class Vertex<Edge<V>>;

private:
    V* m_p_orig_vtx = nullptr;
    V* m_p_dest_vtx = nullptr;
    Edge<V>* m_p_next_of_orig = nullptr;
    size_t m_idx = 0;

    // set methods

    void set_next_of_orig(Edge<V>* const next_of_orig) {this->m_p_next_of_orig = next_of_orig;}

public:
    // constructors

    // default constructor
    Edge() : m_p_orig_vtx(nullptr), m_p_dest_vtx(nullptr), m_p_next_of_orig(nullptr) {}

    Edge(const V* const orig, const V* const dest) : m_p_orig_vtx(orig), m_p_dest_vtx(dest), m_p_next_of_orig(nullptr) {}

    // methods

    // get methods

    const V* get_orig() const {return this->m_p_orig_vtx;}
    V* get_orig() {return this->m_p_orig_vtx;}

    const V* get_dest() const {return this->m_p_dest_vtx;}
    V* get_dest() {return this->m_p_dest_vtx;}

    const Edge<V>* get_next_of_orig() const {return this->m_p_next_of_orig;}
    Edge<V>* get_next_of_orig() {return this->m_p_next_of_orig;}

    size_t get_idx() const {return this->m_idx;}

    // set methods
    
    void set_orig(V* const v) {this->m_p_orig_vtx = v;}

    void set_dest(V* const v) {this->m_p_dest_vtx = v;}

    void set_idx(const size_t idx) {this->m_idx = idx;}

    // virtual methods

    virtual double get_weight() const = 0; // must be implemented by derived classes- used for algorithms like shortest path, etc.
};