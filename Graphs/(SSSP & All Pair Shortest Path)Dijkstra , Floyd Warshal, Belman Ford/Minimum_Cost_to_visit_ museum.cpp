//Multi-source Dijkstra
//Minimum cost to visit the museum
//
//Shadowland is a beautiful city with N museums which are connected
//with bidirectional roads. The city can be represented as a graph with N nodes
//representing museums and M edges representing roads.
//There is a cost of traveling each road in order to move from the front of one
//museum to that of the other. However, there is an additional cost one has to 
//pay if and only if he decides to enter the museum.
//The cost of entering the museums need not be the same.
//
//For each museum i, Abhishek wants to know the minimum total amount he has to
//pay if he starts his journey from the front of the ith museum and enters any
//one museum. 
//
//Given an array of integers A of size N for which A[i] represents the cost of
//entering the i'th museum. And three more integer arrays B, C and D. B[i], C[i]
//and D[i] represents the i'th road i.e. there is an edge from B[i] to C[i] with
//edge weight D[i].
//
//Find and return the integer array in which the i'th element represents the 
//minimum cost Abhishek has to pay in order to visit any museum if he is standing
//in front of the i'th museum.
//
//Input 1:
//    A = [1, 2, 3, 1, 5]
//    B = [1, 2, 3, 4]
//    C = [2, 3, 4, 5]
//    D = [1, 1, 1, 1]
//Output 1:
//    [1, 2, 2, 1, 2]
//
//Input 2:
//    A = [5, 17, 100, 11]
//    B = [2, 3]
//    C = [1, 4]
//    D = [5, 50]
//Output 2:
//    [5, 10, 61, 11]


#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,x,y,wt,u;
vector<pair<int,int> >g[N];
vector<int>dis,a;
void museum_dis(vector<int> &a);
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
	   		cin>>x>>y>>wt;
	   		g[x].push_back({y,wt});
	   		g[y].push_back({x,wt});
		}
		
		a.resize(n);
		
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		
		
		museum_dis(a);
	
	return 0;
}
void museum_dis(vector<int> &a)
{
	int n=a.size();
	dis.resize(n+1);
	set<pair<int,int> >st;
	
	for(int i=0;i<n;i++)
	{
	dis[i+1]=a[i];
	st.insert({a[i],i+1});
	}	
	
	while(!st.empty())
	{
		auto x=*(st.begin());
		st.erase(x);
		int u=x.second;
		
		for(auto v:g[u])
		{
			if(dis[v.first] + v.second < dis[u])
			{
				//st.erase({dis[u],u})
				dis[u]=dis[v.first] + v.second;
				st.insert({dis[u],u});
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	cout<<dis[i]<<" ";
	
	
}
