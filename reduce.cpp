//sortowanie i usuwanie powtarzających się elementów
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int MAX=100;
int reduce(long ar[], int n);

using namespace std;

int main()
{
    srand(time(0));
    long tab[MAX];
    for (int i=0; i<MAX; i++)
        tab[i]=rand()%30;
    int n;
    cout<<"Początkowo ilość elementów tablicy: "<<MAX<<endl;
    cout<<"Zawartość tablicy: ";
    for (int i=0; i<MAX; i++)
        cout<<tab[i]<<" ";
    n=reduce(tab,MAX);
    cout<<"\nPo posortowaniu i usunięciu powtarzających się elementów: "<<n<<endl;
    for (int i=0; i<n; i++)
        cout<<tab[i]<<" ";
    cout<<endl;
    return 0;
}

int reduce(long ar[], int n)
{
    int count=0;
    sort(ar,ar+n);
    auto last=unique(ar,ar+n);
    for (long * begin=ar; begin<last; begin++)
        count++;
    return count;
}
