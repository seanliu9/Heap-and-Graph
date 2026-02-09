#include <stdexcept>

// constructors

// reserves the estimated space needed
template<typename V, typename K>
MinHeap<V, K>::MinHeap(const size_t initial_capacity) : pVec(new std::vector<std::pair<V, K>>())
{
    this->pVec->reserve(initial_capacity);
}

// initializes pVec with an array containing the initial data
template<typename V, typename K>
template<size_t N>
MinHeap<V, K>::MinHeap(const std::pair<V, K> (&initial_arr)[N]) : pVec(new std::vector<std::pair<V, K>>)
{
    this->pVec->reserve(2 * N);
    for (size_t i = 0; i < N; i++)
    {
        this->pVec->push_back(initial_arr[i]);
    }
    this->heapify();
}

// methods

// Maintain the min heap property of pVec after an insertion.
template<typename V, typename K>
void MinHeap<V, K>::up_heap()
{
    if (this->empty())
    {
        return;
    }
    size_t curr_idx = this->get_vec().size() - 1;
    size_t parent_idx;
    // Keep swapping curr_idx and parent_idx until they are no longer out of order.
    while (curr_idx > 0) 
    { 
        parent_idx = (curr_idx - 1) / 2;
        if ((*pVec)[curr_idx].second < (*pVec)[parent_idx].second) 
        {
            std::swap(this->get_vec()[curr_idx], this->get_vec()[parent_idx]);
            // Move up to the next level.
            curr_idx = parent_idx;
        } 
        else 
        {
            // The min heap property is now satisfied.
            break;
        }
    }
}

// Maintain the min heap property of pVec after a deletion (of the root/min).
template<typename V, typename K>
void MinHeap<V, K>::down_heap() {
    if (this->empty())
    {
        return;
    }
    size_t n = this->get_vec().size();
    size_t curr_idx = 0;
    size_t left_idx, right_idx, smaller_child_idx;

    while (2 * curr_idx + 1 < n) // while curr_idx has a left child
    {
        left_idx = 2 * curr_idx + 1;
        right_idx = 2 * curr_idx + 2;
        smaller_child_idx = left_idx;

        // Check if right child exists and is smaller than left child
        if (right_idx < n && this->get_vec()[right_idx].second < this->get_vec()[left_idx].second)
        {
            smaller_child_idx = right_idx;
        }

        // Swap the elements at curr_idx and smaller_child_idx if necessary.
        if (this->get_vec()[smaller_child_idx].second < this->get_vec()[curr_idx].second) 
        {
            std::swap(this->get_vec()[curr_idx], this->get_vec()[smaller_child_idx]);
            // Move down to the next level.
            curr_idx = smaller_child_idx;
        } 
        else 
        {
            // The min heap property is now satisfied.
            break;
        }
    }
}

// Maintain the min heap property of pVec (to be used when constructing the heap)
template<typename V, typename K>
void MinHeap<V, K>::heapify()
{
    size_t n = this->get_vec().size();
    size_t parent, left, right, min_idx;
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        parent = i;
        while (true)
        {
            left = 2 * parent + 1;
            right = 2 * parent + 2;
            min_idx = parent;

            // Compare parent with its left child.
            if (left < n && this->get_vec()[min_idx].second > this->get_vec()[left].second)
            {
                min_idx = left;
            }

            // Compare parent with its right child.
            if (right < n && this->get_vec()[min_idx].second > this->get_vec()[right].second)
            {
                min_idx = right;
            }

            if (min_idx != parent)
            {
                std::swap(this->get_vec()[min_idx], this->get_vec()[parent]);
                parent = min_idx;
            }
            else
            {
                // The min heap property is now satisfied.
                break;
            }
        }
    }
}

template<typename V, typename K>
void MinHeap<V, K>::add(const std::pair<V, K> x)
{
    this->get_vec().push_back(x);
    this->up_heap();
}

template<typename V, typename K>
std::pair<V, K> MinHeap<V, K>::pop()
{
    if (this->empty())
    {
        throw std::runtime_error("Heap is already empty.");
    }
    else
    {
        std::pair<V, K> res = this->get_min();
        // Swap the first and last elements of vec.
        std::swap(this->get_vec()[0], this->get_vec()[this->get_vec().size() - 1]);
        // Delete the last element in vec.
        this->get_vec().pop_back();
        this->down_heap();
        return res;
    }
}

template<typename V, typename K>
std::pair<V, K> MinHeap<V, K>::get_min() const
{
    if (this->empty())
    {
        throw std::runtime_error("Heap is empty.");
    }
    else
    {
        return this->get_vec()[0];
    }
}


