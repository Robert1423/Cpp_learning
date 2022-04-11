//wisielec
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cctype>

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;
    using std::vector;
    using std::string;
    std::srand(std::time(0));
    vector<string> wordlist;
    cout<<"Próba wczytania danych z pliku\n";
    std::ifstream fin;
    fin.open("lista.txt");
    if (!fin.is_open())
    {
        cout<<"Otwarcie pliku nie powiodło się!\n";
        cout<<"Nastąpi zamknięcie programu\n";
        exit(EXIT_FAILURE);
    }
    string s;
    int count=0;
    if (fin.good())
    {
        while (fin>>s)
            wordlist.push_back(s);
        count++;
    }
    if (count==wordlist.size())
        cout<<"Wprowadzono "<<count<<" słów\n";
    else
        cout<<"Naliczono "<<count<<", ale Wprowadzono "<<wordlist.size()<<endl;
    if (fin.eof())
        cout<<"Koniec pliku.\n";
    else if (fin.fail())
        cout<<"Wczytywanie przerwane - błąd\n";
    else
        cout<<"Wczytywanie przerwane - przyczyna nieznana\n";
    if (wordlist.size()==0)
        cout<<"Nie wczytano żadnych danych\n";
    else
    {
        cout<<"Ilość wczytnych słów: "<<wordlist.size()<<endl;
        char play;
        cout << "Czy chcesz zagrać w grę słowną? <t/n> ";
        cin >> play;
        play = tolower(play);
        while (play == 't')
        {
            string target = wordlist[std::rand() % wordlist.size()];
            int length = target.length();
            string attempt(length, '-');
            string badchars;
            int guesses = 6;
            cout << "Zgadnij moje sekretne słowo. Ma ono " << length 
                << " liter. Możesz zgadywać\n"
                << "po jednej literze naraz. Możesz pomylić się " << guesses
                << " razy.\n";
            cout << "Twoje słowo: " << attempt << endl;
            while (guesses > 0 && attempt != target)
            {
                char letter;
                cout << "Zgadnij literę: ";
                cin >> letter;
                if (badchars.find(letter) != string::npos
                        || attempt.find(letter) != string::npos)
                {
                    cout << "Ta litera już była. Spróbuj innej.\n";
                    continue;
                }
                int loc = target.find(letter);
                if (loc == string::npos)
                {
                    cout << "Nie ma takiej litery!\n";
                    --guesses;
                    badchars += letter; // dodaje do ciągu
                }
                else
                {
                    cout << "Poprawna litera!\n";
                    attempt[loc] = letter;
                    // sprawdza, czy litera nie pojawia się ponownie w innym miejscu
                    loc = target.find(letter, loc + 1);
                    while (loc != string::npos)
                    {
                        attempt[loc] = letter;
                        loc = target.find(letter, loc + 1);
                    }
                }  
                cout << "Twoje słowo: " << attempt << endl;
                if (attempt != target)
                {
                    if (badchars.length() > 0)
                        cout << "Niepoprawne litery: " << badchars << endl;
                    cout << "Możesz pomylić się jeszcze " << guesses << " razy\n";
                }
            }
            if (guesses > 0)
                cout << "To już całe słowo!\n";
            else
                cout << "Niestety, to słowo to " << target << ".\n";

            cout << "Czy chcesz zagrać jeszcze raz? <t/n> ";
            cin >> play;
            play = tolower(play);
        }
    }
    cout << "Koniec\n";
    fin.close();

    return 0;
}
