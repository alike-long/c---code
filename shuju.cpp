//模拟哈希表
// #include<bits/stdc++.h>
// using namespace std;
// const int N=200003;
// const int null=0x3f3f3f3f;
// int h[N];
// int find(int x){
//     int t=(x%N+N)%N;
//     while (h[t]!=null && h[t]!=x){
//         t++;
//         if (t==N) t=0;
//     }
//     return t;
// }
// int main(){
//     int q,e;
//     memset(h,0x3f,sizeof h);
//     cin>>q>>e;
//     while (q--){
//         int n;
//         cin>>n;
//         h[find(n)]=n;
//     }
//     while (e--){
//         int n;
//         cin>>n;
//         if (h[find(n)]==n) cout<<"yes"<<endl;
//         else cout<<"No"<<endl;
//     }
// }

// kmp算法
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+10;
// char s[N],p[N];
// int ne[N];
// int main(){
//     scanf("%s",s+1);
//     scanf("%s",p+1);
//     int n=strlen(s+1);
//     int m=strlen(p+1);
//     for (int i=2,j=0;i<=n;i++){
//         while (j && s[i]!=s[j+1]) j=ne[j];
//         if (s[i]==s[j+1]) j++;
//         ne[i]=j;
//     }
//     for (int i=1,j=0;i<=m;i++){
//         while (j && p[i]!=s[j+1]) j=ne[j];
//         if (p[i]==s[j+1]) j++;
//         if (j==n){
//             cout<<i-n<<endl;
//             j=ne[j];
//         }
//     }
// }

// 字符串哈希
// #include<bits/stdc++.h>
// using namespace std;
// typedef unsigned long long ULL;
// const int P=131,N=1e5+10;
// ULL h[N],p[N];
// int n;
// char s[N];
// ULL get(int l,int r){
//     return h[r]-h[l-1]*p[r-l+1];
// }
// void init(int len){
//     p[0]=1;
//     for (int i=1;i<=n;i++){
//         h[i]=h[i-1]*P+s[i];
//         p[i]=p[i-1]*P;
//     }
// }
// int main(){
//     int m;
//     cin>>n>>m;
//     scanf("%s",s+1);
//     init(n);
//     while (n--){
//         int l1,l2,r1,r2;
//         cin>>l1>>r1>>l2>>r2;
//         if (get(l1,r1)==get(l2,r2)) cout<<"yes"<<endl;
//         else cout<<"no"<<endl;
//     }
// }

// 并查集
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e5+10;
// int p[N];
// int n;
// int find(int x){
//     if (p[x]!=x) p[x]=find(p[x]);
//     return p[x];
// }
// void init(){
//     for (int i=1;i<=n;i++) p[i]=i;
// }
// int main(){
// }

// 链表
// #include<bits/stdc++.h>
// using namespace std;
// struct Node {
//     int v;
//     Node * next;
// };
// Node *w=NULL;
// void print(Node * head){
//     Node * t=head;
//     while (t!=NULL) {
//         cout<<t->v<<endl;
//         t=t->next;
//     }
// }
// Node * insert(Node * head,int v){
//     Node * noe=(Node *)malloc(sizeof (Node));
//     noe->next=NULL;
//     noe->v=v;
//     if (head==NULL){
//         head=noe;
//         w=noe;
//     } else {
//         w->next=noe;
//         w=noe;
//     }
//     return head;
// }
// Node * erase(Node * head,int v){
//     while (head!=NULL && head->v==v){
//         Node * t=head;
//         head=head->next;
//     }
//     if (head==NULL) return NULL;
//     Node * pre=head;
//     Node * t=head->next;
//     while (t!=NULL){
//         if (t->v==v){
//             Node * tm=t;
//             pre->next=t->next;
//             t=t->next;
//         }
//         else {
//             pre=t;
//             t=t->next;
//         }
//     }
//     return head;
// }
// Node * zz(Node * head){
//     Node * pre=NULL;
//     Node * t=head;
//     Node * ne=NULL;
//     while (t!=NULL){
//         ne=t->next;
//         t->next=pre;
//         pre=t;
//         t=ne;
//     }
//     return pre;
// }
// int main(){
//     Node * head=NULL;
//     head=insert(head,1);
//     head=insert(head,2);
//     head=insert(head,3);
//     head=insert(head,4);
//     head=insert(head,5);
//     head=insert(head,6);
//     head=erase(head,3);
//     head=zz(head);
//     print(head);
// }

// 小根堆
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+10;
// int h[N],asize; 
// void up(int k){
//     while (k/2){
//         if (h[k/2]>h[k]){
//             swap(h[k/2],h[k]);
//         }
//         k/=2;
//     }
// }
// void down(int k){
//     int u=k;
//     if (2*k<=asize && h[u]>h[2*k]) u=2*k;
//     if (2*k+1<=asize && h[u]>h[2*k+1]) u=2*k+1;
//     if (u!=k){
//         swap(h[u],h[k]);
//         down(u);
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     int y=n;
//     while (y--){
//         int x;
//         cin>>x;
//         h[++asize]=x;
//         up(asize);
//     }
//     for (int i=0;i<n;i++){
//         cout<<h[1]<<endl;
//         h[1]=h[asize];
//         down(1);
//     }
// }

//配对堆
// #include<bits/stdc++.h>
// using namespace std;
// struct Node {
//     int v;
//     Node *c;
//     Node *s;
//     Node(int val) : v(val), c(nullptr), s(nullptr) {}
// };
// Node *meld(Node *x,Node *y){
//     if (x==nullptr) return y;
//     if (y==nullptr) return x;
//     if (x->v>y->v) swap(x,y);
//     y->s=x->c;
//     x->c=y;
//     return x;
// }
// void insert(Node * &heap,int x){
//     Node* noe=new Node(x);
//     heap=meld(heap,noe);
// }
// Node * merges(Node *heap){
//     if(heap==nullptr || heap->s==nullptr) return heap;
//     Node * y=heap->s;
//     Node *c=y->s;
//     heap->s=y->s=nullptr;
//     return meld(merges(c),meld(heap,y)); 
// }
// Node *delete_h(Node* heap){
//     Node *t=merges(heap->c);
//     delete heap;
//     return t;
// }
// void print(Node *heap,int d=0){
//     if (heap==nullptr) return ;
//     for (int i=0;i<d;i++) cout<<" ";
//     cout<<heap->v<<endl;
//     print(heap->c,d+1);
//     print(heap->s,d);
// }
// int main(){
//     Node *heap=nullptr;
//     insert(heap,1);
//     insert(heap,2);
//     insert(heap,4);
//     insert(heap,6);
//     insert(heap,8);
//     insert(heap,5);
//     heap=delete_h(heap);
//     print(heap,0);
// }

//左偏堆
// #include<bits/stdc++.h>
// using namespace std;
// struct Node {
//     int v,d;
//     Node *l;
//     Node *r;
//     Node (int x):v(x),d(0),l(nullptr),r(nullptr){}
// };
// Node * meld(Node * x,Node *y){
//     if (!x) return y;
//     if (!y) return x;
//     if (x->v>y->v) swap(x,y);
//     x->r=meld(x->r,y);
//     if ((x->l?x->l->d:-1)<(x->r?x->r->d:-1)){
//         swap(x->l,x->r);
//     }
//     x->d=(x->r?x->r->d:-1)+1;
//     return x;
// }
// void insert(Node *&heap,int x){
//     heap=meld(heap,new Node (x));
// }
// void erase(Node * &heap){
//     if (!heap) return ;
//     Node *t=heap;
//     heap=meld(t->l,t->r);
//     delete(t);
// }
// void print(Node* node, int depth = 0) {
//         if (!node) return;
//         for (int i = 0; i < depth; ++i) cout << "  ";
//         cout << node->v << endl;
//         print(node->l, depth + 1); 
//         print(node->r, depth + 1);
//     }
// int main(){
//     Node * heap=nullptr;
//     insert(heap,1);
//     insert(heap,2);
//     insert(heap,4);
//     insert(heap,5);
//     insert(heap,7);
//     insert(heap,9);
//     insert(heap,8);
//     insert(heap,99);
//     erase(heap);
//     print(heap);
// }

// 单调zai
// #include<bits/stdc++.h>
// using namespace std;
// const int N=3e6+10;
// stack<int> st;
// int a[N],b[N];
// int main(){
//     int n;
//     int j=0;
//     cin>>n;
//     for (int i=0;i<n;i++) cin>>a[i];
//     for (int i=n-1;i>=0;i--){
//         while (!st.empty() && a[i]>=a[st.top()]) st.pop();
//         if (!st.empty()) b[j++]=st.top()+1;
//         else b[j++]=0;
//         st.push(i);
//     }
//     for (int i=j-1;i>=0;i--) cout<<b[i]<<" ";
// }

// 单调队列
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+10;
// deque<int> deq;
// int e[N];
// int main(){
//     int n,k;
//     cin>>n>>k;
//     for (int i=0;i<n;i++) cin>>e[i];
//     for (int i=0;i<n;i++){
//         while (!deq.empty() && i-deq.front()+1>k) deq.pop_front();
//         while (!deq.empty() && e[deq.back()]>=e[i]) deq.pop_back();
//         deq.push_back(i);
//         if (i>=k-1) cout<<e[deq.front()]<<" ";
//     }
//     deq.clear();
//     cout<<endl;
//     for (int i=0;i<n;i++){
//         while (!deq.empty() && i-deq.front()+1>k) deq.pop_front();
//         while (!deq.empty() && e[deq.back()]<=e[i]) deq.pop_back();
//         deq.push_back(i);
//         if (i>=k-1) cout<<e[deq.front()]<<" ";
//     }
// }

//tree树
// #include<bits/stdc++.h>
// using namespace std;
// const int N=10000;
// int son[N][26],cnt[N],pre[N];
// int idx=0;
// void insert(string s){
//     int p=0;
//     for (int i=0;s[i];i++){
//         int u=s[i]-'a';
//         if (!son[p][u]) son[p][u]=++idx;
//         p=son[p][u];
//         pre[p]++;
//     }
//     cnt[p]++;
// }
// int query1(string s){
//     int p=0;
//     for (int i=0;s[i];i++){
//         int u=s[i]-'a';
//         if (!son[p][u]) return 0;
//         p=son[p][u];
//     }
//     return cnt[p];
// }
// int query2(string s){
//     int p=0;
//     for (int i=0;s[i];i++){
//         int u=s[i]-'a';
//         if (!son[p][u]) return 0;
//         p=son[p][u];
//     }
//     return pre[p];
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     while (n--){
//         string s;
//         cin>>s;
//         insert(s);
//     }
//     while (m--){
//         string s;
//         cin>>s;
//         cout<<query1(s)<<" ";
//         cout<<query2(s)<<endl;
//     }
// }

// 一维树状数组
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+10;
// int n=5;
// int t1[N],t2[N];
// int lowbit(int x){
//     return x&-x;
// }
// void add(int k,int v){
//     int v1=k*v;
//     while (k<=n){
//         t1[k]+=v;
//         t2[k]+=v1;
//         k+=lowbit(k);
//     }
// }
// void add1(int l,int r,int v){
//     add(l,v);
//     add(r+1,-v);
// }
// int sum(int *t,int k){
//     int res=0;
//     while (k){
//         res+=t[k];
//         k-=lowbit(k);
//     }
//     return res;
// }
// int sum1(int l,int r){
//     int x1=(r+1)*sum(t1,r)-sum(t2,r);
//     int x2=l*sum(t1,l-1)-sum(t2,l-1);
//     return x1-x2;
// }
// int main(){
//     int a[]={0,1,2,3,4,5};
//     for (int i=1;i<=5;i++) add1(i,i,a[i]);
//     cout<<sum1(2,4)<<" ";
//     add1(2,4,3);
//     cout<<sum1(2,4)<<endl;
//     for (int i=1;i<=5;i++) cout<<sum1(i,i)<<" ";
// }

// 二维树状数组
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e3+10;
// int t1[N][N],t2[N][N],t3[N][N],t4[N][N];
// int a[N][N];
// int n,m,q;
// int lowbit(int x){
//     return x&-x;
// } 
// void add(int x,int y,int v){
//     for (int i=x;i<=n;i+=lowbit(i)){
//         for (int j=y;j<=m;j+=lowbit(j)){
//             t1[i][j]+=v;
//             t2[i][j]+=v*x;
//             t3[i][j]+=v*y;
//             t4[i][j]+=v*x*y;
//         }
//     }
// }
// void add1(int x1,int y1,int x2,int y2,int v){
//     add(x1,y2,v);
//     add(x1,y2+1,-v);
//     add(x2+1,y1,-v);
//     add(x2,y2,v);
// }
// int sum(int x,int y){
//     int res=0;
//     for (int i=x;i;i-=lowbit(i)){
//         for (int j=y;j;j-=lowbit(j)){
//             res+=(x+1)*(y+1)*t1[i][j]-(y+1)*t2[i][j]-(x+1)*t3[i][j]+t4[i][j];
//         }
//     }
//     return res;
// }
// int sum1(int x1,int y1,int x2,int y2){
//     return sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1,y1);
// }
// int main(){
//     cin>>n>>m>>q;
//     for (int i=1;i<=n;i++){
//         for (int j=1;j<=m;j++){
//             int v;
//             cin>>v;
//             a[i][j]=v;
//             add1(i,j,i,j,v);
//         }
//     }
//     while (q--){
//         int op;
//     cin >> op;
//     if (op == 1) {
//       int xa, ya, xb, yb, z;
//       cin >> xa >> ya >> xb >> yb >> z;
//       add1(xa, ya, xb, yb, z);
//     } else {
//       int xa, ya, xb, yb;
//       cin >> xa >> ya >> xb >> yb;
//       cout << sum1(xa, ya, xb, yb) << endl;
//     }
//     }
// }

// pushup线段树(单点修改,查询)
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long LL;
// const int N = 200010;
// int m, p;
// struct Node
// {
//     int l, r;
//     int v;
// }tr[N * 4];
// void pushup(int u)
// {
//     tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
// }
// void build(int u, int l, int r)
// {
//     tr[u] = {l, r};
//     if (l == r) return;
//     int mid = l + r >> 1;
//     build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//     pushup(u); 
// }
// int query(int u, int l, int r)
// {
//     if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;
//     int mid = tr[u].l + tr[u].r >> 1;
//     int v = 0;
//     if (l <= mid) v = query(u << 1, l, r);
//     if (r > mid) v = max(v, query(u << 1 | 1, l, r));
//     return v;
// }
// void modify(int u, int x, int v)
// {
//     if (tr[u].l == x && tr[u].r == x) tr[u].v = v;
//     else
//     {
//         int mid = tr[u].l + tr[u].r >> 1;
//         if (x <= mid) modify(u << 1, x, v);
//         else modify(u << 1 | 1, x, v);
//         pushup(u);
//     }
// }
// int main()
// {
//     int n = 0, last = 0;
//     scanf("%d%d", &m, &p);
//     build(1, 1, m);
//     int x;
//     char op[2];
//     while (m -- )
//     {
//         scanf("%s%d", op, &x);
//         if (*op == 'Q')
//         {
//             last = query(1, n - x + 1, n);
//             printf("%d\n", last);
//         }
//         else
//         {
//             modify(1, n + 1, ((LL)last + x) % p);
//             n ++ ;
//         }
//     }
//     return 0;
// }

//pushdown线段树(区间修改,查询，懒标记)
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long LL;
// const int N = 100010;
// int n, m;
// int w[N];
// struct Node
// {
//     int l, r;
//     LL sum, add;
// }tr[N * 4];
// void pushup(int u)
// {
//     tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
// }
// void pushdown(int u)
// {
//     auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
//     if (root.add)
//     {
//         left.add += root.add, left.sum += (LL)(left.r - left.l + 1) * root.add;
//         right.add += root.add, right.sum += (LL)(right.r - right.l + 1) * root.add;
//         root.add = 0;
//     }
// }
// void build(int u, int l, int r)
// {
//     if (l == r) tr[u] = {l, r, w[r], 0};
//     else
//     {
//         tr[u] = {l, r};
//         int mid = (l + r) >> 1;
//         build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//         pushup(u);
//     }
// }
// void modify(int u, int l, int r, int d)
// {
//     if (tr[u].l >= l && tr[u].r <= r)
//     {
//         tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * d;
//         tr[u].add += d;
//     }
//     else    // 一定要分裂
//     {
//         pushdown(u);
//         int mid = (tr[u].l + tr[u].r) >> 1;
//         if (l <= mid) modify(u << 1, l, r, d);
//         if (r > mid) modify(u << 1 | 1, l, r, d);
//         pushup(u);
//     }
// }
// LL query(int u, int l, int r)
// {
//     if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
//     pushdown(u);
//     int mid = (tr[u].l + tr[u].r) >> 1;
//     LL sum = 0;
//     if (l <= mid) sum = query(u << 1, l, r);
//     if (r > mid) sum += query(u << 1 | 1, l, r);
//     return sum;
// }
// int main()
// {
//     scanf("%d%d", &n, &m);
//     for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
//     build(1, 1, n);
//     char op[2];
//     int l, r, d;
//     while (m -- )
//     {
//         scanf("%s%d%d", op, &l, &r);
//         if (*op == '1')
//         {
//             scanf("%d", &d);
//             modify(1, l, r, d);
//         }
//         else printf("%lld\n", query(1, l, r));
//     }
//     return 0;
// }

// 扫描法(求解矩形)
// #include <cstdio>
// #include <algorithm>
// #include <vector>
// using namespace std;
// typedef long long LL; // 面积可能很大，用long long存储
// const int N = 100010;
// int n;
// // 扫描线的竖线：x坐标（整数），y1~y2区间，k=+1/-1（入边/出边）
// struct Segment {
//     LL x, y1, y2;
//     int k;
//     bool operator< (const Segment &t) const {
//         return x < t.x; // 按x从小到大排序
//     }
// } seg[N * 2];
// // 线段树节点：维护y轴区间的覆盖次数(cnt)和有效长度(len)
// struct Node {
//     int l, r;    // 离散化后的y轴区间下标
//     int cnt;     // 覆盖次数
//     LL len;      // 有效覆盖长度（整数）
// } tr[N * 8];
// vector<LL> ys; // 存储所有y坐标（整数），用于离散化
// // 离散化：找到y对应的下标
// int find(LL y) {
//     return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
// }
// // pushup：更新当前节点的有效长度
// void pushup(int u) {
//     if (tr[u].cnt) { // 有覆盖，有效长度=区间总长度
//         tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
//     } else if (tr[u].l != tr[u].r) { // 无覆盖，合并左右子节点
//         tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
//     } else { // 叶子节点且无覆盖，长度为0
//         tr[u].len = 0;
//     }
// }
// // 建树：u是节点编号，l/r是离散化后的y轴区间下标
// void build(int u, int l, int r) {
//     tr[u] = {l, r, 0, 0};
//     if (l != r) {
//         int mid = l + r >> 1;
//         build(u << 1, l, mid);
//         build(u << 1 | 1, mid + 1, r);
//     }
// }
// // 区间修改：给[l,r]区间的覆盖次数加k
// void modify(int u, int l, int r, int k) {
//     if (tr[u].l >= l && tr[u].r <= r) {
//         tr[u].cnt += k;
//         pushup(u);
//         return;
//     }
//     int mid = tr[u].l + tr[u].r >> 1;
//     if (l <= mid) modify(u << 1, l, r, k);
//     if (r > mid) modify(u << 1 | 1, l, r, k);
//     pushup(u);
// }
// int main() {
//     scanf("%d", &n);
//     ys.clear();
//     // 读入n个矩形，拆成2n条扫描线（所有坐标用LL存储）
//     for (int i = 0, j = 0; i < n; i++) {
//         LL x1, y1, x2, y2;
//         scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
//         seg[j++] = {x1, y1, y2, 1};  // 左边界：入边+1
//         seg[j++] = {x2, y1, y2, -1}; // 右边界：出边-1
//         ys.push_back(y1);
//         ys.push_back(y2);
//     }
//     // 离散化y坐标：排序+去重
//     sort(ys.begin(), ys.end());
//     ys.erase(unique(ys.begin(), ys.end()), ys.end());
//     // 建树：离散化后的y轴区间数是ys.size()-1，下标0~ys.size()-2
//     build(1, 0, ys.size() - 2);
//     // 按x坐标排序所有扫描线
//     sort(seg, seg + 2 * n);
//     LL res = 0; // 面积用long long，避免溢出
//     for (int i = 0; i < 2 * n; i++) {
//         // 计算当前扫描线与上一条的宽度差 × 有效高度，累加到面积
//         if (i > 0) {
//             res += tr[1].len * (seg[i].x - seg[i-1].x);
//         }
//         // 修改当前y区间的覆盖次数
//         modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
//     }
//     printf("%lld\n", res);
//     return 0;
// }

// 主席树(求k-th数)
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+10;
// struct Node {
//     int l,r,sum;
// }hjt[N*40];
// int a[N];
// int cnt,root[N];
// vector<int> ys;
// int getid(int x){
//     return lower_bound(ys.begin(),ys.end(),x)-ys.begin()+1;
// }
// void insert(int l,int r,int pre,int &now,int p){
//     hjt[++cnt]=hjt[pre];
//     now=cnt;
//     hjt[now].sum++;
//     if (l==r) return ;
//     int mid=(l+r)>>1;
//     if (p<=mid) insert(l,mid,hjt[pre].l,hjt[now].l,p);
//     else insert(mid+1,r,hjt[pre].r,hjt[now].r,p);
// }
// int query(int l,int r,int L,int R,int k){
//     if (l==r) return l;
//     int mid=(l+r)>>1;
//     int tmp=hjt[hjt[R].l].sum-hjt[hjt[L].l].sum;
//     if (k<=tmp) return query(l,mid,hjt[L].l,hjt[R].l,k);
//     else return query(mid+1,r,hjt[L].r,hjt[R].r,k-tmp);
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     for (int i=1;i<=n;i++){
//         int x;
//         cin>>x;
//         a[i]=x;
//         ys.push_back(x);
//     }
//     sort(ys.begin(),ys.end());
//     ys.erase(unique(ys.begin(),ys.end()),ys.end());
//     for (int i=1;i<=n;i++){
//         insert(1,n,root[i-1],root[i],getid(a[i]));
//     }
//     while (m--){
//         int l,r,k;
//         cin>>l>>r>>k;
//         cout<<ys[query(1,n,root[l-1],root[r],k)-1]<<endl;
//     }
// }

// 二叉搜索树
// #include<bits/stdc++.h>
// using namespace std;
//int p=-10000;
// struct Node{
//     int  key;
//     Node* l;
//     Node* r;
//     int size;
//     int cnt;
//     Node (int v):
//         key(v),size(1),cnt(1),l(nullptr),r(nullptr) {}
// };
// void print(Node * root){
//     if (root==nullptr){
//         return ;
//     }
//     //cout<<root->key<<" ";前序
//     print(root->l);
//     //cout<<root->key<<" ";中序
//     print(root->r);
//     //cout<<root->key<<" ";后序
// }
// void print2(Node * root){
//     stack< root * > st;
//     Node * p=root;
//     while (p || st.size()){
//         while (p){
//             st.push(p);
//             p=p->l;
//         }
//         p=st.top();
//         st.pop();
//         cout<<p->key<<" ";
//         p=p->r;
//     }
// }
// int findmin(Node *root){
//     if (root==nullptr){
//         return -1;
//     }
//     while (root->l!=nullptr){
//         root=root->l;
//     }
//     return root->key;
// }
// int hgt(Node *root){
//     if (root==nullptr) return ;
//     return max(hgt(root->l),hgt(root->r))+1;
// }
// Node* findmin2(Node *root){
//     if (root==nullptr){
//         return nullptr;
//     }
//     while (root->l!=nullptr){
//         root=root->l;
//     }
//     return root;
// }
// int findmax(Node *root){
//     if (root==nullptr){
//         return -1;
//     }
//     while (root->r!=nullptr){
//         root=root->r;
//     }
//     return root->key;
// }
// bool search(Node * root,int v){
//     if (root==nullptr){
//         return false;
//     }
//     if (root->key==v){
//         return true;
//     } else if (v<root->key){
//         return search(root->l,v);
//     } else {
//         return search(root->r,v);
//     }
// }
// Node *insert(Node *root,int v){
//     if (root==nullptr){
//         return new Node (v); 
//     }
//     if (v<root->key){
//         root->l=insert(root->l,v);
//     } else if (v>root->key){
//         root->r=insert(root->r,v);
//     } else {
//         root->cnt++;
//     }
//     root->size=root->cnt+(root->l?root->l->size:0)+(root->r?root->r->size:0);
//     return root;
// }
// Node *erase(Node *root,int v){
//     if (root==nullptr){
//         return root;
//     }
//     if (v<root->key){
//         root->l=erase(root->l,v);
//     } else if (v>root->key){
//         root->r=erase(root->r,v);
//     } else {
//         if (root->cnt>1){
//             root->cnt--;
//         } else {
//             if (root->l==nullptr){
//                 Node *t=root->r;
//                 delete root;
//                 return t;
//             } else if (root->r==nullptr){
//                 Node *t=root->l;
//                 delete root;
//                 return t;
//             } else {
//                 Node *t=findmin2(root->r);
//                 root->key=t->key;
//                 root->cnt=t->cnt;
//                 t->cnt=1;
//                 root->r=erase(root->r,t->key);
//             }
//         }
//     }
//     root->size=root->cnt+(root->l?root->l->size:0)+(root->r?root->r->size:0);
//     return root;
// }
// int queryRank(Node* root, int v) {
//   if (root == nullptr) return 0;
//   if (root->key == v) return (root->l ? root->l->size : 0) + 1;
//   if (root->key > v) return queryRank(root->l, v);
//   return queryRank(root->r, v) + (root->l ? root->l->size : 0) +
//          root->cnt;
// }
// bool isbst(Node * root){
//     if (root=nullptr) return 1;
//     if (!isbst(root->l)) return 0;
//     if (root->key<=p) return 0;
//     p=root->key;
//     if (!isbst(root->r)) return 0;
//     return 1;
// }
// int main(){
//     Node *root=nullptr;
//     root=insert(root,1);
//     root=insert(root,2);
//     root=insert(root,3);
//     root=insert(root,4);
//     root=insert(root,5);
//     root=insert(root,6);
//     root=insert(root,7);
//     root=insert(root,8);
//     print2(root);
//     cout<<findmin(root)<<" "<<findmax(root)<<endl;
//     root=erase(root,1);
//     root=erase(root,8);
//     cout<<findmin(root)<<" "<<findmax(root)<<endl;
//     print2(root);
//     cout<<queryRank(root,6)<<endl;
// }

//AVL树
// #include<bits/stdc++.h>
// using namespace std;
// struct Node {
//     int v;
//     Node * l;
//     Node * r;
//     int h;
//     Node (int v):
//     v(v),l(nullptr),r(nullptr),h(1){}
// };
// int hgt(Node * root){
//     return root ? root->h : 0;
// }
// int phen(Node * root){
//     return root ? hgt(root->l)-hgt(root->r): 0;
// }
// Node * rx(Node * y){
//     Node * x=y->l;
//     Node * t2=x->r;
//     x->r=y;
//     y->l=t2;
//     x->h=max(hgt(y->l),hgt(y->r))+1;
//     y->h=max(hgt(y->l),hgt(y->r))+1;
//     return x;
// }
// Node * lx(Node * x){
//     Node *y=x->r;
//     Node *t2=y->l;
//     y->l=x;
//     x->r=t2;
//     x->h=max(hgt(x->l),hgt(x->r))+1;
//     y->h=max(hgt(y->l),hgt(y->r))+1;
//     return y;
// }
// Node * insert(Node * root,int v){
//     if (root==nullptr) return new Node (v);
//     if (v<root->v){
//         root->l=insert(root->l,v);
//     } else if (v>root->v){
//         root->r=insert(root->r,v);
//     } else {
//         return root;
//     }
//     root->h=max(hgt(root->l),hgt(root->r))+1;
//     int bal=phen(root);
//     if (bal>1 && v<root->l->v){
//         return rx(root);
//     }
//     if (bal>1 && v>root->l->v){
//         root->l=lx(root->l);
//         return rx(root);
//     }
//     if (bal<-1 && v<root->r->v){
//         root->r=rx(root->r);
//         return lx(root);
//     }
//     if (bal<-1 && v>root->r->v){
//         return lx(root);
//     }
//     return root;
// }
// Node *minroot(Node * root){
//     while (root->l!=nullptr){
//         root=root->l;
//     }
//     return root;
// }
// Node * erase(Node *root,int v){
//     if (root==nullptr) return root;
//     if (v<root->v){
//         root->l=erase(root->l,v);
//     } else if (v>root->v){
//         root->r=erase(root->r,v);
//     } else {
//         if (root->l==nullptr || root->r==nullptr){
//             Node * t=root->l? root->l:root->r;
//             if (t==nullptr){
//                 t=root;
//                 root=nullptr;
//             } else {
//                 *root=*t;
//             }
//             delete t;
//         } else {
//             Node * t=minroot(root->r);
//             root->v=t->v;
//             root->r=erase(root->r,t->v);
//         }
//     }
//     if (root==nullptr) return root;
//     root->h=max(hgt(root->l),hgt(root->r))+1;
//     int bal=phen(root);
//     if (bal>1 && phen(root->l)>=0){
//         return rx(root);
//     }
//     if (bal>1 && phen(root->l)<0){
//         root->l=lx(root->l);
//         return rx(root);
//     }
//     if (bal<-1 && phen(root->r)<=0){
//         return lx(root);
//     } 
//     if (bal<-1 && phen(root->r)>0){
//         root->r=rx(root->r);
//         return lx(root);
//     }
//     return root;
// }
// void print(Node* root) {
//     if (!root) return;
//     print(root->l);
//     cout << root->v << " ";
//     print(root->r);
// }
// int main(){
//     Node * root=nullptr;
//     root=insert(root,1);
//     root=insert(root,2);
//     root=insert(root,3);
//     root=insert(root,4);
//     root=insert(root,5);
//     root=insert(root,6);
//     print(root);
//     root=erase(root,1);
//     print(root);
// }

//手戳红黑树
//想啥呢，我也不会
// 说说原理
// 1:左根右
// 2:跟叶黑
// 3:不红红
// 4:黑路同
// 一:插入要素
// (插入元素都是红节点)
// 1:根节点直接变黑
// 2:叔叔红则将叔叔和爸爸与爷爷变色
// 3:叔叔黑则旋转,变色
// 二,删除要素
// 一,删除节点只有左或右孩子----直接替代然后变色
// 二,删除节点没有孩子--{
//         1,红节点---无需调整
//         2,黑节点---{
//             1,兄弟至少有红孩子---{
//                 变色为上代颜色,父亲变黑
//                 (LL,RR)连续变色(LR,Rl)单点变色,旋转,双黑节点变单黑
//             }
//             2,兄弟全为黑孩子---{
//                 兄弟变红,双黑变单黑,上移,遇到根或红则变单黑
//             }
//         }
// }

//huffman树
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+10;
// struct tree {
//     int w;
//     int p,l,r;
// } HT[2*N];
// char * HC[N];
// char hc[N];
// void Select(int n,int & s1,int & s2){
//     int min1=0x3f3f3f3f,min2=0x3f3f3f3f;
//     s1=0,s2=0;
//     for (int i=1;i<=n;i++){
//         if (HT[i].p==0){
//             if (HT[i].w<min1){
//                 min2=min1;
//                 s2=s1;
//                 min1=HT[i].w;
//                 s1=i;
//             } else if (HT[i].w<min2){
//                 min2=HT[i].w;
//                 s2=i;
//             }
//         }
//     }
// }
// void GreatTree(int n){
//     int T=2*n-1;
//     for (int i=1;i<=T;i++){
//         HT[i].l=HT[i].p=HT[i].r=HT[i].w=0;
//     }
//     for (int i=1;i<=n;i++){
//         cin>>HT[i].w;
//     }
//     for (int i=n+1;i<=T;i++){
//         int s1=0,s2=0;
//         Select(i-1,s1,s2);
//         HT[i].l=s1;
//         HT[i].r=s2;
//         HT[s1].p=i;
//         HT[s2].p=i;
//         HT[i].w=HT[s1].w+HT[s2].w;
//     }
// }
// void CodeTree(int n){
//     for (int i=1;i<=n;i++){
//         string s="";
//         int now=i;
//         int len=0;
//         while (HT[now].p!=0){
//             int u=HT[now].p;
//             if (HT[u].l==now) s+="0";
//             else s+="1";
//             now=u;
//         }
//         reverse(s.begin(),s.end());
//         HC[i] = new char[s.size()+1];
//         strcpy(HC[i], s.c_str());
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     GreatTree(n);
//     CodeTree(n);
//     for (int i=1;i<=n;i++){
//         cout<<HC[i]<<endl;
//     }
// }

