#include "Widget.hpp"
#include <iostream>

using namespace genv;

Widget::Widget(int _posx, int _posy)
{
    posx = _posx;
    posy = _posy;
    valasztva = false;
    telitalalat = false;
}

Widget::Widget()
{
}

//Widget::~Widget() {}

bool Widget:: get_valasztva() const
{
    return valasztva;
}

