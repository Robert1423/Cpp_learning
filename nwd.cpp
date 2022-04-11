//obliczanie Najwiekszego Wspolnego Dzielnika dwoch podanych liczb calkowitych
#include <iostream>
#include <limits>

int nwd(int a, int b);

using namespace std;

int main()
{
    int x, y, z;
    cout<<"Wprowadź x: ";
    while (!(cin>>x))
    {
        cout<<"\nBłąd! Jeszcze raz: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"Wprowadź y: ";
        while (!(cin>>y))
    {
        cout<<"\nBłąd! Jeszcze raz: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    z=nwd(x,y);
    cout<<"NWD liczb "<<x<<" i "<<y<<" = "<<z<<endl;
    return 0;
}

int nwd(int a, int b)
{
    while (a!=b)
        if (a>b)
            a-=b;
        else
            b-=a;
    return a;
}
