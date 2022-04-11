#ifndef CLASSIC_H
#define CLASSIC_H
class Cd
{
private:
    char performers[20];
    char label[20];
    int selections; //liczba utworów
    double playtime; //długość płyty w minutach
public:
    Cd(const char * s1, const char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const; //wyświetla dane płyty
    Cd & operator=(const Cd & d);
};
class Classic : public Cd
{
private:
    char * top;
public:
    Classic(const char * t, const char * s1, const char * s2, int n, double x);
    Classic(const char * t, const Cd & d);
    Classic(const Classic & cl);
    Classic();
    ~Classic();
    virtual void Report() const;
    Classic & operator=(const Classic & d);
};
#endif
