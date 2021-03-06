#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include "Widget.hpp"
#include "Drawer.hpp"
#include <vector>

class GameMaster
{
protected:
    std::vector<std::vector<Widget *> > w;
    Drawer* palya = new Drawer();
    bool kijon, gyozott;
    int nyertes, db, i, tele;
public:
    GameMaster();
    void event_loop();
    bool get_kijon();
};

#endif // GAMEMASTER_HPP_INCLUDED
