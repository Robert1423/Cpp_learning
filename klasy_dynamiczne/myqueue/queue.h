#ifndef QUEUE_H_
#define QUEUE_H_
class Customer
{
private:
    long arrive;    //czas dołączenia do kolejki
    int processtime;    //czas obsługi
public:
    Customer() {arrive=processtime=0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const {return processtime;};
};
typedef Customer Item;  //zdefiniowanie aliasu klasy jako Item
class Queue 
{
private:
    struct Node {Item item; struct Node * next;};   //zagnieżdżenie klasy Customer w klasi Queue, zasięg klasy
    enum {Q_SIZE=10};
    Node * front;       //wskaźnik na początek kolejki
    Node * rear;        //wskaźnik ogona kolejki
    int items;          //obecna liczba elementów kolejki
    const int qsize;    //maksymalna liczba elementów
    //lista inicjalizująca ustawia wartości składowych przed rozpoczęciem wykonywania konstruktora
    Queue(const Queue & q) : qsize(0) {};   //zablokowanie możliwości kopiowania obiektów + lista inicjalizująca
    Queue & operator=(const Queue & q) {return *this;}  //zablokowanie możliwości przypisania
public:
    Queue(int qs=Q_SIZE);   //tworzy kolejekę o pojemności qs
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item); //dodaje element na koniec kolejki
    bool dequeue(Item & item);      //zdejmuje element z początku kolejki
};
#endif
