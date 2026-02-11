#pragma once
#include <string>
#include "Airport.hpp"
#include "Flight.hpp"

template <typename A, typename F>
class Airline : public Graph<A, F>
{
private:
    std::string m_name = "unknown";

public:
    // constructor
    Airline(const size_t n, const size_t m) : Graph<A, F>(n, m) {}

    // methods

    std::string get_name() const {return this->m_name;}

    void set_vertex(const size_t idx, const std::string code);

    void set_edge(const size_t idx, const Airport<F>* p_orig, const Airport<F>* p_dest, const double dist, const double cost);
};