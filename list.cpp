#include "list.h"

//
// Created by chen on 19-9-25.
//
template <typename T>
list_node<T>* list<T>::begin() {
    return head;
}
template <typename T>
list_node<T>* list<T>::end(){
    return tail;
}
template <typename T>
list_node<T> * list<T>::insert(list_node<T> *pos, T t) {
    list_node<T>* p=new list_node<T>(t);
    p->next=pos->next;
    pos->next=p;
    if(head==tail) head=p;
    return p;
}
template <typename T>
void list<T>::sort(){


}
template <typename T>
void list<T>::print() {
    for(auto it=begin();it!=end();it=it->next){
        std::cout<<it->data<<" ";
    }
    std::cout<<std::endl;
}
int main(){
    list<int> l;
    auto p=l.begin();
    p=l.insert(p,1);
    p=l.insert(p,5);
    p=l.insert(p,3);
    p=l.insert(p,2);
    p=l.insert(p,4);
    l.print();
}