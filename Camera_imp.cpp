 #include<iostream>
 #include"Camera_head.h"

 using namespace std;

    Cam1::Cam1()
    {
        backcamera = false;
        video = false;
    }
    void Cam1::set_back_on()
    {
        backcamera = true;
        video = false;
    }
    void Cam1::set_video_on()
    {
        video = true;
        backcamera = false;
    }
    void Cam1::set_both_off()
    {
        backcamera = false;
        video = false;
    }
    bool Cam1::ret_back()
    {
        return backcamera;
    }
    bool Cam1::ret_video()
    {
        return video;
    }
    void Cam1::display()
    {
        cout<<"\n\nCAMERA MODES: \n\n";
        cout<<"BACK CAMERA: "<<backcamera<<"\n\n";
        cout<<"VIDEO: "<<video<<"\n";
    }



    Cam2::Cam2()
    {
        set_both_off();
        frontcamera = false;
        slowmotion = false;
        shortvideo = false;
        nightmode = false;
        potrait = false;
        panorama = false;
    }
    void Cam2::set_front_on()
    {
        set_both_off();
        frontcamera = true;
        slowmotion = false;
        shortvideo = false;
        nightmode = false;
        potrait = false;
        panorama = false;
    }
    void Cam2::set_slow_on()
    {
        set_both_off();
        frontcamera = false;
        slowmotion = true;
        shortvideo = false;
        nightmode = false;
        potrait = false;
        panorama = false;
    }
    void Cam2::set_short_on()
    {
        set_both_off();
        frontcamera = false;
        slowmotion = false;
        shortvideo = true;
        nightmode = false;
        potrait = false;
        panorama = false;
    }
    void Cam2::set_night_on()
    {
        set_both_off();
        frontcamera = false;
        slowmotion = false;
        shortvideo = false;
        nightmode = true;
        potrait = false;
        panorama = false;
    }
    void Cam2::set_pot_on()
    {
        set_both_off();
        frontcamera = false;
        slowmotion = false;
        shortvideo = false;
        nightmode = false;
        potrait = true;
        panorama = false;
    }
    void Cam2::set_pan_on()
    {
        set_both_off();
        frontcamera = false;
        slowmotion = false;
        shortvideo = false;
        nightmode = false;
        potrait = false;
        panorama = true;
    }
    void Cam2::display()
    {
        Cam1::display();
        cout<<"\nFRONT CAMERA: "<<frontcamera<<"\n";
        cout<<"\nSLOW MOTION: "<<slowmotion<<"\n";
        cout<<"\nSHORT VIDEO: "<<shortvideo<<"\n";
        cout<<"\nNIGHT MODE: "<<nightmode<<"\n";
        cout<<"\nPOTRAIT: "<<potrait<<"\n";
        cout<<"\nPANORAMA: "<<panorama<<"\n\n";
    }
    void Cam2::camera()
    {
        int c;
        display();
        cout<<"Change specifications?(0/1): ";
        cin>>c;
        if(c == 1)
        {
            int op;
            cout<<"\nPress \n";
            cout<<"[1] Back Camera \n[2] Video\n[3] Front Camera\n[4] Slow Motion\n[5] Short Video\n[6] Night Mode\n[7] Potrait\n[8] Panorama\n";
            cout<<"\nEnter your choice: ";
            cin>>op;
            switch(op)
            {
            case 1:
                set_back_on();
                break;
            case 2:
                set_video_on();
                break;
            case 3:
                set_front_on();
                break;
            case 4:
                set_slow_on();
                break;
            case 5:
                set_short_on();
                break;
            case 6:
                set_night_on();
                break;
            case 7:
                set_pot_on();
                break;
            case 8:
                set_pan_on();
                break;
            }
        }
        display();
    }
