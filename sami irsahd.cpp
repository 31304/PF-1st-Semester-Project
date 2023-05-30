#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <Windows.h>
#include <ctime>
#include <sstream>
#include <stdio.h>
#include <iomanip>
using namespace std;
void loading()
{
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\tLoading\t";
    char x=219;
    int i=0;
    while (i<35)
    {
        cout<<x;
        if (i<10)
        {
            Sleep(80);
        }
        else if (i<25)
        {
            Sleep(40);
        }
        else
        {
            Sleep(20);
        }
        i++;
    }
    system("cls");
}
int sinupaccount(string file)
{
    a:
    b:
    bool flag;
    string path;
    int counter=1;
    string name,mail;
    fstream myfile;
    string searching;
    cout<<"1-  Follow"<<endl;
    cout<<"2-  Like"<<endl;
    cout<<"3-  Home"<<endl;
    cout<<"4-  Post"<<endl;
    cout<<"5-  View your posts"<<endl;
    cout<<"6-  view your Profile"<<endl;
    cout<<"7-  Comment"<<endl;
    cout<<"8-  Log out"<<endl;
    cout<<"9-  Search any profile"<<endl;
    cout<<"10- setting"<<endl;
    cout<<"11- check Followers"<<endl;
    cout<<"12- check the follower of any person "<<endl;
    int selection;
    string use=file;
    cin>>selection;
    if (selection==12)
    {
        system("cls");
        cin.ignore();
        cout<<"Search the id with name"<<endl;
        getline(cin,searching);
        int len=searching.length();
        int check=0;
        string line;
        myfile.open("sami.txt");
        while (getline(myfile,line))
        {
            check++;
            if (check%2!=0 && line==searching)
            {
                    flag=1;
                    myfile.close();
                    break;
            }
        }
        myfile.close();
        if (flag==0)
        {
            system("cls");
            cout<<"This name id is not exsist"<<endl;

            Sleep(1500);
            system("cls");
            goto a;
        }
        int length;
        flag=0;
        bool flag2=0;
        int counter2=0;
        mail;
        check=0;
        myfile.open("sami.txt",ios::in);
        while (getline(myfile,line))
        {
            flag=0;
            length=line.length();
            if (len==length)
            {
                int i=0;
                while (i<length)
                {
                    if (line[i]==searching[i])
                    {
                        flag=1;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                    i++;
                }
            }
            if (check==1)
            {
                cout<<line<<endl;
                check=0;
            }
            if (flag==1)
            {
                cout<<counter<<") "<<line<<endl;
                name=line;
                counter++;
                flag2=1;
                check=1;
            }
        }
        myfile.close();
        if (flag2==0)
        {
            cout<<"This name person is not existing "<<endl;
            goto a;
        }
        else
        {
            cout<<"choose any one "<<endl;
            int choose;
            cin>>choose;
            system("cls");
            while(choose>=counter || choose<1)
            {
                cout<<"Enter the correct option"<<endl;
                cin>>choose;
                system("cls");
            }
            counter=choose;
            myfile.open("sami.txt",ios::in);
                string line;
                int length=name.length();
                int len;
                flag=0;
                int counter1=0;
                counter2=0;
                while(getline(myfile,line))
                {
                    flag=0;
                    len=line.length();
                    if (len==length)
                    {
                        int i=0;
                        while (i<length)
                        {
                            if (line[i]==searching[i])
                            {
                                flag=1;
                            }
                            else
                            {
                                flag=0;
                                break;
                            }
                            i++;
                        }
                    }
                    if (counter2==1)
                    {
                        mail=line;
                        counter2=0;
                    }
                    if (flag==1)
                    {
                        counter1++;
                        if (counter1==counter)
                        {
                            counter2=1;
                        }
                    }
                }
            myfile.close();
            string result;
            counter=0;
            length;
            string gmail=mail;
            bool flag=0;
            int follower=0;
            int following =0;
            length=mail.length();
                mail.resize(length-4);

            cout<<"This person are following this person : "<<endl;
            myfile.open("follow.txt",ios::in);
            while (getline(myfile,line))
            {
                length=line.length();
                line.resize(length-5);

                counter++;
                if (counter%2==0 && flag==1)
                {
                    cout<<line<<endl;
                    flag=0;
                }
                if (counter%2==1 && line==mail)
                {
                    flag=1;
                }
            }
         counter=0;
         myfile.close();
           cout<<"\nTHese person are following this person : "<<endl;
           myfile.open("follow.txt",ios::in);
            while (getline(myfile,line))
            {
                if (counter%2==0 )
                {
                       flag=1;

                }
                if (line==gmail)
                {
                    length=result.length();
                    result.resize(length-5);
                    cout<<result<<endl;
                    flag=0;
                }
                result=line;
            }

        }
        Sleep(3000);
        system("cls");
        goto a;
        Sleep(100);
    }
    if (selection==11)
    {
        system("cls");

        string result;
        string line;
        counter=0;
        int length;
        bool flag=0;
        int follower=0;
        int following =0;
        cout<<"you are following this person : "<<endl;
        myfile.open("follow.txt",ios::in);
        while (getline(myfile,line))
        {
            counter++;
            if (counter%2==0 && flag==1)
            {
                 int length=line.length();
                line.resize(length-4);
                cout<<line<<endl;
                flag=0;
            }
            if (counter%2==1 && line==file)
            {
                flag=1;
            }
        }
 counter=0;
 myfile.close();
       cout<<"\nTHese person are following you : "<<endl;
       myfile.open("follow.txt",ios::in);
        while (getline(myfile,line))
        {
            counter++;
            use=file;
             int length=line.length();
            line.resize(length-4);
            length=use.length();
            use.resize(length-5);
            if (counter%2==0 )
            {
                   flag=1;

            }
            if (line==use)
            {
                cout<<result<<endl;
                flag=0;
            }
            result=line;
        }
         Sleep(3000);
        system("cls");
        goto a;

    }
    if (selection==9)
    {
        cin.ignore();
        cout<<"Search the id with name"<<endl;
        getline(cin,searching);
        int len=searching.length();
        int check=0;
        string line;
        myfile.open("sami.txt");
        while (getline(myfile,line))
        {
            check++;
            if (check%2!=0 && line==searching)
            {
                    flag=1;
                    myfile.close();
                    break;
            }
        }
        myfile.close();
        if (flag==0)
        {
            cout<<"This name id is not exsist"<<endl;
            goto a;
        }

        int length;
        flag=0;
        bool flag2=0;
        int counter2=0;
        mail;
        check=0;
        myfile.open("sami.txt",ios::in);
        while (getline(myfile,line))
        {
            flag=0;
            length=line.length();
            if (len==length)
            {
                int i=0;
                while (i<length)
                {
                    if (line[i]==searching[i])
                    {
                        flag=1;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                    i++;
                }
            }
            if (check==1)
            {
                cout<<line<<endl;
                check=0;
            }
            if (flag==1)
            {
                cout<<counter<<") "<<line<<endl;
                name=line;
                counter++;
                flag2=1;
                check=1;
            }
        }
        myfile.close();
        if (flag2==0)
        {
            cout<<"This name person is not existing "<<endl;
            goto a;
        }
        else
        {

            cout<<"choose any one "<<endl;
            int choose;
            cin>>choose;

            while(choose>=counter || choose<1)
            {
                system("cls");
                cout<<"Enter the correct option"<<endl;
                cin>>choose;
            }
            counter=choose;
            myfile.open("sami.txt",ios::in);
                string line;
                int length=name.length();
                int len;
                flag=0;
                int counter1=0;
                counter2=0;
                while(getline(myfile,line))
                {
                    flag=0;
                    len=line.length();
                    if (len==length)
                    {
                        int i=0;
                        while (i<length)
                        {
                            if (line[i]==searching[i])
                            {
                                flag=1;
                            }
                            else
                            {
                                flag=0;
                                break;
                            }
                            i++;
                        }
                    }
                    if (counter2==1)
                    {
                        mail=line;
                        counter2=0;
                    }
                    if (flag==1)
                    {
                        counter1++;
                        if (counter1==counter)
                        {
                            counter2=1;
                        }
                    }
                  }
             myfile.close();
             string Gmail=mail;
             length=Gmail.length();
             Gmail.resize(length-4);
             length=Gmail.length();
             Gmail.resize(length+4);
             length=length+4;
             int i=0;
             int j=0;
             string gmail=Gmail;
             gmail.resize(length+1);
             string add=".txt";
             while (i<length)
             {
                if (i>length-5)
                {
                    Gmail[i]=add[j];
                    j++;
                }
                i++;
             }
            add=".html";
            i=0;
            j=0;
            length=length+1;
            while (i<length)
             {
                if (i>length-6)
                {
                    gmail[i]=add[j];
                    j++;
                }
                i++;
             }
            cout<<Gmail<<endl;
            int lenght;
            string name;
            string mail;
            string pass;
            string number;
            myfile.open(Gmail,ios::app);
            getline(myfile,name);
            getline(myfile,mail);
            getline(myfile,pass);
            myfile>>number;
            myfile.close();
            system("cls");
            cout<<"name : \t"<<name<<"mail : \t"<<mail<<endl;
            cout<<"Contact number : \t\t"<<number<<endl<<endl<<endl<<endl;
           cout<<endl<<gmail<<endl;
            myfile.open("follow.txt",ios::in);
            int followers=0;
            int following=0;
            int counter=0;
            while(getline(myfile,pass))
            {
                counter++;
                if (counter%2!=0 && pass==gmail)
                {
                    following++;
                }
                if (counter%2==0 && pass==mail)
                {
                    followers++;
                }

            }
            cout<<"followers : \t"<<followers<<"\t\tfollowing : \t\t"<<following<<endl;
            lenght=mail.length();
            string result="posted by ";
             len=result.length();
            lenght=lenght-4;
            result.resize(lenght+len);
            i=0;
            j=0;
            while (i<lenght+len)
            {
                if (i>=10)
                {
                    result[i]=mail[j];
                    j++;
                }
                i++;
            }
            myfile.close();
            flag=0;
            cin.ignore();
            myfile.open("home.txt",ios::in);
            while (getline(myfile ,line))
            {
                if (flag==1)
                {
                    cout<<endl<<line<<endl;
                    flag=0;
                }
                if (line==result)
                {
                    flag=1;
                }

            }


        }
        Sleep(4000);
        system("cls");
    }

    if (selection==6)
    {
        system("cls");
             int length=use.length();
             use.resize(length-5);
             string Gmail=use;
             length=Gmail.length();
             Gmail.resize(length+4);
             length=length+4;
             int i=0;
             int j=0;
             string add=".txt";
             while (i<length)
             {
                if (i>length-5)
                {
                    Gmail[i]=add[j];
                    j++;
                }
                i++;
             }
            int lenght;
            string name;
            string mail;
            string pass;
            string number;
            myfile.open(Gmail,ios::in);
            getline(myfile,name);
            getline(myfile,mail);
            getline(myfile,pass);
            myfile>>number;
            myfile.close();
            cout<<"name : \t"<<name<<"mail : \t"<<mail<<endl;
            cout<<"Contact number : \t\t"<<number<<endl<<endl<<endl<<endl;

            myfile.open("follow.txt",ios::in);
            int followers=0;
            int following=0;
            int counter=0;
            while(getline(myfile,pass))
            {
                counter++;
                if (counter%2!=0 && pass==file)
                {
                    following++;
                }
                if (counter%2==0 && pass==mail)
                {
                    followers++;
                }

            }
            cout<<"followers : \t"<<followers<<"\t\tfollowing : \t\t"<<following<<endl;



            lenght=file.length();
            string result="posted by ";
            int len=result.length();
            lenght=lenght-5;
            result.resize(lenght+len);
            i=0;
            j=0;
            while (i<lenght+len)
            {
                if (i>=10)
                {
                    result[i]=file[j];
                    j++;
                }
                i++;
            }
            myfile.close();
            string line;
            flag=0;
            cin.ignore();
            myfile.open("home.txt",ios::in);
            while (getline(myfile ,line))
            {
                if (flag==1)
                {
                    cout<<endl<<line<<endl;
                    flag=0;
                }
                if (line==result)
                {
                    flag=1;
                }

            }

            goto a;
    }
    if (selection==4)
    {
        cout<<"which you what to do "<<endl;
        cout<<"1) Tweet "<<endl;
        cout<<"2) upload photo"<<endl;
        cout<<"3) upload video"<<endl;
        int choice;
        cin>>choice;
        while (choice!=1 && choice!=2 && choice!=3)
        {
            cout<<"Please choose the given number "<<endl;
            cin>>choice;
        }
        switch(choice)
        {
            case 1:
            cin.ignore();
            cout<<"Enter the text "<<endl;
            getline(cin,path);
            myfile.open(file,ios::app);
            myfile<<"<br><hr>"<<endl;
            myfile<<path<<"<br>"<<endl;
            myfile.close();
            break;
            {case 2:
            cout<<"Enter the path of the image"<<endl;
            cin>>path;
            myfile.open(file,ios::app);
            myfile<<"<br><hr>"<<endl;
            myfile<<"<img src=\""<<path<<"\" style=\"display: block;margin-left: auto;margin-right: auto;width:200px;height:200px;\"><br>"<<endl;
            myfile.close();
            break;}
            case 3:
            cout<<"Enter the path of the video"<<endl;
            cin>>path;
            myfile.open(file,ios::app);
            myfile<<"<br><hr>"<<endl;
            myfile<<"<video style=\"display: block;margin-left: auto;margin-right: auto;width:200px;height:200px;\" controls>"<<endl;
            myfile<<"<source src=\""<<path<<"\" type=\"video/mp4\"></source></video>"<<endl;
             myfile.close();
            break;
        }
        myfile.open("post.txt",ios::app);
        myfile<<path<<endl;
        myfile.close();
        myfile.open("home.html",ios::app);
        switch(choice)
        {
            case 1:
            myfile<<"<br><hr>"<<endl;
            myfile<<path<<"<br>"<<endl;
            myfile.close();
            break;
            case 2:
            myfile<<"<br><hr>"<<endl;
            myfile<<"<img src=\"  "<<path<<"\" style=\"display: block;margin-left: auto;margin-right: auto;width:200px;height:200px;\"><br>"<<endl;
            myfile.close();
            break;
            case 3:
            myfile<<"<br><hr>"<<endl;
            myfile<<"<video style=\"display: block;margin-left: auto;margin-right: auto;width:200px;height:200px;\" controls>"<<endl;
            myfile<<"<source src=\""<<path<<"\" type=\"video/mp4\"></source></video>"<<endl;
            myfile.close();
            break;
        }
        myfile.open("home.txt",ios::app);
        int lenght=use.length();
        use.resize(lenght-5);
        myfile<<"posted by "<<use<<endl;
        myfile<<path<<endl;
        myfile.close();
        goto a;
    }
    if (selection==5)
    {system("cls");
        int lenght=file.length();
        string use="posted by ";
        int len=use.length();
        lenght=lenght-5;
        use.resize(lenght+len);
        int i=0;
        int j=0;
        while (i<lenght+len)
        {
            if (i>=10)
            {
                use[i]=file[j];
                j++;
            }
            i++;
        }
        string line;
        flag=0;
        myfile.open("home.txt",ios::in);
        while (getline(myfile ,line))
        {
            if (flag==1)
            {
                cout<<endl<<line<<endl;
                flag=0;
            }
            lenght=use.length();
            len=line.length();
            if (line==use)
            {
                flag=1;
            }

        }
        goto a;
    }
    if (selection==3)
    {
        system("cls");
        cout<<"It is the home page "<<endl;
        myfile.open("home.txt",ios::in);
        string line;
        int count=0;
        int cheking=0;
        while (getline(myfile,line))
        {
            cheking++;
            if (cheking%2==0)
            {
                    count++;
                    string str;
                    cout<<endl<<line<<endl;
                    stringstream ss;
                    ss << count;
                    ss >> str;
                    int i=0;
                    int j=0;
                    string Gmail=str;
                    int length=Gmail.length();
                    Gmail.resize(length+4);
                    length=length+4;
                    string add=".txt";
                    while (i<length)
                    {
                        if (i>length-5)
                        {
                            Gmail[i]=add[j];
                            j++;
                        }
                        i++;
                    }
                    fstream yes;
                    string result;
                    int counter=0;
                    yes.open(Gmail,ios::in);
                    while(getline(yes,result))
                    {
                        counter++;
                    }
                      cout<<"Likes = "<<counter;
                      string sr;
                    yes.close();
                    stringstream kk;
                    int change=(count+10000);
                    kk << change;
                    kk >> sr;
                     i=0;
                    j=0;
                    string gmail=sr;
                    length=gmail.length();
                    gmail.resize(length+4);
                    length=length+4;
                    add=".txt";
                    while (i<length)
                    {
                        if (i>length-5)
                        {
                            gmail[i]=add[j];
                            j++;
                        }
                        i++;
                    }
                    counter=0;
                    yes.open(gmail,ios::in);
                    while(getline(yes,result))
                    {
                        counter++;
                    }
                    yes.close();
                    cout<<"\t\t\tComments = "<<counter/2<<endl;
            }
            else
            {
                cout<<line<<endl;
            }
            Sleep(400);
        }
        myfile.close();

        goto a;

    }

    if (selection==1)
    {
        system("cls");
        do{
        cin.ignore();
        cout<<"Search the id with name"<<endl;
        getline(cin,searching);
        int len=searching.length();
        int check=0;
        string line;
        myfile.open("sami.txt");
        while (getline(myfile,line))
        {
            check++;
            if (check%2!=0 && line==searching)
            {
                    flag=1;
                    myfile.close();
                    break;
            }
        }
        myfile.close();
        if (flag==0)
        {
            cout<<"This name id is not exsist"<<endl;
            goto a;
        }
        int length;
        flag=0;
        bool flag2=0;
        int counter2=0;
        mail;
        check=0;
        myfile.open("sami.txt",ios::in);
        while (getline(myfile,line))
        {
            flag=0;
            length=line.length();
            if (len==length)
            {
                int i=0;
                while (i<length)
                {
                    if (line[i]==searching[i])
                    {
                        flag=1;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                    i++;
                }
            }
            if (check==1)
            {
                cout<<line<<endl;
                check=0;
            }
            if (flag==1)
            {
                cout<<counter<<") "<<line<<endl;
                name=line;
                counter++;
                flag2=1;
                check=1;
            }
        }
        myfile.close();
        if (flag2==0)
        {
            cout<<"This name person is not existing "<<endl;
            goto a;
        }
        else
        {
            cout<<"choose any one "<<endl;
            int choose;
            cin>>choose;
            while(choose>=counter || choose<1)
            {
                cout<<"Enter the correct option"<<endl;
                cin>>choose;
            }
            counter=choose;
            cout<<"if you want to follow so please press Y else N"<<endl;
            char choice;
            cin>>choice;
            while (choice!='Y' && choice!='y' && choice!='N' && choice!= 'n')
            {
                cout<<"Please choose the correct option"<<endl;
                cin>>choice;
            }
            if (choice=='Y' || choice=='y')
            {
                myfile.open("sami.txt",ios::in);
                string line;
                int length=name.length();
                int len;
                flag=0;
                int counter1=0;
                counter2=0;
                while(getline(myfile,line))
                {
                    flag=0;
                    len=line.length();
                    if (len==length)
                    {
                        int i=0;
                        while (i<length)
                        {
                            if (line[i]==searching[i])
                            {
                                flag=1;
                            }
                            else
                            {
                                flag=0;
                                break;
                            }
                            i++;
                        }
                    }
                    if (counter2==1)
                    {
                        mail=line;
                        counter2=0;
                    }
                    if (flag==1)
                    {
                        counter1++;
                        if (counter1==counter)
                        {
                            counter2=1;
                        }
                    }
                }
                    myfile.close();
                    myfile.open("follow.txt",ios::in);
                    flag=0;
                    length=mail.length();
                    int length1=file.length();
                    len;
                    counter1=0;
                    while (getline(myfile,line))
                    {
                        len=line.length();
                        if (counter1==1)
                        {
                            int i=0;
                            while (i<length)
                            {
                                if (line[i]==mail[i])
                                {
                                    flag=1;
                                }
                                else
                                {
                                    flag=0;
                                    break;
                                }
                                i++;
                            }
                            counter1=0;
                        }
                        if (flag==1)
                        {
                            myfile.close();
                            cout<<"You have already follow this person"<<endl;
                            goto b;
                            break;
                        }
                        if (length1==len)
                        {
                            int i=0;
                            while (i<length1)
                            {
                                if (file[i]==line[i])
                                {
                                    flag=1;
                                }
                                else
                                {
                                    flag=0;
                                    break;
                                }
                                i++;
                            }
                            if (flag==1)
                            {
                                counter1=1;
                                flag=0;
                            }
                        }
                    }
            }
            else
            {
                goto a;
            }
        }
        }while (flag==1);
        myfile.close();
        myfile.open("follow.txt",ios::app);
        myfile<<file<<endl<<mail<<endl;
        myfile.close();
        cout<<"Now you are following the "<<name<<endl;
        cout<<"Gmail account = "<<mail<<endl;
        goto a;
    }
    if (selection==2)
    {
        system("cls");
        myfile.open("post.txt",ios::in);
        string line;
        counter=1;
        int check=0;
        while (getline(myfile,line))
        {
            check++;
            cout<<counter<<") "<<line<<endl;
            counter++;
        }
        if (check==0)
        {
            cout<<"No post uploaded at that time"<<endl;
            goto a;
        }
        myfile.close();
        int count;
        cout<<"Select the post which you want to like"<<endl;
        cin>>count;
        string str;
        stringstream ss;
        while (count>=counter || count<1)
        {
            system("cls");
            cout<<"PLease select one of them"<<endl;
            cin>>count;
        }
        ss << count;
        ss >> str;
        int likes;
        bool flag=0;
         line;
        int counter1=0;
        int i=0;
        int j=0;
        string Gmail=str;
        int length=Gmail.length();
        Gmail.resize(length+4);
        length=length+4;
        string add=".txt";
        while (i<length)
        {
            if (i>length-5)
            {
                Gmail[i]=add[j];
                j++;
            }
            i++;
        }
        flag=0;
        string lines;
        myfile.open(Gmail,ios ::in);
        while (getline(myfile,lines))
        {
            if(lines==file)
            {
                flag=1;
                myfile.close();
                break;
            }
            else
            {
                flag=0;
            }
        }
        myfile.close();
        if (flag==1)
        {
            system("cls");
            Sleep(1200);
            cout<<"you have Already like this page";
            system("cls");
        }
        else
        {
            system("cls");
            cout<<"you like this post "<<endl;
            Sleep(1200);
            system("cls");
            myfile.open(Gmail,ios::app);
            myfile<<file<<endl;
            myfile.close();
        }
        goto a;
    }

if (selection ==10)
{
    system("cls");
    cout<<"1- Change the theme"<<endl;
    cout<<"2- change your password"<<endl;
    int choice;
    cin>>choice;
    if (choice==1)
    {
        cout<<"1- Dark theme"<<endl;
        cout<<"2- Day theme"<<endl;
        int check;
        cin>>check;
        system ("cls");
        while (check!=1 && check!=2)
        {
            system("cls");
            cout<<"PLease select one of them"<<endl;
            cin>>check;
        }
        fstream data;
        data.open("mode.txt",ios::out);
        if (check==1)
        {
            data<<1;
        }
        if (check==2)
        {
             data<<2;
        }
        data.close();
        system("cls");
        Sleep(1500);
        if (check==1)
        {
            system("Color 0F");
        }
        if (check==2)
        {
            system ("Color F0");
        }
    }
    if (choice==2)
    {
        system("cls");
        string password;
         cout<<"You want to change the password"<<endl;
         char check;
         cin>>check;
         while(check!='y'&& check!='n'&&check!='Y'&& check!='N')
         {
             cout<<"Please select one of them Y or N";
             cin>>check;
         }
         if (check=='y' || check=='Y')
         {
             int length=use.length();
             use.resize(length-5);
             string Gmail=use;
             length=Gmail.length();
             Gmail.resize(length+4);
             length=length+4;
             int i=0;
             int j=0;
             string add=".txt";
             while (i<length)
             {
                if (i>length-5)
                {
                    Gmail[i]=add[j];
                    j++;
                }
                i++;
             }
              int lenght;
                do{
                flag=0;
                cout<<"Enter the password"<<endl;
                cin>>password;
                int i=0;

                lenght=password.length();
                while (i<lenght)
                {
                    if ((password[i]>=32 && password[i]<=47)||(password[i]>=58 && password[i]<=64)||(password[i]>=91 && password[i]<=96)||(password[i]>=123 && password[i]<=126 ))
                    {
                        flag=1;
                        break;
                    }
                    else
                    {
                        flag=0;
                    }
                    i++;
                }
                if (flag==0 || lenght!=8)
                {
                    cout<<"You have only write 8 character with special character"<<endl;
                }

            }while (flag!=1 || lenght!=8);
            string name;
            string mail;
            string pass;
            string number;
            myfile.open(Gmail,ios::in);
            getline(myfile,name);
            getline(myfile,mail);
            getline(myfile,pass);
            myfile>>number;
            myfile.close();
            myfile.open(Gmail,ios::out);
            myfile<<name<<endl;
            myfile<<mail<<endl;
            myfile<<password<<endl;
            myfile<<number<<endl;
            myfile.close();
            }


         }
         goto a;

        }

if (selection ==7)
{
       system("cls");
       cout<<"1- comment any post"<<endl;
       cout<<"2- see the comment of any post"<<endl;
       int check;
       cin>>check;
       while(check!=1 && check!=2)
       {
           cout<<"PLease select the correct option"<<endl;
           cin>>check;
       }
       if (check==1)
       {
            myfile.open("post.txt",ios::in);
            string line;
            counter=1;
            int check=0;
            while (getline(myfile,line))
            {
                check++;
                cout<<counter<<") "<<line<<endl;
                counter++;
            }
            if (check==0)
            {
                cout<<"No post uploaded at that time"<<endl;
                goto a;
            }
            myfile.close();
            int count;
            cout<<"Select the post which you want to comment"<<endl;
            cin>>count;
            string comment;
            cout<<"Enter your comment"<<endl;
            cin.ignore();
            getline(cin,comment);
            string str;
            stringstream ss;
            while (count>=counter || count<1)
            {
                system("cls");
                cout<<"PLease select one of them"<<endl;
                cin>>count;
            }
            count=count+10000;
            ss << count;
            ss >> str;
            bool flag=0;
             line;
            int counter1=0;
            int i=0;
            int j=0;
            string Gmail=str;
            int length=Gmail.length();
            Gmail.resize(length+4);
            length=length+4;
            string add=".txt";
            while (i<length)
            {
                if (i>length-5)
                {
                    Gmail[i]=add[j];
                    j++;
                }
                i++;
            }
            flag=0;
            string lines;
                 length=file.length();
                 length=length-5;
                 use.resize(length);
                system("cls");
                cout<<"you comment this post "<<endl;
                Sleep(1200);
                system("cls");
                myfile.open(Gmail,ios::app);
                myfile<<use<<endl;
                myfile<<comment<<endl;
                myfile.close();
       }
       if (check==2)
       {
            string line;
            counter=1;
            int check1=0;
            myfile.open("post.txt",ios::in);
            while (getline(myfile,line))
            {
                check1++;
                cout<<counter<<") "<<line<<endl;
                counter++;
            }
            if (check1==0)
            {
                cout<<"No post uploaded at that time"<<endl;
                goto a;
            }
            myfile.close();
            int count=0;
            cout<<"Select the post which comment you want to see"<<endl;
            cin>>count;
            string str;
            stringstream ss;
            while (count>=counter || count<1)
            {
                system("cls");
                cout<<"PLease select one of them"<<endl;
                cin>>count;
            }
            count=count+10000;
            ss << count;
            ss >> str;
            bool flag=0;
             line;
            int counter1=0;
            int i=0;
            int j=0;
            string Gmail=str;
            int length=Gmail.length();
            Gmail.resize(length+4);
            length=length+4;
            string add=".txt";
            while (i<length)
            {
                if (i>length-5)
                {
                    Gmail[i]=add[j];
                    j++;
                }
                i++;
            }
                 string lines;
                 length=file.length();
                 length=length-5;
                 use.resize(length);
                system("cls");
                Sleep(1200);
                system("cls");
                flag=0;
                int coun=0;
                myfile.open(Gmail,ios::in);
                while(getline(myfile,lines))
                {
                    coun++;
                    if (coun%2==1)
                    {
                        cout<<endl<<"comment by "<<lines<<endl;
                    }
                    else
                    {
                        cout<<"\t\t"<<lines<<endl;
                    }

                }
                if (coun==0)
                {
                    cout<<"No comment on this post"<<endl;
                }
                myfile.close();
       }

        goto a;
}

}
void menu()
{
    cout<<"\n\n\n\n\n\n\n\n\n\n"<<endl;
    cout<<"\t\t\t\t\t*************************"<<endl;
    cout<<"\t\t\t\t\t|"<<"1. Login"<<"\t\t|"<<endl;
    cout<<"\t\t\t\t\t|"<<"2. Sinup" <<"\t\t|"<<endl;
    cout<<"\t\t\t\t\t|"<<"3. Exit" <<"\t\t|"<<endl;
    cout<<"\t\t\t\t\t*************************"<<endl;
    cout<<"\t\t\t\t\t";
}
void login(string choice)
{
    fstream myfile;

    system("cls");

    string mail,password;
    if (choice=="1")
    {
        bool flag=0;
        do{
       do
       {
            cout<<"Enter the email "<<endl;
            cin>>mail;
            int length=mail.length();
            int i=0;
            string check="@gmail.com";
            int k=0;
            int j=0;
            while (i<length)
            {
                k=i;
                if (mail[i]=='@')
                {
                    while (j<10)
                    {
                        if (mail[k]==check[j])
                        {
                            flag=1;
                        }
                        if (mail[k]!=check[j]||(length-i>10 ||length-i<10 ))
                        {
                            flag=0;
                            break;
                        }
                        j++;
                        k++;
                    }
                }
                i++;
            }
            if (flag==0)
            {
                cout<<"Please Write in correct format \"@gmail.com\""<<endl;
            }
       }while(flag!=1);
       flag=0;
       myfile.open("sami.txt",ios::in);
        if (myfile.is_open())
        {
            int i=0;
            int length;
            string line;
            while (getline(myfile,line))
            {
                length=line.length();
                while (i<length)
                {
                    if (line[i]==mail[i])
                    {
                        flag=1;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                    i++;
                }
                if (flag==1)
                {
                    break;
                }
            }
        }
        if (flag==0)
        {
            cout<<"It is invalide account"<<endl;
        }

        myfile.close();
        }while(flag!=1);
        string line;
        string name;
        do{
        myfile.close();
        cout<<"Enter the password"<<endl;
        cin>>password;
        string file=mail;
        string add=".txt";
        int length=file.length();
        int i=0;
        int j=0;
        while (i<length)
        {
            if (i>length-5)
            {
                file[i]=add[j];
                j++;
            }
            i++;
        }
        myfile.open(file,ios::in);
        {
            myfile>>name;
            myfile>>mail;
            myfile>>line ;
        }
        if (line!=password)
        {
            cout<<"Please write the correct password"<<endl;
        }
        }while (line!=password);
        myfile.close();
        system("cls");
        loading();
        system("cls");
        string add=".html";
        int i=0;
        int j=0;
        string file=mail;
        int length=mail.length();
        length=length+1;
        file.resize(length);
        while (i<length)
        {
            if (i>length-6)
            {
                file[i]=add[j];
                j++;
            }
            i++;
        }
        i=0;
        j=0;
        sinupaccount(file);
    }
    else
    {
        string name;
        string number;
        string password;
        cout<<"Enter your name"<<endl;
        cin>>name;
        bool flag=1;
        while (flag==1)
        {
                flag=0;
                do
                {
                    cout<<"Enter the email "<<endl;
                    cin>>mail;
                    int length=mail.length();
                    int i=0;
                    string check="@gmail.com";
                    int k;
                    int j=0;
                    while (i<length)
                    {
                        k=i;
                        if (mail[i]=='@')
                        {
                            while (j<10)
                            {
                                if (mail[k]==check[j])
                                {
                                    flag=1;
                                }
                                if (mail[k]!=check[j]||(length-i>10 ||length-i<10 ))
                                {
                                    flag=0;
                                    break;
                                }
                                j++;
                                k++;
                            }
                        }
                        i++;
                    }
                    if (flag==0)
                    {
                        cout<<"Please Write in correct format \"@gmail.com\""<<endl;
                    }
                }while(flag!=1);
                flag=0;
                myfile.open("sami.txt",ios::in);
                if (myfile.is_open())
                {
                int i=0;
                int length;
                string line;
                while (getline(myfile,line))
                {
                    length=line.length();
                    while (i<length)
                    {
                        if (line[i]==mail[i])
                        {
                            flag=1;
                        }
                        else
                        {
                            flag=0;
                            break;
                        }
                        i++;
                    }
                    if (flag==1)
                    {
                        break;
                    }
                }
                myfile.close();
                if (flag==1)
                {
                    cout<<"You cannot creat the account because this is already exist"<<endl;
                }
            }
        }
        int lenght;
        do{
        flag=0;
        cout<<"Enter the password"<<endl;
        cin>>password;
        int i=0;
        lenght=password.length();
        while (i<lenght)
        {
            if ((password[i]>=32 && password[i]<=47)||(password[i]>=58 && password[i]<=64)||(password[i]>=91 && password[i]<=96)||(password[i]>=123 && password[i]<=126 ))
            {
                flag=1;
                break;
            }
            else
            {
                flag=0;
            }
            i++;
        }
        if (flag==0 || lenght!=8)
        {
            cout<<"You have only write 8 character with special character"<<endl;
        }

    }while (flag!=1 || lenght!=8);
        flag=1;
        cout<<"Enter your contact number"<<endl;
        cin>>number;
        int length=number.length();
        while (length!=11 || number[0]!='0' || number[1]!='3')
        {
            system("cls");
            cout<<"Please write the correct number"<<endl;
            cin>>number;
            length=number.length();
        }
        srand(time(0));
        int confirm=rand()%999999+100000;
        cout<<"It is cofirmation code "<<endl;
        cout<<confirm<<endl;
        int con;
        cout<<"Enter the cofirmation code "<<endl;
        cin>>con;
        while(con!=confirm)
        {
            cout<<"please write the correct password"<<endl;
            cin>>con;
        }
        if (flag==1)
        {
            myfile.open("sami.txt",ios::app);
            if (myfile.is_open())
            {
                myfile<<name<<endl;
                myfile<<mail<<endl;
            }
            else
            {
                cout<<"error in the file"<<endl;
            }
        }
        myfile.close();
        string file=mail;
        string add=".txt";
        length=file.length();
        int i=0;
        int j=0;
        while (i<length)
        {
            if (i>length-5)
            {
                file[i]=add[j];
                j++;
            }
            i++;
        }
        myfile.open(file,ios::out);
        {
            myfile<<name<<endl;
            myfile<<mail<<endl;
            myfile<<password<<endl;
            myfile<<number<<endl;
        }
    }
}
void screen()
{
    fstream myfile;
    int line;
    myfile.open("mode.txt",ios::in);
    myfile>>line;
    myfile.close();
    if (line==1)
    {
        system("Color 0F");
    }
    if (line==2)
    {
        system ("Color F0");
    }
}
int main()
{

      string choice;
    screen();
    do{
     menu();
    cin>>choice;
    system("cls");
    while (choice!="1" && choice!="2"  && choice!="3")
    {
        system("cls");
        menu();
        cout<<"please select the right option"<<endl;
        cin>>choice;
    }
    if (choice=="1" || choice=="2")
    {
        system("cls");
        login(choice);
    }
   } while(choice!="3");

    return 0;
}
