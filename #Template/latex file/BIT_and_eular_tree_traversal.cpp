vector<int> adj[mx];
lli in[mx], out[mx], temp[2 * mx], BITree[2 * mx], tax[mx], t = 0;
lli get(int idx)
{
    lli sum = 0;idx = idx + 1;
    while (idx > 0){
        sum += BITree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update(int n, int idx, lli val){
    idx = idx + 1;
    while (idx <= n)
    {
        BITree[idx] += val;
        idx += idx & (-idx);
    }
}
void build_BITree(int n){
    for (int i = 1; i <= n; i++)
        BITree[i] = 0;
    for (int i = 0; i < n; i++){
        update(n, i, temp[i]);
    }
}
void dfs(int u, int parent){                ///euler tree traversal using dfs
    in[u] = t++; ///first visiting time
    for (auto child : adj[u]){
        if (child != parent)
            dfs(child, u);
    }
    out[u] = t++; ///last visiting time
}
int main(){
    ll node, query;
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
        cin >> tax[i];
    dfs(1, 0);
    tax[1] = 0;
    for (int i = 1; i <= n; i++){ ///tree ke akta array te convert
        /// korlm euler tree traversal algo diye
        temp[in[i]] = tax[i];
        temp[out[i]] = -(tax[i]);
        //cout<<temp[in[i]]<<" "<<temp[out[i]]<<endl;
    }
    build_BITree(t);
}
