#ifndef OTHERAPPS_HEAD_H_INCLUDED
#define OTHERAPPS_HEAD_H_INCLUDED

#include<fstream>
#include<conio.h>
#include<string.h>
#include<iostream>
#include<cstdlib>
#include<process.h>
#include<string>
#include<math.h>

using namespace std;

class Notes
{
    char title[30];
    int fav;
    char text[60];

	public:

    static int count;

    Notes();

    friend istream& operator >>(istream& in, Notes &N);

    friend ostream& operator <<(ostream& out, const Notes &N);

	char* ret_title();

	char* ret_text();
};

//Notes
void save_notes();
void show_all_notes();
void display_notes(char tit[], int &f);
void edit_notes();
void delete_notes();

//Calendar
int totald(int,int);
void showc(int,int,int);

//calculator
void basiccalci();
void scificalci();

//settings
void settings();
void settings(int pin);

//frontpage
void frontpage();


#endif // OTHERAPPS_HEAD_H_INCLUDED
