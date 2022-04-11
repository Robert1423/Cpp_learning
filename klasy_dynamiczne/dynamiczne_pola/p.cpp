#include <iostream>
#include "cow.h"
using namespace std;
int main()
{
    cout<<"Utworzenie obiektu nr 1\n";
    Cow t;
    cout<<"Dane obiektu nr 1:\n";
    t.ShowCow();
    cout<<"Utworzenie obiektu nr 2\n";
    Cow ct("Bóbr","Kopanie",20.2);
    cout<<"Dane obiektu nr 2:\n";
    ct.ShowCow();
    cout<<"Skopiowanie danych obiektu nr 2 do obiektu nr 1\n";
    t=ct;
    cout<<"Teraz dane obiektu nr 1:\n";
    t.ShowCow();
    {
        cout<<"\nNowy blok\n";
        cout<<"Utworzenie obiektu tymczasowego\n";
        Cow temp=ct;
        cout<<"Dane obiektu tymczasowego:\n";
        temp.ShowCow();
    }
    cout<<"\nPowrót do głównego bloku\n";
    return 0;
}
