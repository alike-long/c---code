#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int> a,int l){
     for (int i=0;i<l;i++){
          cout<<a[i]<<" ";
     }
     cout<<endl;
}
void px(vector<int> a,int l){
     for (int i=0;i<l-1;i++){
          for (int j=0;j<l-i-1;j++){
               if (a[j]>a[j+1]){
                    int t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
               }
          }
     }
     print(a,l);
}
void px2(vector<int> a,int l){
     for (int i=0;i<l-1;i++){
          int t=i;
          for (int j=i+1;j<l;j++){
               if (a[j]<a[t]){
                    t=j;
               }
          }
          swap(a[t],a[i]);
     }
     print(a,l);
}
void px3(vector<int> a,int l){
     for (int i=1;i<l;i++){
          for (int j=i+1;j<l;j++){
               if (a[j]<a[i]){
                    int t=a[j];
                    for (int k=j;k>i;k--){
                         a[k]=a[k-1];
                    }
                    a[i]=t;
               }
          }
     }
     print(a,l);
}
void qs(vector<int> & a,int l,int r){
    if (r<=l) return;
    int x=a[l],i=l-1,j=r+1;
    while(i<j){
    do i++; while (a[i]<x);
    do j--; while (a[j]>x);
    if (i<j) swap(a[i],a[j]);
    }
    qs(a,l,j);
    qs(a,j+1,r);
}
void ms(vector<int> & a,int l,int r){
     vector<int> t;
     if (r<=l) return;
     int m=(r+l)/2;
     ms(a,l,m),ms(a,m+1,r);
     int i=l,j=m+1;
     while (i<=m && j<=r){
          if (a[i]<=a[j]) {t.push_back(a[i++]);}
          else {t.push_back(a[j++]);}
     }
     while (i<=m) t.push_back(a[i++]);
     while (j<=r) t.push_back(a[j++]);
     for (int i=l,j=0;i<=r;i++,j++) a[i]=t[j];
}
int main(){
     int n;
     scanf("%d",&n);
     vector<int> a;
     for (int i=0;i<n;i++){
          int g;
          scanf("%d",&g);
          a.push_back(g);
     }
     ms(a,0,n-1);
     print(a,n);
}


// int main(){
//     vector<int> a;
//     int n;
//     scanf("%d",&n);
//     for (int i=0;i<n;i++){
//         int g;
//         scanf("%d",&g);
//         a.push_back(g);
//     }
//     int h;
//     scanf("%d",&h);
//     int l=0,r=n-1;
//     while(l<r){
//             int m=(l+r)/2;
//         if (a[m]>=h) r=m;
//         else l=m+1; 
//     }
//     if (a[l]!=h) cout<<"-1"<<endl;
//     else {
//         cout<<l<<" ";
//         int l=0,r=n-1;
//         while (l<r){
//                  int m=(l+r+1)/2;
//             if(a[m]<=h) l=m;
//             else r=m-1; 
//         }
//         cout<<l;
//     }
// }