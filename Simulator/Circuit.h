#ifndef Circuit_H
#define Circuit_H
#include "Component.h"
#include <vector>

class Circuit
{
public:
~Circuit();
void sim( int const& iterations, int const& prints, double const& interval ) const;
void insert_connection( std::string const& name );
void insert_battery( std::string const& name, double const& v, std::string next_connect, std::string prev_connect );
void insert_resistor( std::string const& name, double const& r, std::string next_connect, std::string prev_connect );
void insert( Component* insert);

private:
Connection& get_node( std::string const& node ) const;
std::vector<Component*> net{};
std::vector<Connection*> nodes{};
};
#endif