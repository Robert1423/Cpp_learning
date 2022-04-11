#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void wpisz(vector<string> & x);
void Show(const vector<string> & x);

int main()
{
    vector<string> bolek;
    vector<string> lolek;
    vector<string> razem;
    cout<<"Lista Bolka:\n";
    wpisz(bolek);
    sort(bolek.begin(),bolek.end());
    cout<<"Lista Lolka:\n";    
    wpisz(lolek);
    sort(lolek.begin(),lolek.end());
    copy(bolek.begin(),bolek.end(),back_insert_iterator<vector<string>>(razem));
    copy(lolek.begin(),lolek.end(),back_insert_iterator<vector<string>>(razem));
    sort(razem.begin(),razem.end());
    auto last=unique(razem.begin(),razem.end());
    razem.erase(last,razem.end());
    cout<<"Lista gości:\n";
    cout<<"Bolek:\n";
    Show(bolek);
    cout<<"Lolek:\n";
    Show(lolek);
    cout<<"Razem:\n";
    Show(razem);
    return 0;
}
void wpisz(vector<string> & x)
{
    string name;
    cout<<"Wpisuj imiona <koniec, zby zakończyć>: ";
    getline(cin,name);
    while (name!="koniec")
    {
        x.push_back(name);
        cout<<"Wpisz kolejne: ";
        getline(cin,name);
    }
}
void Show(const vector<string> & x)
{
    if (x.size()==0)
        cout<<"\nBrak!\n";
    else
    {
        for (int i=0; i<x.size(); i++)
            cout<<"\t"<<x[i]<<"\n";
    }
}
