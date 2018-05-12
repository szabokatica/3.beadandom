#include "Widget.hpp"
#include "Drawer.hpp"
#include <iostream>

using namespace genv;
using namespace std;

const int tavolsag = 10;
const int hossza = 10;
const int x = 40;
const int x2 = 140;
const int y = 35;
const int meret = 8;
const int hanyszor = 2;

Drawer::Drawer() : Widget()
{
}

//Drawer:: ~Drawer()
//{
//
//}
void Drawer:: reset_playernumber(){}
void Drawer::set_valasztva(){}
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
    gout << move_to(50, 50) << color(0,255,0) << text("Player 1    ") << color(255,0,0) << text("Player 2");
}
void Drawer:: mindennek_vege(int gyoz) const
{
    if(gyoz == 1)
        gout << move_to(250, 50) << color(0, 255, 255) << text("Player 1 win!");
    else
        gout << move_to(250, 50) << color(0, 255, 255) << text("Player 2 win!");
    gout << move_to(250, 65) << text("New Game -> Press ENTER");
}
void Drawer:: halott_jatek() const
{
    gout << move_to(250, 50) << color(0, 255, 255) << text("There is no winner!")
         << move_to(250, 65) << text("New Game -> Press ENTER");

}
void Drawer::ki_jon(bool c) const
{
    gout << color(0,255,255);
    if(c == 1)
        {
            gout << move_to(x,y) << line_to(x+hossza*meret, y)
             << line_to(x+hossza*meret, y+hossza*hanyszor) << line_to(x, y+hossza*hanyszor)
             << line_to(x, y);
        }
    else
        {
            gout << move_to(x2, y) << line_to(x2+hossza*meret, y)
             << line_to(x2+hossza*meret, y+hossza*hanyszor)
             << line_to(x2, y+hossza*hanyszor) << line_to(x2, y);
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
