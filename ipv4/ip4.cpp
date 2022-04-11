#include "ip4.h"
#include <string>
#include <cctype>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

bool czyLiczba(string str) 
{
          for (char ch: str)
              if(!isdigit(ch)) return false;
          return true;
}

ip4::ip4()
{
    cout<<"Wprowadź adres IP: ";
    unsigned int x[4];
    int j=0;
    string ip;
    string temp="";
    cin>>ip;
    cout<<ip<<endl;
    for (int i=0; i<=ip.length(); i++)
    {
        if (isdigit(ip[i]))
            temp+=ip[i];
        else
        {
            if (czyLiczba(temp)&&temp!="")
            {
        	x[j]=stoi(temp);
        	j++;
            }
            temp="";
        }
    }
    for (int i=0; i<4; i++)
    {
        if (x[i]<0||x[i]>255)
        {
            j=0;
            break;
        }
    }
    if (j!=0)
    {
        o1=x[0];
        o2=x[1];
        o3=x[2];
        o4=x[3];
    }
    else
    {
    	cout<<"\nBłąd! IP wyzerowane!\n";
        o1=o2=o3=o4=0;
    }
}
ip4::ip4(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    o1=a;
    o2=b;
    o3=c;
    o4=d;
}
ip4::ip4(const ip4 & i)
{
    o1=i.o1;
    o2=i.o2;
    o3=i.o3;
    o4=i.o4;
}
ip4::~ip4() {}
void ip4::to_bin()
{
    string binary;
    unsigned int x[4]={o1,o2,o3,o4};
    for (int i=0; i<4; i++)
    {
        vector<int> bin;
        int j=0;
        while (x[i]!=0)
        {
            int t=x[i]%2;
            bin.push_back(t);
            x[i]/=2;
            j++;
        }
        if (j==8)
            reverse(bin.begin(),bin.end());
        else
        {
            for (j; j<8; j++)
                bin.push_back(0);
            reverse(bin.begin(),bin.end());
        }
        for (int a=0; a<8; a++)
            binary+=to_string(bin[a]);
        if (i<3)
            binary+=".";
    }
    cout<<binary<<endl;
}
std::ostream & operator<<(std::ostream &os, const ip4 & i)
{
    os<<i.o1<<i.sep<<i.o2<<i.sep<<i.o3<<i.sep<<i.o4;
    return os;
}
