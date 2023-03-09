#include "Connection.h"

Connection::Connection( std::string name )
    : name{name}
{
}
std::string Connection::get_name() const
{
    return name;
}
double Connection::get_voltage() const
{
    return voltage;
}

void Connection::set_voltage( double const& insert )
{
    voltage = insert;
}