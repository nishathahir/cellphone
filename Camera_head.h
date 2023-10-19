#ifndef CAMERA_HEAD_H_INCLUDED
#define CAMERA_HEAD_H_INCLUDED

#include<iostream>
using namespace std;

class Cam1
{
    bool backcamera;
    bool video;

    public:
        Cam1();
        void set_back_on();
        void set_video_on();
        void set_both_off();
        bool ret_back();
        bool ret_video();
        void display();
        virtual void camera()
        {
            int ch;
            display();
            cout<<"\n\n\t\tChange specifications?(0/1): ";
            cin>>ch;
            if(ch == 1)
            {
                int op;
                cout<<"\n\n\t\tPress \n";
                cout<<"\t\t[1] Back Camera \n\n\t\t[2] Video\n";
                cin>>op;
                if(op == 1)
                    set_back_on();
                else
                    set_video_on();
            }
            display();
        }
};

class Cam2: public Cam1
{
    bool frontcamera;
    bool slowmotion;
    bool shortvideo;
    bool nightmode;
    bool potrait;
    bool panorama;

    public:
        Cam2();
        void set_front_on();
        void set_slow_on();
        void set_short_on();
        void set_night_on();
        void set_pot_on();
        void set_pan_on();
        void display();
        void camera();
};

#endif // CAMERA_HEAD_H_INCLUDED
