#include "ip4.h"
#include <limits>
using namespace std;
  
int main()
{
    int x, y;
    cout<<"Podaj liczbę <0-255>: ";
    while(!(cin>>x)||x>255||x<0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Błąd!\nPodaj liczbę <0-255>: ";
    }
    cout<<"Podaj drugą liczbę <0-255>: ";
    while(!(cin>>y)||y>255||y<0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Błąd!\nPodaj liczbę <0-255>: ";
    }
    ip4 i1(168,192,0,x);
    ip4 i2(168,192,0,y);
    cout<<"Adresy IP: "<<i1<<" i "<<i2<<endl;
    i1.zakres(i2);
    return 0;
}
