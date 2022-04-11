#include <iostream>
#include "namsal.h"
namespace SALES
{
    using namespace std;
    void setSales(Sales & s, const double ar[], int n)
    {
        for (int i=0; i<n; i++)
            s.sales[i]=ar[i];
        if (n!=QUARTERS)
            for (int i=n; i<QUARTERS; i++)
                s.sales[i]=0;
        s.max=s.min=s.sales[0];
        for (int i=0; i<n; i++)
        {
            if (s.min>s.sales[i])
                s.min=s.sales[i];
            if (s.max<s.sales[i])
                s.max=s.sales[i];
        }
        s.average=0;
        for (int i=0; i<n; i++)
            s.average+=s.sales[i];
        s.average/=n;
    }
    void setSales(Sales & s)
    {
        cout<<"Podaj dane dla poszczególnych kwartałów:\n";
        for (int i=0; i<QUARTERS; i++)
        {
            cout<<"Kwartał #"<<i+1<<":\n";
            while (!(cin>>s.sales[i]))
            {
                cin.clear();
                while (cin.get()!='\n')
                    continue;
                cout<<"Błędne dane, spróbuj jeszcze raz:\n";
            }
        }
        s.min=s.sales[0];
        s.max=s.sales[0];
        for (int i=0; i<QUARTERS; i++)
        {
            if (s.min>s.sales[i])
                s.min=s.sales[i];
            if (s.max<s.sales[i])
                s.max=s.sales[i];
        }
        s.average=0;
        for (int i=0; i<QUARTERS; i++)
            s.average+=s.sales[i];
        s.average/=QUARTERS;
    }
    void showSales(const Sales & s)
    {
        cout<<"\tWartości kwartałów:\n";
        for (int i=0; i<QUARTERS; i++)
            cout<<"\tKwartał #"<<i+1<<" = "<<s.sales[i]<<endl;
        cout<<"\tŚrednia = "<<s.average<<endl;
        cout<<"\tWartość minimalna = "<<s.min<<endl;
        cout<<"\tWartość maksymalna = "<<s.max<<endl;
    }
}
