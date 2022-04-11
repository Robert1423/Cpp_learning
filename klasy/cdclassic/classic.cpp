#include <iostream>
#include <cstring>
#include "classic.h"
using namespace std;
Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    strcpy(performers,s1);
    strcpy(label, s2);
    selections=n;
    playtime=x;
}
Cd::Cd(const Cd & d)
{
    strcpy(performers,d.performers);
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
}
Cd::Cd()
{
    strcpy(performers,"brak");
    strcpy(label,"brak");
    selections=0;
    playtime=0.0;
}
Cd::~Cd() {}
void Cd::Report() const
{
    cout<<"Wykonawca: "<<performers<<endl;
    cout<<"Tytuł: "<<label<<endl;
    cout<<"Liczba utworów: "<<selections<<endl;
    cout<<"Całkowity czas: "<<playtime<<endl;
}
Cd & Cd::operator=(const Cd & d)
{
    if (this==&d)
        return *this;
    strcpy(performers,d.performers);
    strcpy(label,d.label);
    selections=d.selections;
    playtime=d.playtime;
    return *this;
}
Classic::Classic(const char * t, const char * s1, const char * s2, int n, double x) : Cd(s1,s2,n,x)
{
    top=new char[strlen(t)+1];
    strcpy(top,t);
}
Classic::Classic(const char * t, const Cd & d) : Cd(d)
{
    top=new char[strlen(t)+1];
    strcpy(top,t);
}
Classic::Classic(const Classic & cl) : Cd(cl)
{
    delete [] top;
    top=new char[strlen(cl.top)+1];
    strcpy(top,cl.top);
}
Classic::Classic() : Cd()
{
    top=new char [1];
    top[0]='\0';
}
Classic::~Classic()
{
    delete [] top;
}
void Classic::Report() const
{
    Cd::Report();
    cout<<"Główny utwór: "<<top<<endl;
}
Classic & Classic::operator=(const Classic & d)
{
    if (this==&d)
        return *this;
    Cd::operator=(d);
    delete [] top;
    top=new char[strlen(d.top)+1];
    strcpy(top,d.top);
    return *this;
}
