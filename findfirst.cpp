//szukanie najwiekszej liczby pierwszej mniejszej niz podana liczba dodatnia
#include <iostream>
#include <limits>

using namespace std;

bool czypierwsza(int x);

int main()
{
    int x;
    cout<<"Wprowadź x: ";
    while (!(cin>>x)||x<=0)
    {
        cout<<"\nBłąd! Jeszcze raz: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"Szukanie największej liczby pierwszej mniejszej niż "<<x<<endl;
    int i=x;
    if (czypierwsza(i))
    {
        i--;
        while (!czypierwsza(i))
            i--;;
    }
    else
    while (!czypierwsza(i))
        i--;
    cout<<"Ta liczba to: "<<i<<endl;
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
