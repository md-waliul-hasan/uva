#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll> 
ll fx[]={1,-1,0,0};
ll fy[]={0,0,1,-1};
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
		for(ll k=0;k<4;k++)
		{
			ll tx=top.first+fx[k];
			ll ty=top.second+fy[k];
			if(tx>=0 && ty>=0 && ty<col && tx<row && cell[tx][ty]!=-1 && vis[tx][ty]==0)
			{
				vis[tx][ty]=1;
				d[tx][ty]=d[top.first][top.second]+1;
				q.push(pii(tx,ty));
			}
		}
	}
	return -1;
}
int main()
{
	//freopen("output.txt","w",stdout);
	while(scanf("%lld%lld",&row,&col)&& row && col){
	    for(ll i=0;i<row;i++)for(ll j=0;j<col;j++)cell[i][j]=0;
	    ll ro;
	    cin>>ro;
	    for(ll i=0;i<ro;i++)
	    {
	    	ll x, y;
            cin>>y>>x;
            while(x--)
            {
            	ll place;
            	cin>>place;
            	cell[y][place]=-1;
            }
	    }
	ll sx,sy,r,s;
	scanf("%lld%lld",&sx,&sy);
	scanf("%lld%lld",&r,&s);
	ll dist=bfs(sx,sy,r,s);
	printf("%lld\n",dist );
}
return 0;
}
