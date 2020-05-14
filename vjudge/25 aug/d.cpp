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
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

vector<ll> solve(vector<ll> pr, vector<ll> mai)
{
	if(pr.size()==0) return pr; 
	ll las = pr.back();
	ll ind = 0;
	vector<ll> di;
	f(i,las+1,mai.size())
	{
		if(mai[i]>=2*mai[pr[ind]])
		{
			di.pb(i);
			ind++;
		}
		if(ind==pr.size()) break;
	}

	return di;
	
}

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    ll ti = 0;
    while(t--)
    {
    	ti++;
    	ll n,k;
    	cin>>n>>k;
    	vector<ll> sb;
    	
    	
    	ll x;
    	f(i,0,n)
    	{
    		cin>>x;
    		sb.pb(x);
    	}
    	sort(sb.begin(),sb.end());
    	ll st = 0 , en = n/k;
//cout<<st<<" "<<en<<endl;
    	while(st<=en)
    	{ //	if(en==0) break;
    		//cout<<st<<" "<<en<<" "<<ti<<endl;
    		ll mi = (st+ en) / 2;

    		vector<ll> pr;
    		f(i,0,mi) pr.pb(i);
    		ll co = 1;
    		while(co!=k && pr.size()==mi) 
    		{
    			//cout<<co<<" dd "<<endl;
    			
    			pr = solve(pr,sb);
    			//f(j,0,pr.size()) cout<<pr[j]<< "f  ";
    			//cout<<endl;
    			if(pr.size()==mi) co++;
    			else break;
    		}
    		//cout<<co<<endl;
    		if(co==k)
    		{
    			st = mi+1;
    		}
    		else
    		{
    			en = mi - 1;
    		}
    	}
    	cout<<"Case #"<<ti<<": ";
    	//cout<<ans<<endl;
    	cout<<en<<endl;
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