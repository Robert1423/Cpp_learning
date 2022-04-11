#include <cstring>
#include <cctype>
#include "string2.h"
using std::cin;
using std::cout;
int String::num_strings=0;
int String::HowMany()
{
    return num_strings;
}
String::String(const char * s)
{
    len=std::strlen(s);
    str=new char[len+1];
    std::strcpy(str,s);
    num_strings++;
}
String::String()
{
    len=4;
    str=new char[1];    //new [] bo musi zgadzac się z destruktorem
    str[0]='\0';
    num_strings++;
}
String::String(const String & st)   //konstruktor kopiujący
{
    num_strings++;
    len=st.len;
    str=new char[len+1];
    std::strcpy(str,st.str);
}
String::~String()
{
    --num_strings;
    delete [] str;
}
void String::stringlow()
{
    for (int i=0; i<=len; i++)
        str[i]=std::tolower(str[i]);
}
void String::stringup()
{
    for (int i=0; i<=len; i++)
    str[i]=std::toupper(str[i]);
}
int String::has(char ch)
{
    int ile=0;
    for (int i=0; str[i]!='\0'; i++)
    {
        if (str[i]==ch)
            ile++;
    }
    return ile;
}
String operator+(const String & f, const String & s)
{
    String temp;
    temp.len=f.len+s.len;
    temp.str=new char[temp.len+1];
    std::strcpy(temp.str,f.str);
    std::strcat(temp.str, s.str);
    return temp;
}
String & String::operator=(const String & st)
{
    if (this==&st)
        return *this;
    delete [] str;
    len=st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}
String & String::operator=(const char * s)
{
    delete [] str;
    len=std::strlen(s);
    str=new char[len+1];
    std::strcpy(str,s);
    return *this;
}
char & String::operator[](int i)
{
    return str[i];
}
const char & String::operator[](int i) const
{
    return str[i];
}
bool operator<(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str,st2.str)<0);
}
bool operator>(const String & st1, const String & st2)
{
    return st1<st2;
}
bool operator==(const String & st1, const String & st2)
{
    return (std::strcmp(st1.str, st2.str)==0);
}
ostream & operator<<(ostream & os, const String & st)
{
    os<<st.str;
    return os;
}
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st=temp;
    while (is&&is.get()!='\n')
        continue;
    return is;
}
