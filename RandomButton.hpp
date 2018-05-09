#ifndef RANDOMBUTTON_HPP_INCLUDED
#define RANDOMBUTTON_HPP_INCLUDED

#include "Widget.hpp"
#include "PushButton.hpp"
#include "Player.hpp"

class RandomButton : public PushButton
{
protected:
    GameMaster* parent;
    int szin_r, szin_g, szin_b;
public:
    RandomButton(GameMaster* _parent, int _posx, int _posy);
    virtual void rajzol(genv::event ev) const;
    virtual void valtozik(genv::event ev);
    virtual void valasztos(event ev);
    bool onmouse(int, int) const;
    virtual int get_playernumber();
    virtual void set_ujjatek();
};

#endif // RANDOMBUTTON_HPP_INCLUDED
