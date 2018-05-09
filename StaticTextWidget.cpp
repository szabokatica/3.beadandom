#include "StaticTextWidget.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

StaticTextWidget :: StaticTextWidget(int _posx, int _posy, int _hosszx, int _hosszy)
    : Widget(posx, posy, hosszx, hosszy)
{
    posx = _posx;
    posy = _posy;
    hosszx = _hosszx;
    hosszy = _hosszy;
    if(posx+hosszx >= XX-hatar/2)
    {
        posx = XX-hatar-hosszx;
    }
    if(posy+hosszy >= YY-hatar/2)
    {
        posy = YY - hatar - hosszy;
    }
    kiirt = "";
}
bool StaticTextWidget:: onmouse(int x, int y) const
{
    return x>= posx && x <= posx+hosszx && y >= posy&& y <= posy+hosszy;
}
void StaticTextWidget:: valasztos(event en)
{
    if(en.button == btn_left)
    {
        if(onmouse(en.pos_x, en.pos_y))
            {
                valasztva = true;
                kiirt += "|";
            }
        else
            {
                valasztva = false;
            }
    }
}
void StaticTextWidget:: add_kiirt(char temp)
{
    if(kiirt.size()*8 < hosszx-16)
    {
        if(kiirt.size()>0)
            kiirt.erase (kiirt.end()-1);
        kiirt += (char)temp;
        kiirt += "|";
    }

}
void StaticTextWidget:: rajzol(event en) const
{
    gout << move_to(posx, posy) << color(feher, feher, feher) << box(hosszx, hosszy);
    if(valasztva)
    {
        gout << move_to(posx-keret, posy-keret) << color(keretsz_r, keretsz_g, keretsz_b) << line_to(posx+hosszx+keret, posy-keret)
             << line_to(posx+hosszx+keret, posy+hosszy+keret) << line_to(posx-keret, posy+hosszy+keret) << line_to(posx-keret, posy-keret);
    }
    if(!valasztva)
    {
        gout << move_to(posx-keret, posy-keret) << color(keretsz, keretsz, keretsz) << line_to(posx+hosszx+keret, posy-keret)
             << line_to(posx+hosszx+keret, posy+hosszy+keret) << line_to(posx-keret, posy+hosszy+keret) << line_to(posx-keret, posy-keret);
    }
    gout << color(keretsz, keretsz, keretsz) << move_to(posx+2*keret, posy+hosszy/2+betusize/2) << text(/*trem(kiirt, hosszx-betusize/2)*/kiirt);
}
void StaticTextWidget:: valtozik(event en)
{
    if(valasztva && en.keycode != key_backspace && en.keycode >= 32 && en.keycode <= 256)
    {
        add_kiirt(en.keycode);
    }
    if(valasztva && en.keycode == key_backspace)
    {
        if(kiirt.size()>1)
            kiirt.erase(kiirt.end()-2);
    }
    if(!valasztva && en.button == btn_left)
    {
        kiirt.erase(kiirt.end()-1);
    }
}

