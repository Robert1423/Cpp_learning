//obliczanie NWW dwoch liczb
#include <iostream>
#include <limits>

using namespace std;

int nwd(int a, int b);
int nww(int a, int b);

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
    z=nww(x,y);
    cout<<"NWW liczb "<<x<<" i "<<y<<" = "<<z<<endl;
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

int nww(int a, int b)
{
    int temp=nwd(a,b);
    int n=(a*b)/temp;
    return n;
}
