//liczby armstronga
#include <iostream>
using namespace std;
int main()
{
    cout<<"3-cyfrowe liczby Armstronga: \n";
    for (int i=1; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            for (int k=0; k<9; k++)
            {
                int lic=i*100+j*10+k;
                int wyn=i*i*i+j*j*j+k*k*k;
                if (lic==wyn)
                    cout<<lic<<endl;
            }
        }
    }
    return 0;
}
