//迪杰斯特拉(朴树版)
// #include<bits/stdc++.h>
// using namespace std;
// const int N=100;
// int d[N];
// int g[N][N];
// int st[N];
// int n,m;
// int djk(){
//     memset(d,0x3f,sizeof d);
//     d[1]=0;
//     for (int i=0;i<n;i++){
//         int t=-1;
//         for (int j=1;j<=n;j++){
//             if (!st[j] && (t==-1 || d[t]>d[j])){
//                 t=j;
//             }
//         }
//         for (int j=1;j<=n;j++){
//             if (d[j]>d[t]+g[t][j]){
//                 d[j]=d[t]+g[t][j];
//                 st[t]=1;
//             }
//         }
//     }
//     if (d[n]==0x3f3f3f3f) return -1;
//     else return d[n];
// }
// int main(){
//     memset(g,0x3f,sizeof g);
//     cin>>n>>m;
//     while (m--){
//         int a,b,c;
//         cin>>a>>b>>c;
//         g[a][b]=min(g[a][b],c);
//     }
//     cout<<djk();
// }

//迪杰斯特拉(堆优化)
// #include<bits/stdc++.h>
// using namespace std;
// const int N=100;
// typedef pair<int,int> PII;
// int d[N];
// int e[N],w[N],ne[N],h[N],idx;
// int st[N];
// int n,m;
// void add(int a,int b,int c){
//     e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
// }
// int djk(){
//     memset(d,0x3f,sizeof d);
//     d[1]=0;
//     priority_queue<PII,vector<PII>,greater<PII>> hp;
//     hp.push({0,1});
//     while (hp.size()){
//         auto t=hp.top();
//         hp.pop();
//         int ver=t.second,dis=t.first;
//         if (st[ver]) continue;
//         st[ver]=1;
//         for (int i=h[ver];i!=-1;i=ne[i]){
//             int j=e[ver];
//             if (d[j]>d[ver]+w[i]){
//                 d[j]=d[ver]+w[i];
//                 hp.push({d[j],j});
//             }
//         }
//     }
//     if (d[n]==0x3f3f3f3f) return -1;
//     else return d[n];
// }
// int main(){
//     cin>>n>>m;
//     memset(h,-1,sizeof h);
//     while (m--){
//         int a,b,c;
//         cin>>a>>b>>c;
//         add(a,b,c);
//     }
//     cout<<djk();
// }

//bellon
// #include<bits/stdc++.h>
// using namespace std;
// const int N=100;
// struct dian {
//     int a,b,c;
// } g[N];
// int d[N];
// int l[N];
// int n,m;
// int belf(){
//     memset(d,0x3f,sizeof d);
//     d[1]=0;
//     for (int i=1;i<n;i++){
//         memcpy(l,d,sizeof d);
//         for (int j=1;j<=m;j++){
//             auto t=g[j];
//             if (d[t.b]>l[t.a]+t.c){
//                 d[t.b]=l[t.a]+t.c;
//             }
//         }
//     }
//     if (d[n]>0x3f3f3f3f/2) return -1;
//     else return d[n];
// }
// int main(){
//     cin>>n>>m;
//     for (int i=1;i<=m;i++){
//         int a,b,c;
//         cin>>a>>b>>c;
//         g[i]={a,b,c};
//     }
//     cout<<belf();
// }

//SPFA
// #include<bits/stdc++.h>
// using namespace std;
// const int N=100;
// int e[N],w[N],ne[N],h[N],idx;
// int d[N];
// int st[N];
// int n,m;
// void add(int a,int b,int c){
//     e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
// }
// int bfa(){
//     memset(d,0x3f,sizeof d);
//     d[1]=0;
//     st[1]=1;
//     queue<int> que;
//     que.push(1);
//     while (que.size()){
//         auto t=que.front();
//         que.pop();      
//         st[t]=0;
//         for (int i=h[t];i!=-1;i=ne[i]){
//             int j=e[i];
//             if (d[j]>d[t]+w[i]){
//                 d[j]=d[t]+w[i];
//                 if (!st[j]){
//                     que.push(j);
//                     st[j]=1;
//                 }
//             }
//         }
//     }
//     if (d[n]>0x3f3f3f3f/2) return -1;
//     else return d[n];
// }
// int main(){
//     cin>>n>>m;
//     memset(h,-1,sizeof h);
//     while (m--){
//         int a,b,c;
//         cin>>a>>b>>c;
//         add(a,b,c);
//     }
//     cout<<bfa();
// }

//prim算法
// #include<bits/stdc++.h>
// using namespace std;
// const int N=110;
// const int INF=0x3f3f3f3f;
// bool st[N];
// int g[N][N];
// int d[N];
// int n;
// int prim(){
//     memset(d,0x3f,sizeof d);
//     int res=0;
//     for (int i=0;i<n;i++){
//         int t=-1;
//         for (int j=1;j<=n;j++){
//             if (!st[j] && (t==-1 || d[t]>d[j])){
//                 t=j;
//             }
//         }
//             if (i && d[t]==INF) return INF;
//             if (i) res+=d[t];
//             for (int j=1;j<=n;j++) d[j]=min(d[j],g[t][j]);
//             st[t]=true;
//     }
//     return res;
// }
// int main(){
//     cin>>n;
//     memset(g,0x3f,sizeof g);
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=n;j++){
//             int x;
//             cin>>x;
//             g[i][j]=g[j][i]=min(g[i][j],x);
//         }
//     }
//     cout<<prim();
// }

//kruskal算法
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 25;
// int p[N];
// int f(int x) {
//     if (p[x] != x) p[x] = f(p[x]);
//     return p[x];
// }
// struct E {
//     int u, v, c;
//     bool operator<(const E& o) const {
//         return c < o.c;
//     }
// };
// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<E> es(m);
//     for (int i = 0; i < m; i++) {
//         cin >> es[i].u >> es[i].v >> es[i].c;
//     }
//     for (int i = 1; i <= n; i++) p[i] = i;
//     sort(es.begin(), es.end());
//     int cnt = 0;
//     for (E e : es) {
//         int ur = f(e.u), vr = f(e.v);
//         if (ur != vr) {
//             p[vr] = ur;
//             int a = e.u, b = e.v;
//             if (a > b) swap(a, b);
//             cout << a << "," << b << "," << e.c << endl;
//             cnt++;
//             if (cnt == n - 1) break;
//         }
//     }
//     return 0;
// }

// 二分图最大匹配
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+10;
// int mh[N];
// bool st[N];
// int e[N],ne[N],h[N],idx;
// void add(int a,int b){
//     e[idx]=b,ne[idx]=h[a],h[a]=idx++;
// }
// bool find(int x){
//     for (int i=h[x];i!=-1;i=ne[i]){
//         int j=e[i];
//         if (st[j]) continue;
//         st[j]=true;
//         if (mh[j]==0 || find(mh[j])){
//             mh[j]=x;
//             return true;
//         }
//     }
//     return false;
// }
// int main(){
//     memset(h,-1,sizeof h);
//     int n1,n2;
//     cin>>n1>>n2;
//     int m;
//     cin>>m;
//     while (m--){
//         int a,b;
//         cin>>a>>b;
//         add(a,b);
//         add(b,a);
//     }
//     int res=0;
//     for (int i=1;i<=n1;i++){
//         if (!st[i]){
//             if (find(i)) res++;
//         } 
//     }
//     cout<<res;
// }

//判断二分图
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+10;
// int h[N],e[N],ne[N],idx;
// int c[N];
// void add(int a,int b){
//     e[idx]=b,ne[idx]=h[a],h[a]=idx++;
// }
// bool dfs(int x,int cl){
//     c[x]=cl;
//     for (int i=h[x];i!=-1;i=ne[i]){
//         int j=e[i];
//         if (!c[j]){
//             if (!dfs(j,3-cl)) return false;
//         }
//         else {
//             if (c[j]==cl) return false;
//         }
//     }
//     return true;
// }
// int main(){
//     memset(h,-1,sizeof h);
//     int n,m;
//     cin>>n>>m;
//     while (m--){
//         int a,b;
//         cin>>a>>b;
//         add(a,b);
//         add(b,a);
//     }
//     int y=1;
//     for (int i=1;i<=n;i++){
//         if (!c[i]){
//             if (!dfs(i,1)) y=0;
//         }
//     }
//     if (y) cout<<"yes";
//     else cout<<"no";
// }

// 拓扑排序
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+10;
// queue<int> q;
// int n,m;
// int h[N],e[N],ne[N],idx;
// int d[N];
// int b[N];
// void add(int a,int b){
//     e[idx]=b,ne[idx]=h[a],h[a]=idx++;
// }
// bool topu(){
//     int cnt=0;
//     while (!q.empty()) q.pop();
//     for (int i=1;i<=n;i++) {
//         if (d[i]==0) q.push(i);
//     }
//     while (!q.empty()){
//         auto t=q.front();
//         q.pop();
//         b[cnt++]=t;
//         for (int i=h[t];i!=-1;i=ne[i]){
//             int j=e[i];
//             if (--d[j]==0){
//                 q.push(j);
//             }
//         }
//     }
//     return cnt==n;
// }
// int main(){
//     cin>>n>>m;
//     memset(h,-1,sizeof h);
//     while (m--){
//         int a,b;
//         cin>>a>>b;
//         add(a,b);
//         d[b]++;
//     }
//     if (topu()) {
//         cout<<"yes"<<endl;
//         for (int i=0;i<n;i++) cout<<b[i]<<" ";
//     }
//     else cout<<"no"<<endl;
// }

