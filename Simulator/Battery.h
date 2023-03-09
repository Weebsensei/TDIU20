#ifndef Battery_H
#define Battery_H
#include "Component.h"

class Battery : public Component
{   
public:
    Battery( std::string const name, double const v, Connection& left, Connection& right );

    double get_voltage() const;
    double get_current() const override;
    void sim( double const& interval ) override;
private:
    double voltage;
};

#endif