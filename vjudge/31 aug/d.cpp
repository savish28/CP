#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pi 3.14159265359
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define ld double
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
    	ll a,b,r;
    	ld d;
    	cin>>a>>b>>r>>d;
    	ll d1 = d;
    	d = (ld(d) * ld(pi))/ld(180);

    	//ld ch = ld(b)/ld(r+a);
    	//cout<<"tanb "<<(a+r)*tan(d)<<endl;
    	//ld ta = tan(d);
    	ld ans= sqrt(ld(r+a)*ld(r+a) + ld(b)*ld(b))-ld(r),ans1,ans2;
    	ld ppo = 0.0; 
    	if(d1<90) ppo = ld(r+a)/cos(d)-r;
    	//cout<<ans<<" "<<ppo<<endl;
    	cout<<fixed;
    	cout<<setprecision(10);
    	if(ppo>=ans || d1>=90)
    	{
    		ans =  sqrt(ld(r+a)*ld(r+a) + ld(b)*ld(b))-ld(r);
    		cout<<ans<<endl;
    		//ans1 = sin(ld(d))*(ld(b)-ld(a)*tan(ld(d)));
    		//ans2 = ld(a)/cos(ld(d));
    		//cout<<ans1<<"pppp "<<ans2<<" "<<(r+a)/cos(d)-r<<endl;
    	} 
    	else
    	{
    		//cout<<"sss"<<endl;
    		//ans1 = sin(ld(d))*(ld(b)-ld(a)*tan(ld(d)));
    		//ans2 = ld(a)/cos(ld(d));
    		//cout<<ans1<<"pppp "<<ans2<<" "<<(r+a)/cos(d)-r<<endl;
    		//cout<<ans1+ans2<<endl;
    		cout<<(ld(b)-(a+r)*tan(d))*sin(d)+ppo<<endl;
    	}
    //	cout<<endl;
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