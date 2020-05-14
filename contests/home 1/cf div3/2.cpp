#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

 	ll n;
 	cin>>n;
 	ll a[n];
 	f(0,n)
 	{
 		cin>>a[i];
 	}

 	ll ans1=0,ans2=0,ans=0;
 	f(0,n)
 	{
 		if(a[i]!=1) break;

 		ans1++;
 	}
 	for(ll j=n-1;j>=0;j--)
 	{
 		if(a[j]!=1) break;

 		ans2++;
 	}

 	ll cans=0;
 	ll p=2;
 	f(0,n)
 	{
 		if(a[i]!=p)
 		{
 			if(p==1)
 			{
 				ans=max(ans,cans);
 				cans=0;
 			}
 			p=a[i];
 		}

 		if(p==1) cans++;
 	}

 	ans=max(ans,cans);

 	cout<<max(ans,ans1+ans2)<<endl;
    
return 0;
}

ll exp(ll a,ll b,ll m)
{
	if(b==0)
	{
		return 1;
	}
	ll temp =exp(a,b/2,m);
	temp=(temp*temp)%m;
	if(b&1)
	{
		return (temp*(a%m))%m;
	}
	return temp;
}