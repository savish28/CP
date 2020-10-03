#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl

ll exp(ll a,ll b,ll m);
bool ok = 1;

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    ll t1 = 0;
    while(t--)
    {
    	
    	t1++;
    	cout<<"Case #"<<t1<<": ";

    	ll x,y;
        cin>>x>>y;
        string s;
        cin>>s;

        ll tp = 0,ts = 0;

        ll n = s.length();
        ll ans = -1;
        f(i,0,n)
        {
            if(s[i]=='N') y++;
            else if(s[i]=='S') y--;
            else if(s[i]=='E') x++;
            else x--;
            tp++;
            ts = abs(x) + abs(y);

            if(ts<=tp)
            {
                ans = tp;
                break;
            }
        }

        if(ans==-1)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else 
        {
            cout<<ans<<endl;
        }
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
