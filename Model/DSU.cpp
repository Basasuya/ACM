int fa[MAXN];
int Find(int x) { return fa[x] == x ? fa[x] : (fa[x] = Find(fa[x])); }