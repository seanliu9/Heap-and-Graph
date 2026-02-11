#include "Airline.h"
#include "MinHeap.hpp"
#include <iostream>
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

void test_Graph()
{
    std::cout << "starting graph tests" << endl;

    Airline delta(4, 6, "Delta");
    Airport* pATL = delta.get_vertex(0);
    delta.set_airport(pATL, "ATL");
    Airport* pSFO = delta.get_vertex(1);
    delta.set_airport(pSFO, "SFO");
    Airport* pSJC = delta.get_vertex(2);
    delta.set_airport(pSJC, "SJC");
    Airport* pJFK = delta.get_vertex(3);
    delta.set_airport(pJFK, "JFK");

    Flight* const p_atl2sfo = delta.get_edge(0);
    delta.set_flight(p_atl2sfo, pATL, pSFO, 2500, 300);
    Flight* const p_atl2sjc = delta.get_edge(1);
    delta.set_flight(p_atl2sjc, pATL, pSJC, 2600, 350);
    Flight* const p_atl2jfk = delta.get_edge(2);
    delta.set_flight(p_atl2jfk, pATL, pJFK, 1800, 280);
    Flight* const p_sjc2sfo = delta.get_edge(3);
    delta.set_flight(p_sjc2sfo, pSJC, pSFO, 150, 190);
    Flight* const p_sjc2jfk = delta.get_edge(4);
    delta.set_flight(p_sjc2jfk, pSJC, pJFK, 3000, 470);
    Flight* const p_sfo2jfk = delta.get_edge(5);
    delta.set_flight(p_sfo2jfk, pSFO, pJFK, 2900, 550);
    

    std::cout << "finished graph tests" << endl;
}

int main()
{
    test_Graph();
}