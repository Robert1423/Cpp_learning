#include "emp.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
abstr_emp::abstr_emp() : fname("brak"), lname("brak"), job("brak") {}
abstr_emp::abstr_emp(const string & fn, const string & ln, const string & j)
    : fname(fn), lname(ln), job(j) {}
abstr_emp::~abstr_emp() {}
void abstr_emp::ShowAll() const
{
    cout<<"Nazwisko: "<<lname<<endl;
    cout<<"Imię: "<<fname<<endl;
    cout<<"Zawód: "<<job<<endl;
}
void abstr_emp::SetAll()
{
    cout<<"Podaj imię: ";
    getline(cin,fname);
    cout<<"Podaj nazwisko: ";
    getline(cin,lname);
    cout<<"Podaj zawód: ";
    getline(cin,job);
}
std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    os<<e.fname<<" "<<e.lname<<endl;
    return os;
}
employee::employee() : abstr_emp() {}
employee::employee(const string & fn, const string & ln, const string & j) : abstr_emp(fn,ln,j) {}
void employee::ShowAll() const
{
    cout<<"Pracownik:\n";
    abstr_emp::ShowAll();
}
void employee::SetAll()
{
    abstr_emp::SetAll();
}
manager::manager() : abstr_emp(), inchargeof(0) {}
manager::manager(const string & fn, const string & ln, const string & j, int ico) : abstr_emp(fn,ln,j), inchargeof(ico) {}
manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico) {}
manager::manager(const manager & m) : abstr_emp(m), inchargeof(m.inchargeof){}
void manager::ShowAll() const
{
    cout<<"Manager:\n";
    abstr_emp::ShowAll();
    cout<<"Zarządza "<<InChargeOf()<<" ludźmi.\n";
}
void manager::SetAll()
{
    abstr_emp::SetAll();
    cout<<"Podaj iloma ludźmi zarządza: ";
    cin>>inchargeof;
}
fink::fink() : abstr_emp(), reportsto("brak") {}
fink::fink(const std::string & fn, const std::string & ln,
         const std::string & j, const std::string & rpo) : abstr_emp(fn,ln,j), reportsto(rpo) {}
fink::fink(const abstr_emp & e, const std::string & rpo) : abstr_emp(e), reportsto(rpo) {}
fink::fink(const fink & e) : abstr_emp(e), reportsto(e.reportsto) {}
void fink::ShowAll() const
{
    cout<<"Donosiciel:\n";
    abstr_emp::ShowAll();
    cout<<"Donosi do: "<<reportsto<<endl;
}
void fink::SetAll()
{
    abstr_emp::SetAll();
    cout<<"Podaj do kogo donosi: ";
    getline(cin,reportsto);
}
highfink::highfink() : abstr_emp(), manager(), fink() {}
highfink::highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico) : abstr_emp(fn,ln,j), manager(fn,ln,j,ico), fink(fn,ln,j,rpo) {}
highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico) : abstr_emp(e), manager(e,ico), fink(e,rpo) {}
highfink::highfink(const fink & e, int ico) : abstr_emp(e), manager(e,ico), fink(e) {}
highfink::highfink(const manager & m, const std::string & rpo) : abstr_emp(m), manager(m), fink(m,rpo) {}
highfink::highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h) {}
void highfink::ShowAll() const
{
    cout<<"Główny donosicel:\n";
    abstr_emp::ShowAll();
    cout<<"Donosi do: "<<fink::ReportsTo()<<endl;
    cout<<"Zarządza "<<manager::InChargeOf()<<endl;
}
void highfink::SetAll()
{
    abstr_emp::SetAll();
    cout<<"Podaj komu donosi: ";
    string tempr;
    getline(cin,tempr);
    ReportsTo()=tempr;
    cout<<"Podaj iloma ludźmi zarządza: ";
    int temp;
    cin>>temp;
    InChargeOf()=temp;
}
