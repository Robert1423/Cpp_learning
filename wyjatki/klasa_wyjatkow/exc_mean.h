// exc_mean.h -- klasy wyjątków dla funkcji hmean() i gmean()
#include <iostream>
#include <stdexcept>

class bad_hmean : public std::invalid_argument
{
    private:
        double v1;
        double v2;
    public:
        bad_hmean(double a = 0, double b = 0) : std::invalid_argument(" niepoprawne argumenty: a = -b\n"), v1(a), v2(b){}
        const char* what() const throw() {return "Funkcja hmean(): niepoprawne argumenty: a = -b\n";}
};

/*inline const char* bad_hmean::what() const throw();
{
    return "Funkcja hmean(): ";
}*/

class bad_gmean : public std::out_of_range
{
    public:
        double v1;
        double v2;
        bad_gmean(double a = 0, double b = 0) : std::out_of_range("Argumenty funkcji gmean() powinny być >= 0\n"), v1(a), v2(b) {}
        const char* what() const throw() {return "\nFunkcja gmean(): Argumenty funkcji gmean() powinny być >= 0\n";}
};
/*
inline const char* bad_gmean::what() const throw();
{
    return "Funkcja gmean(): ";
}*/

