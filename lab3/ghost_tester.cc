#include "ghost_tester.h"

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

// +++++Komplettering: Använd inte pekare där det inte absolut behövs
// +++++Komplettering: Kodupprepning i kommandona för pos, dir och flytta spöken

// Constructor
Ghost_Tester::Ghost_Tester()
   : pacman {}, ghosts{}, chasing{}
{
    ghosts.emplace_back(make_unique<Blinky>(pacman, Point{5, 10}, Point{WIDTH-1, HEIGHT-1}));
    ghosts.emplace_back(make_unique<Pinky>(pacman, Point{4, 2}, Point{0, HEIGHT-1}));
    ghosts.emplace_back(make_unique<Clyde>(pacman, Point{10, 10}, Point{0, 0}, 6));
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
            for (std::unique_ptr<Ghost>& ghost : ghosts)
            {
                if (ghost->get_color() == command)
                {
                    ghost->set_position(get_point(iss));
                }
            }
        }
        else if (command == "pos") 
        {
            pacman.set_position(get_point(iss));
        }
        else if (command == "dir") 
        {
            pacman.set_direction(get_point(iss));
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
            for (std::unique_ptr<Ghost>& ghost : ghosts)
            {
                // Swap between angry or not
                if (Blinky* blinky = dynamic_cast<Blinky*>(ghost.get()))
                {
                    blinky->set_angry(!blinky->is_angry());
                }
            }
        }
    }
}

Point Ghost_Tester::get_point(istringstream &iss)
{
    Point new_pos {};
    iss >> new_pos.x >> new_pos.y;
    return new_pos;
}

string Ghost_Tester::to_draw(Point const& curr_pos)
{
    string to_draw{"  "};

    // Pacman position
    if (pacman.get_position() == curr_pos)
    {
        to_draw[1] = '@';
    }

    // Ghost Positions (Uppercase)
    for(const std::unique_ptr<Ghost>& ghost : ghosts)
    {
        if(ghost->get_position() == curr_pos)
        {
            // Ghosts cant overlap pacman
            to_draw[0] = toupper(ghost->get_color()[0]);
        }
    }

    // Ghost Target (Lowercase)
    for(const std::unique_ptr<Ghost>& ghost : ghosts)
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