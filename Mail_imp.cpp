#include<string.h>
#include<iostream>
#include<cstdlib>
#include<process.h>
#include<windows.h>
#include<string>
#include<mmsystem.h>
#include "Mail_head.h"

Email em;

 Email::Email()
 {
     strcpy(to," ");
     strcpy(from," ");
     strcpy(sub," ");
     strcpy(content," ");
}


fstream fpe;

 void Email::compose_email()
{
            cout<<"\n-------------------------------------------------------------------------------------------------";

            cout<<"\nFrom:";
            cin.ignore();
            cin>>from;

            cout<<"\nTo:";
            cin.ignore();
            cin>>to;

            cout<<"\n-------------------------------------------------------------------------------------------------";

            cout<<"\nSubject:";
            cin.ignore();
            cin.getline(sub,40);

            cout<<"\n-------------------------------------------------------------------------------------------------";

            cout<<"\n\n\t\t";
             cin.ignore();
            cin.getline(content,500);

            cout<<"\n-------------------------------------------------------------------------------------------------\n";

}

        void Email::display_mail()
        {
            cout<<"\n\nFrom:"<<from<<endl;
            cout<<"To:"<<to;
            cout<<"\n-------------------------------------------------------------------------------------------------";
            cout<<"\nSub:"<<sub;
            cout<<"\n-------------------------------------------------------------------------------------------------";
            cout<<"\nBody:"<<content;
            cout<<"\n\n===================================***************=======================================\n"<<endl;
        }

        char* Email::getto()
        {
            return to;
        }

        void Email::savein_sent()
         {
            strcpy(em.to,to);
            strcpy(em.from,from);
            strcpy(em.sub,sub);
            strcpy(em.content,content);
            fpe.open("sent.dat",ios::out|ios::app);
            fpe.write((char*)&em,sizeof(Email));
            fpe.close();
            fpe.open("allmail.dat",ios::out|ios::app);
            fpe.write((char*)&em,sizeof(Email));
            fpe.close();
            cout<<"\n\nEmail Has Been Successfully Sent...";
            _getch();
         }

         void Email::savein_draft()
         {
            strcpy(em.to,to);
            strcpy(em.from,from);
            strcpy(em.sub,sub);
            strcpy(em.content,content);
            fpe.open("draft.dat",ios::out|ios::app);
            fpe.write((char*)&em,sizeof(Email));
            fpe.close();
            fpe.open("allmail.dat",ios::out|ios::app);
            fpe.write((char*)&em,sizeof(Email));
            fpe.close();
            cout<<"\n\nEmail Has Been saved as Draft...";
            _getch();
         }

 void display_inbox()
 {
     int f=0;
     system("cls");
    cout<<"\n\t\t\t\t\t\t  =============================***\t INBOX \t***=============================\n";
	fpe.open("inbox.dat",ios::in);
	while(fpe.read((char*)&em,sizeof(Email)))
	{
	     f=1;
		em.display_mail();
	}
	fpe.close();
	if(f==0)
    {
        cout<<"\n\n\t\t\t\t\t\t///EMPTY///\n\n";
    }
 }

void display_sent()
{
    int f=0;
    system("cls");
    cout<<"\n\t  =============================***\t SENT \t  ***=============================\n";
	fpe.open("sent.dat",ios::in);
	while(fpe.read((char*)&em,sizeof(Email)))
	{
	     f=1;
		em.display_mail();
	}
	fpe.close();
	if(f==0)
    {
        cout<<"\n\n\t\t\t\t\t\t///EMPTY///\n\n";
    }
}

void display_draft()
{
    int f=0;
    system("cls");
    cout<<"\n\t  =============================***\t DRAFTS \t  ***=============================\n";
	fpe.open("draft.dat",ios::in);
	while(fpe.read((char*)&em,sizeof(Email)))
	{
	     f=1;
		em.display_mail();
	}
	fpe.close();
	if(f==0)
    {
        cout<<"\n\n\t\t\t\t\t\t///EMPTY///\n\n";
    }
}

void display_allmail()
{
    int f=0;
     system("cls");
    cout<<"\n\t  =============================***\t ALL MAIL \t  ***=============================\n";
	fpe.open("allmail.dat",ios::in);
	while(fpe.read((char*)&em,sizeof(Email)))
	{
	     f=1;
		em.display_mail();
	}
	fpe.close();
	if(f==0)
    {
        cout<<"\n\n\t\t\t\t\t\t///EMPTY///\n\n";
    }
}

void display_starred()
{
    int f=0;
     system("cls");
    cout<<"\n\t  =============================***\t STARRED \t  ***=============================\n";
	fpe.open("starred.dat",ios::in);
	while(fpe.read((char*)&em,sizeof(Email)))
	{
	     f=1;
		em.display_mail();
	}
	fpe.close();
	if(f==0)
    {
        cout<<"\n\n\t\t\t\t\t\t///EMPTY///\n\n";
    }
}

void display_spam()
{
    int f=0;
     system("cls");
    cout<<"\n\t  =============================***\t SPAM \t  ***=============================\n";
	fpe.open("spam.dat",ios::in);
	while(fpe.read((char*)&em,sizeof(Email)))
	{
	    f=1;
		em.display_mail();
	}
	fpe.close();
	if(f==0)
    {
        cout<<"\n\n\t\t\t\t\t\t///EMPTY///\n\n";
    }
}

void display_trash()
{
    int f=0;
     system("cls");
    cout<<"\n\t  =============================***\t TRASH \t  ***=============================\n";
	fpe.open("trash.dat",ios::in);
	while(fpe.read((char*)&em,sizeof(Email)))
	{
	     f=1;
		em.display_mail();
	}
	fpe.close();
	if(f==0)
    {
        cout<<"\n\n\t\t\t\t\t\t///EMPTY///\n\n";
    }
}



void search_mail()
{
    fstream fpe1;
    bool found;
    found=false;
    int op,op1;
    char tomail[30];
    cout<<"\n\t\t\t\t~~~~~~~~~~??? SEARCH ???~~~~~~~~~~~"<<endl;
    cout<<"\n\t\t1.Inbox\n\t\t2.Sent\n\t\t3.Draft\n\t\t4.All mail\n\t\t5.Starred\n\t\t6.Spam\n\t\t7.Trash\n";
    cout<<"\n\nWhere do you want to search? "<<endl;
    cin>>op;
    switch(op)
    {
        case 1:fpe.open("inbox.dat",ios::in);
                break;
        case 2:fpe.open("sent.dat",ios::in);
                break;
         case 3:fpe.open("draft.dat",ios::in);
                break;
         case 4:fpe.open("allmail.dat",ios::in);
                break;
         case 5:fpe.open("starred.dat",ios::in);
                break;
         case 6:fpe.open("spam.dat",ios::in);
                break;
         case 7:fpe.open("trash.dat",ios::in);
                break;
        default:cout<<"\nInvalid Entry";
    }
    cout<<"Enter the receiver mail ID: ";
    cin.ignore();
    cin>>tomail;
    load1();
	while(fpe.read((char*)&em,sizeof(Email)))
	{
		if(strcmp(em.getto(),tomail)==0)
		{
			em.display_mail();
			found=true;
			cout<<"\n\n\t\t\t\t\t1.Star\n\t\t\t\t\t2.Spam\n\t\t\t\t\t3.None";
			cout<<"\n\nDo you want to do any of the above to the mail ?";
			cin>>op1;
			if(op1==1)
            {
                fpe1.open("starred.dat",ios::out|ios::app);
                fpe1.write((char*)&em,sizeof(Email));
                fpe1.close();
            }
            else if(op1==2)
            {
                fpe1.open("spam.dat",ios::out|ios::app);
                fpe1.write((char*)&em,sizeof(Email));
                fpe1.close();
            }
		}
	}
    fpe.close();
	if(found == false)
    {
        cout<<"\n\nNo record found...";
	}
    _getch();
}



void delete_mail()
{
    int f = 0,t=0,op;
    char tomail[30];
    cout<<"\n\t\t\t\t~~~~~~~~~~XXX DELETE XXX~~~~~~~~~~~"<<endl;
    cout<<"\n\t\t1.Inbox\n\t\t2.Sent\n\t\t3.Draft\n\t\t4.All mail\n\t\t5.Starred\n\t\t6.Spam\n\t\t7.Trash\n";
    cout<<"\n\nWhere do you want to delete the mail? "<<endl;
    cin>>op;
    switch(op)
    {
        case 1:fpe.open("inbox.dat",ios::in);
                break;
        case 2:fpe.open("sent.dat",ios::in);
                break;
         case 3:fpe.open("draft.dat",ios::in);
                break;
         case 4:fpe.open("allmail.dat",ios::in);
                break;
         case 5:fpe.open("starred.dat",ios::in);
                break;
         case 6:fpe.open("spam.dat",ios::in);
                break;
         case 7:fpe.open("trash.dat",ios::in);
                t=1;
                break;
        default:cout<<"\nInvalid Entry";
    }
    cout<<"\n\nEnter the receiver mail ID: ";
    cin.ignore();
    cin>>tomail;

    fstream fpe2;
    fstream fpe3;
    fpe2.open("Temp.dat",ios::out);
    fpe3.open("trash.dat",ios::out);
    fpe.seekg(0,ios::beg);
    while(fpe.read((char*)&em,sizeof(Email)))
    {
        if(strcmp(em.getto(),tomail)!=0)
        {
            fpe2.write((char*)&em,sizeof(Email));
        }
        else
        {
             f = 1;
             if(t==0)
             {
                  fpe3.write((char*)&em,sizeof(Email));
             }
        }

    }
    fpe2.close();
    fpe3.close();
    fpe.close();
    switch(op)
    {
        case 1:remove("inbox.dat");
                rename("Temp.dat","inbox.dat");
                break;
        case 2:remove("sent.dat");
                rename("Temp.dat","sent.dat");
                break;
         case 3:remove("draft.dat");
                rename("Temp.dat","draft.dat");
                break;
         case 4:remove("allmail.dat");
                rename("Temp.dat","allmail.dat");
                break;
         case 5:remove("starred.dat");
                rename("Temp.dat","starred.dat");
                break;
         case 6:remove("spam.dat");
                rename("Temp.dat","spam.dat");
                break;
         case 7:remove("trash.dat");
                rename("Temp.dat","trash.dat");
                break;
    }

        if(f == 1)
        {
            cout<<"\n\n\tEmail Deleted...\n";
        }
        else
            cout<<"\n\n\tNo such Email found :( \n";

}
