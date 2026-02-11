#pragma once
#include <string>
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
};
