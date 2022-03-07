##### tarjan求割点

```cpp
int n,m,cnt_dfn;
int low[N],dfn[N];
bool vis[N];
vector<int> g[N];

void tarjan(int u,int root){
    low[u]=dfn[u]=++cnt_dfn;
    int cnt_son=0;
    for(auto x:g[u]){
        if(low[x]==0){
            tarjan(x,root);
            low[u]=min(low[u],low[x]);
            if(low[x]>=dfn[u]&&u!=root) vis[u]=1;
            if(u==root) cnt_son++;
        }
        low[u]=min(low[u],dfn[x]);
    }
    if(cnt_son>=2&&u==root){
        vis[u]=1;
    }
}

int main(){
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]==0) tarjan(i,i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==1) ++ans;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        if(vis[i]) cout<<i<<" ";
    }
    return 0;
}

```

