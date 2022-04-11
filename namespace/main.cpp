#include <iostream>
#include "namsal.h"
int main()
{
    using namespace SALES;
    Sales s1;
    Sales s2;
    double tab[2]={2.24,1.15};
    setSales(s1,tab,2);
    setSales(s2);
    std::cout<<"Zbiór 1:\n";
    showSales(s1);
    std::cout<<"Zbiór 2:\n";
    showSales(s2);
    std::cout<<"\nGOTOWE\n";
    return 0;
}
