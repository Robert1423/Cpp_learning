#include <iostream>
#include "emp.h"
using namespace std;
int main()
{
    employee em("Tadeusz","Hubert","Sprzedawca");
    cout<<endl<<em<<endl;
    em.ShowAll();
    manager ma("Amoriusz","Smoczewski","Malarz",5);
    cout<<endl<<ma<<endl;
    ma.ShowAll();
    fink fi("Maurycy","Olkuski","Hydraulik","Julian Bar");
    cout<<endl<<fi<<endl;
    fi.ShowAll();
    highfink hf(ma,"Jan Kudłaty");
    cout<<endl<<hf<<endl;
    hf.ShowAll();
    cout<<"\nWciśnij enter, aby przejść do następnego etapu:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();
    cout<<"\nUżywa wskaźnika abstr_emp *:\n";
    abstr_emp * tri[4] = {&em,&fi,&hf,&hf2};
    for (int i=0; i<4; i++)
    {
        cout<<endl;
        tri[i]->ShowAll();
    }
    return 0;
}
