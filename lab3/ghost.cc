#include "ghost.h"

using namespace std;

bool operator==(Point const& lhs, Point const& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

std::istream& operator>>(std::istream& is, Point& rhs)
{
    return is >> rhs.x >> rhs.y;
}

//Ghost
Ghost::Ghost(Pacman* pacman, Point const& startPosition, 
             Point const& scatterPosition, string const& color)
    : pos(startPosition), scatterPosition(scatterPosition), color(color) {}

// Blinky
Blinky::Blinky(Pacman* pacman, Point const& startPosition, 
               Point const& scatterposition)
    : Ghost(pacman, startPosition, scatterposition, "red") {}

Point Blinky::get_chase_point() const
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
Pinky::Pinky(Pacman* pacman, Point const& startPosition, 
             Point const& scatterposition)
    : Ghost(pacman, startPosition, scatterposition, "pink") {}

Point Pinky::get_chase_point() const
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
Clyde::Clyde(Pacman* pacman, Point const& startPosition, 
             Point const& scatterposition, int distance)
    : Ghost(pacman, startPosition, scatterposition, "orange"), distance(distance) {}

Point Clyde::get_chase_point() const
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