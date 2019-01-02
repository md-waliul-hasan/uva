#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> g[205];
ll color[205];
ll bfs(ll src,ll n)
{

	queue<ll>q;
	q.push(src);
	color[src]=1;
	ll f=1,one=0,s=0,i;

	while(!q.empty())
	{
		ll u=q.front();q.pop();
		if(u<=n)s++;
		if(color[u]==1 && u<=n)one++;
		for(i=0;i<g[u].size();i++)
		{
			ll v=g[u][i];
			if(color[v]==2)
			{
				color[v]=1-color[u];
				q.push(v);
			}
			else if(color[u]==color[v])
			{
				f=0;
			}
		}
	}
	if(f==0)return 0;
	else{
	if(s==1)return 1;
	
	return max(one,s-one);
}
}
int main()
{
	ll n,i,j,tc;
	cin>>tc;
	while(tc--)
	{
		for(i=0;i<205;i++)g[i].clear();
		string blank;
		getline(cin,blank);
		cin>>n;
		for(i=1;i<=n;i++)
		{
			ll x;
			cin>>x;
			while(x--)
			{
				ll y;
				cin>>y;
				g[i].push_back(y);
				g[y].push_back(i);
			}
		}
		
		ll ans=0;
		for(i=0;i<205;i++)color[i]=2;
		for(i=1;i<=n;i++)
		{
			
			ll temp;
			if(color[i]==2)
			{

				temp=bfs(i,n);
				ans+=temp;
			}	
		}
		cout<<ans<<endl;
	}
}
