#pragma once

template<typename F> class Airport;

template<typename A>
class Flight : public Edge<A>
{
private:
    const double distance = 0;
    const double cost = 0;

public:
    double get_distance() const {return this->distance;}
    double get_cost() const {return this->cost;}

    void setup(const Airport<F>* p_orig, const Airport<F>* p_dest, const double dist, const double cost);
};