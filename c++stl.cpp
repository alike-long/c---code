#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<list>
#include<numeric>
#include<functional>
#include<cmath>
#include<string.h>
using namespace std;
                                        
//     int a;
//    cin>>dec>>a;
//    cout<<dec<<a<<endl;
//    cout<<hex<<a<<endl;
//    cout<<oct<<a<<endl;
//     double b;
//     cin>>b;
//     cout<<setprecision(6)<<b<<endl;
//     cout<<fixed<<setprecision(6)<<b<<'\n'<<setiosflags(ios::fixed)<<setprecision(6)<<b;
    // char s[11];
    // int w;
    // cin.width(5);
    // while (cin>>s){
    //     cout<<setw(w++);
    //     cout<<s<<endl;
    //     cin.width(5);
    // }
    // double x;
    // cin>>x;
    // cout<<fixed<<setprecision(6);
    // cout<<setw(12)<<left<<setfill('*')<<x<<endl;
    // cout<<setw(12)<<right<<setfill('*')<<x<<endl;
    // cout<<"zyk "<<zhenhua<<" shi "<<"shuaige";

// template <class T>
// T s(T a,T b){
//     return (a+b)/2;
// }
// template <class T,int size>
// class asd{
//     public:
//     T a[size];
// };
// int main(){
//     int m=12,n=13;
//     cout<<s(m,n)<<endl;
//     cout<<fixed<<setprecision(8)<< s<double>(m,n)<<endl;
//     asd<int,10> ob;
//     ob.a[0]=1;
//     for (int i=0;i<10;i++){
//         ob.a[i+1]=ob.a[i]+1;
//         cout<<ob.a[i]<<" ";
//     }
// }

// class ffd{
//     public:
//     static bool cmp(const int & a1,const int & a2){
//         return a1%10<a2%10;
//     }
//     static bool  asd(const int & a){
//         if (a%10==4){
//             return true;
//         } else {
//             return false;
//         }
//     }
// };
// int main(){
//     vector <int> a;
//     for (int i=0;i<5;i++){
//         int g;
//         cin>>g;
//         a.push_back(g);
//     }
//     ffd s;
//     sort(a.begin(),a.begin()+5,ffd::cmp);
//     for (const auto & i:a){
//         cout<<i<<" ";
//     }
//     auto b=find_if(a.begin(),a.begin()+5,ffd::asd);
//     if (b!=a.end()){
//         cout<<*b;
//     }
// }

// class kjh{
//     private:
//         char s[100];
//     public:
//         kjh(){s[0]='\0';}
//         kjh & operator=(const char* a){
//             strcpy(s,a);
//             return *this;
//         }
//         const char* get() const{
//             return s;
//         }
// };
// int main(){
//     kjh d;
//     d="asdf";
//     cout<<d.get();
// }
// template <class T>
// class jhg{
//     public:
//     T s;
//     jhg(){}
//     jhg(T a):s(a){}
//     jhg<T> & operator=(const T & a){
//         s=a;
//         return *this;
//     }
//     T get() const{
//         return s;
//     }
// };
// int main(){
//     jhg<int> s;
//     s=123;
//     cout<<s.get();
// }

// ostream & odd(ostream & a){
//     a<<"gfd";
//     return a;
// }
// int main(){
//    cout<<odd<<"sda";
// }

//    string a;
//     int n=0,l=0;
//     getline(cin,a);
//     istringstream idd(a);
//     string t;
//     string g="secret";
//     while (idd>>t){
//         l++;
//         if (t.compare(g)==0){
//             n=1;
//             cout<<"secret"<<"is"<<l<<endl;
//         }
//     }

// vector<int > a;
//     int g;
//     for (int i=0;i<5;i++){
//         cin>>g;
//         a.push_back(g);
//     }
//     a.push_back(5);
//     a.insert(a.begin(),1,1);
//     a.pop_back();
//     a.erase(a.begin(),a.begin()+3);
//     vector<int> b;
//     b.push_back(4);
//     a.swap(b);
//     a.clear();
//     for (const auto & i:a){
//         cout<<i<<" ";
//     }
//     cout<<endl;
//      for (const auto & i:b){
//         cout<<i<<" ";
//     }

// list <int> a;
//     for (int i=0;i<5;i++){
//         a.push_back(i);
//     }
//     a.push_back(1);
//     a.push_back(2);
//     a.sort();
//     a.unique();
//     a.reverse();
//     list <int> b;
//     b.push_back(6);
//     b.push_back(5);
//     b.push_back(6);
//     b.push_back(5);
//     auto f=b.begin();
//     advance(f,1);
//     auto e=b.end();
//     advance(e,4);
//     a.splice(a.end(),b,f,e);
//     for (const auto & i:a){
//         cout<<i<<" ";
//     }

//  string a,b,c,d;
//    a="hello";
//    istringstream idd(a);
//    idd>>c;
//    cout<<c<<endl;
//    ostringstream odd;
//    odd<<a<<endl;
//    b=" world";
//    a+=b;
//    a.insert(0,"hi ");
//    a.erase(0,3);
//    a.insert(0,b);
//    a.swap(b);
//    a.clear();
//    a.swap(b);
//    const char *str=a.c_str();
//    cout<<str<<endl;
//    cout<<a.find("he")<<endl;
//     cout<<a.compare(b)<<endl;
//    cout<<a<<" "<<a.length()<<endl;
//    for (const auto & i:a){
//     cout<<i<<" ";
//    }

// class han{
//     public:
//     int n;
//     function<int(int,int)> wp=[](int a,int b){
//         return pow(a,3)+b;
//     };
// };
// int main(){
//    vector <int> a;
//    for (int i=0;i<5;i++){
//     a.push_back(i);
//    }
//    han Han;
//    int re=accumulate(a.begin(),a.end(),0,Han.wp);
//    cout<<re;
// } 

// using namespace std;
// int main(){
//     string k;
//     getline(cin,k);
//     ostringstream idd;
//     idd<<k;
//     string h=idd.str();
//     cout<<h<<endl;
//     istringstream idi(k);
//     string j,s,d,f;
//     idi>>j>>s>>d>>f;
//     cout<<j<<s<<d<<f;
// }
// string a,b=("hello");
//     a=b;
//     a+=" world";
//     a.clear();
//     a="abcd";
//     const char* c=a.c_str();
//     cout<<c<<endl;
//     cout<<a.length();
//     cout<<a<<endl;
//     a.append("efhijk");
//     cout<<a<<endl;
//     a.push_back('l');
//     cout<<a<<endl;
//     string k="1233fghfgj";
//     a.insert(0,k,0,k.length());
//     cout<<a<<endl;
//     a.erase(2,2);
//     cout<<a<<endl;
//     a.replace(2,5,"mnbvc");
//     cout<<a<<endl;
//     string h="asdfg";
//     a.swap(h);
//     cout<<a<<endl;
//     cout<<a.compare(2,2,h,2,2)<<endl;