//funkcja logiczna sprawdzająca czy ciąg jest palindromem, bez wielkich liter i białych znaków
#include <iostream>
#include <string>
#include <cctype>
#include <iterator>
using namespace std;

bool ispali(string & s);
bool sprawdz(string & s);

int main()
{
    string str;
    cout<<"Podaj ciąg znaków, bez wielkich liter i białych znaków: <koniec, aby zakończyć>\n";
    while (getline(cin,str)&&str!="koniec")
    {
        cout<<"\nPodano: "<<str<<endl;
        if (sprawdz(str))
        {
            str.clear();
            cout<<"Spróbuj jeszcze raz:\n";
            cout<<"Podaj ciąg znaków, bez wielkich liter i białych znaków: <koniec, aby zakończyć>\n";
            continue;
        }
        if (ispali(str))
            cout<<"Podany ciąg znaków jest palindromem\n";
        else
            cout<<"To nie jest palindrom.\n";
        cout<<"\nPodaj ciąg znaków, bez wielkich liter i białych znaków: <koniec, aby zakończyć>\n";
    }
    return 0;
}
bool sprawdz(string & s)
{
    for (int i=0; i<s.size(); i++)
    {
        if (isupper(s[i])||!isalpha(s[i]))
        {
            cout<<"Błąd! \""<<s[i];
            if (isupper(s[i]))
                cout<<"\" jest wielką literą!\n";
            if (!isalpha(s[i]))
                cout<<"\" nie jest literą!\n";
            return true;
        }
    }
    return false;
}
bool ispali(string & s)
{
    int b=0;
    int rb=s.size()-1;
    while (s[b]!=s[rb])
    {
        if (s[b]!=s[rb])
            return false;
        b++;
        rb--;
    }
    return true;
}
