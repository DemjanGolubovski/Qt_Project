//#include <iostream>
//#include "SLL.h"

//using namespace std;
//template <class T> SLLNode<T>::SLLNode(T d, SLLNode<T> *n){
//    data=d;
//    next=n;
//}
//template <class T> void SLLNode<T>::setData(const T d){
//    data=d;
//}
//template <class T> void SLLNode<T>::setNext(SLLNode<T> *n){
//    next=n;
//}
//template <class T> T SLLNode<T>::getData() const{
//    return data;
//}
//template <class T> SLLNode<T>* SLLNode<T>::getNext() const{
//    return next;
//}

//template <class T> SLL<T>::SLL(){
//    first=NULL;
//}
//template <class T> SLLNode<T>* SLL<T>::getFirst() const{
//    return first;
//}
//template <class T> void SLL<T>::setFirst(const T d){
//    SLLNode<T> *ins=new SLLNode<T>(d, NULL);
//    first=ins;
//}
//template <class T> void SLL<T>::setLast(const T d){
//    if(first!=NULL){
//        SLLNode<T> *tmp=first;
//        while(tmp->getNext()!=NULL){
//            tmp=tmp->getNext();
//        }
//        SLLNode<T> *ins=new SLLNode<T>(d, nullptr);
//        tmp->setNext(ins);

//    }else{
//        setFirst(d);
//    }
//}
//template <class T> void SLL<T>::display(){
//    SLLNode<T> *tmp=first;
//    while(tmp!=NULL){
//        cout<<tmp->getData()<<" ";
//        tmp=tmp->getNext();
//    }
//    cout<<endl;
//}
//template <class T> void SLL<T>::deleteNode(T d){
//    if(first->getData()==d){
//        SLLNode<T> *f=first;
//        first=first->getNext();
//        delete f;
//    }else{
//        SLLNode<T> *tmp=first;
//        while(tmp->getNext()!=NULL && (tmp->getNext())->getData()!=d){
//            tmp=tmp->getNext();
//        }
//        if(tmp->getNext()!=NULL){
//            SLLNode<T> *del=tmp->getNext();
//            tmp->setNext(tmp->getNext()->getNext());
//            delete del;
//        }
//    }
//}
