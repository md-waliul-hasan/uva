#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector< ll >  g[1002];
ll level[1002];
ll parent[1002];
void bfs(ll src)
{
    queue<ll>q;
    ll i,visited[1002]={0};
    q.push(src);
    
    visited[src]=1;
    level[src]=0;
    while(!q.empty())
    {
    	ll u=q.front(); q.pop();
    	for(i=0;i<g[u].size();i++)
    	{
    		ll v=g[u][i];
    		if(!visited[v])
    		{
    			level[v]=level[u]+1;
    			parent[v]=u;
    			visited[v]=1;
    			q.push(v);
    		}
    	}
    }  
}

int main()
{
    //freopen("output.txt","w",stdout);
	ll i,j,k;
    string x,y,source,destination;
	ll n,m,tc;
    scanf("%lld",&tc);
    while(tc--){
    map<string, ll> mp;
    map<ll, string> mp1;
	cin>>m>>n;
    ll c=0;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
        if(!mp[x]){mp[x]=++c;mp1[c]=x;}
        if(!mp[y]){mp[y]=++c;mp1[c]=y;}
        g[mp[x]].push_back(mp[y]);
		g[mp[y]].push_back(mp[x]);
	}
    while(n--){
        cin>>source>>destination;
        bfs(mp[source]);
        string path="";
        for(i=mp[destination];;)
        {
            string hmmm=mp1[i];
            path.push_back(hmmm[0]);
            if(i==mp[source])break;
            i=parent[i];
        }
        for(i=path.size()-1;i>=0;i--)cout<<path[i];
        cout<<endl;
}
    if(tc)cout<<endl;
    for(i=0;i<1002;i++)g[i].clear();
}
	return 0;
}
