#pragma once
#include <string>
#include <unordered_map>
#include "Airport.h"
#include "Flight.h"
#include "Graph.hpp"

class Airline : public Graph<Airport, Flight>
{
private:
    std::string m_name = "unknown";
    std::unordered_map<std::string, int> code_to_idx; // maps a 3-letter airport code to its corresponding index in m_arr_vertices
    size_t curr_idx = 0; // current index we are setting

    // private get methods

    std::unordered_map<std::string, int>& get_code_to_idx() {return this->code_to_idx;}
    const std::unordered_map<std::string, int>& get_code_to_idx() const {return this->code_to_idx;}

public:
    // constructor
    Airline(const size_t n, const size_t m, const std::string name) : Graph<Airport, Flight>(n, m), m_name(name) {}

    // methods

    // get methods

    std::string get_name() const {return this->m_name;}

    const Airport* get_airport_from_code(const std::string& code) const {return this->get_vertex(this->code_to_idx.at(code));}
    Airport* get_airport_from_code(const std::string& code) {return this->get_vertex(this->code_to_idx.at(code));}

    // set methods

    void set_airport(Airport* const airport, const std::string& code) 
    {
        airport->set_code(code);
        this->get_code_to_idx()[code] = this->curr_idx;
        this->curr_idx++;
    }

    void set_flight(Flight* const flight, Airport* const p_orig, Airport* const p_dest, const double dist, const double cost)
    {
        this->setup_E(flight, p_orig, p_dest);
        flight->set_distance(dist);
        flight->set_cost(cost);
    }

    bool are_connected(const std::string& a_code, const std::string& b_code) const {return this->connected(this->get_airport_from_code(a_code), this->get_airport_from_code(b_code));}

    // inherited virtual method from Graph
    virtual void display() const
    {
        for (size_t i = 0; i < this->get_num_vertices(); i++)
        {
            this->get_vertex(i)->display();
        }
    }
};

