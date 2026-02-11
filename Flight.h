#pragma once
#include "Graph.hpp"

class Airport;
class Airline;

class Flight : public Edge<Airport>
{
friend class Airline;
private:
    double m_distance = 0; // distance from the origin to destination
    double m_cost = 0; // cost of the flight ticket

public:
    // methods

    // get methods

    double get_distance() const {return this->m_distance;}

    double get_cost() const {return this->m_cost;}

    // set methods

    void set_distance(const double dist) {this->m_distance = dist;}
    void set_cost(const double cost) {this->m_cost = cost;}
};