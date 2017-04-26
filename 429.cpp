#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector< ll >  g[202];
vector<string> vt;
ll level[202];
ll parent[202];
void bfs( ll src)
{
    queue<ll>q;
    ll i,visited[202]={0};
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
    ll n,i,j,k;
    string s,x,y,source,destination;
    scanf("%lld",&n);
    while(n--)
    {
        map<string,ll>mp;
        ll c=0;
        while(cin>>s && s!="*")
        {
             vt.push_back(s);
             mp[s]=++c;
        }
        for(i=0;i<vt.size();i++){
            for(j=0;j<vt.size();j++){
                x=vt[i]; y=vt[j];
                ll l1=x.size(),l2=y.size();
                ll cnt=0;
                if(l1=l2)
                {
                    for(k=0;k<l1;k++)if(x[k]==y[k])cnt++;
                    if(l1-cnt ==1){
                        g[mp[x]].push_back(mp[y]);
                        g[mp[y]].push_back(mp[x]);
                    }
                }
            }
        }
    string line;
    size_t pos;
    getline(cin,line);
    getline(cin,line);
    while(line != ""){
      pos = line.find(" ");
      source = line.substr(0,pos);
      destination = line.substr(pos+1,line.size());
      bfs(mp[source]);
      cout<<source<<" "<<destination<<" "<<level[mp[destination]]<<endl;
      if(!getline(cin,line))
        break;
    }
       if(n) puts("");   
       for(i=0;i<202;i++)g[i].clear();
       vt.clear();   
    }



	return 0;
}
