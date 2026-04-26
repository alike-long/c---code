#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;






// string ooo(string & a){
//     a.erase(0.,a.find_first_not_of('0'));
//     return a.empty()?"0":a;
// }
// string cheng(string a,int b){
//     ooo(a);
//     int num=0;
//     int c=0;
//     string m;
//     reverse(a.begin(),a.end());
//     for (auto n:a){
//         num=(n-'0')*b+c;
//         c=num/10;
//         num%=10;
//         m.push_back(num+'0');
//     }
//     while ( c>0 ) {
//         m.push_back(c%10+'0');
//         c/=10;
//     }
//     reverse(m.begin(),m.end());
//     return m;
// }
// int main(){
//     string a;
//     int b;
//     int n;
//     cin>>n;
//     a=n+'0';
//     for (int i=n-1;i>=1;i--){
//         a=cheng(a,i);
//     }
//     cout<<a;                                                                                                                                                                            
// }

// string ooo(string & a){
//     a.erase(0,a.find_first_not_of('0'));
//     return a.empty()?"0":a;
// }
// string chu(string a,int b,int & r){
//     int y=0;
//     if (a[0]=='-'){
//         a=a.substr(1);
//         y=1;
//     }
//     int c;
//     r=0;
//     int num=0;
//     string m;
//     for (auto n:a){
//         num=(n-'0')+r*10;
//         m.push_back(num/b+'0');
//         r=num%b;
//     }
//     ooo(m);
//     if (y) m='-'+m;
//     return m;
// }
// int main(){
//     string a;
//     int b,r;
//     cin>>a>>b;
//     cout<<chu(a,b,r)<<" "<<r;
// }

// string ooo(string & a){
//     a.erase(0.,a.find_first_not_of('0'));
//     return a.empty()?"0":a;
// }
// string cheng(string a,int b){
//     ooo(a);
//     int num=0;
//     int c=0;
//     string m;
//     reverse(a.begin(),a.end());
//     for (auto n:a){
//         num=(n-'0')*b+c;
//         c=num/10;
//         num%=10;
//         m.push_back(num+'0');
//     }
//     while ( c>0 ) {
//         m.push_back(c%10+'0');
//         c/=10;
//     }
//     reverse(m.begin(),m.end());
//     return m;
// }
// int main(){
//     string a;
//     int b;
//     cin>>a>>b;
//     cout<<cheng(a,b);
// }

// string ooo(string & a){
//     a.erase(0,a.find_first_not_of('0'));
//     return a.empty()?"0":a;
// }
// string jh(string  a,string  b){
//     ooo(a);
//     ooo(b);
//     int y=0;
//     int i=a.size()-1;
//     int j=b.size()-1;
//     if (i<j || (i==j && a<b)){
//         a.swap(b);
//         swap(i,j);
//         y=1;
//     }
//     string n;
//     int c=0;
//     int num;
//     while (i>=0 || j>=0 || c){
//         num=c;
//     if (i>=0) num+=a[i--]-'0';
//     if (j>=0) num-=b[j--]-'0';
//     if(num<0) {
//         num+=10;
//         c=-1;
//     } else {
//         c=0;
//     }
//     n.push_back(num+'0');
//     }
//     reverse(n.begin(),n.end());
//     ooo(n);
//     if (y) n='-'+n;
//     return n;
// }
// int main(){
//     string a,b;
//     cin>>a>>b;
//     cout<<jh(a,b)<<endl;
// }

// string ooo(string & a){
//     a.erase(0,a.find_first_not_of('0'));
//     return a.empty()?"0":a;
// }
// string add(string a,string b){
//     ooo(a);
//     ooo(b);
//     int c=0;
//     string n;
//     int i=a.size()-1,j=b.size()-1;
//     while (i>=0 || j>=0 || c){
//         int num=c;
//         if (i>=0) num+=a[i--]-'0';
//         if (j>=0) num+=b[j--]-'0';
//         c=num/10;
//         num%=10;
//         n.push_back(num+'0');
//     }
//     reverse(n.begin(),n.end());
//     return n;
// }
// int main(){
//     string a,b;
//     cin>>a>>b;
//     string c=add(a,b);
//     cout<<c;
// }
