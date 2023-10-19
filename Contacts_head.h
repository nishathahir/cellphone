#ifndef CONTACTS_HEAD_H_INCLUDED
#define CONTACTS_HEAD_H_INCLUDED

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

class Contact
{
	long long int ph;
    char name[20],email[30];

	public:

    static int count;

    Contact();
    void create_contact();
    void show_contact();
    long long getPhone();
    char* getName();
    char* getEmail();
    void input_ph();
    int search_contact();
};

void save_contact();
void show_all_contacts();
void edit_contact();
void delete_contact();
void display_contact(long long int num, int &f1);
void display_contact_(char nam[20], int &f1);
void load1();
void load2();
void dial_contact();


#endif // CONTACTS_HEAD_H_INCLUDED
