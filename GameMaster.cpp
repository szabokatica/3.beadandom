#include "GameMaster.hpp"
#include "RandomButton.hpp"
#include <iostream>

using namespace std;
using namespace genv;

GameMaster::GameMaster()
{
    for(unsigned int i = 0; i < palyameret; i++)
    {
        for(unsigned int j = 0; j < palyameret; j++)
        {
            w.push_back(new RandomButton(honnanx+i*racstav, honnany+j*racstav, i, j));
        }
    }
}

void GameMaster:: event_loop()
{
    int fokusz = -1;
    event ev;
    cout << "haho" << endl;
    palya->ablak();
    while(gin >> ev && ev.keycode != key_escape)
    {
        palya->palyarajz();
//        for(Widget * wid : w)
//        {
//            wid -> rajzol(ev);
//        }
        if(ev.button == btn_left) {
            for(unsigned int i = 0; i < w.size(); i++)
            {
                w[i]->valasztos(ev);
            }
        }
        for(unsigned int i = 0; i < w.size(); i++)
        {
            if(w[i]->get_valasztva())
                {
                    fokusz = i;
                }
        }
        if(fokusz != -1)
            {
                w[fokusz]->valtozik(ev);
                w[fokusz]->rajzol(ev);
            }
        for(Widget * wid : w)
            {
                wid -> rajzol(ev);
            }
//        if(ev.keycode == key_enter)
//        {
//            for(unsigned int i = 0; i < w.size(); i++)
//            {
//                w[i]->set_ujjatek();
//            }
//        }
        gout << refresh;
    }
}
