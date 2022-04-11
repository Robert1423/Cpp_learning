#include <iostream>
#include <cstring>
struct chaff
{
    char dross[20];
    int slag;
};
chaff buffor[512];
int main()
{
    using namespace std;
    chaff *p;
    cout<<"Adres buffora: "<<&buffor<<endl;
    cout<<"Adres końca buffora: "<<&buffor[511]<<endl;
    p=new (buffor) chaff[2];
    strcpy(p[0].dross,"miejscowe new");
    p[0].slag=1;
    strcpy(p[1].dross,p[0].dross);
    p[1].slag=2;
    chaff *pd;
    pd=new chaff[2];
    strcpy(pd[0].dross,"zwykłe new");
    pd[0].slag=3;
    strcpy(pd[1].dross,pd[0].dross);
    pd[1].slag=4;
    cout<<"Dane struktur:\n";
    cout<<"Struktury w bufforze:\n";
    for (int i=0; i<2; i++)
    {
        cout<<"Struktura w bufforze #"<<i+1<<":\n";
        cout<<"Pole dross: \""<<p[i].dross<<"\" o adresie: "<<&p[i].dross<<endl;
        cout<<"Pole slag: "<<p[i].slag<<" o adresie: "<<&p[i].slag<<endl;
    }
    cout<<"Struktury przydzielone zwykłym new:\n";
    for (int i=0; i<2; i++)
    {
        cout<<"Nowa struktura #"<<i+1<<":\n";
        cout<<"Pole dross: "<<pd[i].dross<<" o adresie: "<<&pd[i].dross<<endl;
        cout<<"Pole slag: "<<pd[i].slag<<" o adresie: "<<&pd[i].slag<<endl;
    }
    delete [] pd;
    return 0;
}
