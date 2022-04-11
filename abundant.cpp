//wyswietla liczby obfite i ich obifitosc do liczby podanej
#include <iostream>
#include <limits>

bool obfi(int x, int &obf)
{
    int sum=0;
    int j=0;
    for (int i=1; i<=x; i++)
    {
        if (x%i==0)
        {
            sum+=i;
            j++;
        }
    }
    if (j>4&&sum>x)
    {
        obf=sum;
        return true;
    }
    else
        return false;
}

using namespace std;

int main()
{
    int x, ob, u;
    cout<<"Podaj x: ";
    while (!(cin>>x))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Błąd! Jeszcze raz: ";
    }
    cout<<"Liczby obfite do "<<x<<":\n";
    u=0;
    for (int i=2; i<=x; i++)
    {
        if (obfi(i,ob))
        {
            cout<<i<<" - obfitość: "<<ob-i<<endl;
            u++;
        }
    }
    if (u==0)
        cout<<"Brak liczb obfitych\n";
    return 0;
}
