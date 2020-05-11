#include <bits/stdc++.h>
using namespace std;
//0-1 BFS  
// Useful when the graph only has weights 0 or 1.
// Complexity becomes O(V+E)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;
const int INF=1e9;
int i,j,n,cnt,res,m,t,a,b,wt,src;
vector<pair<int,int> >g[N];
void O_1_BFS(int src);
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
	   	cin>>a>>b>>wt;
	   	g[a].push_back({b,wt});
	   	g[b].push_back({a,wt});
	   }
	   
	   	cin>>src;
	   	
	   	O_1_BFS(src);
		
		
	return 0;
}
void O_1_BFS(int src)
{
	vector<int>dis(n+1,INF);
	
	deque<int>dq;
	
	dis[src]=0;
	
	dq.push_front(src);
	
	while(!dq.empty())
	{
		int x=dq.front();
		dq.pop_front();
		
		for(auto v:g[x])
		{
			int u=v.first;
			int wt=v.second;
			if(dis[x] + wt < dis[u])
			{
			dis[u]=dis[x] + wt;
			if(wt == 1)
			dq.push_back(u);
			else
			dq.push_front(u);
			}
		}
	}
	for(int i=1;i<=n;i++)
	cout<<dis[i]<<" ";
	
}
