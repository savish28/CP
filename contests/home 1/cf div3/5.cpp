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

 	ll h,n;
 	cin>>h>>n;
 	ll a[n];
 	f(0,n) cin>>a[i];

 	ll h1=h;

 	//map<ll,ll> sb;
 	ll sum=0;
 	ll mi=0;
 	//ll ind=0;
 	f(0,n)
 	{
 		sum+=a[i];

 	//	sb[-sum]=i+1;
 		h1+=a[i];

 		if(mi< -sum)
 		{
 			mi=-sum;
 		//	ind=i+1;
 		}
 		if(h1<=0)
 		{
 			cout<<i+1<<endl;
 			return 0;
 		}
 	}

 	if(sum>=0)
 	{
 		cout<<-1<<endl;
 		return 0;
 	}

 	//cout<<"sjdhs "<<endl;
 	sum*=-1;

 	ll h2=h-mi;

 	ll k=h2/sum;

 	ll ans=k*n;

 	ll h3= h-k*sum;

 	while(h3>0)
 	{
 		f(0,n)
 		{
 			h3+=a[i];
 			ans++;
 			if(h3<=0) break;
 		}
 	}

 	cout<<ans<<endl;
 	

    
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