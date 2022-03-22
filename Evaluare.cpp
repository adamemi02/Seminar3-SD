#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;
ifstream fin("evaluare.in");
ofstream fout("evaluare.out");
char s[100010], *p = s;

int inmultire();
int adunare();
int  element()
{
    int  x = 0;
    if(*p == '(')
    {
        p++;
        x = adunare();
        p++;
    }
    else{
        while(*p <= '9' && *p >= '0')
        {
            x = x*10 + (*p-'0');
            p++;
        }
    }
    return x;
}


int  inmultire()
{
    int  x = element();
    while ( *p == '*' || *p == '/')
    {
        if(*p == '*')
        {
            p++;
            x=x* element();
        }
        else {
            p++;
            x=x/ element();
        }
    }
    return x;
}

int  adunare()
{
    int  x = inmultire();
    while( *p == '+' || *p == '-')
    {
        if(*p == '+')
        {
            p++;
            x=x+ inmultire();
        }
        else{
            p++;
            x=x- inmultire();
        }
    }
    return x;

}
int main()
{
    fin>>s;
    fout<<adunare();

    return 0;
}
