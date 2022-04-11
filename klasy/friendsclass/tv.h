#ifndef TV_H_
#define TV_H_
//symulacja dzialania pilota
class Remote;
class Tv
{
public:
    friend class Remote; //klasa zaprzyjaźniona z klasą Tv, Remote może działać na klasie Tv
    enum {Off,On};
    enum {MinVal, MaxVal=20};
    enum {Antenna,Cable};
    enum {TV,DVD};
    Tv(int s=Off, int mc=125) : state(s), volume(5),
    maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state=(state==On)?Off:On;} //instrukcja warunkowa - jeżeli state ma wartość On zmienia na Off, i na odwrót
    bool ison() const {return state==On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode=(mode==Antenna)?Cable:Antenna;}
    void set_input() {input=(input==TV)?DVD:TV;}
    void settings() const; //wyśwoetla ustawienia
    void remote_typ(Remote & r); //ma działać tylko wtedy kiedy telewizor jest włączony
    void question(Remote & r);
private:
    int state; //włączony/wyłączony
    int volume; //głośność, założenie że można wyrazić cyframi
    int maxchannel; //maksymalna liczba kanałów
    int channel; //aktualny kanał
    int mode; //antena czy kablówka
    int input; //tv czy dvd
};
class Remote
{
private:
    int mode; //kontroluje TV czy DVD
    int type; //Normalny lub interaktywny;
public:
    friend class Tv;
    enum {Normal,Interactive};
    Remote(int m=Tv::TV, int t=Normal) : mode(m), type(t) {}
    bool volup(Tv & t) {return t.volup();}
    bool voldown(Tv & t) {return t.voldown();}
    void onoff(Tv & t) {return t.onoff();}
    void chanup(Tv & t) {return t.chanup();}
    void chandown(Tv & t) {return t.chandown();}
    void set_chan(Tv & t, int c) {t.channel=c;}
    void set_mode(Tv & t) {t.set_mode();}
    void set_input(Tv & t) {t.set_input();}
    void set_typ() {type=(type==Normal)?Interactive:Normal;}
    void setting() const;
    char q_a();
    bool Wtype() const {return type==Interactive;}
};
#endif
