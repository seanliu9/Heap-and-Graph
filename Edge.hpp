#pragma once

template<typename E> class Vertex;

template<typename V>
class Edge
{
private:
    V* p_orig_vtx;
    V* p_dest_vtx;
    Edge<V>* p_next_of_orig;

public:
    // constructors

    // default constructor
    Edge() : p_orig_vtx(nullptr), p_dest_vtx(nullptr), p_next_of_orig(nullptr) {}

    Edge(const V* const orig, const V* const dest) : p_orig_vtx(orig), p_dest_vtx(dest), p_next_of_orig(nullptr) {}

    // methods

    // get methods

    const V* get_orig() const {return this->p_orig_vtx;}
    V* get_orig() {return this->p_orig_vtx;}

    const V* get_dest() const {return this->p_dest_vtx;}
    V* get_dest() const {return this->p_dest_vtx;}

    const Edge<V>* get_next_of_orig() const {return this->p_next_of_orig;}
    Edge<V>* get_next_of_orig() {return this->p_next_of_orig;}

    // set methods

    void set_next_of_orig(const Edge<V>* const next_of_orig)
    {
        this->p_next_of_orig = next_of_orig;
    }
};