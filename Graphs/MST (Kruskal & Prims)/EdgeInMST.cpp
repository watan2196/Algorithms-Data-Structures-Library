#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;
struct edge
{
	int a;
	int b;
	int wt;
};
bool comp(edge e1,edge e2)
{
	if(e1.wt <= e2.wt)
	return true;
	
	return false;
}
int parent[N];
int find(int x)
{
	if(parent[x] < 0)
	return x;
	else
	return parent[x]=find(parent[x]);
}
void merge(int a,int b)
{
	parent[a]=b;
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
	parent[i]=-1;
	
	vector<edge>edg(m,{0,0,0});
	for(int i=0;i<m;i++)	   
	cin>>edg[i].a>>edg[i].b>>edg[i].wt;
	
	set<pair<int,int>>st;
	vector<edge>edg2;
	edg2=edg;
	
	sort(edg.begin(),edg.end(),comp);
	vector<edge>res;
	for(int i=0;i<m;i++)
	{
		a=find(edg[i].a);
		b=find(edg[i].b);
		
		if(a != b)
		{
		res.push_back(edg[i]);
		st.insert({edg[i].a,edg[i].b});
		merge(a,b);
		}
	}
	
	cout<<endl;
	
	for(auto it:st)
	cout<<it.first<<" "<<it.second<<endl;
	
	
	cout<<endl;
	
	vector<int>ans;
	for(int i=0;i<m;i++)
	{
		if(st.find({edg2[i].a,edg2[i].b}) != st.end())
		ans.push_back(1);
		else
		ans.push_back(0);
	}
	
	for(auto it:ans)
	cout<<it<<" ";
	
	
	
	return 0;
}

