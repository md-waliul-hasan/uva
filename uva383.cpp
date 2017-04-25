#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mx 1000000007
vector< ll >  g[35];
ll level[35];
ll parent[35];
void bfs(ll n, ll src)
{
    queue<ll>q;
    ll i,visited[35]={0};
    q.push(src);
    for(i=0;i<35;i++)level[i]=mx;
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
	ll t,tc,m,n,p,i,j,k;
    string x,y,s,source,destination;
    scanf("%lld",&t);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for(tc=1;tc<=t;tc++)
    {
        printf("DATA SET  %lld\n\n",tc );
        scanf("%lld%lld%lld",&m,&n,&p);
        map<string, ll> mp;
        for(i=1;i<=m;i++){
            cin>>s;
            mp[s]=i;
        }
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            g[mp[x]].push_back(mp[y]);
            g[mp[y]].push_back(mp[x]);
        }
        for(j=0;j<p;j++)
        {
            cin>>k>>source>>destination;
            bfs(m,mp[source]);
            if(!mp[source] || !mp[destination] || level[mp[destination]]==mx)
                printf("NO SHIPMENT POSSIBLE\n");
            else {
                printf("$%lld\n",level[mp[destination]]*k*100 );
            }
        }
        cout<<endl;
        for(i=0;i<35;i++)g[i].clear();
    }
    printf("END OF OUTPUT\n");

	return 0;
}