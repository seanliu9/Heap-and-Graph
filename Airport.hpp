#pragma once
#include <string>

template<typename F>
class Airport : public Vertex<F>
{
friend class Airline<Airport<F>, F>;

private:
    const std::string m_code = "XXX"; // 3-letter airport code

public:
    std::string get_code() const {return this->m_code;}

    void setup(const std::string code) {this->m_code = code};
};
