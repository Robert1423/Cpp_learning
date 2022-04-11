#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

void ShowStr(const std::string & s) {std::cout<<s<<std::endl;}
void GetStrs(std::ifstream & f, std::vector<std::string> & v);

class Store
{
private:
    std::ofstream & os;
public:
    Store(std::ofstream & o) : os(o) {}
    void operator()(const std::string & s);
};

int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;
    //pobierz łańcuchy
    cout<<"Podaj łańcuchy (aby zakończyć, wprowadź pusty wiersz):\n";
    while (getline(cin,temp)&&temp[0]!='\0')
        vostr.push_back(temp);
    cout<<"Oto Twoje dane wejściowe.\n";
    for_each(vostr.begin(),vostr.end(),ShowStr);
    //zapisz w pliku
    ofstream fout("łańcuchy.dat",ios_base::out|ios_base::binary);
    for_each(vostr.begin(),vostr.end(),Store(fout));
    fout.close();
    //odzczyt z pliku
    vector<string> vistr;
    ifstream fin("łańcuchy.dat",ios_base::in|ios_base::binary);
    if (!fin.is_open())
    {
        cerr<<"Nie można otworzyć pliku do odczytu.\n";
        exit(EXIT_FAILURE);
    }
    GetStrs(fin,vistr);
    cout<<"\nOto łańcuchy odczytane z pliku:\n";
    for_each(vistr.begin(),vistr.end(),ShowStr);
    return 0;
}

void GetStrs(std::ifstream & f, std::vector<std::string> & v)
{
    char ch;
    std::size_t len;
    while (f.peek()&&!f.eof())
    {
        std::string temp;
        f.read((char *) &len, sizeof(std::size_t));
        for (int i=0; i<len; i++)
        {
            f.read(&ch,sizeof(char));
            temp.push_back(ch);
        }
        v.push_back(temp);
    }
}

void Store::operator()(const std::string & s)
{
    std::size_t len=s.size();
    os.write((char *)&len, sizeof(std::size_t));
    os.write(s.data(), len);
}
