#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> Lotto(int p, int n);

int main()
{
    srand(time(0));
    cout<<"Losowanie liczb Lotto:\n";
    vector<int> winners;
    winners=Lotto(49,6);
    cout<<"Zwycięzskie liczby:\n";
    for (int i=0; i<winners.size(); i++)
        cout<<winners[i]<<" ";
    cout<<endl;
    return 0;
}

vector<int> Lotto(int p, int n)
{
    vector<int> pula;
    for (int i=1; i<=p; i++)
        pula.push_back(i);
    random_shuffle(pula.begin(),pula.end());
    vector<int> los;
    for (int i=0; i<n; i++)
        los.push_back(pula[i]);
    return los;
}
