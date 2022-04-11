#include <iostream>
using namespace std;
#include "classic.h"
void Bravo(const Cd & disk);
int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2=Classic("Sonata fortepianowa B-dur. Fantazja c-moll", "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd=&c1;
    cout<<"Bezpośrednie użycie obiektu:\n";
    c1.Report();
    cout<<endl;
    c2.Report();
    cout<<endl;
    cout<<"Użycie wskaźnika na cd:\n";
    pcd->Report();
    cout<<endl;
    pcd=&c2;
    pcd->Report();
    cout<<endl;
    cout<<"Wywołanie funkcji z argumentem w postaci referencji do typu Cd:\n";
    Bravo(c1);
    Bravo(c2);
    cout<<"Test przypisania:\n";
    Classic copy;
    copy=c2;
    copy.Report();
    cout<<endl;
    return 0;
}
void Bravo(const Cd & disk)
{
    disk.Report();
    cout<<endl;
}
