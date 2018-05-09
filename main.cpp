#include "graphics.hpp"
#include "Widget.hpp"
#include "PushButton.hpp"
#include "RandomButton.hpp"
#include "GameMaster.hpp"
#include "StaticTextWidget.hpp"

#include <vector>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace genv;
using namespace std;

//class Master: public GameMaster
//{
////    RandomButton* p1;
////    RandomButton* p2;
//public:
//    Master();
//    void nyero();
//};
//
//Master:: Master()
//{
////    p1 = new RandomButton(40, 40, 1);
////    p2 = new RandomButton(40, 150, 2);
////    w.push_back(p1);
////    w.push_back(p2);
//    for(unsigned int i = 0; i < palyameret; i++)
//    {
//        for(unsigned int j = 0; j < palyameret; j++)
//        {
//            w.push_back(new RandomButton(honnanx+i*racstav, honnany+j*racstav, i, j));
//        }
//    }
//}
//
//void Master:: nyero()
//{
//
//}

int main()
{
    GameMaster game;
    game.event_loop();
    return 0;
}
