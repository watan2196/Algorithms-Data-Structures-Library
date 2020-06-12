#include <bits/stdc++.h>
using namespace std;
//RMQ Trivial approach with O(n^3)/O(n^2) dp preprocessing and O(1) query
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,b;

int a[N];
int RMQ[1000][1000];
int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		//preprocessing in O(n^2)
		
		for(int i=0;i<n;i++)
		{
			RMQ[i][i]=i;
			for(int j=(i+1);j<n;j++)
			{
				if(a[RMQ[i][j-1]] < a[j])
				RMQ[i][j]=RMQ[i][j-1];
				else
				RMQ[i][j]=j;
			}
		}
	   
		//query in O(1)
		int q;
		cin>>q;
		int l,r;
		for(int i=0;i<q;i++)
		{
			cin>>l>>r;
			cout<<a[RMQ[l][r]]<<endl;
		}
	return 0;
}

