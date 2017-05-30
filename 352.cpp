#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
ll fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
ll flag[505][505],row,col;
char cell[1005][1005];
void floodfill(ll i,ll j)
{
    if(i<0 || j<0 || i>=row || j>=col)return;

    if(cell[i][j]=='1' && flag[i][j]==0)
    {
        flag[i][j]=1;
        for(ll k=0;k<8;k++)
        {
            ll x=i+fx[k];
            ll y=j+fy[k];
            floodfill(x,y);
        }
    }
}
int main()
{
    ll i,j,cnt;
    ll tc=0;
    while(cin>>row){
        col=row;
    memset(flag,0,sizeof(flag));
    getchar();
    for(i=0;i<row;i++){
            for(j=0;j<col;j++) scanf("%c", &cell[i][j]);
            getchar();
    }
    cnt=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(cell[i][j]=='1' && flag[i][j]==0)
            {
                cnt++;
                floodfill(i,j);
            }
        }
    }
   printf("Image number %lld contains %lld war eagles.\n",++tc,cnt);
    }
}

