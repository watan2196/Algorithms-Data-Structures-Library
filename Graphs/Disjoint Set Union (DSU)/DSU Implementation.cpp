#include <bits/stdc++.h>
using namespace std;
//Disjoint Set Union
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;
vector<int>g[N];
int find(int x,vector<int> &parent);
void merge(int a,int b,vector<int> &parent);
int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;
	cin>>n>>m;
	
	vector<int>parent(n+1,-1);
	
	
	
	for(int j=0;j<m;j++)
	{
		cin>>a>>b;
		a=find(a,parent);
		b=find(b,parent);
		if(a != b)
		merge(a,b,parent);	
	}	
	
	   for(int i=1;i<=n;i++)
	   cout<<parent[i]<<" ";
	   
	   cout<<endl;

	return 0;
}
int find(int x,vector<int> &parent)
{
	if(parent[x] < 0)
	return x;
	else
	return find(parent[x],parent);
}
void merge(int a,int b,vector<int> &parent)
{
	parent[b]+=parent[a];
	parent[a]=b;
}
