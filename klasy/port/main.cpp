#include <iostream>
#include "port.h"
using namespace std;
int main()
{
    cout<<"Test klasy VintagePort\n";
    cout<<"Tworzenie obiektu klasy Port:\n";
    Port p("Gallo","lekko brązowy",20);
    cout<<"Obiekt klasy Port:\n";
    p.Show();
    cout<<"Kopia port:\n";
    Port p2(p);
    p2.Show();
    cout<<"Tworzenie obiektu VintagePort:\n";
    VintagePort v("Gallo",20,"Szlachetny",1985);
    cout<<"Obiekt klasy VintagePort:\n";
    v.Show();
    cout<<"Kopia VintagePort:\n";
    VintagePort v2(v);
    v2.Show();
    cout<<"Dodanie 3 butelek do p:\n";
    p+=3;
    cout<<"Teraz p: "<<p<<endl;
    cout<<"Próba zabrania 23 butelek z p2:\n";
    p2-=23;
    cout<<"p2 -5\n";
    p2-=5;
    cout<<"Teraz p2: "<<p2<<endl;
    cout<<"Przypisanie p do p2: \n";
    p2=p;
    cout<<"Teraz p2: "<<p2<<endl;
    cout<<"Dodanie do v 5 butelek: \n";
    v+=5;
    cout<<"Teraz v: "<<v<<endl;
    cout<<"Przypisanie v do v2: \n";
    v2=v;
    cout<<"Teraz v2: "<<v2<<endl;
    return 0;
}
