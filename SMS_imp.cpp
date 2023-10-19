#include<fstream>
#include<conio.h>
#include<string.h>
#include<iostream>
#include<cstdlib>
#include<process.h>
#include<windows.h>
#include<string>
#include<mmsystem.h>
#include "Contacts_head.h"
#include "SMS_head.h"

fstream fps;

Sms msg1;
Sms *msg2=&msg1;

Sms::Sms()
{
   strcpy(msg," ");
}
        void Sms::create_sms()
        {
            cout<<"\n\nType the SMS here: ";
            cin.ignore();
            cin.getline(msg,100);
        }

        void Sms::display_sms()
        {
           /* long long int num;
            num=this->getPhone();
            cout<<"To:"<<num;*/
            cout<<"\nTo:";
            cout<<"\n\tName: "<< this->getName();
            cout<<"\n\tNumber: "<< this->getPhone();
            cout<<"\n-------------------------------------------------------------------------------------------------";
            cout<<"\nMessage:"<<msg;
            cout<<"\n\n===================================***************=======================================\n"<<endl;
        }



void display_s_inbox()
{
    int f=0;
    system("cls");
    cout<<"\n\t\t\t\t\t\t  =============================***\t INBOX \t***=============================\n";
	fps.open("s-inbox.dat",ios::in);
	while(fps.read((char*)&msg1,sizeof(Sms)))
	{
	     f=1;
        msg1.display_sms();
	}
	fps.close();
	if(f==0)
    {
        cout<<"\n\n\t\t\t\t\t\t///EMPTY///\n\n";
    }
 }

void display_s_sent()
{
    int f=0;
    system("cls");
    cout<<"\n\t  =============================***\t SENT \t  ***=============================\n";
	fps.open("s-sent.dat",ios::in);
	while(fps.read((char*)&msg1,sizeof(Sms)))
	{
	     f=1;
		msg1.display_sms();
	}
	fps.close();
	if(f==0)
    {
        cout<<"\n\n\t\t\t\t\t\t///EMPTY///\n\n";
    }
}

void display_s_draft()
{
    int f=0;
    system("cls");
    cout<<"\n\t  =============================***\t DRAFTS \t  ***=============================\n";
	fps.open("s-draft.dat",ios::in);
	while(fps.read((char*)&msg1,sizeof(Sms)))
	{
	     f=1;
		msg1.display_sms();
	}
	fps.close();
	if(f==0)
    {
        cout<<"\n\n\t\t\t\t\t\t///EMPTY///\n\n";
    }
}

void display_s_trash()
{
    int f=0;
     system("cls");
    cout<<"\n\t  =============================***\t TRASH \t  ***=============================\n";
	fps.open("s-trash.dat",ios::in);
	while(fps.read((char*)&msg1,sizeof(Sms)))
	{
	     f=1;
		msg1.display_sms();
	}
	fps.close();
	if(f==0)
    {
        cout<<"\n\n\t\t\t\t\t\t///EMPTY///\n\n";
    }
}

void search_sms()
{
    fstream fps2;
    bool found;
    found=false;
    int op;
    long long int numb;
    cout<<"\n\t\t\t\t~~~~~~~~~~??? SEARCH ???~~~~~~~~~~~"<<endl;
    cout<<"\n\t\t1.Inbox\n\t\t2.Sent\n\t\t3.Draft\n\t\t4.Trash\n";
    cout<<"\n\nWhere do you want to search? "<<endl;
    cin>>op;
    switch(op)
    {
        case 1:fps2.open("s-inbox.dat",ios::in);
                break;
        case 2:fps2.open("s-sent.dat",ios::in);
                break;
         case 3:fps2.open("s-draft.dat",ios::in);
                break;
         case 4:fps2.open("s-trash.dat",ios::in);
                break;
        default:cout<<"\nInvalid Entry";
    }
    cout<<"\nEnter the number: ";
    cin>>numb;
    load1();
	while(fps2.read((char*)&msg1,sizeof(Sms)))
	{
		if(msg2->getPhone()==numb)
		{
			msg1.display_sms();
			found=true;
		}
	}
    fps2.close();
	if(found == false)
    {
        cout<<"\n\nNo record found...";
	}
    _getch();
}

void delete_sms()
{
    fstream fps2;
    fstream fps3;
    int op,f=0,t=0;
    long long int numb;
    cout<<"\n\t\t\t\t\t~~~~~~~~~~XXX DELETE XXX~~~~~~~~~~~"<<endl;
    cout<<"\n\t\t\t1.Inbox\n\t\t\t2.Sent\n\t\t\t3.Draft\n\t\t\t4.Trash\n";
    cout<<"\n\nWhere do you want to delete? "<<endl;
    cin>>op;
    switch(op)
    {
        case 1:fps.open("s-inbox.dat",ios::in);
                break;
        case 2:fps.open("s-sent.dat",ios::in);
                break;
         case 3:fps.open("s-draft.dat",ios::in);
                break;
         case 4:fps.open("s-trash.dat",ios::in);
                t=1;
                break;
        default:cout<<"\nInvalid Entry";
    }
    cout<<"\nEnter the number: ";
    cin>>numb;
    fps2.open("s-Temp.dat",ios::out);
    fps3.open("s-trash.dat",ios::out);
    fps.seekg(0,ios::beg);
    while(fps.read((char*)&msg1,sizeof(Sms)))
    {
        if(msg2->getPhone()!=numb)
        {
            fps2.write((char*)&msg1,sizeof(Sms));
        }
        else
        {
             f=1;
             if(t==0)
             {
                  fps3.write((char*)&msg1,sizeof(Sms));
             }
        }

    }
    fps2.close();
    fps3.close();
    fps.close();
    switch(op)
    {
        case 1:remove("s-inbox.dat");
                rename("s-Temp.dat","s-inbox.dat");
                break;
        case 2:remove("s-sent.dat");
                rename("s-Temp.dat","s-sent.dat");
                break;
         case 3:remove("s-draft.dat");
                rename("s-Temp.dat","s-draft.dat");
                break;
         case 4:remove("s-trash.dat");
                rename("s-Temp.dat","s-trash.dat");
                break;
    }

    if(f == 1)
    {
        cout<<"\n\n\tSms Deleted...\n";
    }
    else
        cout<<"\n\n\tNo such Sms found :( \n";
}
