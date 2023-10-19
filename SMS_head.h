#ifndef SMS_HEAD_H_INCLUDED
#define SMS_HEAD_H_INCLUDED

#include<fstream>
#include<conio.h>
#include<string.h>
#include<iostream>
#include<cstdlib>
#include<process.h>
#include<windows.h>
#include<string>
#include<mmsystem.h>

using namespace std;

class Sms:public Contact
{
    char msg[100];

    public:
        Sms();
        void create_sms();
        void display_sms();
};



void display_s_inbox();
void display_s_sent();
void display_s_draft();
void display_s_trash();
void search_sms();
void delete_sms();


#endif // SMS_HEAD_H_INCLUDED
