//nauka serializacji klas, bazy danych
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>//do serializacji vectora, bez tego jest problem z vectorem

using namespace std;

class Book
{
private:
    friend class boost::serialization::access;
    string title;
    int n;
    template<class Archive>
    void serialize(Archive &a, const unsigned version)
    {
        a & title & n;
    }
public:
    Book() {}
    Book(string t, int i) : title(t),n(i) {}
    void Show() { cout<<title<<" "<<n<<endl;}
};

class Reader
{
private:
    friend class boost::serialization::access;
    string name;
    template<class Archive>
    void serialize(Archive &a, const unsigned version)
    {
        a & name;
    }
public:
    Reader() {}
    Reader(string n) : name(n) {}
    void Show() {cout<<name<<endl;}
};

class Data
{
private:
    friend class boost::serialization::access;
    vector<Book> books;
    vector<Reader> readers;
    template<class Archive>
    void serialize(Archive &a, const unsigned version)
    {
        a & books & readers;
    }
public:
    Data() {}
    void AddBooks(Book &b) {books.push_back(b);}
    void AddReader(Reader &r) {readers.push_back(r);}
    void ShowBooks() {
        for (Book i : books)
            i.Show();
    }
    void ShowReader() {
        for (Reader i : readers)
            i.Show();
    }
    int SizeBooks() {return books.size();}
    int SizeReaders() {return readers.size();}
};

int main()
{
    //utworzenie bazy
    Book b1("aaaa",2);
    Book b2("bbbb",3);
    Reader r1("rrrr");
    Reader r2("kkkk");
    Data base;
    base.AddBooks(b1);
    base.AddBooks(b2);
    base.AddReader(r1);
    base.AddReader(r2);
    Book b3("wwww",46);
    base.AddBooks(b3);
    
    const string file="data.json"; //nazwa pliku
    //seriazizacja do pliku, w bloku dla wygody
    {
        std::ofstream outfile(file);
        boost::archive::text_oarchive archive(outfile);
        archive<<base;
    }
    Data restored;
    //deserializacja, w try/catch jakby nie było pliku żeby program się nie wyłączął
    try
    {
        std::ifstream infile(file);
        boost::archive::text_iarchive archive(infile);
        archive>>restored;
    }
    catch (...)
    {
        cout<<"Brak pliku!\n";
    }
    restored.ShowBooks();
    restored.ShowReader();
    cout<<"Readers = "<<restored.SizeReaders()<<endl;
    cout<<"Books = "<<restored.SizeBooks()<<endl;
    cin.get();
    return 0;
}
