#include <vector>
#include <iostream>
using namespace std;

template<typename V, typename K>
class MinHeap
{
private:
    std::vector<std::pair<V, K>>* pVec; // holds the value-key pairs that make up the min heap

public:
    // constructors

    // default constructor
    MinHeap() : pVec(new std::vector<std::pair<V, K>>()) {}

    // reserves the estimated space needed
    MinHeap(const size_t initial_capacity) : pVec(new std::vector<std::pair<V, K>>())
    {
        this->pVec->reserve(initial_capacity);
    }

    // initializes pVec with an array containing the initial data
    template<size_t N>
    MinHeap(const pair<V, K> (&initial_arr)[N]) : pVec(new std::vector<std::pair<V, K>>())
    {
        this->pVec->reserve(2 * N);
        for (size_t i = 0; i < N; i++)
        {
            this->add(initial_arr[i]);
        }
    }

    // methods

    std::vector<pair<V, K>>* get_vec() const
    {
        return this->pVec;
    }

    // Maintain the min heap property of pVec after an insertion.
    void up_heap()
    {
        if (this->empty())
        {
            return;
        }
        size_t curr_idx = this->get_vec()->size() - 1;
        size_t parent_idx;
        // Keep swapping curr_idx and parent_idx until they are no longer out of order.
        while (curr_idx > 0) 
        { 
            parent_idx = (curr_idx - 1) / 2;
            if ((*pVec)[curr_idx].second < (*pVec)[parent_idx].second) 
            {
                std::swap((*this->get_vec())[curr_idx], (*this->get_vec())[parent_idx]);
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
    void down_heap() {
        if (this->empty())
        {
            return;
        }
        size_t n = this->get_vec()->size();
        size_t curr_idx = 0;
        size_t left_idx, right_idx, smaller_child_idx;

        while (2 * curr_idx + 1 < n) // while curr_idx has a left child
        {
            left_idx = 2 * curr_idx + 1;
            right_idx = 2 * curr_idx + 2;
            smaller_child_idx = left_idx;

            // Check if right child exists and is smaller than left child
            if (right_idx < n && (*this->get_vec())[right_idx].second < (*this->get_vec())[left_idx].second)
            {
                smaller_child_idx = right_idx;
            }

            // Swap the elements at curr_idx and smaller_child_idx if necessary.
            if ((*this->get_vec())[smaller_child_idx].second < (*this->get_vec())[curr_idx].second) 
            {
                std::swap((*this->get_vec())[curr_idx], (*this->get_vec())[smaller_child_idx]);
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

    void add(const pair<V, K> x)
    {
        this->get_vec()->push_back(x);
        this->up_heap();
    }

    std::pair<V, K> pop()
    {
        std::pair<V, K> res = this->get_min();
        // Swap the first and last elements of vec.
        std::swap((*this->get_vec())[0], (*this->get_vec())[this->get_vec()->size() - 1]);
        // Delete the last element in vec.
        this->get_vec()->pop_back();
        this->down_heap();
        return res;
    }

    std::pair<V, K> get_min() const
    {
        return (*this->get_vec())[0];
    }

    bool empty() const
    {
        return this->get_vec()->empty();
    }

    friend ostream& operator << (ostream& os, const MinHeap<V, K>* const mh)
    {
        for (int i = 0; i < mh->get_vec()->size(); i++) 
        {
            std::pair<V, K> curr_pair = (*mh->get_vec())[i];
            os << "(" << curr_pair.first << ", " << curr_pair.second << ")" << endl;
        }
        os << endl;
        return os;
    }

    // destructor
    ~MinHeap()
    {
        delete this->pVec;
    }

};

int main()
{
    cout << "Starting tests: " << endl;

    std::pair<char, int> arr[] = {{'A', 53}, {'B', 40}, {'M', 38}, {'R', 62}, {'H', 48}, {'D', 63}, {'C', 60}, {'G', 122}, {'W', 3}, {'J', 25}, {'Q', 81}, {'Z', 37}, {'N', 118}};
    MinHeap<char, int>* mh = new MinHeap<char, int>(arr);
    cout << mh;

    cout << "Testing add: " << endl;
    mh->add({'P', 16});
    mh->add({'E', 220});
    mh->add({'T', 44});
    cout << mh;

    cout << "Testing pop: " << endl;
    // Pop 3 times and see the status of mh.
    for (size_t i = 0; i < 3; i++)
    {
        mh->pop();
        cout << mh;
        cout << "min of heap = (" << mh->get_min().first << ", " << mh->get_min().second << ")" << endl << endl;
    }
    // Finish popping from mh.
    while (!mh->empty())
    {
        mh->pop();
    }
    cout << mh;
    delete mh;
    
    cout << endl << "Finished tests" << endl;
}