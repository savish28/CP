#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    while(t--)
    {
  
    	ll n;
    	cin>>n;
    	vector< pair<ll,ll> > a;
    	ll x;
        ll b[n];
    	f(i,0,n)
    	{
    		cin>>x;
            b[i] = x;
    		a.pb(mp(x,i+1));
    	}
    	sort(a.begin(),a.end());
    	bool ch[n+1]={0};
    	
    	vector< pair<ll,ll> > sb[32];

    	ll an[32];

    	f(j,0,32)
    	{
    		an[j] = (1 << (j+1)) -1;
    	}
    	f(i,0,n)
    	{

    		f(j,0,32)
    		{
    			ll nu = a[i].ff & an[j];

    			bool k2 = (nu & (1 << j));
    			if(k2)
    			{
    				sb[j].pb(mp(nu,a[i].ss));
    			}
    		}
    	}

    	
    	ll aya[32]={0};
    	ll bi = 0;
    	for(ll j = 31; j>=0 ; j--)
    	{
    		if( ((1<<j) & bi )>0) continue;
    		ll sz = sb[j].size();
    		if(sz)
    		{
    			vector< pair<ll,ll> > kon;
    			f(i,0,sz)
    			{
    				if(ch[sb[j][i].ss]>0) continue;

    				kon.pb(mp( (bi | sb[j][i].ff) , sb[j][i].ss));
    				
    			}

                if(kon.size()>0)
                {
                    ll ps = kon.size();
                    sort(kon.begin(),kon.end());

                    ll ind  = kon[ps-1].ss;
                    bi = kon[ps-1].ff;
                    ch[ind] = 1;
                    aya[j] = ind;
                }
    				
    		}
    	}

    	vector<ll> pr;

    	f(i,1,n+1)
    	{
    		if(ch[i]==0) pr.pb(i);
    	}
    	
    
    	f(j,0,32)
    	{
    		if(aya[j]>0)
    		{
    			pr.pb(aya[j]);
    			
    		}
    	}
    	
        ll ans = 0; ll las = 0;

        for(ll j = n-1;j>=0;j--)
        {
            las |= b[pr[j]-1];

            ans+=las;
        }
        cout<<ans<<endl;
    	f(i,0,n)
    	{
    		cout<<pr[i]<<" ";
    	}
    	cout<<endl;
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
