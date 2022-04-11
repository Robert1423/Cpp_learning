//wyswietla czynniki peirwsze
#include <iostream>
#include <limits>

using namespace std;

bool czypierwsza(int x);
void czynnik1(int x);

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
    if (czypierwsza(x))
        cout<<"Brak czynników pierwszych\n";
    else
    {
        cout<<"Czynniki pierwsze liczby "<<x<<endl;
        czynnik1(x);
    }
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
void czynnik1(int x)
{
    while (x>1)
    {
        if (czypierwsza(x))
        {
            cout<<x<<" | "<<x<<endl;
            x/=x;
            continue;
        }
        if (x%2==0)
        {
            cout<<x<<" | 2"<<endl;
            x/=2;
        }
        else
        {
            for (int i=3; i<x; i++)
            {
                if (czypierwsza(i))
                {
                	if (x%i==0)
                	{
                    		cout<<x<<" | "<<i<<endl;
                    		x/=i;
                    	}
                }
            }
        }
    }
    cout<<x<<" |\n";
}
