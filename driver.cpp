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

    std::pair<char, int> arr1[] = {{'A', 53}, {'B', 40}, {'M', 38}, {'X', 40}, {'R', 62}, {'H', 48}, {'D', 63}, {'C', 60}, {'G', 122}, {'S', 60}, {'W', 3}, {'J', 25}, {'Q', 81}, {'Z', 37}, {'N', 118}};
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

    // Test graph construction.

    std::cout << endl << "constructing the graph" << endl;

    size_t num_airports = 9;
    size_t num_flights = 15;
    Airline delta(num_airports, num_flights, "Delta");

    // Set Delta's airports.
    std::string airport_codes [] = {"ATL", "JFK", "MSP", "SEA", "DEN", "SFO", "SJC", "LAX", "LAS"};
    for (size_t i = 0; i < num_airports; i++)
    {
        Airport* const curr_airport = delta.get_vertex(i);
        delta.set_airport(curr_airport, airport_codes[i]);
    }

    // Set Delta's flights.
    std::pair<std::string, std::string> flight_cities [] = {{"ATL", "JFK"}, {"ATL", "MSP"}, {"ATL", "DEN"}, {"ATL", "SJC"}, {"SEA", "JFK"}, {"SEA", "MSP"}, {"SFO", "SEA"}, {"SEA", "DEN"}, {"SFO", "DEN"}, {"SFO", "LAX"}, {"LAX", "SFO"}, {"LAX", "SJC"}, {"SJC", "LAX"}, {"LAS", "SEA"}, {"LAS", "DEN"}};
    std::pair<double, double> flight_data [] = {{50, 345}, {35, 305}, {30, 415}, {35, 550}, {60, 590}, {40, 535}, {25, 355}, {20, 275}, {15, 220}, {10, 200}, {10, 200}, {15, 195}, {15, 195}, {15, 170}, {10, 160}};
    for (size_t i = 0; i < num_flights; i++)
    {
        Flight* const curr_flight = delta.get_edge(i);
        Airport* const orig = delta.get_airport_from_code(flight_cities[i].first);
        Airport* const dest = delta.get_airport_from_code(flight_cities[i].second);

        delta.set_flight(curr_flight, orig, dest, flight_data[i].first, flight_data[i].second);
    }
    
    delta.display();

    std::cout << endl << "finished constructing the graph" << endl;

    // Test graph connectivity.

    std::cout << endl << "testing graph connectivity" << endl;

    std::cout << "Are ATL and JFK connected? " << delta.are_connected("ATL", "JFK") << endl;
    std::cout << "Are MSP and MSP connected? " << delta.are_connected("MSP", "MSP") << endl;
    std::cout << "Are SJC and JFK connected? " << delta.are_connected("SJC", "JFK") << endl;
    std::cout << "Are DEN and ATL connected? " << delta.are_connected("DEN", "ATL") << endl;
    std::cout << "Are LAX and SFO connected? " << delta.are_connected("LAX", "SFO") << endl;
    std::cout << "Are SFO and LAX connected? " << delta.are_connected("SFO", "LAX") << endl;
    std::cout << "Are ATL and SFO connected? " << delta.are_connected("ATL", "SFO") << endl;
    std::cout << "Are SFO and ATL connected? " << delta.are_connected("SFO", "ATL") << endl;

    std::cout << endl << "finished testing graph connectivity" << endl;

    std::cout << "testing shortest path" << endl;

    const Airport* pATL = delta.get_airport_from_code("ATL");
    double* a_dist = new double[delta.get_num_vertices()];
    const Edge<Airport>** a_pred = new const Edge<Airport>*[delta.get_num_vertices()];
    delta.Dijkstra(pATL, a_dist, a_pred);
    std::cout << "distance from ATL to LAX = " << a_dist[delta.get_airport_from_code("LAX")->get_idx()] << endl;
    std::cout << "distance from ATL to SFO = " << a_dist[delta.get_airport_from_code("SFO")->get_idx()] << endl;
    std::cout << "distance from ATL to ATL = " << a_dist[delta.get_airport_from_code("ATL")->get_idx()] << endl;
    std::cout << "distance from ATL to MSP = " << a_dist[delta.get_airport_from_code("MSP")->get_idx()] << endl;
    std::cout << "distance from ATL to JFK = " << a_dist[delta.get_airport_from_code("JFK")->get_idx()] << endl;
    std::cout << "distance from ATL to LAS = " << a_dist[delta.get_airport_from_code("LAS")->get_idx()] << endl;

    std::cout << "finished graph tests" << endl;
}

int main()
{
    // test_MinHeap();
    test_Graph();
}