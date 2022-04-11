//ip wyswietlanie danych z klasy
#include "ip4.h"
#include <iostream>

using namespace std;

int main()
{
    ip4 i;
    unsigned int a,b,c,d;
    a=168;
    b=192;
    c=0;
    d=3;
    ip4 i2(a,b,c,d);
    cout<<"IP:\t"<<i<<"\nBinarnie:\t"<<endl;
    i.to_bin();
    cout<<"IP:\t"<<i2<<"\nBinarnie:\t"<<endl;
    i2.to_bin();
    ip4 i3=i2;
    cout<<"Oryginał\t"<<i2<<"\tKopia:\t"<<i3<<endl;
    return 0;
}
