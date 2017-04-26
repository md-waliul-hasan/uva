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
	ll n,m,x,y,tc,p,d;
    scanf("%lld",&tc);
    while(tc--){
    scanf("%lld%lld",&p,&d);
    while(d--){
	scanf("%lld%lld",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
}
    bfs(0);
     
    for(i=1;i<p;i++)cout<<level[i]<<endl;
    for(i=0;i<1002;i++)g[i].clear();

    if(tc)cout<<endl;
}
	return 0;
}
