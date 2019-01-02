#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> g[305];
ll color[305],f,n;

void dfs(ll src,ll clr)
{
	color[src]=clr;

	for(ll i=0;i<g[src].size();i++)
	{
		if(color[g[src][i]]==2 && g[src][i]<=n)
		{
			dfs(g[src][i],1-color[src]);
		}
		else if(color[g[src][i]]<2)
		{
			if(color[src]==color[g[src][i]])
				f=0;
		}
	}
}
int main()
{
	ll i,j,tc;
	
	while(cin>>n)
	{
		if(n==0)break;
		for(i=0;i<305;i++)g[i].clear();
	
		while(1)
		{
			ll x,y;
			cin>>x>>y;
			if(x==0 && y==0)break;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		for(i=0;i<305;i++)color[i]=2;
		f=1;
		dfs(1,1);
		if(f==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
