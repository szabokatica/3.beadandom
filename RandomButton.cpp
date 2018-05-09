#include "RandomButton.hpp"

using namespace std;
using namespace genv;

RandomButton::RandomButton(int _posx, int _posy, int _sor, int _oszlop)
        : PushButton(_posx, _posy), oszlop(_oszlop), sor(_sor)
{
    szin_g = 0;
    if(playernumber == 1)
    {
        szin_r = 0;
        szin_b = 255;
    }
    else
    {
        szin_r = 255;
        szin_b = 0;
    }

}
bool RandomButton:: onmouse(int x, int y) const
{
    return x> posx && x < posx+racstav && y > posy&& y < posy+racstav;
}

void RandomButton:: valasztos(event en)
{
    if(en.button == btn_left && onmouse(en.pos_x, en.pos_y))
    {
        valasztva = true;
    }
}

void RandomButton:: rajzol(event en) const
{
    if(valasztva)
    {
        gout << move_to(posx+beljebb, posy+beljebb) << color(szin_r, szin_g, szin_b)
        << box(negyzetmeret, negyzetmeret);
    }
}
void RandomButton:: valtozik(event en)
{

}
void RandomButton:: set_ujjatek()
{
    valasztva = false;
}
