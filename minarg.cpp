//wyszukiwanie minium z podanej listy argumentow
#include <iostream>

using namespace std;

template <typename T>
T minimum(T a, T b)
{
    return a < b ? a : b;
}
template <typename T1, typename... T>
T1 minimum(T1 a, T... args)
{
    return minimum(a,minimum(args...));
}

int main()
{
    auto x=minimum(5,4,6,3,7,2,0);
    cout<<x<<endl;
    return 0;
}
