#ifndef MAIL_HEAD_H_INCLUDED
#define MAIL_HEAD_H_INCLUDED

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

class Email
{
    char to[30],from[30],sub[40],content[500];

    public:
        Email();
        void compose_email();
        void display_mail();
        void savein_sent();
        void savein_draft();
        char* getto();
};


void display_inbox();
void display_sent();
void display_draft();
void display_allmail();
void display_starred();
void display_spam();
void display_trash();
void load1();
void search_mail();
void delete_mail();



#endif // MAIL_HEAD_H_INCLUDED
