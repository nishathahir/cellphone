#include <iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<cstdlib>
#include<process.h>
#include<windows.h>
#include<string>
#include<mmsystem.h>
#include<ctime>
#include <vector>
#include"Contacts_head.h"
#include"SMS_head.h"
#include"Mail_head.h"
#include"Otherapps_head.h"
#include"Camera_head.h"
#include"Snake_head.h"

using namespace std;

bool power;
int f=0;

int main()
{
    system("color 05");
    frontpage();
    _getch();
    int choice;
    system("cls");
    system("color 64");
    cout<<"\n\n\n\n\t\t\t------------------------------***** WELCOME *****------------------------------";
    try
    {

        cout<<"\n\n\n\t\t\t\t\t\t\t\t1.NOKIA\n\n\t\t\t\t\t\t\t\t2.REDMI";
        cout<<"\n\nEnter your choice: ";
        cin>>choice;
        system("cls");
        if(choice==1)
        {
            system("color 07");
            //menu for nokia
            int ch;
            g1:cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t1.POWER ON\n\n\t\t\t\t\t\t\t\t0.POWER OFF";
            cout<<"\n\nEnter choice: ";
            cin>>ch;
            if(ch==1)
            {
                //mobile on
                int ch1;
               m: system("cls");
                system("color 01");
                cout<<"\n\n\t\t\t\t\t\t\t\t~~~~~~~* HOME SCREEN *~~~~~~~"<<endl;
                cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t MAIN MENU\n\t\t\t\t\t\t\t\t   =====================\n\n\n\t\t\t\t\t\t\t\t  [1] Contacts\n\n\t\t\t\t\t\t\t\t  [2] SMS\n\n\t\t\t\t\t\t\t\t  [3] Camera\n\n\t\t\t\t\t\t\t\t  [4] Clock\n\n\t\t\t\t\t\t\t\t  [5] Calculator\n\n\t\t\t\t\t\t\t\t  [6] Calender\n\n\t\t\t\t\t\t\t\t  [7] Settings\n\n\t\t\t\t\t\t\t\t  [8] Games\n\n\t\t\t\t\t\t\t\t  [0] Power off\n\n\n\t\t\t\t\t\t\t\t  ======================\n\t\t\t\t\t\t\t\t  ";
                cout<<"\n\n\t\tEnter the choice: ";
                cin>>ch1;
                system("cls");
                switch(ch1)
                {
                    case 1:{

                                system("color 01");
                                int f1;
                                for(;;)
                                {
                                    int ch,opt1;
                                    char nam[20];
                                    cout<<"\n\t\t\t\t\t\t\t\t******** CONTACTS ********";
                                    cout<<"\n\t\t\t\t\t\t\t\t   =====================\n\t\t\t\t\t\t\t\t  [1] Add a new Contact\n\t\t\t\t\t\t\t\t  [2] List all Contacts\n\t\t\t\t\t\t\t\t  [3] Search for contact\n\t\t\t\t\t\t\t\t  [4] Edit a Contact\n\t\t\t\t\t\t\t\t  [5] Delete a Contact\n\t\t\t\t\t\t\t\t  [6] Dial Contact\n\t\t\t\t\t\t\t\t  [0] Exit\n\t\t\t\t\t\t\t\t  ======================\n\t\t\t\t\t\t\t\t  ";
                                    cout<<"\nEnter the choice: ";
                                    cin>>ch;
                                    system("cls");
                                    switch(ch)
                                    {
                                        case 0: cout<<"\n\n\t\tThank you...";
                                                break;
                                        case 1: cout<<"\n\n\t\t~~~~~ CREATE NEW CONTACT ~~~~~\n";
                                                save_contact();
                                                break;
                                        case 2: show_all_contacts();
                                                break;
                                        case 3: long long int num;
                                                l:cout<<"~~~~~ SEARCH CONTACT ~~~~~\n";
                                                cout<<"Search through \n [1] Name \n [2] Phone Number";
                                                cout<<"\nEnter choice: ";
                                                cin>>opt1;
                                                if(opt1==1)
                                                {
                                                    cout<<"\n\nName: ";
                                                    //cin>>nam;
                                                    cin.ignore();
                                                    cin.getline(nam,20);
                                                    display_contact_(nam,f1);
                                                }
                                                else if(opt1==2)
                                                {
                                                    cout<<"\n\nPhone: ";
                                                    cin>>num;
                                                    display_contact(num,f1);
                                                }
                                                else
                                                {
                                                    cout<<"\nInvalid choice...Re-Enter";
                                                    system("cls");
                                                    goto l;
                                                }
                                                break;
                                        case 4: edit_contact();
                                                break;
                                        case 5: delete_contact();
                                                break;
                                        case 6: dial_contact();
                                                break;
                                        default:
                                                break;
                                    }
                                    int opt;
                                    if(ch!=0)
                                    {

                                        cout<<"\n\n\n Enter the Choice:\n\n\t[1] Contact Menu\t\t[0] Exit\n";
                                        cin>>opt;
                                       if(opt==1)
                                       {
                                           system("cls");
                                           continue;
                                       }
                                       else
                                       {
                                           break;
                                       }
                                    }
                                    else
                                    {
                                        break;
                                    }

                                }
                                break;
                            }
                    case 2:{    Sms msg1;
                                Sms *msg2=&msg1;
                                system("color 06");
                                int ch;
                                 for(;;)
                                {
                                    system("cls");
                                    cout<<"\n\t\t\t\t\t\t\t\t\t~~~~~~~# SMS #~~~~~~~"<<endl;
                                    cout<<"\n\n\n\t\t\t\t\t\t\t\t   =====================\n\n\t\t\t\t\t\t\t\t  [1] Create a SMS \n\t\t\t\t\t\t\t\t  [2] Inbox\n\t\t\t\t\t\t\t\t  [3] Sent\n\t\t\t\t\t\t\t\t  [4] Drafts\n\t\t\t\t\t\t\t\t  [5] Search\n\t\t\t\t\t\t\t\t  [6] Delete an SMS\n\t\t\t\t\t\t\t\t  [7] Trash\n\t\t\t\t\t\t\t\t  [8] Exit\n\n\t\t\t\t\t\t\t\t======================\n\t\t\t\t\t\t\t\t  ";
                                    cout<<"\nEnter the choice: ";
                                    cin>>ch;
                                    fstream fp1;
                                    switch(ch)
                                    {
                                        case 1: int ch1,ch2;
                                                msg2->create_sms();
                                               l1: cout<<"\n\n1.Message existing contact\n2.Message unknown number\n";
                                               cout<<"\nEnter your choice: ";
                                                cin>>ch1;
                                                f=0;
                                                if(ch1==1)
                                                {
                                                   f=msg2->search_contact();
                                                }
                                                else if(ch1==2)
                                                {
                                                    msg2->input_ph();
                                                    strcpy(msg2->getName(),"unknown");
                                                    f=1;
                                                }
                                                else
                                                {
                                                    cout<<"\nInvalid entry!!\t\tTRY AGAIN"<<endl;
                                                    goto l1;
                                                }

                                                if(f==1)
                                                {
                                                    l2:cout<<"\n\n1.Message this contact\n2.Save as Draft ";
                                                    cout<<"\n\nEnter your choice: ";
                                                    cin>>ch2;
                                                    if(ch2==1)
                                                    {
                                                        fp1.open("s-sent.dat",ios::out|ios::app);
                                                        fp1.write((char*)&msg1,sizeof(Sms));
                                                        fp1.close();
                                                        cout<<"\nSMS has been sent successfully :)";
                                                    }
                                                    else if(ch2==2)
                                                    {
                                                        fp1.open("s-draft.dat",ios::out|ios::app);
                                                        fp1.write((char*)&msg1,sizeof(Sms));
                                                        fp1.close();
                                                        cout<<"\nSMS has been saved as draft";
                                                    }
                                                    else
                                                    {
                                                        cout<<"\nINVALID ENTRY"<<endl;
                                                        goto l2;
                                                    }
                                                }
                                                break;
                                        case 2:display_s_inbox();
                                                break;
                                        case 3:display_s_sent();
                                                break;
                                        case 4:display_s_draft();
                                                break;
                                        case 5:search_sms();
                                                break;
                                        case 6:delete_sms();
                                                break;
                                        case 7:display_s_trash();
                                                break;
                                        case 8: cout<<"\n\n\t\tThank you...";
                                                break;
                                        default:cout<<"\nINVALID ENTRY";
                                                break;
                                    }
                                    int opt;
                                    if(ch!=8)
                                    {

                                        cout<<"\n\n\n Enter the Choice:\n\n\t[1] SMS Menu\t\t[0] Exit\n";
                                        cin>>opt;
                                       if(opt==1)
                                       {
                                           system("cls");
                                           continue;
                                       }
                                       else
                                       {
                                           break;
                                       }
                                    }
                                    else
                                    {
                                        break;
                                    }

                                }
                                break;
                            }
                    case 3:{
                                system("color E2");
                                Cam1 bb;
                                Cam1 *s = &bb;
                                c2:cout<<"\n\t\t\t\t\t\t\t\t\t~~~~~~~! CAMERA !~~~~~~~\n\n"<<endl;
                                s->camera();
                                int ot;
                                    cout<<"\n\n\n Enter the Choice:\n\n\t[1] Camera Menu\t\t[0] Exit\n";
                                    cin>>ot;
                                    switch (ot)
                                    {
                                        case 1:goto c2;

                                        default:break;
                                    }
                                break;
                            }
                    case 4:{
                                 system("color 70");
                                int ch;
                                t:cout<<"\n\t\t\t\t\t\t\t\t**********  TIME  **********";
                                cout<<"\n\n\n\t\t\t\t\t\t\t\t   =====================\n\n\n\t\t\t\t\t\t\t\t        [1] CLOCK\n\n\t\t\t\t\t\t\t\t        [2] STOPWATCH\n\n\t\t\t\t\t\t\t\t        [3]Exit\n\n\t\t\t\t\t\t\t\t        =====================\n\n\t\t\t\t\t\t\t\t";
                                cout<<"Enter the choice: ";
                                cin>>ch;
                                system("cls");
                                time_t result=time(0);
                                switch(ch)
                                {
                                    case 1:
                                        {

                                        cout<<"\n\n ~~ CURRENT TIME ~~ \n";
                                        result=time(0);
                                        cout<<ctime(&result);
                                        _getch();
                                        system("cls");
                                        goto t;
                                        }
                                    case 2:{
                                        int HH=0,MM=0,SS=0;
                                        cout<<"\n ~~ STOPWATCH ~~ ";
                                        cout<<"\n\nHH: MM: SS";
                                        cout<<"\n"<<HH<<" : "<<MM<<" : "<<SS;
                                        cout<<"\n\nPress any key to start ";
                                        _getch();
                                        while(!_kbhit())//Returns a non-zero integer if the keyboard buffer is not empty
                                        {
                                            SS++;
                                            Sleep(1000);//Runs for 1 sec = 1000 ms
                                            if(SS>59)
                                            {
                                                MM++;
                                                SS=0;
                                            }
                                            if(MM>59)
                                            {
                                                HH++;
                                                MM=0;
                                            }
                                            system("cls");
                                            cout<<"\n~~ STOPWATCH ~~ ";
                                            cout<<"\n\nHH: MM: SS";
                                            cout<<"\n"<<HH<<" : "<<MM<<" : "<<SS;
                                            cout<<"\n\nPress any key to stop";
                                        }
                                        _getch();
                                        cout<<"\n\nThe time after pausing is";
                                        cout<<"\n"<<HH<<" : "<<MM<<" : "<<SS;
                                        _getch();
                                        system("cls");
                                        goto t;
                                    }


                                    default:break;
                                }
                                break;
                            }
                    case 5:basiccalci();
                            break;
                    case 6:{
                                int m,y,d;
                                c:system("cls");
                                system("color 70");
                                cout<<"\n\t\t\t\t\t\t\t\t\t~~~~~~~^^ CALENDER ^^~~~~~~~"<<endl;
                                cout<<"Enter month : ";
                                cin>>m;
                                cout<<"Enter Year : ";
                                cin>>y;

                                d=totald(m,y);
                                showc(d,m,y);

                                char c;
                                do
                                {
                                    c=_getch();
                                    switch(c)
                                    {
                                        case 72://Up
                                            if(++ m > 12)
                                                { ++ y; m = 1; }
                                            d=totald(m,y);
                                            showc(d,m,y);
                                            break;

                                        case 80://Down
                                            if(-- m < 1)
                                                {  -- y; m = 12; }
                                            d=totald(m,y);
                                            showc(d,m,y);
                                            break;

                                        case 75://Left
                                            d=totald(m,--y);
                                            showc(d,m,y);
                                            break;

                                        case 77://Right
                                            d=totald(m,++y);
                                            showc(d,m,y);
                                            break;

                                        case 'g':
                                            goto c;
                                        case 'G':
                                            goto c;
                                    }
                                } while(c!='e' && c!='E');
                                break;
                            }
                    case 7:cout<<"\n\t\t\t\t\t\t\t\t\t~~~~~~~$ SETTINGS $~~~~~~~"<<endl;
                            settings();
                            break;
                    case 8:{
                                system("color A5");
                                g3:bool GameIsRunning = true;
                                int GameSpeed = 100;
                                short dire[2]={0,1};
                                vector<snakeBlock> snake;
                                snakeInit(1,1,snake);
                                drawMap(snake);
                                while (GameIsRunning)
                                {
                                    if (GetAsyncKeyState(VK_UP))
                                    {
                                        if (dire[1]==0)
                                        {
                                            dire[1]=-1;
                                            dire[0]=0;
                                        }
                                    }
                                    else if (GetAsyncKeyState(VK_DOWN))
                                    {
                                        if (dire[1]==0)
                                        {
                                            dire[1]=1;
                                            dire[0]=0;
                                        }
                                    }
                                    else if (GetAsyncKeyState(VK_LEFT))
                                    {
                                        if (dire[0]==0)
                                        {
                                            dire[1]=0;
                                            dire[0]=-1;
                                        }
                                    }
                                    else if (GetAsyncKeyState(VK_RIGHT))
                                    {
                                        if (dire[0]==0)
                                        {
                                            dire[1]=0;
                                            dire[0]=1;
                                        }
                                    }
                                    if(snakeMove(snake,dire))
                                    {
                                        int ch;
                                        system("cls");
                                        cout<<"!!!!Game Over!!!!"<<endl;
                                       // cout<<"\n\n\t\tSCORE: "<<score<<"\n";
                                        _getch();
                                        cout<<"\nExit game? (1-yes/0-no) ";
                                        cin>>ch;
                                        if(ch == 1)
                                            GameIsRunning=false;
                                        else
                                        {
                                            //score = 0;
                                            goto g3;
                                        }
                                    }
                                    Sleep(GameSpeed);
                                }
                                break;
                            }
                    case 0:cout<<"\n\n\t\tTurning off\n\n";
                            exit(0);
                }
                goto m;
            }
            else if(ch==0)
            {
                //mobile off
                system("cls");
                cout<<"\n\n\t\t\tTURNING OFF...";
                exit(0);
            }
            else
            {
                system("cls");
                cout<<"\n\n\t\t\tINVALID ENTRY..Try again!";
                system("cls");
                goto g1;
            }


        }
        else if(choice==2)
        {
            //menu for redmi
            system("color 07");
            int ch;
            g2:cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t1.POWER ON\n\n\t\t\t\t\t\t\t\t0.POWER OFF";
            cout<<"\n\n\t\tEnter your choice: ";
            cin>>ch;
            if(ch==1)
            {
                //mobile on
                 system("cls");
                 char passwd[10]="oops";
                 char i_passwd[10];
                 int p=0;
                 p1: cout<<"\n\n\t\t\t\tEnter Password: ";
                 cin>>i_passwd;
                 if(strcmp(passwd,i_passwd)==0)
                 {
                    m1:system("cls");
                    system("color 04");
                    int ch1;
                    cout<<"\n\n\t\t\t\t\t\t\t\t~~~~~~~* HOME SCREEN *~~~~~~~"<<endl;
                    cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t MAIN MENU\n\t\t\t\t\t\t\t\t   =====================\n\n\n\t\t\t\t\t\t\t\t  [1] Contacts\n\n\t\t\t\t\t\t\t\t  [2] SMS\n\n\t\t\t\t\t\t\t\t  [3] Camera\n\n\t\t\t\t\t\t\t\t  [4] Clock\n\n\t\t\t\t\t\t\t\t  [5] Calculator\n\n\t\t\t\t\t\t\t\t  [6] Calender\n\n\t\t\t\t\t\t\t\t  [7]Email\n\n\t\t\t\t\t\t\t\t  [8]Music\n\n\t\t\t\t\t\t\t\t  [9]Notes\n\n\t\t\t\t\t\t\t\t  [10] Settings\n\n\t\t\t\t\t\t\t\t  [11] Games\n\n\t\t\t\t\t\t\t\t  [0] Exit\n\n\n\t\t\t\t\t\t\t\t  ======================\n\t\t\t\t\t\t\t\t  ";
                    cout<<"Enter the choice: ";
                    cin>>ch1;
                    system("cls");
                    switch(ch1)
                    {
                        case 1:{
                                    system("color 01");
                                    int f1;
                                    for(;;)
                                    {
                                        int ch,opt1;
                                        char nam[20];
                                        cout<<"\n\t\t\t\t\t\t\t\t******** CONTACTS ********";
                                        cout<<"\n\t\t\t\t\t\t\t\t   =====================\n\t\t\t\t\t\t\t\t  [1] Add a new Contact\n\t\t\t\t\t\t\t\t  [2] List all Contacts\n\t\t\t\t\t\t\t\t  [3] Search for contact\n\t\t\t\t\t\t\t\t  [4] Edit a Contact\n\t\t\t\t\t\t\t\t  [5] Delete a Contact\n\t\t\t\t\t\t\t\t  [6] Dial Contact\n\t\t\t\t\t\t\t\t  [0] Exit\n\t\t\t\t\t\t\t\t  ======================\n\t\t\t\t\t\t\t\t  ";
                                        cout<<"\nEnter the choice: ";
                                        cin>>ch;
                                        system("cls");
                                        switch(ch)
                                        {
                                            case 0: cout<<"\n\n\t\tThank you...";
                                                    break;
                                            case 1: cout<<"\n\n\t\t~~~~~ CREATE NEW CONTACT ~~~~~\n";
                                                    save_contact();
                                                    break;
                                            case 2: show_all_contacts();
                                                    break;
                                            case 3: long long int num;
                                                    s2:cout<<"~~~~~ SEARCH CONTACT ~~~~~\n";
                                                    cout<<"Search through \n [1] Name \n [2] Phone Number";
                                                    cout<<"\nEnter choice: ";
                                                    cin>>opt1;
                                                    if(opt1==1)
                                                    {
                                                        cout<<"\n\nName: ";
                                                        //cin>>nam;
                                                        cin.ignore();
                                                        cin.getline(nam,20);
                                                        display_contact_(nam,f1);
                                                    }
                                                    else if(opt1==2)
                                                    {
                                                        cout<<"\n\nPhone: ";
                                                        cin>>num;
                                                        display_contact(num,f1);
                                                    }
                                                    else
                                                    {
                                                        cout<<"\nInvalid choice...Re-Enter";
                                                        system("cls");
                                                        goto s2;
                                                    }
                                                    break;
                                            case 4: edit_contact();
                                                    break;
                                            case 5: delete_contact();
                                                    break;
                                            case 6: dial_contact();
                                                    break;
                                            default:
                                                    break;
                                        }

                                        int opt;
                                        if(ch!=0)
                                        {

                                            cout<<"\n\n\n Enter the Choice:\n\n\t[1] Contact Menu\t\t[0] Exit\n";
                                            cout<<"\n\nEnter your choice: ";
                                            cin>>opt;
                                           if(opt==1)
                                           {
                                               system("cls");
                                               continue;
                                           }
                                           else
                                           {
                                               break;
                                           }
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    break;
                                }
                        case 2:{    Sms msg1;
                                    Sms *msg2=&msg1;

                                    system("color 06");
                                    int ch;
                                     for(;;)
                                    {
                                        system("cls");
                                        cout<<"\n\t\t\t\t\t\t\t\t\t~~~~~~~# SMS #~~~~~~~"<<endl;
                                        cout<<"\n\n\n\t\t\t\t\t\t\t\t   =====================\n\n\t\t\t\t\t\t\t\t  [1] Create a SMS \n\t\t\t\t\t\t\t\t  [2] Inbox\n\t\t\t\t\t\t\t\t  [3] Sent\n\t\t\t\t\t\t\t\t  [4] Drafts\n\t\t\t\t\t\t\t\t  [5] Search\n\t\t\t\t\t\t\t\t  [6] Delete an SMS\n\t\t\t\t\t\t\t\t  [7] Trash\n\t\t\t\t\t\t\t\t  [8] Exit\n\n\t\t\t\t\t\t\t\t======================\n\t\t\t\t\t\t\t\t  ";
                                        cout<<"\nEnter the choice: ";
                                        cin>>ch;
                                        fstream fp1;
                                        switch(ch)
                                        {
                                            case 1: int ch1,ch2;
                                                    msg2->create_sms();
                                                   d1: cout<<"\n\n1.Message existing contact\n2.Message unknown number\n";
                                                   cout<<"\n\n\tEnter your choice: ";
                                                    cin>>ch1;
                                                    f=0;
                                                    if(ch1==1)
                                                    {
                                                        f=msg2->search_contact();
                                                    }
                                                    else if(ch1==2)
                                                    {
                                                        msg2->input_ph();
                                                        strcpy(msg2->getName(),"unknown");
                                                        f=1;
                                                    }
                                                    else
                                                    {
                                                        cout<<"\nInvalid entry!!\t\tTRY AGAIN"<<endl;
                                                        goto d1;
                                                    }

                                                    if(f==1)
                                                    {
                                                        d2:cout<<"\n\n1.Message this contact\n2.Save as Draft ";
                                                        cout<<"\n\nEnter your choice: ";
                                                        cin>>ch2;
                                                        if(ch2==1)
                                                        {
                                                            fp1.open("s-sent.dat",ios::out|ios::app);
                                                            fp1.write((char*)&msg1,sizeof(Sms));
                                                            fp1.close();
                                                            cout<<"\nSMS has been sent successfully :)";
                                                        }
                                                        else if(ch2==2)
                                                        {
                                                            fp1.open("s-draft.dat",ios::out|ios::app);
                                                            fp1.write((char*)&msg1,sizeof(Sms));
                                                            fp1.close();
                                                            cout<<"\nSMS has been saved as draft";
                                                        }
                                                        else
                                                        {
                                                            cout<<"\nINVALID ENTRY"<<endl;
                                                            goto d2;
                                                        }
                                                    }
                                                    break;
                                            case 2:display_s_inbox();
                                                    break;
                                            case 3:display_s_sent();
                                                    break;
                                            case 4:display_s_draft();
                                                    break;
                                            case 5:search_sms();
                                                    break;
                                            case 6:delete_sms();
                                                    break;
                                            case 7:display_s_trash();
                                                    break;
                                            case 8: cout<<"\n\n\t\tThank you...";
                                                    break;
                                            default:cout<<"\nINVALID ENTRY";
                                                    break;
                                        }
                                       int opt;
                                        if(ch!=8)
                                        {

                                            cout<<"\n\n\n Enter the Choice:\n\n\t[1] SMS Menu\t\t[0] Exit\n";
                                            cin>>opt;
                                           if(opt==1)
                                           {
                                               system("cls");
                                               continue;
                                           }
                                           else
                                           {
                                               break;
                                           }
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    break;
                                }
                        case 3:{
                                    system("color E2");
                                    Cam2 d;
                                    Cam1 *b = &d;
                                   c1:cout<<"\n\t\t\t\t\t\t\t\t\t~~~~~~~! CAMERA !~~~~~~~\n\n"<<endl;
                                    b->camera();
                                    int ot;
                                        cout<<"\n\n\n Enter the Choice:\n\n\t[1] Camera Menu\t\t[0] Exit\n";
                                        cin>>ot;
                                        switch (ot)
                                        {
                                            case 1:goto c1;
                                            default:break;
                                        }
                                        break;
                                }
                        case 4:{
                                     system("color 70");
                                    int ch;
                                    t1:cout<<"\n\t\t\t\t\t\t\t\t**********  TIME  **********";
                                    cout<<"\n\n\n\t\t\t\t\t\t\t\t   =====================\n\n\n\t\t\t\t\t\t\t\t        [1] CLOCK\n\n\t\t\t\t\t\t\t\t        [2] STOPWATCH\n\n\t\t\t\t\t\t\t\t        [3]Exit\n\n\t\t\t\t\t\t\t\t        =====================\n\n\t\t\t\t\t\t\t\t";
                                    cout<<"Enter the choice: ";
                                    cin>>ch;
                                    system("cls");
                                    time_t result=time(0);
                                    switch(ch)
                                    {
                                        case 1:{
                                            cout<<"\n\n ~~ CURRENT TIME ~~ \n";
                                            result=time(0);
                                            cout<<ctime(&result);
                                            _getch();
                                            system("cls");
                                            goto t1;
                                            }
                                        case 2:{
                                            int HH=0,MM=0,SS=0;
                                            cout<<"\n ~~ STOPWATCH ~~ ";
                                            cout<<"\n\nHH: MM: SS";
                                            cout<<"\n"<<HH<<" : "<<MM<<" : "<<SS;
                                            cout<<"\n\nPress any key to start ";
                                            _getch();
                                            while(!_kbhit())//Returns a non-zero integer if the keyboard buffer is not empty
                                            {
                                                SS++;
                                                Sleep(1000);//Runs for 1 sec = 1000 ms
                                                if(SS>59)
                                                {
                                                    MM++;
                                                    SS=0;
                                                }
                                                if(MM>59)
                                                {
                                                    HH++;
                                                    MM=0;
                                                }
                                                system("cls");
                                                cout<<"\n~~ STOPWATCH ~~ ";
                                                cout<<"\n\nHH: MM: SS";
                                                cout<<"\n"<<HH<<" : "<<MM<<" : "<<SS;
                                                cout<<"\n\nPress any key to stop";
                                            }
                                            _getch();
                                            cout<<"\n\nThe time after pausing is";
                                            cout<<"\n"<<HH<<" : "<<MM<<" : "<<SS;
                                            _getch();
                                            system("cls");
                                            goto t1;
                                        }


                                        default:break;
                                    }
                                    break;
                                }

                        case 5:scificalci();
                                break;

                        case 6:{
                                    int m,y,d;
                                    c3:system("cls");
                                    system("color 70");
                                    cout<<"\n\t\t\t\t\t\t\t\t\t~~~~~~~^^ CALENDER ^^~~~~~~~"<<endl;
                                    cout<<"Enter month : ";
                                    cin>>m;
                                    cout<<"Enter Year : ";
                                    cin>>y;

                                    d=totald(m,y);
                                    showc(d,m,y);

                                    char c;
                                    do
                                    {
                                        c=_getch();
                                        switch(c)
                                        {
                                            case 72://Up
                                                if(++ m > 12)
                                                    { ++ y; m = 1; }
                                                d=totald(m,y);
                                                showc(d,m,y);
                                                break;

                                            case 80://Down
                                                if(-- m < 1)
                                                    {  -- y; m = 12; }
                                                d=totald(m,y);
                                                showc(d,m,y);
                                                break;

                                            case 75://Left
                                                d=totald(m,--y);
                                                showc(d,m,y);
                                                break;

                                            case 77://Right
                                                d=totald(m,++y);
                                                showc(d,m,y);
                                                break;

                                            case 'g':
                                                goto c3;
                                            case 'G':
                                                goto c3;
                                        }
                                    } while(c!='e' && c!='E');
                                    break;
                                }

                        case 7:{
                                    Email ema;
                                    system("color 05");
                                    int ch;
                                    for(;;)
                                    {

                                        cout<<"\n\t\t\t\t\t\t\t//------******** EMAIL ********------//";
                                        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t  =====================\n\n\t\t\t\t\t\t\t\t  [1] Compose Email \n\t\t\t\t\t\t\t\t  [2] Inbox\n\t\t\t\t\t\t\t\t  [3] Sent\n\t\t\t\t\t\t\t\t  [4] Drafts\n\t\t\t\t\t\t\t\t  [5] Search\n\t\t\t\t\t\t\t\t  [6] Delete an Email\n\t\t\t\t\t\t\t\t  [7] All mail\n\t\t\t\t\t\t\t\t  [8] Starred\n\t\t\t\t\t\t\t\t  [9] Spam\n\t\t\t\t\t\t\t\t [10] Trash\n\t\t\t\t\t\t\t\t  [0] Exit\n\n\t\t\t\t\t\t\t\t======================\n\t\t\t\t\t\t\t\t  ";
                                        cout<<"Enter the choice: ";
                                        cin>>ch;
                                        system("cls");
                                        switch(ch)
                                        {
                                            case 1:cout<<"\n\t\t\t\t\t***** Composing an Email *****"<<endl;
                                                   ema.compose_email();
                                                   cout<<"\n\n1.SEND\t\t\t2.SAVE AS DRAFT"<<endl;
                                                   int c;
                                                   e:cout<<"\nEnter your choice: ";
                                                   cin>>c;
                                                   if(c==1)
                                                   {
                                                       ema.savein_sent();
                                                   }
                                                   else if(c==2)
                                                   {
                                                       ema.savein_draft();
                                                   }
                                                   else
                                                   {
                                                       cout<<"\n\nInvalid entry";
                                                       goto e;
                                                   }
                                                   break;

                                            case 2:display_inbox();
                                                    break;
                                            case 3:display_sent();
                                                    break;
                                            case 4:display_draft();
                                                    break;
                                            case 5:search_mail();
                                                    break;
                                            case 6:delete_mail();
                                                    break;
                                            case 7:display_allmail();
                                                    break;
                                            case 8:display_starred();
                                                    break;
                                            case 9:display_spam();
                                                    break;
                                            case 10:display_trash();
                                                    break;
                                            case 0: cout<<"\n\n\t\tThank you...";
                                                    break;
                                        }
                                        int opt;
                                        if(ch!=0)
                                        {

                                            cout<<"\n\n\n Enter the Choice:\n\n\t[1] Email Menu\t\t[0] Exit\n";
                                            cin>>opt;
                                           if(opt==1)
                                           {
                                               system("cls");
                                               continue;
                                           }
                                           else
                                           {
                                               break;
                                           }
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    break;
                                }
                        case 8:{
                                    system("color B5");
                                    int ch;
                                    s1:cout<<"\n\t\t\t\t\t\t\t\t******** MUSIC PLAYER ********";
                                    cout<<"\n\n\n\t\t\t\t\t\t\t\t      SELECT A SONG\n\t\t\t\t\t\t\t\t   =====================\n\t\t\t\t\t\t\t\t  [1] Ok Kanmani\n\t\t\t\t\t\t\t\t  [2] Nee Korinaal\n\t\t\t\t\t\t\t\t  [3] Kadhale\n\t\t\t\t\t\t\t\t  [4] Inkem Inkem\n\t\t\t\t\t\t\t\t  [5] Kaun Tujhe\n\t\t\t\t\t\t\t\t  [0] Exit\n\t\t\t\t\t\t\t\t  ======================\n\t\t\t\t\t\t\t\t  ";
                                    cout<<"Enter the choice: ";
                                    cin>>ch;

                                    switch(ch)
                                    {
                                        case 0:
                                            cout<<"\n\n\t\tThank you...";
                                            break;
                                        case 1:
                                            cout<<"\n\nNOW PLAYING >>>>> ";
                                            PlaySound(TEXT("Ok Kanmani.wav"),NULL,SND_SYNC);
                                            cout<<"\nSong Played\n";
                                            system("cls");
                                            goto s1;
                                        case 2:
                                            cout<<"\n\nNOW PLAYING >>>>> ";
                                            PlaySound(TEXT("Nee Korinaal.wav"),NULL,SND_SYNC);
                                            cout<<"\nSong Played\n";
                                            system("cls");
                                            goto s1;
                                        case 3:
                                            cout<<"\n\nNOW PLAYING >>>>> ";
                                            PlaySound(TEXT("Kadhale.wav"),NULL,SND_SYNC);
                                            cout<<"\nSong Played\n";
                                            system("cls");
                                            goto s1;
                                        case 4:
                                            cout<<"\n\nNOW PLAYING >>>>> ";
                                            PlaySound(TEXT("Inkem Inkem.wav"),NULL,SND_SYNC);
                                            cout<<"\nSong Played\n";
                                            system("cls");
                                            goto s1;
                                        case 5:
                                            cout<<"\n\nNOW PLAYING >>>>> ";
                                            PlaySound(TEXT("Kaun Tujhe.wav"),NULL,SND_SYNC);
                                            cout<<"\nSong Played\n";
                                            system("cls");
                                            goto s1;
                                    }
                                    break;
                                }
                        case 9:{
                                    int f;
                                    for(;;)
                                    {
                                        int ch;
                                        char nam[30];
                                        cout<<"\n\t\t\t\t\t\t\t\t********** NOTES **********";
                                        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   =====================\n\t\t\t\t\t\t\t\t  [1] Add new Notes\n\t\t\t\t\t\t\t\t  [2] List all Notes\n\t\t\t\t\t\t\t\t  [3] Search for Notes\n\t\t\t\t\t\t\t\t  [4] Edit Notes\n\t\t\t\t\t\t\t\t  [5] Delete Notes\n\t\t\t\t\t\t\t\t  [0] Exit\n\t\t\t\t\t\t\t\t  ======================\n\t\t\t\t\t\t\t\t  ";
                                        cout<<"Enter the choice: ";
                                        cin>>ch;

                                        switch(ch)
                                        {
                                            case 0: cout<<"\n\n\t\tThank you...";
                                                    break;
                                            case 1: cout<<"~~~~~ CREATE NEW NOTES ~~~~~\n";
                                                    save_notes();
                                                    break;
                                            case 2: show_all_notes();
                                                    break;
                                            case 3:
                                                    cout<<"~~~~~ SEARCH NOTES ~~~~~\n";
                                                    cout<<"\n\nTitle: ";
                                                    cin.ignore();
                                                    cin.getline(nam,30);
                                                    display_notes(nam,f);
                                                    break;
                                            case 4: edit_notes();
                                                    break;
                                            case 5: delete_notes();
                                                    break;
                                            default:
                                                    break;
                                        }

                                        int opt;
                                        if(ch!=0)
                                        {

                                            cout<<"\n\n\n Enter the Choice:\n\n\t[1] Notes Menu\t\t[0] Exit\n";
                                            cin>>opt;
                                           if(opt==1)
                                           {
                                               system("cls");
                                               continue;
                                           }
                                           else
                                           {
                                               break;
                                           }
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    break;
                                }
                        case 10:{
                                    int pin1;
                                    cout<<"\n\n\t\tEnter the Pin: ";
                                    cin>>pin1;
                                    settings(pin1);
                                    break;
                                }
                        case 11:{
                                    system("color A5");
                                    g4:bool GameIsRunning = true;
                                    int GameSpeed = 100;
                                    short dire[2]={0,1};
                                    vector<snakeBlock> snake;
                                    snakeInit(1,1,snake);
                                    drawMap(snake);
                                    while (GameIsRunning)
                                    {
                                        if (GetAsyncKeyState(VK_UP))
                                        {
                                            if (dire[1]==0)
                                            {
                                                dire[1]=-1;
                                                dire[0]=0;
                                            }
                                        }
                                        else if (GetAsyncKeyState(VK_DOWN))
                                        {
                                            if (dire[1]==0)
                                            {
                                                dire[1]=1;
                                                dire[0]=0;
                                            }
                                        }
                                        else if (GetAsyncKeyState(VK_LEFT))
                                        {
                                            if (dire[0]==0)
                                            {
                                                dire[1]=0;
                                                dire[0]=-1;
                                            }
                                        }
                                        else if (GetAsyncKeyState(VK_RIGHT))
                                        {
                                            if (dire[0]==0)
                                            {
                                                dire[1]=0;
                                                dire[0]=1;
                                            }
                                        }
                                        if(snakeMove(snake,dire))
                                        {
                                            int ch;
                                            system("cls");
                                            cout<<"!!!!Game Over!!!!"<<endl;
                                            //cout<<"\n\n\t\tSCORE: "<<score<<"\n";
                                            _getch();
                                            cout<<"\nExit game? (1-yes/0-no) ";
                                            cin>>ch;
                                            if(ch == 1)
                                                GameIsRunning=false;
                                            else
                                            {
                                                //score = 0;
                                                goto g4;
                                            }
                                        }
                                        Sleep(GameSpeed);
                                    }
                                }
                        case 0:cout<<"\n\n\t\tTurning off\n\n";
                                exit(0);
                    }
                    goto m1;
                 }
                 else
                 {
                     cout<<"\n\n\t\tIncorrect password";
                     p++;
                     if(p<3)
                     {
                         cout<<"\tTry again";
                         goto p1;
                     }
                     else
                     {
                         cout<<"\n\n\t\tThree trys over\tTry again later!\n\n\t\tTURNING OFF...";
                         exit(0);
                     }

                 }

            }
            else if(ch==0)
            {
                //mobile off
                system("cls");
                cout<<"\n\n\t\t\tTURNING OFF...";
                exit(0);
            }
            else
            {
                cout<<"\nINVALID ENTRY..Try again!";
                system("cls");
                goto g2;
            }

        }
        else
        {
            throw"\nINVALID ENTRY...Try again!\n";

        }
    }
    catch(const char* mesg)
    {
        cerr<<mesg;
    }
    return 0;
}
