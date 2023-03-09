#ifndef Resistor_H
#define Resistor_H
#include "Component.h"

class Resistor : public Component
{
public:
    Resistor( std::string const name, double const res, Connection& left, Connection& right );

    double get_current() const override;
    void sim( double const& interval ) override;
private:
    double resistance;
    
};
#endif