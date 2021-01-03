#include <bits/stdc++.h>
using namespace std;
//https://www.spoj.com/problems/TOPOSORT/
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;
vector<int>g[N];
int In[N];
vector<int>ans;
bool IsTopo(int n)
{

	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=1;i<=n;i++)
	{
		if(In[i] == 0)
		pq.push(i);
	}
	
	while(!pq.empty())
	{
		int node=pq.top();
		ans.push_back(node);
		pq.pop();
		
		
		for(int v:g[node])
		{
			In[v]--;
			if(In[v] == 0)
			pq.push(v);
		}
	}
	
//	for(auto it:ans)
//	cout<<it<<" ";
	
	if(ans.size() == n)
	return 1;
	else
	return 0;
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
	In[i]=0;	
	g[i].clear();
	}
	
	
	ans.clear();
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		In[b]++;
	}
	
	if(IsTopo(n) == 1)
	{
		for(auto it:ans)
		cout<<it<<" ";
	}
	else
	cout<<"Sandro fails."<<endl;
	
	   

	return 0;
}

