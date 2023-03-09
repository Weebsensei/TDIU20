#include "Resistor.h"

Resistor::Resistor( std::string const name, double const r, Connection& p, Connection& n )
    :   Component( name, p, n ), resistance{r}
{
}

double Resistor::get_current() const 
{
    double temp;
    temp = get_potential()/resistance;
    return temp;
}

void Resistor::sim( double const& interval )
{
    double temp = Resistor::get_current() * interval;
    if ( p.voltage > n.voltage )
    {
        p.voltage -= temp;
        n.voltage += temp;
    }
    else if ( n.voltage > p.voltage )
    {
        p.voltage += temp;
        n.voltage -= temp;
    }
    else //n.voltage == p.voltage
    {
        return;
    }
}
