#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
using std::ostream;
using std::istream;
class String 
{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM=80;
public:
    String(const char * s); //konstruktor
    String(); //konstruktor domyślny
    String(const String &); //konstruktor kopiujący
    ~String();  //destruktor
    int length() const {return len;}
    void stringlow();
    void stringup();
    int has(char ch);
    String & operator=(const String &); //przeciążenie operatora, op = można przeciążyć tylko jako metodę klasę
    String & operator=(const char *);
    char & operator[](int i);
    friend String operator+(const String & f,const String & s);
    //Stri operator+(const char * s, const String & s)
    const char & operator[](int i) const;
    friend bool operator<(const String & st, const String & st2);
    friend bool operator>(const String & st1, const String & st2);
    friend bool operator==(const String & st1, const String & st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
    static int HowMany();
};
#endif
