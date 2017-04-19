#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector< ll >  g[35];
ll level[35];
ll parent[40];
void bfs(ll n, ll src)
{
    queue<ll>q;
    ll i,visited[35]={0};
    q.push(src);
    for(i=0;i<35;i++)level[i]=100000000;
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

    			level[v]=min(level[v],level[u]+1);
    			parent[v]=u;
    			visited[v]=1;
    			q.push(v);
    		}
    	}	
    } 
}

int main()
{
	ll i,j,k;
	ll n,m,x,y,a,b,tc=1;
    map<ll, ll> mp;
	while(cin>>n && n){
    ll c=0;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
        if(!mp[x])mp[x]=++c;
        if(!mp[y])mp[y]=++c;
        
		g[mp[x]].push_back(mp[y]);
		g[mp[y]].push_back(mp[x]);
	}
    while(scanf("%lld%lld",&a,&b)==2 )
    {
        if(a==0 & b==0 )break;
    
        bfs(n,mp[a]);
     ll cnt=0;
    for(i=1;i<=c;i++)
        {
            if(level[i]<=b)cnt++;
        }

    printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n",tc++,c-cnt,a,b );
}
for(i=0;i<35;i++)g[i].clear();
mp.clear();
}
	return 0;
}
