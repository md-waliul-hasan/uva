#include<bits/stdc++.h>
using namespace std;
#define mx 100005
typedef long long ll;
vector< ll >  g[mx];
vector<string> vt;
ll level[mx];
ll parent[mx];
void bfs( ll src)
{
    queue<ll>q;
    ll i,visited[mx]={0};
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
   ll tc,i,n,j,k,x,y,l,t,src,dest;
   scanf("%lld",&tc);
   while(tc--)
   {
       scanf("%lld",&n);
       while(n--)
       {
           scanf("%lld%lld",&l,&t);
           while(t--){
            scanf("%lld",&x);
            g[l].push_back(x);
           }
       }
       scanf("%lld%lld",&src,&dest);
       bfs(src);
       printf("%lld %lld %lld\n",src,dest,level[dest]-1);
   if(tc)printf("\n");
   for(i=0;i<mx;i++)g[i].clear();
 }
return 0;
}
