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

Contact::Contact()
{
        strcpy(name,"unknown");
        ph=0000000000;
}

fstream fp;

int Contact::count = 0;

Contact cont;

void Contact::create_contact()
{
        cout<<"Name: ";
        cin.ignore();
        cin.getline(name,20);

        cout<<"Phone: ";
        cin>>ph;

        cout<<"Email address: ";
        cin.ignore();
        cin>>email;

        cout<<"\n";

        count++;
	}
    void Contact::show_contact()
	{
	    cout<<endl<<"Name: "<<name;
		cout<<endl<<"Phone #: "<<ph;
		cout<<endl<<"Email Address : "<<email;
	}

	long long Contact::getPhone()
	{
		return ph;
	}

	char* Contact::getName()
	{
		return name;
	}

	char* Contact::getEmail()
	{
		return email;
	}

	void Contact::input_ph()
	{
	    cout<<"\n\nEnter the Number: ";
	    cin>>ph;
	}
	int Contact::search_contact()
	{
	    int opt1;
	    bool found;
        Contact conti;
        found=false;
        int v=0;
	    cout<<"\n\n\t***** SEARCH CONTACT *****\n";
       s3: cout<<"\n\tSearch through \n\t\t [1] Name \n\t\t [2] Phone Number";
        cout<<"\n\n\tEnter choice: ";
        cin>>opt1;
        if(opt1==1)
        {
            cout<<"\n\nName of the Contact: ";
            cin.ignore();
            cin.getline(name,20);
            fp.open("contactBook.dat",ios::in);
            while(fp.read((char*)&conti,sizeof(Contact)))
            {
                if(strcmp(conti.getName(),name)==0)
                {
                    conti.show_contact();
                    ph=conti.getPhone();
                    found=true;
                    v=1;
                }
            }
            fp.close();
            if(found == false)
            {
                cout<<"\n\nNo record found...";
            }
        }
        else if(opt1==2)
        {
            cout<<"\n\nPhone: ";
            cin>>ph;
            found=false;
            fp.open("contactBook.dat",ios::in);
            while(fp.read((char*)&conti,sizeof(Contact)))
            {
                if(conti.getPhone()==ph)
                {
                    conti.show_contact();
                    strcpy(name,conti.getName());
                    found=true;
                    v=1;
                }
            }
            fp.close();
            if(found == false)
            {
               cout<<"\n\nNo record found...";
            }
        }
        else
        {
            cout<<"\n\nInvalid entry\n";
            goto s3;
        }
    _getch();
    return v;
}

void save_contact()
{
    int g=0;
	fp.open("contactBook.dat",ios::in);
	cont.create_contact();
	long long int num = cont.getPhone();
	Contact conti;
	while(fp.read((char*)&conti,sizeof(Contact)))// To check whether there is any other contact with the same Phone number
	{
		if(conti.getPhone() == num)
		{
			g=1;
			cout<<"\n\nOOPS! There already exists a contact with the given phone number!";
			break;
		}
	}
    fp.close();

    if(g==0)
    {
        fp.open("contactBook.dat",ios::out|ios::app);
        fp.write((char*)&cont,sizeof(Contact));
        fp.close();
        cout<<"\n\nContact Has Been Successfully Created...";
        _getch();
    }
}

void show_all_contacts()
{
	system("cls");
	system("color 06");
    cout<<"\n\t  ================================\n\t\t  LIST OF CONTACTS"<<" ( "<<Contact::count<<" ) "<<"\n\t  ================================\n";
	fp.open("contactBook.dat",ios::in);
	while(fp.read((char*)&cont,sizeof(Contact)))
	{
		cont.show_contact();
		cout<<endl<<"=================================================\n"<<endl;
	}
	fp.close();
}

void edit_contact()
{
	long long int num;
	char nam[20];
	int ch;
	int n;
	bool found=false;
	system("cls");

	cout<<"~~~~~ EDIT CONTACT ~~~~~\n\n";
	cout<<"Enter either of the below: \n";
	cout<<" [1] Phone \n [2] Name \n";
	cout<<"\n\nEnter choice: ";
	cin>>ch;
	if(ch == 1)
    {
        cout<<"\n\nEnter the Phone number of contact to edit: ";
        cin>>num;

        fp.open("contactBook.dat",ios::in|ios::out);
        while(fp.read((char*)&cont,sizeof(Contact)) && found==false)
        {
            if(cont.getPhone()==num)
            {
                cont.show_contact();
                cout<<"\n\nPress 1 to continue: ";
                cin>>n;
                cout<<"\n\nPlease Enter The New Details of Contact: \n";
                cont.create_contact();
                int pos = -1 * sizeof(cont);
                fp.seekp(pos,ios::cur);
                fp.write((char*)&cont,sizeof(cont));
                cout<<"\n\n\t Contact Successfully Updated...";
                found=true;
            }
        }
        fp.close();
        if(found==false)
            cout<<"\n\nContact Not Found...";
    }
    else
    {
        cout<<"Enter the Name of contact to edit: ";
        //cin>>nam;
        cin.ignore();
        cin.getline(nam,20);

        fp.open("contactBook.dat",ios::in|ios::out);
        while(fp.read((char*)&cont,sizeof(Contact)) && found==false)
        {
            if(strcmp(cont.getName(),nam)==0)
            {
                cont.show_contact();
                cout<<"\nPress 1 to continue: ";
                cin>>n;
                cout<<"\n\nPlease Enter The New Details of Contact: \n";
                cont.create_contact();
                Contact::count--;
                int pos = -1 * sizeof(cont);
                fp.seekp(pos,ios::cur);
                fp.write((char*)&cont, sizeof(cont));
                cout<<"\n\n\t Contact Successfully Updated...";
                found=true;
            }
        }
        fp.close();
        if(found==false)
            cout<<"\n\nContact Not Found...";
    }
}

void delete_contact()
{
	long long int num;
	char nam[20];
	int ch, fo;
	system("cls");
	cout<<"~~~~~ DELETE CONTACT ~~~~~";
	cout<<"\n\nEnter either of the below: \n";
	cout<<" [1] Phone \n [2] Name \n";
	cin>>ch;
	if(ch == 1)
    {
        fo = 0;
        cout<<"\n\nPlease Enter The Phone Number #: ";
        cin>>num;

        fp.open("contactBook.dat",ios::in|ios::out);
        fstream fp2;
        fp2.open("Temp.dat",ios::out);
        fp.seekg(0,ios::beg);
        while(fp.read((char*)&cont,sizeof(Contact)))
        {
            if(cont.getPhone()!=num)
            {
                fp2.write((char*)&cont,sizeof(Contact));
            }
            else
                fo = 1;
        }
        fp2.close();
        fp.close();
        remove("contactBook.dat");
        rename("Temp.dat","contactBook.dat");
        if(fo == 1)
        {
            Contact::count--;
            cout<<"\n\tContact Deleted...";
        }
         else
            cout<<"\n\n\tNo such Contact found :( \n";
    }
    else
    {
        fo = 0;
        cout<<"\n\nPlease Enter Name of the Contact: ";
        cin.ignore();
        cin.getline(nam,20);

        fp.open("contactBook.dat",ios::in|ios::out);
        fstream fp2;
        fp2.open("Temp.dat",ios::out);
        fp.seekg(0,ios::beg);
        while(fp.read((char*)&cont,sizeof(Contact)))
        {
            if(strcmp(cont.getName(),nam)!=0)
            {
                fp2.write((char*)&cont,sizeof(Contact));
            }
            else
                fo = 1;
        }
        fp2.close();
        fp.close();
        remove("contactBook.dat");
        rename("Temp.dat","contactBook.dat");
        if(fo == 1)
        {
            Contact::count--;
            cout<<"\n\n\tContact Deleted...";
        }
        else
            cout<<"\n\n\tNo such Contact found :( \n";
    }
}

void display_contact(long long int num, int &f1)
{
	bool found;
    found=false;
	fp.open("contactBook.dat",ios::in);
	while(fp.read((char*)&cont,sizeof(Contact)))
	{
		if(cont.getPhone()==num)
		{
			//system("cls");
			cont.show_contact();
			found=true;
			f1 = 1;
		}
	}
    fp.close();
	if(found == false){
    if(f1 != 2)
        cout<<"\n\nNo record found...";
	f1 = 0;
	}
    _getch();
}

void display_contact_(char nam[20], int &f1)
{
	bool found;
    found=false;
	fp.open("contactBook.dat",ios::in);
	while(fp.read((char*)&cont,sizeof(Contact)))
	{
		if(strcmp(cont.getName(),nam)==0)
		{
			//system("cls");
			cont.show_contact();
			found=true;
			f1 = 1;
		}
	}
    fp.close();
	if(found == false){
	cout<<"\n\nNo record found...";
	f1 = 0;
	}
    _getch();
}


void load1()
{
    cout<<"\n\n\tSearching";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);

    cout<<"\n\n";
}

void load2()
{
    system("color 02");
    cout<<"\n\n\tCalling";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<"\n\n";
    PlaySound(TEXT("Ringing_Phone.wav"),NULL,SND_SYNC);
    PlaySound(TEXT("Ringing_Phone.wav"),NULL,SND_SYNC);
    PlaySound(TEXT("Ringing_Phone.wav"),NULL,SND_SYNC);
     system("color 04");
    cout<<"\n\nCall ended\n";
    _getch();
}

void dial_contact()
{
    int opt;
	cout<<"\n[1] Dial Existing Contact \n[2] Dial Unknown Number\n";
	cout<<"\n\nEnter your choice: ";
	cin>>opt;
	int f1;

	switch(opt)
	{
        case 1:
            cout<<"\n\t~~~~~ DIAL EXISTING CONTACT ~~~~~\n\n";
            long long int num;
            int opt1,op;
            char nam[20];
            l1:cout<<"\t***** SEARCH CONTACT *****\n";
            cout<<"\n\tSearch through \n\t\t [1] Name \n\t\t [2] Phone Number";
            cout<<"\n\n\tEnter choice: ";
            cin>>opt1;
            if(opt1==1)
            {
                cout<<"\n\nName of the Contact: ";
                //cin>>nam;
                cin.ignore();
                cin.getline(nam,20);
                load1();
                display_contact_(nam,f1);
                cout<<"\n";
                if(f1 == 1)
                {
                    cout<<"\n Call this contact? ( 0/1 ): ";
                    cin>>op;
                    if(op==1)
                        load2();
                    else
                    {
                         system("color 04");
                         cout<<"\n\nCall discarded\n";
                    }

                }
            }
            else if(opt1==2)
            {
                cout<<"\n\nPhone number: ";
                cin>>num;
                load1();
                display_contact(num,f1);
                cout<<"\n";
                if(f1 == 1)
                {
                    cout<<"\n Call this contact? ( 0/1 ): ";
                    cin>>op;
                    if(op==1)
                        load2();
                    else
                        {
                         system("color 04");
                         cout<<"\n\nCall discarded\n";
                        }

                }
            }
            else
            {
                cout<<"\nInvalid choice...Re-Enter";
                system("cls");
                goto l1;
            }

            break;

        case 2:
            int fg=2;//random
            cout<<"\n~~~~~ DIAL UNKNOWN NUMBER ~~~~~\n";
            long long int numb;
            int c;
            cout<<"\nEnter the phone number you want to dial: ";
            cin>>numb;
            cout<<"\n\n>>>>>>>\n";
            display_contact(numb,fg);
            cout<<"\n\n Call this number? ( 0/1 )";
            cin>>c;
            if(c==1)
                load2();
            else
               {
                    system("color 04");
                    cout<<"\n\nCall discarded\n";
                }

            break;
    }
}
