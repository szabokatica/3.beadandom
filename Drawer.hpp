#ifndef DRAWER_HPP_INCLUDED
#define DRAWER_HPP_INCLUDED

#include "Widget.hpp"

class Drawer : public Widget
{
public:
    Drawer();
    ~Drawer();
    void ablak() const;
    void palyarajz() const;
    void dontetlen() const;
    void mindennek_vege(int) const;
    virtual int get_playernumber();
    virtual void rajzol(genv:: event ev) const;
    virtual void valtozik(genv:: event ev);
    virtual void valasztos(genv:: event ev);
    virtual bool onmouse(int, int) const;
    virtual void reset_playernumber();
    virtual void set_valasztva();
    virtual bool get_valasztva() const;
};

#endif // DRAWER_HPP_INCLUDED
