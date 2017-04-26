#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mx 1000000000
vector< ll >  g[5100];
ll level[5100];
ll parent[555100];
void bfs(ll n, ll src)
{
    queue<ll>q;
    ll i,visited[51000]={0};
    q.push(src);
    for(i=0;i<5100;i++)level[i]=mx;
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
	ll i,j,k;
	ll n,m,a,b,tc=1;
    string x,y,source,destination;
    map<string , ll> mp1;
    map<ll,string> mp2;
    ll f=0;
	while(cin>>n){
        for(i=0;i<5100;i++)g[i].clear();
        mp1.clear();mp2.clear();
        if(f) printf("\n");
        f = 1;
    ll c=0;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
        if(!mp1[x]){
            mp1[x]=++c;
            mp2[c]=x;
            }
        if(!mp1[y])
            {
                mp1[y]=++c;
                mp2[c]=y;
            }
		g[mp1[x]].push_back(mp1[y]);
		g[mp1[y]].push_back(mp1[x]);
	}
    
    cin>>source>>destination;
    if((!mp1[source]) ||(!mp1[destination])){printf("No route\n");continue;}
    bfs(c,mp1[source]);

    if(level[mp1[destination]]==mx){printf("No route\n");}
    else{
    ll temp[51000];
    temp[0]=mp1[destination];
    ll counter=0;
    for(i=mp1[destination];;){
        if(mp1[source]==i)break;
        temp[++counter]=parent[i];
        i=parent[i];
    }
    for(i=counter;i>=1;i--)cout<<mp2[temp[i]]<<" "<<mp2[temp[i-1]]<<endl;
        }
    }
	return 0;
    }
