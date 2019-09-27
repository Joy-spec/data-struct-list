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
    //先处理prev然后再处理next,因为处理prev时使用了next
    pos->next->prev=p;
    p->prev=pos;
    p->next=pos->next;
    pos->next=p;
    if(head==tail) head=p;
    return p;
}
template <typename T>
list_node<T>* list<T>::erase(list_node<T> *pos) {
    if(head==tail) return nullptr;
    if(pos==tail) return nullptr;
    pos->prev->next=pos->next;
    pos->next->prev=pos->prev;
    if(pos==head) head=pos->next;
    delete pos;
}
template <typename T>
void list<T>::sort(list_node<T>* h,list_node<T>* t){
    if(h==t) return;
    T key=h->data;
    auto p=h->next;
    auto q=t->prev;
    while(true){
        while(p->data<=key) {
            //寻找第一个>key的值，或者查找到了终点
            p=p->next;
            if(p==t) break;//因为t是尾后迭代器，因此意味着所有元素<=key
        }
        while(q->data>key) {
            //寻找第一个<=key的值
            q=q->prev;
            if(q==h) break;
        }
        //q==p意味着在最后一个元素p和q相遇
        //q->next==p意味着在最后一个元素之前相遇
        if(q==p||q->next==p) break;
        T tmp=p->data;
        p->data=q->data;
        q->data=tmp;
    }
    T tmp=key;
    h->data=q->data;
    q->data=key;
    sort(h,q);
    sort(q->next,t);
}
template <typename T>
void list<T>::print() {
    std::cout<<"正序输出"<<std::endl;
    for(auto it=begin();it!=end();it=it->next){
        std::cout<<it->data<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"反序输出"<<std::endl;
    for(auto it=end()->prev;it!=end();it=it->prev){
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
    l.insert(p,4);
    l.print();
    l.sort();
    l.print();
    l.insert(l.begin(),6);
    l.erase(l.end()->prev->prev);
    l.print();
    l.sort();
    l.print();
}