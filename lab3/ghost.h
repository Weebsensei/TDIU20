#ifndef GHOST_H
#define GHOST_H

#include <string>
#include "given.h"

using namespace std;
// Information om komplettering:
//   Siffrorna hänvisar till rättningsprotokollet som finns på
//   kurshemsidan -> läsning -> Literatur -> "Uppgruppens bedömningsprotokoll"
//   Kompletteringen kan gälla hela filen och alla filer i labben,
//   så får ni komplettering på en sak, kan samma sak förekomma på
//   fler ställen utan att jag skrivit det.
//
//   Komplettering lämnas in via sendlab efter senast en (1) vecka
//
//   Har ni frågor om kompletteringen kan ni maila mig.

// +++++Komplettering: konstruktorn behöver kontrollera att den inskickade positionen är inom spelplanen och informera anropande kod.
// +++++Komplettering: Kodupprepning i de härledda klassernas implementation av get_scatter_point().
// +++++komplettering: Variabler initieras alltid med måsvingar

class Ghost
{
public:
    Ghost(Pacman& pacman, Point const& startPosition, Point const& scatterPosition, string const& color);
    virtual ~Ghost() = default;
        
    Ghost(const Ghost&) = delete;
    Ghost operator=(const Ghost&) = delete;

    Point get_position() const;
    void set_position(Point const& p);

    virtual Point get_chase_point() const = 0;
    virtual Point get_scatter_point() const;
    string get_color() const;

protected:
    const Pacman& pacman;
    Point pos;
    Point scatterPosition;
    string color;
};

class Blinky : public Ghost
{
public:
    Blinky(Pacman& pacman, Point const& startPosition, Point const& scatterPosition);

    Point get_chase_point() const override;
    Point get_scatter_point() const override;

    bool is_angry() const;
    void set_angry(bool anger);

private:
    bool angry {false};
};

class Pinky : public Ghost
{
public:
    Pinky(Pacman& pacman, Point const& startPosition, Point const& scatterPosition);

    Point get_chase_point() const override;
};

class Clyde : public Ghost
{
public:
    Clyde(Pacman& pacman, Point const& startPosition, Point const& scatterPosition, int distance);

    Point get_chase_point() const override;
private:
    int distance;
};

#endif
