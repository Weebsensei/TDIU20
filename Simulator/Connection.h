#ifndef CONNECTION_H
#define CONNECTION_H
#include <string>

class Connection
{
public:
    Connection() = default;
    Connection(std::string name);

    double get_voltage() const;               
    void set_voltage( double const& insert );  
    std::string get_name() const;
    double voltage{};

private:
    std::string name{};
};

#endif