#ifndef GHOST_H
#define GHOST_H

#include <string>
#include "given.h"

using namespace std;

class Ghost
{
public:
    Ghost(Pacman* pacman, Point const& startPosition, Point const& scatterPosition, string const& color);
    virtual ~Ghost() = default;
        
    Ghost(const Ghost&);
    Ghost operator=(const Ghost&);

    Point get_position() const;
    void set_position(Point const& p);

    virtual Point get_chase_point() const = 0;
    virtual Point get_scatter_point() const = 0;
    virtual string get_color() const = 0;

protected:
    const Pacman* pacman;
    Point targetPos;
    Point targetDir;
    Point pos;
    Point scatterPosition;
    string color;
};

class Blinky : public Ghost
{
public:
    Blinky(Pacman* pacman, Point const& startPosition, Point const& scatterPosition);

    Point get_chase_point() const override;
    Point get_scatter_point() const override;
    string get_color() const override;

    bool is_angry() const;
    void set_angry(bool);

private:
    bool angry = false;
};

class Pinky : public Ghost
{
public:
    Pinky(Pacman* pacman, Point const& startPosition, Point const& scatterPosition);

    Point get_chase_point() const override;
    Point get_scatter_point() const override;
    string get_color() const override;
};

class Clyde : public Ghost
{
public:
    Clyde(Pacman* pacman, Point const& startPosition, Point const& scatterPosition, int distance);

    Point get_chase_point() const override;
    Point get_scatter_point() const override;
    string get_color() const override;
private:
    int distance;
};

#endif
