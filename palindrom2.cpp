//funkcja sprawdzająca czy palindrom, z wielkimi literami
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

char toLower(char ch) {return tolower(ch);}
bool ispali(string & s);

int main()
{
    string str;
    cout<<"Podaj ciąg znaków: <koniec, aby zakończyć>\n";
    getline(cin,str);
    while (str!="koniec")
    {
        if (str.size()>0)
        {
            cout<<"Podany ciąg znaków \""<<str;
            if (ispali(str))
                cout<<"\" to palindrom\n";
            else
                cout<<"\" nie jest palindromem\n";
        }
        else
            cout<<"Nie wprowadzono żadnego znaku! Spróbuj jeszcze raz!\n";
        cout<<"Podaj ciąg znaków: <koniec, aby zakończyć>\n";
        getline(cin,str);
    }
    return 0;
}

bool ispali(string & s)
{
    for (int i=0; i<s.size(); i++)
    {
        if (!isalpha(s[i]))
        {
            s.erase(i,1);
        }
    }
    transform(s.begin(),s.end(),s.begin(),toLower);
    int b=0;
    int rb=s.size()-1;
    while (b!=rb)
    {
        if (s[b]!=s[rb])
            return false;
        b++;
        rb--;
    }
    return true;
}
