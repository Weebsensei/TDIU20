#include "ghost_tester.h"

using namespace std;

// Constructor
Ghost_Tester::Ghost_Tester()
    : pacman {}, ghosts{}, chasing{}
{
    pacman = new Pacman{};
    ghosts.emplace_back(new Blinky{pacman, Point{5, 10}, Point{WIDTH-1, HEIGHT-1}});
    ghosts.emplace_back(new Pinky{pacman, Point{4, 2}, Point{0, HEIGHT-1}});
    ghosts.emplace_back(new Clyde{pacman, Point{10, 10}, Point{0, 0}, 6});
}

// Deconstructor
Ghost_Tester::~Ghost_Tester()
{
    delete pacman;
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
        
        if(command == "red" || command == "pink" || command == "orange") 
        {  
            Point new_pos {};
            iss >> new_pos.x >> new_pos.y;
            for (Ghost* &ghost : ghosts)
            {
                if (ghost->get_color() == command)
                {
                    ghost->set_position(new_pos);
                }
            }
        }
        else if (command == "pos") 
        {
            Point new_pos {};
            iss >> new_pos.x >> new_pos.y;
            pacman->set_position(new_pos);
        }
        else if (command == "dir") 
        {
            Point new_dir {};
            iss >> new_dir.x >> new_dir.y;
            pacman->set_direction(new_dir);
        }
        else if(command == "chase") {
            chasing = true;
        }
        else if(command == "scatter") {
            chasing = false;
        }
        else if (command == "quit")
        {
            break;
        }
        else if(command == "anger") {
            for (Ghost* &ghost : ghosts)
            {
                // Swap between angry or not
                if (Blinky* blinky = dynamic_cast<Blinky*>(ghost)){
                    blinky->set_angry(!blinky->is_angry());
                }
            }
        }
    }
}

string Ghost_Tester::to_draw(Point const& curr_pos)
{
    string to_draw{"  "};

    // Pacman position
    if (pacman->get_position() == curr_pos)
    {
        to_draw[1] = '@';
    }

    // Ghost Positions (Uppercase)
    for(const Ghost* ghost : ghosts)
    {
        if(ghost->get_position() == curr_pos)
        {
            // Ghosts cant overlap pacman
            to_draw[0] = toupper(ghost->get_color()[0]);
        }
    }

    // Ghost Target (Lowercase)
    for(const Ghost* ghost : ghosts)
    {
        if(chasing)
        {
            if(ghost->get_chase_point() == curr_pos)
            {
                // Ghosts cant overlap pacman
                to_draw[0] = tolower(ghost->get_color()[0]);
            }
        } else {
            if(ghost->get_scatter_point() == curr_pos)
            {
                // Ghosts cant overlap pacman
                to_draw[0] = tolower(ghost->get_color()[0]);
            }
        }

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