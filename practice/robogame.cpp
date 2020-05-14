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
    	string s;
    	cin>>s;

    	vector< pair<ll,ll> > sb;
    	ll n = s.length();
    	//cout<<n<<endl;
    	f(i,0,n)
    	{
    		if(s[i]!='.')
    		{
    			ll x1 = s[i]-'0';
    			//cout<<i-x1<<" "<<i+x1<<endl;
    			sb.pb( mp(i-x1, i+x1 ) );
    		}
    		// cout<<sb[0].ff<<" "<<sb[0].ss<<endl;
    	//	return 0;
    	}
    	//f(i,0,n) cout<<sb[i].ff<<" "<<sb[i].ss<<endl;
    	
    	if(sb.size()!=0) sort(sb.begin(),sb.end());
    //	cout<<sb.size()<<endl;
    	//return 0;
    	bool ans = 0;
    	ll sz = sb.size();
    	f(i,1,sz)
    	{
    		if(sb[i].ff<=sb[i-1].ss)
    		{
    			ans = 1;
    			break;
    		}
    	}

    	if(ans)
    	{
    		cout<<"unsafe"<<endl;
    	}
    	else cout<<"safe"<<endl;
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
