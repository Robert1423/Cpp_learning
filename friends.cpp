//liczby zaprzyjaznione mniejsze niz milion
#include <iostream>
#include <limits>

bool zap(long x, long y);
long znajdzzap(long x);

using namespace std;

int main()
{
    const long l= 1000000;
    long prev=0;
    cout<<"Liczby zaprzyjaźnione do "<<l<<endl;
    for (long i=1; i<l; i++)
    {
        long j=znajdzzap(i);
        if (zap(i,j)&&i!=j&&i!=prev)
        {
            cout<<i<<" "<<j<<endl;
            prev=j;
        }
    }
    return 0;
}

bool zap(long x, long y)
{
    long sum1, sum2;
    sum1=0;
    sum2=0;
    for (long i=1; i<x; i++)
        if (x%i==0)
            sum1+=i;
    for (long i=1; i<y; i++)
        if (y%i==0)
            sum2+=i;
    if (x==sum2&&y==sum1)
        return true;
    else
        return false;
}

long znajdzzap(long x)
{
    long sum=0;
    for (long i=1; i<x; i++)
        if (x%i==0)
            sum+=i;
    return sum;
}
