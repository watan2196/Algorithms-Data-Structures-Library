#include <bits/stdc++.h>
using namespace std;
//cycle detection in a directed graph
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;
vector<int>g[N];
int vis[N];
int stk[N];
bool dfs(int node);
int HasCycle();
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
		}
		
		int ans=HasCycle();
		cout<<ans<<endl;	
}
int HasCycle()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i] && dfs(i))
		cnt++;
	}
	return cnt;
}
int dfs(int node)
{
	if(vis[node] == 1)
	return 1;
	if(vis[node] == 2)
	return 0;
	
	vis[node]=1;
	for(int v:g[node])
	{
		cnt+=dfs(v);
	}
	vis[node]=2;
	return 0;
}
