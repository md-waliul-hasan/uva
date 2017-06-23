#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1005][35];
ll n;
ll weight[1005],cost[1005];
ll func(ll i, ll w,ll cap)
{
	 
     if(i==n+1)return 0;
     if(dp[i][w]!=-1)return dp[i][w];
     
     ll profit1=0,profit2=0;
     if(w+weight[i]<=cap) 
     profit1 = cost[i] + func(i + 1,w + weight[i],cap);
     profit2=func(i+1,w,cap);
     return dp[i][w]=max(profit1,profit2);

}
int main()
{
	ll tc;
	cin>>tc;
	while(tc--){
	
    memset(weight,0,sizeof(weight));
    memset(cost,0,sizeof(cost));
    ll i,q,cap;
    cin>>n;
    for(i=1;i<=n;i++)cin>>cost[i]>>weight[i];
    cin>>q;
    ll sum=0;
    while(q--){
    	cin>>cap;
    	memset(dp,-1,sizeof(dp));
    	ll p=func(1,0,cap);
        sum+=p;
    }
    cout<<sum<<endl;
    }
}
