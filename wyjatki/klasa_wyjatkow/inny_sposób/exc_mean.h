// exc_mean.h -- klasy wyjątków dla funkcji hmean() i gmean()
#include <iostream>
#include <stdexcept>

class bad : public std::logic_error
{
    private:
        double v1;
        double v2;
    public:
        bad(double a=0, double b=0) : std::logic_error("Błąd!\n"), v1(a), v2(b) {}
        double val1() const {return v1;}
        double val2() const {return v2;}
        virtual void mesg() const;
};
inline void bad::mesg() const
{
    std::cout<<what()<<"Użyte wartości: "<<v1<<", "<<v2<<std::endl;
}
class bad_hmean : public bad
{
    public:
        bad_hmean(double a = 0, double b = 0) : bad(a,b){}
        void mesg() const;
        const char* what() const throw() {return "Niepoprawne argumenty: a = -b\n";}
};

class bad_gmean : public bad
{
    public:
        bad_gmean(double a = 0, double b = 0) : bad(a,b) {}
        const char* what() const throw() {return "Argumenty funkcji powinny być >= 0\n";}
        void mesg() const;
};
