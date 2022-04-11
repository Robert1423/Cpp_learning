#ifndef IP4_H_
#define IP4_H_
#endif // !ip4_H_
//deklaracja klasy opisujacej ip
#include <iostream>
class ip4
{
private:
    unsigned int o1;
    unsigned int o2;
    unsigned int o3;
    unsigned int o4;
    const char sep='.';
public:
    ip4(); //interaktywny konstruktor domyslny
    ip4(unsigned int a, unsigned int b, unsigned int c, unsigned int d); //konstruktor
    ip4(const ip4 & i); //konstruktor kopiuj¹cy
    ~ip4();
    void to_bin();//wyswietlenie binarne z podzia³em na oktety
    friend std::ostream & operator<<(std::ostream &os, const ip4 & i);
};
#endif