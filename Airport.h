#pragma once
#include <string>
#include <iostream>
#include "Graph.hpp"

class Flight;
class Airline;

class Airport : public Vertex<Flight>
{
friend class Airline;

private:
    std::string m_code = "XXX"; // 3-letter airport code

public:
    // methods

    // get methods

    std::string get_code() const {return this->m_code;}

    // set methods

    void set_code(const std::string code) {this->m_code = code;}

    // inherited virtual method from Vertex
    virtual void display() const {std::cout << "Airport " << this->get_code() << " at index " << this->get_idx() << " with " << this->get_orig_edge_count() << " outgoing flights" << std::endl;}
};
