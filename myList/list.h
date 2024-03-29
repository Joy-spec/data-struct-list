#ifndef LIST
#define LIST

#include <iostream>
#include <memory>
template <typename T> struct list_node{
    T data;
    list_node<T>* next;
    list_node<T>* prev;
    list_node(T t):data(t),next(nullptr),prev(nullptr){}
    list_node()= default;
};

template<typename T> class list{
    list_node<T> *blank=new list_node<T>;
    list_node<T> *head,*tail;
    void sort(list_node<T>* h,list_node<T>* t);
    public:
    list_node<T>* begin();
    list_node<T>* end();
    list():head(blank),tail(blank){
        blank->next= blank;
        blank->prev= blank;
    };
    //返回指向新添加的第一个元素的指针
    list_node<T>* insert(list_node<T>* pos,T t);
    //返回指向最后一个被删除元素的下一个元素的指针
    list_node<T>* erase(list_node<T>* pos);
    void sort(){
        sort(head,tail);
    }
    void print();
    ~list(){
        auto it=begin();
        while(it!=end()){
            auto p=it->next;
            delete it;
            it=p;
        }
        delete tail;
    }

};
#endif
