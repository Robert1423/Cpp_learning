//szablon typu tablicowego
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iterator>

using namespace std;

template<typename t>
class tab
{
private:
    std::vector<t> t1;
    std::vector<t> t2;
    int cap;
public:
    tab();
    tab(t x, t y, int n=0);
    ~tab();
    void at(t x);
    void data();
    void setcapacity(int n);
    void fill(t x, t y);
    void edit();
    tab<t> operator[](int i);
};

template<typename t>
tab<t>::tab()
{
    t x, y;
    int n;
    cout<<"Wprowadź maksymalną pojemność: ";
    while (!(cin>>n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Błąd!\nWprowadź maksymalną pojemność: ";
    }
    cap=n;
    for (int i=0; i<cap; i++)
    {
        cout<<"Wprowadź 1 wartość: ";
        while (!(cin>>x))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Błąd!\nWprowadź 1 wartość: ";
        }
        t1.push_back(x);
        cout<<"Wprowadź 2 wartość: ";
        while (!(cin>>y))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Błąd!\nWprowadź 2 wartość: ";
        }
        t2.push_back(y);
        char ch;
        cout<<"Chcesz wprowadzać dalej: <n, aby zakończyć>";
        cin>>ch;
        if (ch=='n'||ch=='N')
            break;
    }
}
template<typename t>
tab<t>::tab(t x, t y, int n)
{
    if (n>0)
    {
        cap=n;
        t1=x;
        t2=y;
    }
    else
        cout<<"Błędna pojemność!\n";
}
template<typename t>
tab<t>::~tab() {}
template<typename t>
void tab<t>::at(t x)
{
    if (cap>0)
    {
        int a=0;
        for (int i=0; i<cap; i++)
        {
            if (x==t1[i]||x==t2[i])
            {
                a=1;
                cout<<x<<" znajduje się w tabeli\n";
                break;
            }
        }
    }
    else
        cout<<x<<" nie znajduje się w tabeli\n";
}
template<typename t>
void tab<t>::data()
{
    cout<<"Zawartość tabeli:\n";
    for (int i=0; i<t1.size(); i++)
        cout<<i+1<<": "<<t1[i]<<" "<<t2[i]<<endl;
}
template<typename t>
void tab<t>::setcapacity(int n)
{
    cap=n;
    if (t1.size()>cap)
        t1.erase(t1.begin()+n,t1.end());
    if (t2.size()>cap)
        t2.erase(t2.begin()+n,t2.end());
}
template<typename t>
void tab<t>::fill(t x, t y)
{
    if (cap>t1.size())
    {
        for (int i=t1.size(); i<cap; i++)
            t1.push_back(x);
    }
    if (cap>t2.size())
    {
        for (int i=t2.size(); i<cap; i++)
            t2.push_back(y);
    }
}
template<typename t>
void tab<t>::edit()
{
    data();
    cout<<"Który wiersz edytować: ";
    int x;
    while (!(cin>>x))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Błąd!\nKtóry wiersz edytować: ";
    }
    t a, b;
    cout<<"Wprowad nową 1 wartość: ";
    while (!(cin>>a))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Błąd!\nWprowadź 1 wartość: ";
    }
    cout<<"Wprowadź nową 2 wartość: ";
    while (!(cin>>b))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Błąd!\nWprowadź 2 wartość: ";
    }
    t1[x-1]=a;
    t2[x-1]=b;
}
template<typename t>
tab<t> tab<t>::operator[](int i)
{
	cout<<t1[i]<<" "<<t2[i]<<endl;
	return *this;
}

int main()
{
    tab<int> t;
    t.data();
    cout<<"SPRAWDZANIE CZY 2 JEST W TABLICY\n";
    t.at(2);
    cout<<"UZUPEŁNIANIE!\n";
    t.fill(3,4);
    cout<<"EDYTOWANIE TABLICY\n";
    t.edit();
    cout<<"PO EDYCJI\n";
    t.data();
    cout<<"ITERATOR\n";
    t[1];
    cout<<"ZMIANA ROZMIARU TABLICY\n";
    cout<<"Do ilu skrócić: ";
    int x;
     while (!(cin>>x))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Błąd!\nDo ilu skrócić: ";
    }
    t.setcapacity(x);
    t.data();
    return 0;
}
