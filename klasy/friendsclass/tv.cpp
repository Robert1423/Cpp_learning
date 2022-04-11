#include <iostream>
#include "tv.h"
bool Tv::volup()
{
    if (volume<MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if (volume>MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}
void Tv::chanup()
{
    if (channel<maxchannel)
        channel++;
    else
        channel=1;
}
void Tv::chandown()
{
    if (channel>1)
        channel--;
    else
        channel=maxchannel;
}
void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout<<"Telewizor jest "<<(state==Off?"Wyłączony":"Włączony")<<endl;
    if (state==On)
    {
        cout<<"Głośność = "<<volume<<endl;
        cout<<"Program = "<<channel<<endl;
        cout<<"Tryb = "
          <<(mode==Antenna?"antena":"kabel")<<endl;
        cout<<"Wejście = "
          <<(input==TV?"TV":"DVD")<<endl;
    }
}
void Tv::remote_typ(Remote & r)
{
    if (state==On)
        r.set_typ();
}
void Tv::question(Remote & r)
{
    using std::cout;
    if (r.Wtype())
    {
        cout<<"Test metody\n";
        cout<<"Czy 2 + 2 = 4? <y/n>";
        char a;
        a=r.q_a();
        if (a=='y')
            cout<<"Dobrze!\n";
        else
            cout<<"\aBłędna odpowiedź\n";
    }
}
void Remote::setting() const
{
    using std::cout;
    using std::endl;
    cout<<"Ustawienia pilota:\n";
    cout<<"Mod = "<<(mode==Tv::TV?"TV":"DVD")<<endl;
    cout<<"Tryb = "<<(type==Normal?"Normalny":"Interaktywny")<<endl;
}
char Remote::q_a()
{
    using std::cin;
    char ch;
    cin>>ch;
    return ch;
}
