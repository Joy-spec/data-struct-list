//
// Created by chen on 19-9-27.
//

#include<list>
#include<iostream>
#include<iterator>
using namespace std;
struct node{
    int coef;//ÏµÊý
    int expn;//ÃÝ
    friend istream& operator>>(istream& is,node& n);
    friend ostream& operator<<(ostream& os,node& n);
};
istream& operator>>(istream& is,node& n){
    is>>n.coef>>n.expn;
    return is;
}
ostream& operator<<(ostream& os,node& n){
    if(n.expn==0) os<<n.coef;
    else os<<n.coef<<"x^"<<n.expn<<"+";
}
list<node>& AddExpr(list<node> &l1,list<node> &l2){
    auto it2=l2.begin();
    auto it1=l1.begin();
    while(it1!=l1.end() && it2!=l2.end()){
        if(it1->expn < it2->expn){
            l1.insert(it1,*it2);
            ++it2;
        }
        if(it1->expn == it2->expn){
            it1->coef+=it2->coef;
            ++it1;
            ++it2;
        }
        if(it1->expn > it2->expn) ++it1;
    }
    if(it2!=l2.end()) l1.insert(l1.end(),it2,l2.end());
}
int main(){
    node tmp;
    list<node> l1;
    while(cin>>tmp){
        l1.push_back(tmp);
        if(tmp.expn==0) break;
    }
    list<node> l2;
    while(cin>>tmp){
        l2.push_back(tmp);
        if(tmp.expn==0) break;
    }
    AddExpr(l1,l2);
    for(auto &t:l1)cout<<t;
}
