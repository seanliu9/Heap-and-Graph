#pragma once
#include <string>
#include "Airport.h"
#include "Flight.h"
#include "Graph.hpp"

class Airline : public Graph<Airport, Flight>
{
private:
    std::string m_name = "unknown";

public:
    // constructor
    Airline(const size_t n, const size_t m, const std::string name) : Graph<Airport, Flight>(n, m), m_name(name) {}

    // methods

    std::string get_name() const {return this->m_name;}

    void set_airport(Airport* const airport, const std::string code)
    {
        airport->set_code(code);
    }

    void set_flight(Flight* const flight, Airport* const p_orig, Airport* const p_dest, const double dist, const double cost)
    {
        this->setup_E(flight, p_orig, p_dest);
        flight->set_distance(dist);
        flight->set_cost(cost);
    }
};