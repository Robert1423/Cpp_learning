#ifndef PORT_H_
#define PORT_H_
#include <iostream>
using namespace std;
class Port
{
private:
    char * brand;
    char style[20];
    int bottles;
public:
    Port(const char * br="brak", const char * st="brak", int b=0);
    Port(const Port & p);
    virtual ~Port() {delete [] brand;}
    Port & operator=(const Port & p);
    Port & operator+=(int b);   //dodaje b do bottles
    Port & operator-=(int b);   //jeżeli można, odejmuje b od bottles
    int BottlesCount() const {return bottles;}
    virtual void Show() const;
    friend ostream & operator<<(ostream & os, const Port & p);
};
class VintagePort : public Port
{
private:
    char * nickname;
    int year;
public:
    VintagePort();
    VintagePort(const char * br, int b, const char * nm, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() {delete [] nickname;}
    VintagePort & operator=(const VintagePort & vp);
    void Show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & vp);
};
#endif
