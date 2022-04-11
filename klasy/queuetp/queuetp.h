#ifndef QUEUETP_H_
#define QUEUETP_H_
#include <string>
template <class T>
class QueueTP
{
private:
    struct Node {T item; struct Node * next;};
    enum {Q_SIZE=10};
    Node * front;
    Node * rear;
    int items;
    const int qsize;
    QueueTP(const QueueTP & q) : qsize(0) { }
    QueueTP & operator=(const QueueTP & q) { return *this;}
public:
    QueueTP(int qs=Q_SIZE);
    ~QueueTP();
    bool isempty() const {return items==0;}
    bool isfull() const {return items==qsize;}
    int queuecount() const {return items;}
    bool enqueue(const T & item);
    bool dequeue(T item);
};
template <class T>
QueueTP<T>::QueueTP(int qs) : qsize(qs)
{
    front=rear=NULL;
    items=0;
}
template <class T>
QueueTP<T>::~QueueTP()
{
    Node * temp;
    while (front!=NULL)
    {
        temp=front;
        front=front->next;
        delete temp;
    }
}
template <class T>
bool QueueTP<T>::enqueue(const T & item)
{
    if (isfull())
        return false;
    Node * add=new Node;
    add->item=item;
    add->next=NULL;
    items++;
    if (front==NULL)
        front=add;
    else
        rear->next=add;
    rear=add;
    return true;
}
template <class T>
bool QueueTP<T>::dequeue(T item)
{
    if (front==NULL)
        return false;
    item=front->item;
    items--;
    Node * temp=front;
    front=front->next;
    delete temp;
    if (items==0)
        rear=NULL;
    return true;
}
class Worker
{
    private:
        std::string fullname;
        long id;
    public:
        Worker() : fullname("brak"), id(0L) {}
        Worker(const std::string & s, long n)
            : fullname(s), id(n) {}
        ~Worker();
        void Set();
        void Show() const;
};
#endif
