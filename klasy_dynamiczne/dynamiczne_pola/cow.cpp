#include <iostream>
#include <cstring>
#include "cow.h"
using namespace std;
Cow::Cow()
{
    strcpy(name,"brak nazwy");
    hobby=new char[5];
    strcpy(hobby,"brak");
    weight=0.0;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
    strcpy(name,nm);
    hobby=new char[strlen(ho)+1];
    strcpy(hobby,ho);
    weight=wt;
}
Cow::Cow(const Cow & c)
{
    strcpy(name,c.name);
    hobby=new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight=c.weight;
}
Cow::~Cow()
{
    delete [] hobby;
    cout<<"Usunięcie obiektu\n";
}
Cow & Cow::operator=(const Cow & c)
{
    if (this==&c)
        return *this;
    delete [] hobby;
    hobby=new char[strlen(c.hobby)+1];
    strcpy(name,c.name);
    strcpy(hobby,c.hobby);
    weight=c.weight;
    return *this;
}
void Cow::ShowCow() const
{
    cout<<"Nazwisko: "<<name<<endl;
    cout<<"Hobby: "<<hobby<<endl;
    cout<<"Waga: "<<weight<<endl;
}
