#include <iostream>
#include "tv.h"
int main()
{
    using namespace std;
    Tv te;
    Remote p;
    cout<<"Ustawienia TV:\n";
    te.settings();
    te.remote_typ(p);
    cout<<endl;
    p.setting();
    p.onoff(te);
    if (te.ison())
        cout<<"\nWłączono telewizor!\n\n";
    else
        cout<<"TV wyłączono!\n";
    te.settings();
    cout<<endl;
    p.volup(te);
    p.chandown(te);
    p.set_mode(te);
    cout<<"Ustawienia TV:\n";
    te.settings();
    cout<<endl;
    te.remote_typ(p);
    p.setting();
    cout<<endl;
    te.question(p);
    cout<<endl;
    cout<<"Ustawienia TV:\n";
    te.settings();
    cout<<endl;
    p.setting();
    te.remote_typ(p);
    cout<<endl;
    p.setting();
    p.onoff(te);
    if (te.ison())
        cout<<"Włączono telewizor!\n";
    else
        cout<<"TV wyłączono!\n";
    return 0;
}
