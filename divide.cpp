//oblicza sume liczb podzielnych przez 3 i 5 do wartosci podanej
#include <iostream>
#include <limits>

bool czydzieli(int x); //sprawdza czy liczba jest podzielna przez 3 i 5

using namespace std;

int main()
{
    int x, sum;
    sum=0;
    cout<<"Wprowadź wartoś graniczną: "<<endl;
    while (!(cin>>x))
    {
        cout<<"Błąd! Jeszcze raz: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    for (int i=0; i<=x; i++)
    {
        if (czydzieli(i))
            sum+=i;
    }
    cout<<"Suma liczb podzielnych przez 3 i 5 do liczby "<<x<<": "<<sum<<endl;
    cin.get();
    cin.get();
    return 0;
}

bool czydzieli(int x)
{
    if (x%3==0 || x%5==0)
        return true;
    else
        return false;
}
