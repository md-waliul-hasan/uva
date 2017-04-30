#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mx 1000000005
vector< ll >  g[400];
char s[305],*tok;
ll level[400];
ll parent[400];
void bfs(ll src)
{
    queue<ll>q;
    ll i,visited[400]={0};
    q.push(src);
    for(i=0;i<400;i++)level[i]=mx;
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
    ll n,m,i,j,x,y,num;
    
    while(scanf("%lld\n", &n)==1){
        for ( i=1 ; i<=n ; i++) {
            gets(s);
            tok = strtok(s, " ,-");
            while ((tok = strtok(NULL, " ,-")) != NULL) {
                sscanf(tok, "%lld", &num);
                g[i].push_back(num);
            }
        }
        printf("-----\n");
    scanf("%lld",&m);
    while(m--)
    {
        scanf("%lld%lld",&x,&y);
        bfs(x);
        if(level[y]==mx)printf("connection impossible\n");
        else{
        vector<ll>v;
        v.push_back(y);
        for(i=parent[y];i!=x;i=parent[i])
        { 
            v.push_back(i);
        }
        v.push_back(x);
            for(i=v.size()-1;i>=0;i--){
                printf("%lld",v[i]);
                if(i)printf(" ");
            }
            printf("\n");
        }
    }
    for(i=0;i<400;i++)g[i].clear();
}
	return 0;
}
