#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> g[205];
ll color[205],n,one,zero,f;

void dfs(ll src,ll clr)
{
	color[src]=clr;
	if(clr==1)one++;
	else zero++;
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
			
			one=0,zero=0,f=1;
			if(color[i]==2)
			{

				dfs(i,1);
				if(f==1)ans+=max(one,zero);
			}	
		}
		cout<<ans<<endl;
	}
}
