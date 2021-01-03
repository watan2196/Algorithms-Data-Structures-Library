#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b,sum;
vector<int>g[N];
int vis[N];
int st[N];
void dfs(int node)
{
	vis[node]=1;
	sum+=st[node-1];
	for(int v:g[node])
	{
		if(!vis[v])
		dfs(v);
	}
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;
	int d;
	   	cin>>n>>m;
	   	for(int i=0;i<m;i++)
	   	{
	   		cin>>a>>b;
	   		g[a].push_back(b);
			g[b].push_back(a);	
		}
		
		for(int i=0;i<n;i++)
		cin>>st[i];
		cin>>d;
		int cnt=0;sum=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				dfs(i);
				if(sum >= d)
				cnt++;
			}
			sum=0;
		}
		cout<<cnt<<endl;
	return 0;
}

