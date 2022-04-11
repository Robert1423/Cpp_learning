//rozszerzenie klasy IP
#ifdef IP4_H_
#define IP4_H_
#endif // IP4_H_

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
	//konstruktory
    ip4();
    ip4(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
    ip4(const ip4 & i);
    ~ip4(); //destruktor
    void to_bin(); //binarnie
    void zakres(ip4 i1); //wyswietlenie zakresu ip
    friend std::ostream & operator<<(std::ostream &os, const ip4 & i);
};
#endif