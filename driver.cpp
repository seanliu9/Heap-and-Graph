#include "MinHeap.hpp"
#include "Graph.hpp"
using namespace std;

void test_MinHeap()
{
    std::cout << "Starting function tests: " << endl;

    std::pair<char, int> arr[] = {{'A', 53}, {'B', 40}, {'M', 38}, {'R', 62}, {'H', 48}, {'D', 63}, {'C', 60}, {'G', 122}, {'W', 3}, {'J', 25}, {'Q', 81}, {'Z', 37}, {'N', 118}};

    MinHeap<char, int>* mh = new MinHeap<char, int>(arr);
    std::cout << "mh: " << endl << mh;

    MinHeap<char, int>* mh2 = new MinHeap<char, int>(arr, 13);
    std::cout << "mh2: " << endl << mh2;
    delete mh2;

    std::cout << "Testing add: " << endl;
    mh->add({'P', 16});
    mh->add({'E', 220});
    mh->add({'T', 44});
    std::cout << mh;

    std::cout << "Testing pop: " << endl;
    // Pop 3 times and see the status of mh.
    for (size_t i = 0; i < 3; i++)
    {
        mh->pop();
        std::cout << mh;
        std::cout << "min of heap = (" << mh->get_min().first << ", " << mh->get_min().second << ")" << endl << endl;
    }
    // Finish popping from mh.
    while (!mh->empty())
    {
        mh->pop();
    }
    std::cout << mh;
    delete mh;
    
    std::cout << endl << "Finished function tests" << endl;

    std::cout << endl << "Starting heap sort test: " << endl;

    std::pair<char, int> arr1[] = {{'A', 53}, {'B', 40}, {'M', 38}, {'R', 62}, {'H', 48}, {'D', 63}, {'C', 60}, {'G', 122}, {'W', 3}, {'J', 25}, {'Q', 81}, {'Z', 37}, {'N', 118}};
    MinHeap<char, int>* mh1 = new MinHeap<char, int>(arr1);
    std::vector<int> sorted;
    while (!mh1->empty())
    {
        sorted.push_back(mh1->pop().second);
    }
    for (size_t i = 0; i < sorted.size(); i++)
    {
        std::cout << sorted[i] << endl;
    }
    delete mh1;

    std::cout << endl << "Finished heap sort tests" << endl;
}

int main()
{
    test_MinHeap();
}