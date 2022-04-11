//ciąg Collatza
#include <iostream>
#include <limits>

using namespace std;

void szukajliczby(long limit);

int main()
{
    cout<<"Ciąg collatza do limitu\n";
    cout<<"Podaj limit: ";
    long x;
    while (!(cin>>x))
    {
        cout<<"Błąd! Jeszcze raz\n";
        cout<<"Podaj limit: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout<<"Mniejsza od "<<x<<endl;
    cout<<"Wartość początkowa: ";
    szukajliczby(x);
    return 0;
}

void szukajliczby(long limit)
{
    unsigned long d=0;
    unsigned long y=0;
    for (unsigned long i=2; i<limit; i++)
    {
        auto x=i;
        unsigned long t=0;
        while (x!=1)
        {
            if ((x%2)==0)
                x=x/2;
            else
                x=3*x+1;
            t++;
        }
        if (t>d)
        {
            d=t;
            y=i;
        }
    }
    cout<<y<<endl;
    cout<<"długość ciągu: "<<d<<endl;
}
