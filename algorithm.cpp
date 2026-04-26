//欧拉回路  欧拉路径
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3=10;
// int p[N];
// int d[N];
// int root;
// int n,m;
//  void init(){
//     for (int i=1;i<=n;i++) p[i]=i;
//  }
//  int find(int x){
//     if (p[x]!=x) p[x]=find(p[x]);
//     return p[x];
//  }
//  int main(){
//     cin>>n>>m;
//     init();
//     while (m--){
//         int a,b;
//         cin>>a>>b;
//         d[a]++;
//         d[b]++;
//     }
//     for (int i=1;i<=n;i++){
//         if (d[i]%2!=0) cnt++;
//     }
//     int y=1;
//     for (int i=1;i<=n;i++){
//         if (!root) root=find(i);
//         else if (find(i)!=root) y=0;
//     }
//     /*欧拉回路*/if (y && !cnt) cout<<"yes";
//     else cout<<"no";
//     /*欧拉路径*/if (y && (cnt==0 || cnt==2)) cout<<" yes";
//     else cout<<"no";
// }

// 欧拉筛
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+10;
// bool st[N];
// int b[N],cnt;
// void ols(int n){
//     for (int i=2;i<=n;i++){
//         if (!st[i]) b[cnt++]=i;
//         for (int j=0;b[j]<=n/i;j++){
//             st[b[j]*i]=true;
//             if(i%b[j]==0) break;
//         }
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     ols(n);
//     for (int i=0;i<cnt;i++) cout<<b[i]<<endl;
// }

// 快速幂
// #include<bits/stdc++.h>
// using namespace std;
// int ksm(int a,int b,int c){
//     int res=1;
//     while (b){
//         if (b&1) res=res*a%c;
//         a=a*a%c;
//         b>>=1;
//     }
//     return res;
// }
// int main(){
//     int a,b,c;
//     cin>>a>>b>>c;
//     cout<<ksm(a,b,c);
// }

// 离散化
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+10;
// int a[N];
// vector<int> ys;
// int find(int x){
//     return lower_bound(ys.begin(),ys.end(),x)-ys.begin();
// }
// int main(){
//     int n;
//     cin>>n;
//     for (int i=1;i<=n;i++) {
//         int x;
//         cin>>x;
//         a[i]=x;
//         ys.push_back(x);
//     }
//     sort(ys.begin(),ys.end());
//     ys.erase(unique(ys.begin(),ys.end()),ys.end());
//     for (int i=1;i<=n;i++) {
//         cout<<find(a[i])<<' ';
//     }
//     cout<<endl;
//     for (int i=1;i<=n;i++) {
//         cout<<ys[find(a[i])]<<' ';
//     }
//     cout<<endl;
//     for (int i=1;i<=n;i++) {
//         cout<<a[find(a[i])]<<' ';
//     }
// }

//进制转进制
// #include<bits/stdc++.h>
// using namespace std;
// int rzs(string s,int r){
//     int res=0;
//     for (int i=0;s[i];i++){
//         int c;
//         if (s[i]<='9' && s[i]>='0') c=s[i]-'0';
//         else c=s[i]-'A'+10;
//         res=res*r+c;
//     }
//     return res;
// }
// string szr(int n,int r){
//     string s;
//     char c;
//     while (n>0){
//         int res=n%r;
//         if (res>=10) c=res-10+'A';
//         else c=res+'0';
//         s+=c;
//         n/=r; 
//     }
//     reverse(s.begin(),s.end());
//     return s;
// }
// int main(){
//     string s;
//     int r1,r2;
//     cin>>s>>r1>>r2;
//     cout<<szr(rzs(s,r1),r2);
// }

//求组合数N=2010;
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e3+10;
// int c[N][N];
// int n,m,p;
// void init(){
//     for (int i=0;i<N;i++){
//         for (int j=0;j<=i;j++){
//             if (!j) c[i][j]=1;
//             else c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
//         }
//     }
// }
// int main(){
//     cin>>n>>m>>p;
//     init();
//     cout<<c[n][m];
// }

//求组合数N=100010,次数很多;
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+10;
// const int P=1e9+7;
// typedef long long ll;
// int fa[N],ifa[N];
// int kms(int a,int b,int c){
//     ll res=1;
//     while (b){
//         if (b&1) res=(ll)res*a%c;
//         a=(ll)a*a%c;
//         b>>=1;
//     }
//     return res;
// }
// void init(){
//     fa[0]=ifa[0]=1;
//     for (int i=1;i<N;i++){
//         fa[i]=(ll)fa[i-1]*i%P;
//         ifa[i]=(ll)ifa[i-1]*kms(i,P-2,P)%P;
//     }
// } 
// int main(){
//     int n,m;
//     init();
//     cin>>n>>m;
//     int res=(ll)fa[n]*ifa[m]%P*ifa[n-m]%P;
//     cout<<res;
// }

//求组合数N很大
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int P=1e9+7;
// ll kms(int a,int b,int c){
//     ll res=1;
//     while (b){
//         if (b& 1) res=(ll)res*a%c;
//         a=(ll)a*a%c;
//         b>>=1;
//     }
//     return res;
// }
// ll C(int a,int b,int c){
//     if (b>a) return 0;
//     ll res=1;
//     for (int i=1,j=a;i<=b;i++,j--){
//         res=(ll)res*j%c;
//         res=(ll)res*kms(i,c-2,c)%c;
//     }
//     return res;
// }
// ll lucas(int a,int b,int c){
//     if (a<c && b<c) return C(a,b,c);
//     else return (ll)C(a%c,b%c,c)*lucas(a/c,b/c,c)%c;
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     cout<<lucas(n,m,P);
// }

//st表
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+10;
// int dp[N][20];
// int a[N];
// int logn[N];
// int n,m;
// void init_log() {
//     logn[1] = 0;
//     for(int i=2; i<=N; i++) {
//         logn[i] = logn[i/2] + 1;
//     }
// }
// int qurry(int l,int r){
//     int j=logn[r-l+1];
//     return max(dp[l][j],dp[r-(1<<j)+1][j]);
// }
// void init(){
//     for (int i=0;i<n;i++) dp[i][0]=a[i];
//     for (int j=1;j<logn[n]+1;j++){
//         for (int i=0;i+(1<<j)-1<n;i++){
//             dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(false),cin.tie(nullptr);
//     cin>>n>>m;
//     for (int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     init_log();
//     init();
//     while (m--){
//         int l,r;
//         cin>>l>>r;
//         cout<<qurry(l-1,r-1)<<'\n';
//     }
// }

// AC自动机&&trie图
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+10;
// int tr[N][26],idx;
// int cnt[N];
// string s;
// string str;
// int ne[N];
// queue<int> q;
// void insert(string s){
//     int p=0;
//     for (int i=0;s[i];i++){
//         int u=s[i]-'a';
//         if (!tr[p][u]) tr[p][u]=++idx;
//         p=tr[p][u];
//     }
//     cnt[p]++;
// }
// void build(){
//     for (int i=0;i<26;i++){
//         if (tr[0][i]) {
//             q.push(tr[0][i]);
//         }
//     }
//     while (q.size()){
//         auto t=q.front();
//         q.pop();
//         for (int i=0;i<26;i++){
//             int p=tr[t][i];
//             if (!p) tr[t][i]=tr[ne[t]][i];
//             else {
//                 ne[p]=tr[ne[t]][i];
//                 q.push(p);
//             }
//         }
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     while (n--){
//         cin>>s;
//         insert(s);
//     }
//     build();
//     cin>>str;
//     int res=0;
//     for (int i=0,j=0;str[i];i++){
//         int u=str[i]-'a';
//         j=tr[j][u];
//         int p=j;
//         while (p && cnt[p]!=-1){
//             res+=cnt[p];
//             cnt[p]=-1;
//             p=ne[p];
//         }
//     }
//     cout<<res;
// }
