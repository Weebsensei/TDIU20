#ifndef GHOST_H
#define GHOST_H
#include "given.h"
#include <string>

using namespace std;

class Ghost
{
public:
    Ghost(Point const& startPosition, string const& color);
    virtual ~Ghost() = default;
    
    Point get_position() const;
    void set_position(Point const& p);

    virtual Point get_chase_point() = 0;
    virtual Point get_scatter_point() const = 0;
    virtual string get_color() const = 0;

protected:
    
    Point pos;
    Point targetPos;
    Point targetDir;
    string color;
};

class Blinky : public Ghost
{
public:
    Blinky(Point const& startPosition, string const& color);

    Point get_chase_point() override;
    Point get_scatter_point() const override;
    string get_color() const override;

    bool is_angry() const;
    void set_angry(bool);

private:
    bool angry = false;
};

class Pinky : public Ghost
{
    Pinky(Point const& startPosition, string const& color);

    Point get_chase_point() override;
    Point get_scatter_point() const override;
    string get_color() const override;
};

class Clyde : public Ghost
{
    Clyde(Point const& startPosition, string const& color);

    Point get_chase_point() override;
    Point get_scatter_point() const override;
    string get_color() const override;
};

#endif