#include "port.h"
#include <iostream>
#include <cstring>
using namespace std;
Port::Port(const char * br, const char * st, int b)
{
    brand=new char[strlen(br)+1];
    strcpy(brand, br);
    strcpy(style,st);
    bottles=b;
}
Port::Port(const Port & p)
{
    brand=new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles=p.bottles;
}
Port & Port::operator=(const Port & p)
{
    if (this==&p)
        return *this;
    delete [] brand;
    brand=new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles=p.bottles;
    return *this;
}
Port & Port::operator+=(int b)
{
    bottles+=b;
    return *this;
}
Port & Port::operator-=(int b)
{
    if (bottles==0)
    {
        cout<<"Odejmowanie niemożliwe. Operacja przerwana.\n";
        return *this;
    }
    else if ((bottles-b)<0)
    {
        cout<<"Odejmowanie niemożliwe. Operacja przerwana.\n";
        return *this;
    }
    else
    {
        bottles-=b;
        return *this;
    }
}
void Port::Show() const
{
    cout<<"Marka: "<<brand<<endl;
    cout<<"Rodzaj: "<<style<<endl;
    cout<<"Butelek: "<<bottles<<endl;
}
ostream & operator<<(ostream & os, const Port & p)
{
    os<<p.brand<<", "<<p.style<<", "<<p.bottles;
    return os;
}
VintagePort::VintagePort() : Port()
{
    nickname=new char[1];
    nickname[0]='\0';
    year=0;
}
VintagePort::VintagePort(const char * br, int b, const char * nm, int y) : Port(br,"najlepszy rocznik",b)
{
    nickname=new char[strlen(nm)+1];
    strcpy(nickname, nm);
    year=y;
}
VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
    nickname=new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
    year=vp.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (this==&vp)
        return *this;
    Port::operator=(vp);
    delete [] nickname;
    nickname=new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
    year=vp.year;
    return *this;
}
void VintagePort::Show() const
{
    Port::Show();
    cout<<"Charakter: "<<nickname<<endl;
    cout<<"Rocznik: "<<year<<endl;
}
ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os<<(const Port &) vp;
    os<<", "<<vp.nickname<<", "<<vp.year;
    return os;
}
