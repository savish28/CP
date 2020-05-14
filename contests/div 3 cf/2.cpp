#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll q;
    cin >> q;
    while(q--)
    {
    	ll n,k;
    	cin>>n>>k;
    	ll a[n];
    	f(0,n) cin>>a[i];
    	ll o=1;
    	ll mil,mal, mil1,mal1;
    	mil = max(o,a[0]-k);
    	mal = a[0]+k;

    	f(0,n)
    	{
    		mil1 = max(o,a[i]-k);
    		mal1 = a[i]+k;

    		mil = max(mil,mil1);
    		mal = min(mal,mal1);
    	}

    	if(mil<=mal)
    	{
    		cout<<mal<<endl;
    	}
    	else cout<<-1<<endl;

    }
    
    
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