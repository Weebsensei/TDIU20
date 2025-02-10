#include "ghost.h"

using namespace std;

//Ghost
Ghost::Ghost(Point const& startPosition, string const& color)
    : pos(startPosition), color(color) {}

// Blinky
Blinky::Blinky(Point const& startPosition, string const& color)
    : Ghost(startPosition, "red") {}

Point Blinky::get_chase_point()
{
    return Point{0, 0}; //return Pacman::get_position();
}

Point Blinky::get_scatter_point() const
{
    if (!angry) {
        return Point{WIDTH, HEIGHT};
    } else {
        return targetPos; //return Pacman::get_position();
    }
}

string Blinky::get_color() const
{
    return "red";
}

//Pinky
Pinky::Pinky(Point const& startPosition, string const& color)
    : Ghost(startPosition, "red") {}

Point Pinky::get_chase_point()
{
    return Point{0, HEIGHT};
}

Point Pinky::get_scatter_point() const
{

    return targetPos;
}

string Pinky::get_color() const
{
    return "pink";
}

//Clyde
Clyde::Clyde(Point const& startPosition, string const& color)
    : Ghost(startPosition, "red") {}

Point Clyde::get_chase_point()
{
    return Point{0, 0};
}

Point Clyde::get_scatter_point() const
{

    return targetPos;
}

string Clyde::get_color() const
{
    return "orange";
}

bool operator==(Point const& lhs, Point const& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

std::istream& operator>>(std::istream& is, Point& rhs)
{
    return is >> rhs.x >> rhs.y;
}

Ghost::Ghost()
    : pos {}, dir {1,0}
{}

Point Ghost::get_position() const
{
    return pos;
}

void Ghost::set_position(Point const& p)
{
    if (p.x > WIDTH or p.x < 0 or p.y > HEIGHT or p.y < 0)
    {
        throw std::runtime_error("position outside valid range");
    }
    pos = p;
}

Point Ghost::get_direction() const
{
    return dir;
}

void Ghost::set_direction(Point const& p)
{
    if (p.x > 1 or p.x < -1 or p.y > 1 or p.y < -1 or abs(p.x + p.y) != 1)
    {
        throw std::runtime_error("direction outside valid range");
    }
    dir = p;
}