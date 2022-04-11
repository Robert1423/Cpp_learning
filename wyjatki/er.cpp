// error4.cpp -- używa klas wyjątków
#include <iostream>
#include <cmath> // lub math.h; użytkownicy systemu UNIX mogą potrzebować opcji -lm
#include <stdexcept>
// prototypy funkcji
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Podaj dwie liczby: ";
    while (cin >> x >> y)
    {
        try {      // początek bloku try
            z = hmean(x, y);
            cout << "Średnia harmoniczna liczb " << x << " i " << y
                << " wynosi " << z << endl;
            cout << "Średnia geometryczna liczb " << x << " i " << y
                << " wynosi " << gmean(x, y) << endl;
            cout << "Podaj kolejną parę liczb <w, aby wyjść>: ";
        }   // koniec bloku try
        catch (std::invalid_argument & bg)   // początek bloku catch
        {
            cout<<bg.what();
            cout << "Spróbuj ponownie.\n";
            continue;
        }
        catch (std::out_of_range & hg)
        {
            cout << endl << hg.what();
            cout << "Użyte wartości: " << x << ", "
                << y<< endl;
            cout << "Niestety, to koniec zabawy.\n";
            break;
        } // koniec bloku catch
    }
    cout << "Koniec\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw std::invalid_argument("Niepoprawne argumenty\n");
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw std::out_of_range("Wartości poza dopuszczalnym zakresem\n");
    return std::sqrt(a * b);
}

