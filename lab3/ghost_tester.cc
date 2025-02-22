#include "ghost_tester.h"

using namespace std;

// Constructor
Ghost_Tester::Ghost_Tester()
    : pacman {}, ghosts{}
{
    pacman = new Pacman{};
    ghosts.emplace_back(new Blinky{pacman, Point{0, 1}, Point{WIDTH-1, HEIGHT-1}});
    ghosts.emplace_back(new Pinky{pacman, Point{0, 2}, Point{0, HEIGHT-1}});
    ghosts.emplace_back(new Clyde{pacman, Point{0, 3}, Point{0, 0}, 4});
}

// Deconstructor
Ghost_Tester::~Ghost_Tester()
{
    for (Ghost* ghost : ghosts) {
        delete ghost;
    }

}

void Ghost_Tester::run()
{
    while(true)
    {
        draw_map();
        cout << "> ";

        string line {};
        getline(cin, line);
        istringstream iss {line};
    
        string command {};
        iss >> command;

        if (command == "pos")
        {
            Point new_pos {};
            iss >> new_pos.x >> new_pos.y;
            pacman->set_position(new_pos);
        }
        else if (command == "dir")
        {
        }
        else if (command == "quit")
        {
            break;
        }
    }
}

string Ghost_Tester::to_draw(Point const& curr_pos)
{
    string to_draw{"  "};

    if (pacman->get_position() == curr_pos)
    {
        to_draw[1] = '@';
    }

    return to_draw;
}

void Ghost_Tester::draw_map()
{
    cout << "+" << setfill('-') << setw(WIDTH * 2) << "-" << "+\n";

    for (int y {HEIGHT - 1}; y >= 0; --y) 
    {
        cout << "|";
        for (int x {}; x < WIDTH; ++x) 
        {
            cout << to_draw( Point{x,y} );
        }
        cout << "|\n";
    }

    cout << "+" << setfill('-') << setw(WIDTH * 2) << "-" << "+" << endl;
}