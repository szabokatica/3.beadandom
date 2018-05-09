#ifndef STATICTEXTWIDGET_HPP_INCLUDED
#define STATICTEXTWIDGET_HPP_INCLUDED

#include "Widget.hpp"

using namespace std;
using namespace genv;

class StaticTextWidget: public Widget
{
protected:
    int feher = 255;
    int darab = 0;
    int betusize = 8;
public:
    StaticTextWidget(int _posx, int _posy, int _hosszx, int _hosszy);
    virtual void rajzol(genv::event ev) const;
    virtual void valasztos(genv::event ev);
    virtual void valtozik(genv:: event ev);
    virtual bool onmouse(int,int) const;
    void add_kiirt(char temp);
};
#endif // STATICTEXTWIDGET_HPP_INCLUDED
