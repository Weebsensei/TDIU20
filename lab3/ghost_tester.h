#ifndef GHOST_TESTER_H
#define GHOST_TESTER_H

#include "ghost.h"
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <memory>

using namespace std;

class Ghost_Tester
{
public:
    Ghost_Tester();
    ~Ghost_Tester() = default;

    Ghost_Tester(const Ghost_Tester&) = delete;
    Ghost_Tester operator=(const Ghost_Tester&) = delete;

    void run();

private:
    string to_draw(Point const &curr_pos);
    void draw_map();

    Point get_point(istringstream &iss);

    Pacman pacman;
    vector<unique_ptr<Ghost>> ghosts;
    bool chasing = true;
};

#endif