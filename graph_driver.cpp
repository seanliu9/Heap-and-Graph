#include "Vertex.hpp"
#include "Edge.hpp"
#include "Graph.hpp"
#include "Airport.hpp"
#include "Flight.hpp"
#include "Airline.hpp"
#include <iostream>
using namespace std;

int main()
{
    std::cout << "starting graph tests" << endl;

    Airline<Airport<Flight<void>>, Flight<Airport<void>>> delta(50, 1000);

    std::cout << "finished graph tests" << endl;
}