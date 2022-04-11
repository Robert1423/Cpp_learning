#include <iostream>
#include "queuetp.h"
using std::cout;
using std::cin;
using std::endl;
Worker::~Worker() {}
void Worker::Show() const
{
    cout << "Imię i nazwisko: " << fullname << endl;
    cout << "Numer identyfikacyjny: " << id << endl;
}
void Worker::Set()
{
    cout<<"Podaj nazwisko: ";
    getline(cin, fullname);
    cout << "Podaj numer identyfikacyjny: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}
