#ifndef Component_H
#define Component_H
#include "Connection.h"

class Component
{
public:
    Component( std::string const& name, Connection& left, Connection& right );
    virtual ~Component() = default;

    std::string get_name() const;
    virtual double get_potential() const;
    virtual double get_current() const;
    virtual void sim( double const& interval ) = 0;               
private:
    //std::string name;
protected:
    std::string name;
    Connection& p;          //connection point 1
    Connection& n;          //connection point 2

};

#endif