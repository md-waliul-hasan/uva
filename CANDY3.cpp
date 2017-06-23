//the reason behind i am crating this file is modular property...if you don't use
//mod in every step of sum and just check the sum modulo n then you will get WA. 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll tc,i,n;
	string s;
	cin>>tc;
	while(tc--)
	{
		cin>>n;
		ll x,sum=0;
		for(i=0;i<n;i++)
		{
			cin>>x;
			sum+=x;
			sum%=n;
		}
		if(sum==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
