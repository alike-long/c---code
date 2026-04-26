#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
struct word
{
    string wd;
    int t;
};
struct rl
{
    bool operator ()(const word &a1,const word &a2) const{
        if (a1.t!=a2.t){
            return a1.t>a2.t;
        } else {
            return a1.wd<a2.wd;
        }
    }
};
int main(){
    string s;
    map<string,int> mp;
    set<word,rl> st;
    while (cin>>s){
        mp[s]++;
    }
    for (map<string,int>::iterator i=mp.begin();i!=mp.end();i++){
        word tp;
        tp.wd=i->first;
        tp.t=i->second;
        st.insert(tp);
    }
    for (set<word,rl>::iterator i=st.begin();i!=st.end();i++){
        cout<<i->wd<<" "<<i->t<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
struct Node {
    int v;
    struct Node * next; 
};
struct Node * init(){
    return NULL;
}
struct Node * print(struct Node * h){
    struct Node * t=h;
    while (t!=NULL){
        cout<<t->v<<" ";
        t=t->next;
    }
    return h;
}
struct Node * add(struct Node * h,int n){
    struct Node * noe =(struct Node *)malloc(sizeof(struct Node));
    noe->v=n;
    noe->next=NULL;
    struct Node * t=h;
    if (h==NULL){
        h=noe;
    }  else {
        while (t->next!=NULL){
            t=t->next;
        }
        t->next=noe;
    }
    return h;
}
struct Node * del(struct Node * h,int n){
    while (h!=NULL && h->v==n){
        struct Node * tm=h;
        h=h->next;
        free(tm);
    }
     if (h==NULL) return h;
    struct Node * pre=h;
    struct Node * t=h->next;
    while (t!=NULL){
        if (t->v==n){
            struct Node * tm=t;
            pre->next=t->next;
            t=t->next;
            free(tm);
        }
        else {
            pre=t;
            t=t->next;
        }
    }
    return  h;
}
int main(){
    struct Node * head=init();
    head=add(head,1);
    head=add(head,2);
    head=add(head,3);
    head=add(head,2);
    head=del(head,2);
    print(head);
}








// #include<bits/stdc++.h>
// using namespace std;
// struct Node{
//     int v;
//     struct Node *next;
// };
// struct Node * init(){
//     return NULL;
// }
// void print(struct Node * h){
//     struct Node * t=h;
//     while (t!=NULL){
//         cout<<t->v<<" ";
//         t=t->next;
//     }
// }
// struct Node * add(struct Node * h ,int n){
//     struct Node * noe=(struct Node*)malloc(sizeof (struct Node));
//     noe->v=n;
//     noe->next=NULL;
//     if (h==NULL){
//         h=noe;
//     } else {
//         struct Node *t=h;
//         while (t->next!=NULL){
//             t=t->next;
//         }
//         t->next=noe;
//     }
//     return h;
// }
// struct Node * ese(struct Node * h,int n){
//     while (h!=NULL && h->v==n){
//         struct Node * tm=h;
//         h=h->next;
//         free(tm);
//     }
//     if (h==NULL) return h;
//     struct Node * pre=h;
//     struct Node * t=h->next;
//     while (t!=NULL){
//         if (t->v==n){
//             struct Node * tm=t;
//             pre->next=t->next;
//             t=t->next;
//             free(tm);
//         } else {
//             pre=t;
//             t=t->next;
//         }
//     }
//     return h;
// }
// int main(){
//     struct Node * head=init();
//     head=add(head,1);
//     head=add(head,2);
//     head=add(head,3);
//     head=add(head,2);
//     head=ese(head,2);
//     print(head);
// }

// #include<bits/stdc++.h>