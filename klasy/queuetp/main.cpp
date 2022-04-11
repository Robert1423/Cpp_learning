#include <iostream>
#include <string>
#include "queuetp.h"
const int SIZE = 5;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    cout << "Podaj maksymalną długość kolejki: ";
    int qs;
    cin >> qs;
    while (cin.get()!='\n')
        continue;
    Worker * np=new Worker[qs];
    QueueTP<Worker *> kol(qs);
    for (int i=0; i<=qs; i++)
    {
        cout<<"\nObecnie w kolejce: "<<kol.queuecount()<<endl;
        if (!kol.isfull())
        {
            cout<<"Nowy pracownik w kolejce:\n";
            np[i].Set();
            kol.enqueue(&np[i]);
        }
        else
            cout<<"\nKolejka jest pełna"<<endl;
    }
    cout<<"\nLiczba pracowników w kolejce: "<<kol.queuecount()<<endl;
    for (int i=0; i<=qs; i++)
    {
        if (!kol.isempty())
        {
            cout<<"\nPracownik usunięty z kolejki:\n";
            np[i].Show();
            kol.dequeue(&np[i]);
            cout<<"Pozostała liczba pracowników w kolejce: "<<kol.queuecount()<<endl;
        }
        else
            cout<<"\nKolejka pusta\n";
    }
    delete [] np;
    cout<<"Koniec\n";
    return 0;
}
