//do mierzenia czasu clock_t start=clock();
//do zakończenia pomiaru clocl_t end=clock; cout<<(double)(end-start)/CLOCKS_PER_SEC wszystko z biblioteki ctime
#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>

const int SIZE=10000000;

using namespace std;

int main()
{
    srand(time(0));
    cout<<"Rozmiar obiektów = "<<SIZE<<endl;
    vector<int> vi0(SIZE);
    for (auto v : vi0)
        v=rand();
    vector<int> vi(vi0.begin(),vi0.end());
    list<int> li(SIZE);
    copy(vi0.begin(),vi0.end(),li.begin());
    clock_t startvi=clock();
    sort(vi.begin(),vi.end());
    clock_t endvi=clock();
    cout<<"Przybliżony czas sortowania vektora vi funkcją sort(): ";
    cout<<(double)(endvi-startvi)/CLOCKS_PER_SEC<<endl;;
    clock_t startli=clock();
    li.sort();
    clock_t endli=clock();
    cout<<"Przybliżony czas sortowania listy li metodą sort(): ";
    cout<<(double)(endli-startli)/CLOCKS_PER_SEC<<endl;
    cout<<"Przywrócenie oryginalnej zawartości li\n";
    copy(vi0.begin(),vi0.end(),li.begin());
    clock_t start=clock();
    copy(li.begin(),li.end(),vi.begin());
    sort(vi.begin(),vi.end());
    copy(vi.begin(),vi.end(),li.begin());
    clock_t end=clock();
    cout<<"Przybliżony czas skopiowania li do vi, sortowania vi i skopiowania vi do li: ";
    cout<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
