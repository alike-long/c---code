#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 20010;  // 无向边，存两次
int n, p, k;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(int x) {
    // 边权 ≤ x 花费 0，> x 花费 1，01-BFS
    memset(dist, 0x3f, sizeof dist);
    deque<int> q;
    dist[1] = 0;
    q.push_back(1);
    while (q.size()) {
        int u = q.front();
        q.pop_front();
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i], cost = (w[i] > x);
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                cost ? q.push_back(v) : q.push_front(v);
            }
        }
    }
    return dist[n] <= k;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> p >> k;
    int maxw = 0;
    for (int i = 0; i < p; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
        maxw = max(maxw, c);
    }
    int l = 0, r = maxw + 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        check(mid) ? r = mid : l = mid + 1;
    }
    cout << (l > maxw ? -1 : l);
    return 0;
}
