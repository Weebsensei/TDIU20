#include "Component.h"


Component::Component( std::string const& name, Connection& left, Connection& right)
    :  name{name}, p{left}, n{right}
{
}
std::string Component::get_name() const
{
    return name;
}
double Component::get_current() const
{
    return 0.0;    //default value
}

double Component::get_potential() const         //Laddningsskillnad mellan punkt a och b
{
    double voltage{};
    
    if ( p.get_voltage() > n.get_voltage() )
    {
        voltage = p.get_voltage() - n.get_voltage();
    }
    else
    {
        voltage = n.get_voltage() - p.get_voltage();
    }
    return voltage;
}