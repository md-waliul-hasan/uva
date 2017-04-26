#include<bits/stdc++.h>
using namespace std;
#define mx 2505
#define tuttut 100000007
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
    for(i=0;i<mx;i++)level[i]=tuttut;
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
            }}}}

int main()
{
    //freopen("output.txt","w",stdout);
   ll tc,i,n,j,k,x,y,l,t,src,dest;
   scanf("%lld",&n);
   for(i=0;i<n;i++)
   {
       scanf("%lld",&t);
       while(t--)
       {
           scanf("%lld",&x);
           g[i].push_back(x);
       }
   }
       scanf("%lld",&tc);
       while(tc--)
       {
           scanf("%lld",&src);
           if(g[src].size()==0)printf("0\n");
           else
           {
               bfs(src);
               ll l1=0,ml[n+2],bl[n+2],mxlvl=-1;
               for(i=0;i<n;i++)ml[i]=bl[i]=0;
               for(i=0;i<n;i++){
                    if(level[i]!=tuttut)ml[level[i]]++;
               }
               ll ans;
               for(i=1;i<n;i++)if(ml[i]>mxlvl){mxlvl=ml[i];ans=i;}
               printf("%lld %lld\n",mxlvl,ans);
           }
       }
     for(i=0;i<mx;i++)g[i].clear();
return 0;
}

