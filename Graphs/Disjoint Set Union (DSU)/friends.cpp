#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;
unordered_set<int>st;
int parent[N];
int sz[N];
int find(int x)
{
	if(parent[x] < 0)
	return x;
	else
	return parent[x]=find(parent[x]);
}
void merge(int a,int b)
{
	a=find(a);
	b=find(b);
	if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        sz[a] += sz[b];    
        parent[b] = a;
        st.insert(a);
    }
}

int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;
       int node;
       	cin>>node;
       	for(int i=1;i<=node;i++)
       	{
       		parent[i]=-1;
       		sz[i]=1;
		}
		
		cin>>n;
		
		vector<vector<int> >v1(n,vector<int>(2,0));
		
		for(int i=0;i<n;i++)
	   	cin>>v1[i][0]>>v1[i][1];
		
		cin>>m;
		vector<vector<int> >v2(m,vector<int>(2,0));
	   	
		for(int i=0;i<m;i++)
	   	cin>>v2[i][0]>>v2[i][1];
	   	
	   
	   	
	   	for(int i=0;i<n;i++)
	   	{  
	   		a=find(v1[i][0]);
	   		b=find(v1[i][1]);
		   	if(a!=b)
		   merge(v1[i][0] , v1[i][1]);
		}
		
		
		
		int flag=0;int ans=0;
		for(int i=0;i<m;i++)
	   	{  
	   		a=find(v2[i][0]);
	   		b=find(v2[i][1]);
	   		if(st.find(a) != st.end() || st.find(b) != st.end())
	   		{
			   flag=1;break;
			}
		   	if(a!=b)
		   	{
			   if (sz[a] < sz[b])
            		swap(a, b);
        		sz[a] += sz[b];    
        		parent[b] = a;
        	}
		}
		
		
		
		int cnt=0;
		for(int i=1;i<=node;i++)
		{
			if(parent[i] < 0)
			cnt++;
		}
		
		
		ans=(int)pow(2,cnt) % mod;
		if(flag)
		cout<<0<<endl;
		else
		cout<<ans<<endl;
		
	return 0;
}

