#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE
//Dijkstra - 
const int N=1e5+5;
const int mod=1e9+7;
//const int INF=1e9+7;

int i,j,n,cnt,res,m,t,a,b,wt,src;
vector<pair<int,int>>g[N];
vector<int>dis;
void dijkstra(int src);
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
		
		dijkstra(src);
		
		
		
	return 0;
}
void dijkstra(int src)
{
	vector<int>dis(n+1,INT_MAX); // min-distance array
	
	set<pair<int,int> >s; // a set to allow insert, delete and min edge wt node in o(logn)
	
	s.insert({0,src}); // initially we insert the source node at distance 0 from the source itself
	dis[src]=0;       // update the min distance of source node
	
	while(!s.empty())  // perform till set is empty
	{
		auto x= *(s.begin());  // extract the min weight edged node
		s.erase(x);            // delete it from the set
		int u=x.second;        // the node value of the min edge 
		
		for(auto v:g[u])
		{
			if(dis[v.first] > dis[u] + v.second)  
			{
					s.erase({dis[v.first],v.first});
					dis[v.first]=dis[u] + v.second;
					s.insert({dis[v.first],v.first});
			}
		}
	}
	
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
}
// Problems:
// https://www.interviewbit.com/problems/dijsktra/
