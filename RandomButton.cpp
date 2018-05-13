#include "RandomButton.hpp"

RandomButton::RandomButton(GameMaster* _parent, int _posx, int _posy)
        : PushButton(_posx, _posy), parent(_parent)
{
    szin_b = 0;
    playernumber = 0;
}
bool RandomButton:: onmouse(int x, int y) const
{
    return x > posx && x < posx+racstav && y > posy && y < posy+racstav;
}
void RandomButton:: set_valasztva()
{
    valasztva = false;
}
int RandomButton::get_playernumber()
{
    return playernumber;
}
void RandomButton:: valasztos(event en)
{
    if(en.button == btn_left && onmouse(en.pos_x, en.pos_y))
    {
        valasztva = true;
    }
    else
        valasztva = false;
}

void RandomButton:: rajzol(event en) const
{
        gout << move_to(posx+beljebb, posy+beljebb) << color(szin_r, szin_g, szin_b) << box(negyzetmeret, negyzetmeret);
}
void RandomButton:: valtozik(event en)
{
    if(parent->get_kijon())
        playernumber = 1;
    else
        playernumber = 2;
    if(playernumber == 1)
    {
        szin_r = 0;
        szin_g = 255;
    }
    else
    {
        szin_r = 255;
        szin_b = 0;
    }
}
void RandomButton::reset_playernumber()
{
    playernumber = 0;
    szin_r = 0;
    szin_g = 0;
}
void RandomButton:: set_ujjatek()
{
    valasztva = false;
}
