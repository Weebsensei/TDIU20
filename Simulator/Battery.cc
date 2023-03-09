#include "Battery.h"

Battery::Battery( std::string const name, double const v, Connection& p, Connection& n )
    :   Component( name, p, n ), voltage{v}
{
}

double Battery::get_voltage() const
{
    return voltage;
}

double Battery::get_current() const
{
    return 0.0; //alltid noll
}

void Battery::sim( double const& interval )
{
    n.voltage = get_voltage();
    p.voltage = 0.0 * interval;   //noll :)
}
