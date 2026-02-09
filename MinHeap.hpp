#pragma once

#include <vector>
#include <iostream>

template<typename V, typename K>
class MinHeap
{
private:
    std::vector<std::pair<V, K>>* const pVec; // holds the value-key pairs that make up the min heap

    // methods

    std::vector<std::pair<V, K>>& get_vec() {return *this->pVec;}
    const std::vector<std::pair<V, K>>& get_vec() const {return *this->pVec;}

    // Maintain the min heap property of pVec after an insertion.
    void up_heap();

    // Maintain the min heap property of pVec after a deletion (of the root/min).
    void down_heap();

    // Maintain the min heap property of pVec (to be used when constructing the heap)
    void heapify();

public:
    // constructors

    // default constructor
    MinHeap() : pVec(new std::vector<std::pair<V, K>>()) {}

    // reserves the estimated space needed
    MinHeap(const size_t initial_capacity);

    // initializes pVec with an array containing the initial data
    template<size_t N>
    MinHeap(const std::pair<V, K> (&initial_arr)[N]);

    // initializes pVec with an array containing the initial data, and also the initial size
    MinHeap(const std::pair<V, K>* initial_arr, const size_t initial_size);

    // methods

    void add(const std::pair<V, K> x);

    std::pair<V, K> pop();

    std::pair<V, K> get_min() const;

    bool empty() const {return this->get_vec().empty();}

    friend std::ostream& operator << (std::ostream& os, const MinHeap<V, K>* const mh)
    {
        for (size_t i = 0; i < mh->get_vec().size(); i++) 
        {
            std::pair<V, K> curr_pair = mh->get_vec()[i];
            os << "(" << curr_pair.first << ", " << curr_pair.second << ")" << std::endl;
        }
        os << std::endl;
        return os;
    }

    // destructor
    ~MinHeap() {delete this->pVec;}
};

#include "MinHeap.hxx"