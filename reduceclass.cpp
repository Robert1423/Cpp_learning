#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

template <class T>
int reduce(T ar[], int n)
{
    int count=0;
    std::sort(ar,ar+n);
    auto last=std::unique(ar,ar+n);
    for (T * begin=ar; begin<last; begin++)
        count++;
    return count;
}

using namespace std;

int main()
{
    srand(time(0));
    long  tab[10];
    for (int i=0; i<10; i++)
        tab[i]=rand()%10;
    string words[5]={"test1","test5","test3","test1","test1"};
    cout<<"Tablica long:\n";
    cout<<"Początkowa ilość elemetów = 10\n";
    cout<<"Zawartość: ";
    for (int i=0; i<10; i++)
        cout<<tab[i]<<" ";
    int n=reduce(tab,10);
    cout<<"\nPo użyciu reduce():\nLiczba elemetów = "<<n<<endl;
    cout<<"Zawartość: ";
    for (int i=0; i<n; i++)
        cout<<tab[i]<<" ";
    cout<<"Tablica string:\n";
    cout<<"Początkowa ilość elemetów = 5\n";
    cout<<"Zawartość: ";
    for (int i=0; i<5; i++)
        cout<<words[i]<<" ";
    int w=reduce(words,5);
    cout<<"\nPo użyciu reduce():\nLiczba elemetów = "<<w<<endl;
    cout<<"Zawartość: ";
    for (int i=0; i<w; i++)
        cout<<words[i]<<" ";
    cout<<endl;
    return 0;
}
