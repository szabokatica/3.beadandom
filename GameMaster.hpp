#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include "Widget.hpp"
#include "Drawer.hpp"
#include <vector>

class GameMaster
{
protected:
    std::vector<Widget*> w;
    Drawer* palya = new Drawer();
public:
   // virtual void esemeny(std::string mitortent){}
    GameMaster();
    void event_loop();
};

#endif // GAMEMASTER_HPP_INCLUDED
