#ifndef Capacitor_H
#define Capacitor_H
#include "Component.h"

class Capacitor : public Component
{
public:
    Capacitor( std::string const name, double const cap, Connection& left, Connection& right );

    double get_current();
    
private:
    double Capacitance;

};


#endif