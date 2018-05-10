#include "GameMaster.hpp"
#include "RandomButton.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace genv;

GameMaster::GameMaster()
{
    kijon = true;
    gyozott = false;
    nyertes = 0;
    db = 0;
    i = 0;
    w = vector<vector<Widget *>>(palyameret,vector<Widget *>(palyameret,nullptr));
    for(unsigned int i = 0; i < palyameret; i++)
    {
        for(unsigned int j = 0; j < palyameret; j++)
        {
            w[i][j] = new RandomButton(this, honnanx+i*racstav, honnany+j*racstav);
        }
    }
}
bool GameMaster::get_kijon()
{
    return kijon;
}
//int get_nyertes()
//{
//    return nyertes;
//}
void GameMaster:: event_loop()
{
    int fokuszx = -1;
    int fokuszy = -1;
    event ev;
    palya->ablak();
    while(gin >> ev && ev.keycode != key_escape)
    {
        palya->palyarajz();
        if(ev.button == btn_left) {
            for(unsigned int i = 0; i < w.size(); i++)
            {
                for(unsigned int j = 0; j < w[i].size(); j++)
                {
                    w[i][j]->valasztos(ev);
                }
            }
        }
        for(unsigned int i = 0; i < w.size(); i++)
        {
            for(unsigned int j = 0; j < w[i].size(); j++)
            {
                if(w[i][j]->get_valasztva())
                {
                    fokuszx = i;
                    fokuszy = j;
                }
            }

        }
        if(fokuszx != -1 && fokuszy != -1)
            {
                if(w[fokuszx][fokuszy]->get_playernumber()==0)
                    {
                        w[fokuszx][fokuszy]->valtozik(ev);
                        w[fokuszx][fokuszy]->rajzol(ev);
                        if(ev.button == btn_left)
                            kijon = !kijon;
                        db = 1;
                        i = 1;

                        while(fokuszx-i >= 0 && w[fokuszx-i][fokuszy]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
                           // if(i < 20)
                                i++;
                        }
                        i = 1;
                        while(fokuszx + i < 20 && w[fokuszx+i][fokuszy]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
                           // if(i < 20)
                                i++;
                        }
                        if(db >= 5)
                        {
                            gyozott = true;
                            nyertes = w[fokuszx][fokuszy]->get_playernumber();
                        }
                        db = 1;
                        i = 1;

                        while(fokuszy-i >= 0 && w[fokuszx][fokuszy-i]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
                            //if(i < 20)
                                i++;
                        }
                        i = 1;
                        while(fokuszy+i < 20 && w[fokuszx][fokuszy+i]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
                           // if(i < 20)
                                i++;
                        }
                        if(db >= 5)
                        {
                            gyozott = true;
                            nyertes = w[fokuszx][fokuszy]->get_playernumber();
                        }
                        db = 1;
                        i = 1;

                        while(fokuszx-i >= 0 && fokuszy+i < 20 && w[fokuszx-i][fokuszy+i]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
                            //if(i < 20)
                                i++;
                        }
                        i = 1;
                        while(fokuszx+i < 20 && fokuszy-i >= 0 && w[fokuszx+i][fokuszy-i]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
                            //if(i < 20)
                                i++;
                        }
                        if(db >= 5)
                        {
                            gyozott = true;
                            nyertes = w[fokuszx][fokuszy]->get_playernumber();
                        }
                        db = 1;
                        i = 1;

                        while(fokuszx-i >= 0 && fokuszy-i >= 0 &&w[fokuszx-i][fokuszy-i]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
                          //  if(i < 20)
                                i++;
                        }
                        i = 1;
                        while(fokuszx+i < 20 && fokuszy+i < 20 && w[fokuszx+i][fokuszy+i]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
                            i++;
                        }
                        if(db >= 5)
                        {
                            gyozott = true;
                            nyertes = w[fokuszx][fokuszy]->get_playernumber();
                            s = nyertes;
                        }

                    }

            }
            for(unsigned int i = 0; i < w.size(); i++)
            {
                for(unsigned int j = 0; j < w[i].size(); j++)
                {
                    w[i][j] -> rajzol(ev);
                }
            }
            if(gyozott)
            {
                palya->mindennek_vege(s);
                break;
            }
        gout << refresh;
    }
    while(gin >> ev && ev.keycode != key_escape)
    {
        if(ev.keycode == key_enter)
            event_loop();
            gout << refresh;
    }
}
