#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll> 
ll fx[]={2,1,-1,-2,-2,-1,1,2};
ll fy[]={-1,-2,-2,-1,1,2,2,1};
ll cell[1005][1005];
ll d[1005][1005];
ll vis[1005][1005];
ll row,col;
ll bfs(ll sx,ll sy,ll r,ll s)
{
	for(ll i=0;i<row;i++)for(ll j=0;j<col;j++)vis[i][j]=0;
	d[sx][sy]=0;
	vis[sx][sy]=1;
	queue<pii>q;
	q.push(pii(sx,sy));
	while(!q.empty())
	{
		pii top=q.front();q.pop();
		if(top.first==r && top.second==s)
			return d[r][s];
		for(ll k=0;k<8;k++)
		{
			ll tx=top.first+fx[k];
			ll ty=top.second+fy[k];
			if(tx>=0 && ty>=0 && ty<col && tx<row && vis[tx][ty]==0)
			{
				vis[tx][ty]=1;
				d[tx][ty]=d[top.first][top.second]+1;
				q.push(pii(tx,ty));
			}
		}
	}
}
int main()
{
	//freopen("output.txt","w",stdout);
	char sx,r;
	ll sy,s;
	row=8,col=8;
	while(cin>>sx>>sy>>r>>s){
	   ll fc,sc;
	   fc=sx-'a';
	   sy--;
	   sc=r-'a';
	   s--;
	ll dist=bfs(fc,sy,sc,s);
	printf("To get from %c%lld to %c%lld takes %lld knight moves.\n",sx,++sy,r,++s,dist );
}
return 0;
}
