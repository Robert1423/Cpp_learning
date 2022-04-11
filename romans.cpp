//konwersja na liczbe rzymska
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

string rzym(int x);

int main()
{
    int x;
    cout<<"Podaj liczbę całkowitą: (max. 4999) ";
    while(!(cin>>x)||x>4999)
    {
        cout<<"Błąd! Spróbuj jeszcze raz: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"Lczba rzymska: "<<rzym(x)<<endl;
    return 0;
}
//moje rozwiazanie
string rzym(int x)
{
    vector<pair<int, string>> r
    {
      { 1000, "M" },{ 900, "CM" },{800,"DCCC"},{700,"DCC"},{600,"DC"},
      { 500, "D" },{ 400, "CD" },{300,"CCC"},{200,"CC"},{ 100, "C" },
      { 90, "XC" },{80,"LXXX"},{70,"LXX"},{60,"LX"},{ 50, "L" },{ 40, "XL" },
      {20,"XX"},{30,"XXX"},{ 10, "X" },{ 9, "IX" },{ 8, "VII"},{7,"VII"}, {6,"VI"},
      { 5, "V" },{ 4, "IV" }, {3,"III"},{2,"II"}, { 1, "I" }
   };
   string result="";
   int d=10;
   int y;
   for (int i=2; i<to_string(x).length(); i++)
       d*=10;
   while (x>0)
   {
       y=x%d;
       x-=y;
       if (x>1000)
       {
           int i=x/1000;
           for (int j=0; j<i; j++)
               result+=r[0].second;
       }
       if (x%d==0)
       {
           for (int i=0; i<r.size(); i++)
           {
               if (x==r[i].first)
                   result+=r[i].second;
           }
       }
       x=y;
       d/=10;
   }
   return result;
}
//Łatwiejsze rozwiązanie ze wzorca

/*
std::string to_roman(unsigned int value)
{
   std::vector<std::pair<unsigned int, char const*>> roman
   {
      { 1000, "M" },{ 900, "CM" },
      { 500, "D" },{ 400, "CD" },
      { 100, "C" },{ 90, "XC" },
      { 50, "L" },{ 40, "XL" },
      { 10, "X" },{ 9, "IX" },
      { 5, "V" },{ 4, "IV" },
      { 1, "I" }
   };

   std::string result;
   for (auto const & kvp : roman)
   {
      while (value >= kvp.first)
      {
         result += kvp.second;
         value -= kvp.first;
      }
   }

   return result;
}*/
