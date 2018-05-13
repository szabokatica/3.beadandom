#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED

#include "Widget.hpp"
#include "graphics.hpp"

using namespace std;
using namespace genv;

class PushButton: public Widget
{
public:
    PushButton(int _posx, int _posy);
    virtual void rajzol(event ev) const = 0;
    virtual void valtozik(event ev) = 0;
    virtual void valasztos(event ev) = 0;
    bool onmouse(int, int) const = 0;
};



#endif // PUSHBUTTON_HPP_INCLUDED
