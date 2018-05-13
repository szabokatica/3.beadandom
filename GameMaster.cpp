#include "GameMaster.hpp"
#include "RandomButton.hpp"
#include <iostream>

using namespace std;
using namespace genv;

GameMaster::GameMaster()
{
    kijon = true;
    gyozott = false;
    nyertes = 0;
    tele= 0;
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
void GameMaster:: event_loop()
{
    gyozott = false;
    int fokuszx = -1;
    int fokuszy = -1;
    event ev;
    palya->ablak();
    for(unsigned int i = 0; i < w.size(); i++)
    {
        for(unsigned int j = 0; j < w[i].size(); j++)
        {
            w[i][j]->reset_playernumber();
            w[i][j]->rajzol(ev);
        }
    }
    palya->palyarajz();
    while(gin >> ev)
    {
        if(ev.keycode == key_escape)
            return;
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
                        {

                            kijon = !kijon;
                            tele++;
                        }

                        db = 1;
                        i = 1;

                        while(fokuszx-i >= 0 && w[fokuszx-i][fokuszy]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
                            i++;
                        }
                        i = 1;
                        while(fokuszx + i < palyameret && w[fokuszx+i][fokuszy]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
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
                            i++;
                        }
                        i = 1;
                        while(fokuszy+i < palyameret && w[fokuszx][fokuszy+i]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
                            i++;
                        }
                        if(db >= 5)
                        {
                            gyozott = true;
                            nyertes = w[fokuszx][fokuszy]->get_playernumber();
                        }
                        db = 1;
                        i = 1;

                        while(fokuszx-i >= 0 && fokuszy+i < palyameret && w[fokuszx-i][fokuszy+i]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
                            i++;
                        }
                        i = 1;
                        while(fokuszx+i < palyameret && fokuszy-i >= 0 && w[fokuszx+i][fokuszy-i]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
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
                            i++;
                        }
                        i = 1;
                        while(fokuszx+i < palyameret && fokuszy+i < palyameret && w[fokuszx+i][fokuszy+i]->get_playernumber()
                              == w[fokuszx][fokuszy]->get_playernumber())
                        {
                            db++;
                            i++;
                        }
                        if(db >= 5)
                        {
                            gyozott = true;
                            nyertes = w[fokuszx][fokuszy]->get_playernumber();
                        }
                    }
            }
            for(unsigned int i = 0; i < w.size(); i++)
            {
                for(unsigned int j = 0; j < w[i].size(); j++)
                {
                    w[i][j] -> rajzol(ev);
                    palya->ki_jon(kijon);
                }
            }
            if(gyozott)
            {
                palya->mindennek_vege(nyertes);
                w[fokuszx][fokuszy]->set_valasztva();
                tele = 0;
                break;
            }
            if(tele== palyameret*palyameret)
            {
                tele = 0;
                palya->halott_jatek();
                w[fokuszx][fokuszy]->set_valasztva();
                break;
            }
        gout << refresh;
    }
    while(gin >> ev)
    {
        if(ev.keycode == key_enter)
            {

                event_loop();
                break;
            }
        if(ev.keycode == key_escape)
            return;
        gout << refresh;
    }
}
