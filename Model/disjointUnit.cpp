const int MAXN = 1e5 + 5;

int fa[MAXN];
int Find(int x) { return fa[x] == x ? fa[x] : (fa[x] = Find(fa[x])); }