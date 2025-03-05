#include "ghost.h"
#include <cmath>

using namespace std;

//Ghost
Ghost::Ghost(Pacman* pacman, Point const& startPosition, 
             Point const& scatterPosition, string const& color)
    : pacman{pacman}, pos(startPosition), scatterPosition(scatterPosition), color(color) {}

string Ghost::get_color() const
{
    return color;
}

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

// Blinky
Blinky::Blinky(Pacman* pacman, Point const& startPosition, 
               Point const& scatterPosition)
    : Ghost(pacman, startPosition, scatterPosition, "red") {}

Point Blinky::get_chase_point() const
{
    return pacman->get_position();
}

Point Blinky::get_scatter_point() const
{
    if (!is_angry()) {
        return scatterPosition;
    } else {
        return pacman->get_position();
    }
}

bool Blinky::is_angry() const {
    return angry;
}

void Blinky::set_angry(bool anger) {
    this->angry = anger;
}
//Pinky
Pinky::Pinky(Pacman* pacman, Point const& startPosition, 
             Point const& scatterPosition)
    : Ghost(pacman, startPosition, scatterPosition, "pink") {}

Point Pinky::get_chase_point() const
{
    Point target = pacman->get_position();
    Point direction = pacman->get_direction();
    int targetX = target.x + direction.x * 2;
    int targetY = target.y + direction.y * 2;
    return Point{targetX, targetY};
}

Point Pinky::get_scatter_point() const
{
    return scatterPosition;
}


//Clyde
Clyde::Clyde(Pacman* pacman, Point const& startPosition, 
             Point const& scatterPosition, int distance)
    : Ghost(pacman, startPosition, scatterPosition, "orange"), distance(distance) {}

Point Clyde::get_chase_point() const
{
    Point target = pacman->get_position();
    int distX = abs(pos.x - target.x);
    int distY = abs(pos.y - target.y);

    if(sqrt(distX * distX + distY * distY) < static_cast<float>(distance)){
        return scatterPosition;
    } else {
        return target;
    }
}

Point Clyde::get_scatter_point() const
{
    return scatterPosition;
}
