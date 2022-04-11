#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

void wpisz(const char * file, vector<string> & x);//dane z pliku do kontenera
void Show(const vector<string> & x);//pokazuje zawartość kontenera
vector<string> Scal(vector<string> & x1, vector<string> & x2);//łączy dwa kontenery i usuwa powtórki
void DoPliku(const char * file, vector<string> & x);//zapisuje do pliku

int main()
{
    using namespace std;
    vector<string> bolek;
    vector<string> lolek;
    wpisz("bolek.dat",bolek);
    wpisz("lolek.dat",lolek);
    cout<<"Dane z bolek.dat:\n";
    Show(bolek);
    cout<<"Dane z lolek.dat:\n";
    Show(lolek);
    vector<string> razem=Scal(bolek,lolek);
    cout<<"Dane posortowane:\n";
    Show(razem);
    DoPliku("bolilol.dat",razem);
    return 0;
}
 
 void wpisz(const char * file, vector<string> & x)
 {
     cout<<"Próba otwarcia pliku "<<file<<"\n";
     ifstream fin;
     fin.open(file,ios_base::in|ios_base::binary);
     if (!fin.is_open())
     {
         cerr<<"Nie udało się otworzyć pliku "<<file<<endl;
         exit(EXIT_FAILURE);
     }
     int count=0;
     while (!fin.eof())
     {
         string temp;
         getline(fin,temp);
         if (temp.size()>1)
         {
            count++;
            x.push_back(temp);
         }
     }
     if (fin.eof())
         cout<<"Kopiowanie z pliku "<<file<<" zakończone"<<endl;
     sort(x.begin(),x.end());
     fin.close();
 }
 
 void Show(const vector<string> & x)
{
    if (x.size()==0)
        cout<<"\nBrak!\n";
    else
    {
        for (int i=0; i<x.size(); i++)
            cout<<i+1<<"#\t"<<x[i]<<"\n";
    }
}

vector<string> Scal(vector<string> & x1, vector<string> & x2)
{
    vector<string> w;
    copy(x1.begin(),x1.end(),back_insert_iterator<vector<string>>(w));
    copy(x2.begin(),x2.end(),back_insert_iterator<vector<string>>(w));
    sort(w.begin(),w.end());
    auto last=unique(w.begin(),w.end());
    w.erase(last,w.end());
    return w;
}

void DoPliku(const char * file, vector<string> & x)
{
    cout<<"Próba utworzenia pliku "<<file<<endl;
    ofstream fout;
    fout.open(file,ios_base::out|ios_base::binary);
    if (!fout.is_open())
    {
        cerr<<"Nie udało się utworzyć pliku "<<file;
        exit(EXIT_FAILURE);
    }
    else
        cout<<"Utworzono plik "<<file<<endl;
    for (int i=0; i<x.size(); i++)
        fout<<x[i]<<endl;
    cout<<"Zakończono tworzenie pliku, nastąpi zamknięcie pliku "<<file<<endl;
    fout.close();
}
