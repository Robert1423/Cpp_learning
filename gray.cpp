//Kod graya
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

using namespace std;

long ileliczb(int x);
vector<int> to_bin(long x, int n);
vector<int>  to_gray(vector<int> bin, int n);
void wyswetl(vector<int> v, int n);
void kod(int i, vector<int> v, vector<int> v2, int n);
int main()
{
    int n;
    cout<<"Podaj ilość bitów: ";
    while (!(cin>>n))
    {
        cout<<"\nBłąd! Jeszcze raz: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    long x=ileliczb(n);
    cout<<"Liczba:\tBinarnie:\tKod Graya:\n";
    for (int i=1; i<=x; i++)
    {
        vector<int> bin=to_bin(i,n);
        vector<int> gray=to_gray(bin,n);
        kod(i,bin,gray,n);
    }
    return 0;
}

long ileliczb(int x)
{
    vector<int> temp;
    for (int i=0; i<x; i++)
        temp.push_back(1);
    long sum=0;
    for (int j=0; j<x; j++)
            sum+=pow(2,j);
    return sum;
}

vector<int> to_bin(long x, int n)
{
    vector<int> bin;
    int j=0;
    while (x!=0)
    {
        int t=x%2;
        bin.push_back(t);
        x/=2;
        j++;
    }
    if (j==n)
        reverse(bin.begin(),bin.end());
    else
    {
        for (j; j<n; j++)
            bin.push_back(0);
        reverse(bin.begin(),bin.end());
    }
    return bin;
}

vector<int> to_gray(vector<int> bin, int n)
{
    vector<int> temp;
    vector<int> gray;
    temp.push_back(0);
    for (int i=0; i<n; i++)
        temp.push_back(bin[i]);
    temp.erase(temp.begin()+n,temp.end());
    for (int i=0; i<n; i++)
        gray.push_back(bin[i]^temp[i]);
    return gray;
}
void wyswetl(vector<int> v, int n)
{
    for (int i=0; i<n; i++)
        cout<<v[i];
}

void kod(int i, vector<int> v, vector<int> v2, int n)
{
     cout<<i<<'\t';
     wyswetl(v,n);
     cout<<"\t\t";
     wyswetl(v2,n);
     cout<<endl;
}
