#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE
//XOR tree
const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;
vector<int>g[N];
int xorsum[N];
int vis[N];
int val[N];
int cxor=0;
map<int,int>mp;
int dfs(int node)
{
	vis[node]=1;
	int cxor=val[node];
	
	for(int v:g[node])
	{
		if(!vis[v])
		cxor=cxor^dfs(v);
	}
	mp[cxor]++;
	xorsum[node]=cxor;
	return cxor;
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		
		for(int i=0;i<n;i++)
		cin>>val[i];
		
		int xr=dfs(0);
		
		xorsum[0]=xr;
		
		
		
		int mx=INT_MIN;
		int ans;
		for(auto it:mp)
		{
			if(it.first > mx)
			{
				mx=it.first;
				ans=it.second;
			}
		}
		
		cout<<mx<<" "<<ans<<endl;
	return 0;
}

