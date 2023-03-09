#include "Circuit.h"
#include <iomanip>
#include <iostream>

using namespace std;

Connection& Circuit::get_node( string const& node ) const
{
   Connection* A{};
   for ( Connection* i : nodes )
   {
      if ( i->get_name() == node )
      {
         A = i;
      }
   }
}

void Circuit::insert( Component* insert )
{
   net.push_back(insert);
}

void Circuit::connection( string const& name )
{
   nodes.push_back(new Connection{name});
}

void Circuit::insert_battery( string const& name, double const& v, string next_connect, string prev_connect )
{
   insert( new Battery{name, v, get_node(node1), get_node(node2)} );
}

void Circuit::insert_resistor( string const& name, double const& r, string next_connect, string prev_connect )
{
   insert( new Resistor{name, r, get_node(node1), get_node(node2)} );
}