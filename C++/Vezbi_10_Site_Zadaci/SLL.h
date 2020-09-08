#ifndef SLL_H
#define SLL_H

#include <iostream>
using namespace std;

template<class T> class SLLNode{
    T *data;
    SLLNode<T> *next;
public:
    SLLNode(T *d, SLLNode<T> *n){
        data=d;
        next=n;
    }
    void setData(const T *d){
        data=d;
    }
    void setNext(SLLNode<T> *n){
        next=n;
    }
    T *getData() const{
        return data;
    }
    SLLNode<T>* getNext() const{
        return next;
    }
    ~SLLNode(){
        delete next;
    }
};

template<class T> class SLL{
    SLLNode<T> *first;
public:
    SLL(){
        first=NULL;
    }
    SLLNode<T>* getFirst() const{
        return first;
    }
    void setFirst(T *d){
        SLLNode<T> *ins=new SLLNode<T>(d, NULL);
        first=ins;
    }
    void setLast(T *d){
        if(first!=NULL){
            SLLNode<T> *tmp=first;
            while(tmp->getNext()!=NULL){
                tmp=tmp->getNext();
            }
            SLLNode<T> *ins=new SLLNode<T>(d, nullptr);
            tmp->setNext(ins);

        }else{
            setFirst(d);
        }
    }
    ~SLL(){
        delete first;
    }
};

#endif // SLL_H
