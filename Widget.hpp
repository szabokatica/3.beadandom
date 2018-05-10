#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"

const int XX = 600;
const int YY = 650;
const int honnanx = 50;
const int honnany = 100;
const int racstav = 25;
const int negyzetmeret = 20;
const int beljebb = 3;
const int palyameret = 20;
const int keretsz_r = 34;
const int keretsz_g = 177;
const int keretsz_b = 76;
const int keretsz = 0;
const int keret = 1;
class Widget
{
protected:
    int posx, posy, playernumber;
    bool valasztva, telitalalat;
public:
    Widget(int _posx, int _posy);
    Widget();
    virtual ~Widget();
    virtual void rajzol(genv:: event ev) const = 0;
    virtual void valtozik(genv:: event ev) = 0;
    virtual void valasztos(genv:: event ev) = 0;
    virtual bool onmouse(int, int) const = 0;
    bool get_valasztva() const;
    virtual void reset_playernumber() = 0;
    virtual void set_valasztva() = 0;
    virtual int get_playernumber() = 0;
};

#endif // WIDGET_HPP_INCLUDED
