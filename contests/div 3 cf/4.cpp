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
    	ll n;
    	cin>>n;

       ll a[n];
       f(0,n) cin>>a[i];

       ll co[n+1]={0};
       f(0,n)
       {
        co[a[i]]++;
       }

       vector<ll> sb;

       f(1,n+1)
       {
        if(co[i])
        {
            sb.pb(co[i]);
        }
       }

    
       ll l=sb.size();
       sort(sb.begin(),sb.end());
       ll ans=0;
       ll cou = sb[l-1];
       for(ll i = l-1;i>=0;i--)
       {
           if(cou>=sb[i]) cou = sb[i];

           ans+=cou;
           cou--; 
           if(cou<0) break;
       }

    	cout<<ans<<endl;
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