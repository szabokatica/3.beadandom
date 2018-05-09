#include "PushButton.hpp"
#include "graphics.hpp"
#include "Widget.hpp"

#include <sstream>
#include <iostream>

using namespace std;
using namespace genv;

PushButton:: PushButton(int _posx, int _posy)
    : Widget(_posx, _posy)
{

}

bool PushButton:: onmouse(int x, int y) const
{
    return x> posx && x < posx+racstav && y > posy&& y < posy+racstav;
}
//void PushButton:: valasztos(event en)
//{
//    if(en.button == btn_left)
//    {
//        if(onmouse(en.pos_x, en.pos_y))
//        {
//            valasztva = true;
//        }
//        else
//        {
//            valasztva = false;
//        }
//    }
//}
