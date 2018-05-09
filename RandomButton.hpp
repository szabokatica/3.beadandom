#ifndef RANDOMBUTTON_HPP_INCLUDED
#define RANDOMBUTTON_HPP_INCLUDED

#include "Widget.hpp"
#include "PushButton.hpp"
#include "Player.hpp"

class RandomButton : public PushButton
{
protected:
    int oszlop, sor;
    int playernumber, szin_r, szin_g, szin_b;
public:
    RandomButton(int _posx, int _posy, int _sor, int _oszlop);
    virtual void rajzol(genv::event ev) const;
    virtual void valtozik(genv::event ev);
    virtual void valasztos(event ev);
    bool onmouse(int, int) const;
    virtual void set_ujjatek();
};

#endif // RANDOMBUTTON_HPP_INCLUDED
