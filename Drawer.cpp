#include "Widget.hpp"
#include "Drawer.hpp"

using namespace genv;
using namespace std;

Drawer::Drawer() : Widget()
{
}

Drawer:: ~Drawer()
{

}
int Drawer::get_playernumber()
{

}
void Drawer:: ablak() const
{
    gout.open(XX,YY);
}

void Drawer:: palyarajz() const
{
    gout << move_to(0, 0) << color(0, 0, 0) << box(XX, YY) << color(255, 255, 255);
    for(unsigned int i = 0; i <= palyameret; i++)
    {
        gout << move_to(honnanx+i*racstav, honnany) << line_to(honnanx+i*racstav, honnany+racstav*palyameret);
    }
    for(unsigned int i = 0; i <= palyameret; i++)
    {
        gout << move_to(honnanx, honnany+i*racstav) << line_to(honnanx+racstav*palyameret, honnany+i*racstav);
    }
}
void Drawer:: rajzol(event ev) const{}
void Drawer:: valtozik(event ev){}
bool Drawer:: get_valasztva() const
{
    return false;
}
void Drawer::valasztos(event ev){}
bool Drawer::onmouse(int x, int y) const
{
    return true;
}
