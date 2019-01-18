#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<string> Assign(int a, vector<string> s, int x)
{
    char player;
    if(x==1)player='O';
    else player='X';
    switch(a)
    {
        case 1:s[1][1]=player;break;
        case 2:s[1][5]=player;break;
        case 3:s[1][9]=player;break;
        case 4:s[5][1]=player;break;
        case 5:s[5][5]=player;break;
        case 6:s[5][9]=player;break;
        case 7:s[9][1]=player;break;
        case 8:s[9][5]=player;break;
        case 9:s[9][9]=player;break;
    }
    return s;
}
int check(vector<string> a)
{
    for(int i=1;i<11;i=i+4)
    {
        if(a[i][1]==a[i][5] && a[i][5]==a[i][9])
        {
            if(a[i][1]=='X')
                {cout<<"Player 2 Wins";return 1;}
            if(a[i][1]=='O')
                {cout<<"Player 1 Wins";return 1;}
        }
        if(a[1][i]==a[5][i] && a[5][i]==a[9][i])
        {
            if(a[1][i]=='X')
                {cout<<"Player 2 Wins";return 1;}
            if(a[1][i]=='O')
                {cout<<"Player 1 Wins";return 1;}
        }
    }
    if(a[1][1]==a[5][5] && a[5][5]==a[9][9])
    {   if(a[1][1]=='X')
                {cout<<"Player 2 Wins";return 1;}
        if(a[1][1]=='O')
                {cout<<"Player 1 Wins";return 1;}
    }
    if(a[1][9]==a[5][5] && a[5][5]==a[9][1])
    {   if(a[1][9]=='X')
                {cout<<"Player 2 Wins";return 1;}
        if(a[1][9]=='O')
                {cout<<"Player 1 Wins";return 1;}
    }
    return 0;
}
int main() {
    int input, j=0;
    int win=0;
    vector<string> s;
    s.push_back("   |   |   ");
    s.push_back("   |   |   ");
    s.push_back("  1|  2|  3");
    s.push_back("-----------");
    s.push_back("   |   |   ");
    s.push_back("   |   |   ");
    s.push_back("  4|  5|  6");
    s.push_back("-----------");
    s.push_back("   |   |   ");
    s.push_back("   |   |   ");
    s.push_back("  7|  8|  9");
    for(int i=0;i<s.size();i++)
        cout<<s[i]<<endl;
    do{
        j++;
        for(int i=1;i<3 && win!=1;i++)
        {
            cout<<"Player "<<i<<">> ";
            cin>>input;
            if(input>=1 && input<=9)
            {
                s=Assign(input, s, i);
                for(int i=0;i<s.size();i++)
                cout<<s[i]<<endl;
                cout<<endl;
                win = check(s);
            }
            else
            {
                cout<<"invalid input";continue;
            }
        }
    }while(win!=1 && j<=9);
    system("pause");
    return 0;
}
