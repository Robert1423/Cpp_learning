#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR=60;
bool newcustomer(double x);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));
    cout<<"Studium przypadku: bankomat Banku Stu Kas\n";
    int x;
    long wynik=0;
    cout<<"Ile powtórzeń symulacji wykonać: ";
    cin>>x;
    int * tab = new int[x];
    for (int i=0; i<x; i++)
    {
    cout<<"Symulacja nr "<<i+1<<":\n";
    int qs=10;
    //cout<<"Maksymalną długość kolejki: "<<qs<<endl;;
    Queue line(qs);
    Queue line2(qs);
    //cout<<"Symulowany czas (w godzinach): ";
    //cout<<"Liczba kolejek: 2\n";
    int hours=100;
    //cout<<hours<<endl;
    long cyclelimit=MIN_PER_HR*hours;
    //cout<<"Podaj średnią liczbę klientów na godzinę: ";
    double perhour=0;
    //cin>>perhour;
     double sred=0;
     //int count=0;
    do
    {
    double min_per_cust;
    min_per_cust=MIN_PER_HR/perhour;
    Item temp1;
    Item temp2;
    long turnaways=0;
    long customers=0;
    long served=0;
    long sum_line=0;
    int wait_time=0;
    long line_wait=0;
        //cout<<"Średnia liczba klientów na godzinę: "<<perhour<<endl;
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))  // mamy nowego chętnego
        {
            if (line.queuecount()<=line2.queuecount())
            {
                if (line.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp1.set(cycle);        // czas przybycia = nr cyklu
                    line.enqueue(temp1);     // dołączenie klienta do kolejki
                }
            }
            else
            {
                if (line2.isfull())
                    turnaways++;
                else
                {
                    customers++;
                    temp2.set(cycle);        // czas przybycia = nr cyklu
                    line2.enqueue(temp2);     // dołączenie klienta do kolejki
                }
            }
        }
            if (wait_time <= 0)
            {
                if (!line.isempty())
                {
                    line.dequeue (temp1);        // następny do obsłużenia
                    wait_time = temp1.ptime();   // czas obsługi = wait_time
                    line_wait += cycle - temp1.when();
                    served++;
                }
                if (!line2.isempty())
                {
                    line2.dequeue (temp2);        // następny do obsłużenia
                    wait_time = temp2.ptime();   // czas obsługi = wait_time
                    line_wait += cycle - temp2.when();
                    served++;
                }
            }
            if (wait_time > 0)
                wait_time--;
            sum_line += line.queuecount();
            sum_line += line2.queuecount();
    }
    if (customers>0)
    {
        cout<<" liczba klientów przyjętych: "<<customers<<endl;
        cout<<"liczba klientów obsłużonych: "<<served<<endl;
        cout<<" liczba klientów odesłanych: "<<turnaways<<endl;
        cout<<"    średnia długość kolejki: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
        cout << (double) sum_line / cyclelimit << endl;
        cout << "    średni czas oczekiwania: "
            << (double) line_wait / served << " minut\n";
        sred=(double) line_wait / served;
    }
    else
        cout<<"Brak klientów!\n";
    if (sred<0.0)
    {
        cout<<"Błędne obliczenia\n";
        continue;
    }
    if (sred<1.0)
        perhour++;
    }
    while (sred<=1.0);
    cout<<"Aby średni czas oczekiwania nie przekraczał 1 minuty, średnia\n"
        <<"liczba klientów na godzinę nie może przekroczyć: "<<perhour-1<<endl;
        cin.get();
    tab[i]=perhour;
    wynik+=tab[i];
    }
    system("clear");
    cout<<"Podsumowanie prób:\n\n";
    for (int i=0; i<x; i++)
        cout<<"Średnia liczba klientów w próbie "<<i+1<<"# = "<<tab[i]<<endl;
    wynik/=x;
    cout<<"\nŚrednia liczba klientów na godzinę przy "<<x<<" powtórzeniach symulacji\n"
        <<"tak, aby czas oczekiwania nie przekroczył 1 minuty wynosi "<<wynik<<endl;
    cout<<"Gotowe!\n";
    return 0;
}
bool newcustomer(double x)
{
    return (std::rand()*x/RAND_MAX<1);
}
