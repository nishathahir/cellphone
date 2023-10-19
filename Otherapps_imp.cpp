#include<fstream>
#include<conio.h>
#include<string.h>
#include<iostream>
#include<cstdlib>
#include<process.h>
#include<string>
#include<math.h>
#include "Otherapps_head.h"

//NOTES
Notes::Notes()
{
    strcpy(title," ");
    fav = 2;
    strcpy(text," ");
}

fstream fpn;
Notes no;

int Notes::count = 0;

istream& operator >>(istream& in, Notes &N)
{
    cout<<"\nNotes Title: ";
    in.ignore();
    in.getline(N.title,30);

    while(N.fav != 0 && N.fav != 1)
    {
        cout<<"\nKeep in Favourites? (0/1): ";
        in>>N.fav;
        if(N.fav != 0 && N.fav != 1)
            cout<<"\n\tInvalid input!\n";
    }

    cout<<"\nText: ";
    in.ignore();
    in.getline(N.text,60);

    cout<<"\n";
    Notes::count++;

    return in;
}

ostream& operator <<(ostream& out, const Notes &N)
{
    out<<"\n\nNOTES TITLE: "<<N.title;
    if(N.fav == 1)
        out<<" ( *** ) ";
    out<<"\n\nTEXT : "<<N.text;
    return out;
}

char* Notes::ret_title()
{
    return title;
}

char* Notes::ret_text()
{
    return text;
}

void save_notes()
{
    fpn.open("NotesBook.dat", ios::out|ios::app);
    cin>>no;
    fpn.write((char*)&no,sizeof(Notes));
    fpn.close();
    cout<<"\n\nNotes Successfully Created...";
    _getch();
}

void show_all_notes()
{
	system("cls");
    cout<<"\n\t  ======================================\n\t\t  LIST OF NOTES"<<" ( "<<Notes::count<<" ) "<<"\n\t  ======================================\n";
	fpn.open("notesBook.dat",ios::in);
	while(fpn.read((char*)&no,sizeof(Notes)))
	{
		cout<<no;
		cout<<endl<<"====================================================================================\n"<<endl;
	}
	fpn.close();
}

void display_notes(char tit[], int &f)
{
	bool found;
    found=false;
	fpn.open("notesBook.dat",ios::in);
	while(fpn.read((char*)&no, sizeof(Notes)))
	{
		if(strcmp(no.ret_title(),tit)==0)
		{
			cout<<no;
			found=true;
			f = 1;
		}
	}
    fpn.close();
	if(found == false){
        cout<<"\n\nNo record found... :(";
        f = 0;
	}
    _getch();
}

void edit_notes()
{
	char nam[30];
	bool found=false;
	system("cls");
	cout<<"~~~~~ EDIT NOTES ~~~~~\n\n";
    cout<<"Enter the Title of the Notes to edit: ";
    cin.ignore();
    cin.getline(nam,30);

    fpn.open("notesBook.dat",ios::in|ios::out);
    while(fpn.read((char*)&no,sizeof(Notes)) && found==false)
    {
        if(strcmp(no.ret_title(),nam)==0)
        {
            int ch = 0;
            cout<<no;
            while(ch != 1)
            {
                cout<<"\n\nTo Enter The New Content of notes, please enter 1: \n\n";
                cin>>ch;
                if(ch != 1)
                    cout<<"\nInvalid input!\n";
            }
            cin>>no;
            Notes::count--;
            int pos = -1 * sizeof(no);
            fpn.seekp(pos,ios::cur);
            fpn.write((char*)&no, sizeof(no));
            cout<<"\n\n\t Notes Successfully Updated...";
            found=true;
        }
    }
    fpn.close();
    if(found==false)
        cout<<"\n\nNotes Not Found...";
}

void delete_notes()
{
	char nam[30];
	int fo=0;
	system("cls");
	cout<<"~~~~~ DELETE NOTES ~~~~~";
    cout<<"\n\nPlease Enter Title of notes: ";
    cin.ignore();
    cin.getline(nam,30);

    fpn.open("notesBook.dat",ios::in|ios::out);
    fstream fpn2;
    fpn2.open("Temp.dat",ios::out);
    fpn.seekg(0,ios::beg);
    while(fpn.read((char*)&no,sizeof(Notes)))
    {
        if(strcmp(no.ret_title(),nam)!=0)
        {
            fpn2.write((char*)&no,sizeof(Notes));
        }
        else
            fo = 1;
    }
    fpn2.close();
    fpn.close();
    remove("notesBook.dat");
    rename("Temp.dat","notesBook.dat");
    if(fo == 1)
    {
        Notes::count--;
        cout<<"\n\n\tNotes Deleted...";
    }
    else
        cout<<"\n Notes not found ...:(\n\n";
}

//CALENDAR
int  totald(int m,int y)
{
    long td11=0;
    for(int i=1990; i<y; i++)
    {
        for(int m=1; m<=12; m++)
        {
            if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
                td11=td11+31;
            if(m==4||m==6||m==9||m==11)
                td11=td11+30;
            if(m==2)
            {
                if(i%4==0)
                    td11=td11+29;
                else
                    td11=td11+28;
            }
        }
    }

    for(int j=1; j<m; j++)
    {
        if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)
            td11=td11+31;
        if(j==4||j==6||j==9||j==11)
            td11=td11+30;
        if(j==2)
        {
            if(y%4==0)
                td11=td11+29;
            else
                td11=td11+28;
        }
    }

    return ((td11+1)%7);
}

void showc(int s,int m,int y)
{
    int x[7][6];
    int k;
    if(s==0)
        k = 1;
    else if(s==1)
        k = 0;
    else if(s==2)
        k = -1;
    else if(s==3)
        k = -2;
    else if(s==4)
        k = -3;
    else if(s==5)
        k = -4;
    else if(s==6)
        k = -5;

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<7; j++)
        {
            x[j][i]=k++;
        }
    }
    system("cls");
    //system("color 07");
    cout<<"\n\t\t\t";
    if(m==1) cout<<"January\t"<<y;
    else if(m==2) cout<<"February  "<<y;
    else if(m==3) cout<<"March\t"<<y;
    else if(m==4) cout<<"April\t"<<y;
    else if(m==5) cout<<"May\t"<<y;
    else if(m==6) cout<<"June\t"<<y;
    else if(m==7) cout<<"July\t"<<y;
    else if(m==8) cout<<"August\t"<<y;
    else if(m==9) cout<<"September  "<<y;
    else if(m==10) cout<<"October  "<<y;
    else if(m==11) cout<<"November  "<<y;
    else if(m==12) cout<<"December  "<<y;

    //system("color 09");
    cout<<"\n\n";
    for(int i=0; i<7; i++)
    {
        cout<<"\t";
        if(i==0) cout<<"Sun\t";
        else if(i==1) cout<<"Mon\t";
        else if(i==2) cout<<"Tues\t";
        else if(i==3) cout<<"Wed\t";
        else if(i==4) cout<<"Thur\t";
        else if(i==5) cout<<"Fri\t";
        else if(i==6) cout<<"Sat\t";
        //system("color 08");
        if(x[i][0]>0)
            cout<<x[i][0]<<"\t";
        else
            cout<<"\t";
        cout<<x[i][1]<<"\t"<<x[i][2]<<"\t"<<x[i][3]<<"\t";
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        {
            if(x[i][4]<=31) cout<<x[i][4]<<"\t";
            if(x[i][5]<=31) cout<<x[i][5];
        }
        else if(m==4||m==6||m==9||m==11)
        {
            if(x[i][4]<=30)
                cout<<x[i][4]<<"\t";
            if(x[i][5]<=30)
                cout<<x[i][5];
        }
        else if(m==2)
        {
            if(y%4==0)
            {
                if(x[i][4]<=29)
                    cout<<x[i][4]<<"\t";
                if(x[i][5]<=29)
                    cout<<x[i][5];
            }
            else
            {
                if(x[i][4]<=28)
                    cout<<x[i][4]<<"\t";
                if(x[i][5]<=28)
                    cout<<x[i][5];
            }
        }
        cout<<"\n";
    }
    cout<<"\n\n\n";
    //system("color 06");
    cout<<"Up\t- Next month\nDown\t- Previous month\n";
    cout<<"Left\t- Previous year\nRight\t- Next year\nE\t- Exit";
    cout<<"\nG\t- Go to particular month";
}


//CALCULATOR
void basiccalci()
{
    float a,b;
    int c;
    b:system("cls");
    cout<<endl;
    cout<<"\n\n\t******************** BASIC CALCULATOR ******************"<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"\n\t\tOPERATIONS:"<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"\n\n\t\t\t\t1: Division"<<endl;
    cout<<"\n\t\t\t\t2: Multiplication"<<endl;
    cout<<"\n\t\t\t\t3: Subtraction"<<endl;
    cout<<"\n\t\t\t\t4: Addition"<<endl;
    cout<<"\n\t\t\t\t5.Square root"<<endl;
    cout<<"\n\t\t\t\t6.Exit"<<endl;
    cout<<"\n\n\t\tEnter the function that you want to perform : ";
    cin>>c;
    cout<<"\n";
     switch(c)
    {
        case 1:
            cout<<"\n\t~~~~ DIVISION ~~~~\n";
            cout<<"\n\tEnter 1st number : ";
            cin>>a;
            cout<<"\n\tEnter 2nd number : ";
            cin>>b;
            cout<<"\n\n\t"<<a<<" % "<<b<<"= "<<a/b<<endl;
            _getch();
            goto b;
        case 2:
            cout<<"\n\t~~~~ MULTIPLICATION ~~~~\n";
            cout<<"\n\tEnter 1st number : ";
            cin>>a;
            cout<<"\n\tEnter 2nd number : ";
            cin>>b;
            cout<<"\n\n\t"<<a<<" x "<<b<<"= "<<a*b<<endl;
            _getch();
            goto b;
        case 3:
            cout<<"\n\t~~~~ SUBTRACTION ~~~~\n";
            cout<<"\n\tEnter 1st number : ";
            cin>>a;
            cout<<"\n\tEnter 2nd number : ";
            cin>>b;
            cout<<"\n\n\t"<<a<<" - "<<b<<"= "<<a-b<<endl;
            _getch();
            goto b;
        case 4:
            cout<<"\n\t~~~~ ADDITION ~~~~\n";
            cout<<"\n\tEnter 1st number : ";
            cin>>a;
            cout<<"\n\tEnter 2nd number : ";
            cin>>b;
            cout<<"\n\n\t"<<a<<" + "<<b<<"= "<<a+b<<endl;
            _getch();
            goto b;
        case 5:
            cout<<"\n\t~~~~ SQUARE ROOT ~~~~\n";
            cout<<"\n\tEnter the number : ";
            cin>>a;
            cout<<"\n\n\tSquare Root of "<<a<<" = "<<sqrt(a)<<endl;
            _getch();
            goto b;
        case 6:break;
        default:cout<<"\n\t\tINVALID ENTRY";
                break;
    }
}

void scificalci()
{
    system("color B6");
    float a,b,PI;
    int c;
    s:system("cls");
    cout<<endl;
    cout<<"\t******************** SCIENTIFIC CALCULATOR ******************\n";
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"OPERATIONS\t"<<"\tTRIGONOMETRIC FUNCTIONS"<<"\t\tLOGARITHMIC FUNCTIONS\n";
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"1: Division\t\t"<<"7: sin\t\t"<<"\t\t13: ln"<<endl;
    cout<<"2: Multiplication\t"<<"8: cos\t\t"<<"\t\t14: log with base 10"<<endl;
    cout<<"3: Subtraction\t\t"<<"9: tan\t\t"<<"\t\t**: Other keys to exit"<<endl;
    cout<<"4: Addition\t\t"<<"10: Inverse of sin"<<endl;
    cout<<"5: Exponent\t\t"<<"11: Inverse of cos"<<endl;
    cout<<"6: Square root\t\t"<<"12: Inverse of tan"<<endl;
    cout<<"\nEnter the function that you want to perform : ";
    cin>>c;
    cout<<"\n";
    PI=3.14159265;
    switch(c)
    {
        case 1:
            cout<<"\n\t~~~~ DIVISION ~~~~\n";
            cout<<"\n\tEnter 1st number : ";
            cin>>a;
            cout<<"\n\tEnter 2nd number : ";
            cin>>b;
            cout<<a<<" % "<<b<<"= "<<a/b<<endl;
            _getch();
            goto s;
        case 2:
            cout<<"\n\t~~~~ MULTIPLICATION ~~~~\n";
            cout<<"\n\tEnter 1st number : ";
            cin>>a;
            cout<<"\n\tEnter 2nd number : ";
            cin>>b;
            cout<<a<<" x "<<b<<"= "<<a*b<<endl;
            _getch();
            goto s;
        case 3:
            cout<<"\n\t~~~~ SUBTRACTION ~~~~\n";
            cout<<"\n\tEnter 1st number : ";
            cin>>a;
            cout<<"\n\tEnter 2nd number : ";
            cin>>b;
            cout<<a<<" - "<<b<<"= "<<a-b<<endl;
            _getch();
            goto s;
        case 4:
            cout<<"\n\t~~~~ ADDITION ~~~~\n";
            cout<<"\n\tEnter 1st number : ";
            cin>>a;
            cout<<"\n\tEnter 2nd number : ";
            cin>>b;
            cout<<a<<" + "<<b<<"= "<<a+b<<endl;
            _getch();
            goto s;
        case 5:
            cout<<"\n\t~~~~ EXPONENT ~~~~\n";
            cout<<"\n\tEnter the number : ";
            cin>>a;
            cout<<"\n\tEnter the exponent : ";
            cin>>b;
            cout<<a<<" raised to "<<b<<"= "<<pow(a,b)<<endl;
            _getch();
            goto s;
        case 6:
            cout<<"\n\t~~~~ SQUARE ROOT ~~~~\n";
            cout<<"\n\tEnter the number : ";
            cin>>a;
            cout<<"\n\tSquare Root of "<<a<<" = "<<sqrt(a)<<endl;
            _getch();
            goto s;
        case 7:
            cout<<"\n\t~~~~ SIN ~~~~\n";
            cout<<"\n\tEnter the number : ";
            cin>>a;
            cout<<"\n\tsin ( "<<a<<" ) = "<<sin(a)<<endl;
            _getch();
            goto s;
        case 8:
            cout<<"\n\t~~~~ COS ~~~~\n";
            cout<<"\n\tEnter the number : ";
            cin>>a;
            cout<<"\n\tcos ( "<<a<<" ) = "<<cos(a)<<endl;
            _getch();
            goto s;
        case 9:
            cout<<"\n\t~~~~ TAN ~~~~\n";
            cout<<"\n\tEnter the number : ";
            cin>>a;
            cout<<"tan ( "<<a<<" ) = "<<tan(a)<<endl;
            _getch();
            goto s;
        case 10:
            cout<<"\n\t~~~~ INVERSE OF SIN ~~~~\n";
            cout<<"\n\tEnter the number : ";
            cin>>a;
            cout<<"\n\tInverse of sin = "<<asin(a)*180.0/PI<<endl;
            _getch();
            goto s;
        case 11:
            cout<<"\n\t~~~~ INVERSE OF COS ~~~~\n";
            cout<<"\n\tEnter the number : ";
            cin>>a;
            cout<<"\n\tInverse of cos = "<<acos(a)*180.0/PI<<endl;
            _getch();
            goto s;
        case 12:
            cout<<"\n\t~~~~ INVERSE OF TAN ~~~~\n";
            cout<<"\n\tEnter the number : ";
            cin>>a;
            cout<<"\n\tInverse of tan = "<<atan(a)*180.0/PI<<endl;
            _getch();
            goto s;
        case 13:
            cout<<"\n\t~~~~ NATURAL LOGARITHM ~~~~\n";
            cout<<"\n\tEnter the number : ";
            cin>>a;
            cout<<"\n\tln( "<<a<<" = "<<log(a)<<endl;
            _getch();
            goto s;
        case 14:
            cout<<"~~~~ LOGARITHM ~~~~\n";
            cout<<"Enter the number : ";
            cin>>a;
            cout<<"\n\tLog with base 10 = "<<log10(a)<<endl;
            _getch();
            goto s;
        default:
            cout<<"\n\t\n---------The End---------\n";
            break;
    }
}

//SETTINGS
int crctpin=1234;

void settings()
{
    system("color 03");
    struct set1
    {
        char devname[30];
        char devmodel[40];
        char storage[5];
        char bluetooth[4];
        char battery[8];
    };

    set1 nokia;
    strcpy(nokia.devname, "Nokia");
    strcpy(nokia.devmodel, "Nokia 3310");
    strcpy(nokia.storage, "16MB");
    strcpy(nokia.bluetooth, "OFF");
    strcpy(nokia.battery, "1200mAh");

    fstream fpn1;
    fpn1.open("settings1.txt",ios::out);
    fpn1.write((char*)&nokia,sizeof(set1));
    fpn1.close();

    set1 nokia_;
    fpn1.open("settings1.txt", ios::in);
    fpn1.read((char*)&nokia_, sizeof(set1));

    cout<<"DEVICE NAME: "<<nokia_.devname<<"\n\n";
    cout<<"DEVICE MODEL: "<<nokia_.devmodel<<"\n\n";
    cout<<"STORAGE: "<<"16MB"<<"\n\n";
    cout<<"BLUETOOTH: "<<"OFF"<<"\n\n";
    cout<<"BATTERY & PERFORMANCE: "<<"1200mAh"<<"\n\n\n";

    fpn1.close();
    _getch();
}

void settings(int pin)
{
    system("color 03");
    if(crctpin==pin)
    {
        cout<<"\n\t\t\t\t\t\t\t\t\t~~~~~~~$ SETTINGS $~~~~~~~"<<endl;
        struct set2
        {
            char devname[30];
            char devmodel[40];
            char miuiversion[50];
            char androidversion[3];
            char storage[5];
            char wifi[4];
            char bluetooth[4];
            char hotspot[4];
            char usbtether[4];
            char battery[8];
        };

        set2 redmi7;
        strcpy(redmi7.devname, "Redmi");
        strcpy(redmi7.devmodel, "Redmi Note 7 pro");
        strcpy(redmi7.miuiversion, "MIUI Global 11.0.9");
        strcpy(redmi7.androidversion, "9P");
        strcpy(redmi7.storage, "64GB");
        strcpy(redmi7.wifi, "OFF");
        strcpy(redmi7.bluetooth, "OFF");
        strcpy(redmi7.hotspot, "OFF");
        strcpy(redmi7.usbtether, "OFF");
        strcpy(redmi7.battery, "4000mAh");

        fstream fpn2;
        fpn2.open("settings2.txt",ios::out);
        fpn2.write((char*)&redmi7,sizeof(set2));
        fpn2.close();

        set2 redmi7_;
        fpn2.open("settings2.txt", ios::in);
        fpn2.read((char*)&redmi7_, sizeof(set2));

        cout<<"\n\nDEVICE NAME: "<<redmi7_.devname<<"\n";
        cout<<"DEVICE MODEL: "<<redmi7_.devmodel<<"\n";
        cout<<"MIUI VERSION: "<<redmi7_.miuiversion<<"\n";
        cout<<"ANDROID VERSION: "<<redmi7_.androidversion<<"\n";
        cout<<"STORAGE: "<<redmi7_.storage<<"\n";
        cout<<"WIFI: "<<redmi7_.wifi<<"\n";
        cout<<"BLUETOOTH: "<<redmi7_.bluetooth<<"\n";
        cout<<"MOBILE HOTSPOT: "<<redmi7_.hotspot<<"\n";
        cout<<"USB TETHERING: "<<redmi7_.usbtether<<"\n";
        cout<<"BATTERY & PERFORMANCE: "<<redmi7_.battery<<"\n";

        fpn2.close();
        _getch();
    }
    else
    {
        cout<<"\nIncorrect pin";
    }

}

//FRONTPAGE
void frontpage()
{
    int i, j, k, e, n, count, x;
    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }

    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }

    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }

    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }

    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }

    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }

    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }

    cout<<"\n\n\t\t\t\t\t\t\t\t";
    cout<<"   <<<<<<  WELCOME  >>>>>> \n";
    cout<<"\n\t\t\t\t\t\t\t\t 18XW27 OBJECT COMPUTING LAB \n";
    cout<<"\n\t\t\t\t\t\t\t\t   CELLPHONE APPLICATIONS \n";
    cout<<"\n\t\t\t\t\t\t\t\t    - GOMATHI K (19PW10) \n";
    cout<<"\n\t\t\t\t\t\t\t\t    - SHRUTI B  (19PW35) \n\n\n";



    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }


    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }



    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }



    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }



    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }



    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }



    e = 2;
    x = 1;

    // for loop for height of wave
    for (i = 0; i < 2; i++) {

        for (j = 2; j <= 2 + i; j++)
            cout << " ";

        // for loop for wave length
        for (count = 1; count <= 41; count++) {

            // checking for intermediate spaces
            for (n = 2; n >= x; n--)
                cout << " ";
            for (k = 1; k <= e; k++) {
                if (k == 1)
                    cout << "/";
                else if (k == e)
                    cout << "\\";
                else
                    cout << " ";
            }
        }

        // incrementing counters value by two
        x = x + 2;
        e = e + 2;
        cout << endl;
    }

}
