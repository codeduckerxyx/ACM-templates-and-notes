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

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+15;

int n,m;
vector<int> g[N];
bool vis[N];
int col[N];
int cnt[5];

bool check(){
    for(int i=1;i<=n;i++){
        cnt[ col[i] ]++;
    }
    for(int i=1;i<=n;i++){
        if( check_node(i)==0 ) return 0;
    }
    return 1;
}

int main(){
    cin>>n>>m; bool ok=1;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(auto x:g[1]){
        vis[x]=1;
    }
    int tem=-1;
    for(int i=1;i<=n;i++){
        if(vis[i]==0) col[i]=1;
        else tem=i;
        vis[i]=0;
    }
    if(tem==-1) ok=0;
    else{
        for(auto x:g[tem]){
            vis[x]=1;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0) col[i]=2;
            else tem=i;
            vis[i]=0;
            if(col[i]==0) col[i]=3;
        }
    }
    if( check()==0 ) ok=0;
    if(ok){
        for(int i=1;i<=n;i++){
            cout<<col[i]<<" ";
        }
    }else{
        cout<<-1<<endl;
    }
    return 0;
}

```

