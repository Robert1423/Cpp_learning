//wyswietla liczby szostkowe do podanego limitu
#include <iostream>
#include <limits>

using namespace std;

bool czypierwsza(int x);

int main()
{
    int x;
    cout<<"Wprowadź x: ";
    while (!(cin>>x))
    {
        cout<<"\nBłąd! Jeszcze raz: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (x<5)
    {
        cout<<"Brak liczb szóstkowych\n";
        return 0;
    }
    cout<<"Liczby pierwsze szóstkowe do liczby "<<x<<":\n";
    for (int i=5;i<x;i++)
        if (czypierwsza(i)&&(i+6)<x)
            cout<<"("<<i<<","<<i+6<<")\n";
    return 0;
}

bool czypierwsza(int x)
{
    if (x<2)
        return false;
    for (int i=2; i*i<=x; i++)
        if (x%i==0)
            return false;
        return true;
}
