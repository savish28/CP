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
    	f(i,0,n)
    	{
    		cin>>x;
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
    	ll bada = (1 << 32) -1;
    	ll bi = 0;
    	for(ll j = 31; j>=0 ; j--)
    	{
    		if(aya[j]==-1) continue;
    		ll sz = sb[j].size();
    		if(sz)
    		{
    			vector< pair<ll,ll> > kon;
    			f(i,0,sz)
    			{
    				if(ch[sb[j][i].ss]>0) continue;

    				kon.pb(mp())

    				
    			}


    				ch[sb[j][i].ss] = 1;
    				aya[j] = sb[j][i].ss;

    				ll ni = sb[j][i].ff;
    				f(k,0,j)
    				{
    					if(ni%2==1) {bi |= (1 << ni); aya[j]=-1;};
    					ni/=2;
    				}
    				
    		}
    	}

    	vector<ll> pr;

    	f(i,1,n+1)
    	{
    		if(ch[i]==0) pr.pb(i);
    	}
    	ll fsz = pr.size();
    	ll kit = 0;
    	f(j,0,32)
    	{
    		if(aya[j]>0)
    		{
    			pr.pb(aya[j]);
    			kit |= (1 << j);
    		}
    	}

    	ll fans = kit * fsz + kit;

    	f(j,0,32)
    	{
    		cout<<aya[j]<<" ";
    	}
    	cout<<endl;
    	cout<<fans<<endl;
    	f(j,0,32)
    	{
    		if(aya[j])
    		{
    			fans += (kit -= (1 << j));
    		}
    	}

    	cout<<fans<<endl;

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
