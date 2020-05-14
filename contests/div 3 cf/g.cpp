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

       ll a[n],on[n];
       f(0,n) cin>>a[i]>>on[i];

       ll co[n+1]={0};
       ll co1[n+1]={0};
       f(0,n)
       {
        co[a[i]]++;
        if(on[i]) co1[a[i]]++;
       }


       vector< pair<ll,ll> > sb;

       f(1,n+1)
       {
        if(co[i])
        {
            sb.pb(mp(co[i],co1[i]));
        }
       }

    
       ll l=sb.size();
       sort(sb.begin(),sb.end());

       vector< pair<pair<ll,ll>,ll> > msm[n+1];
       f(0,l)
       {
        msm[sb[i].ss].pb(mp(sb[i],i));
       }
       

       ll ans=0;
       ll ans2 = 0;
       ll cou = sb[l-1].ff;
       for(ll i = l-1;i>=0;i--)
       {
           if(cou>=sb[i].ff) cou = sb[i].ff;

           ans+=cou;
           pair< pair<ll,ll>,ll> po ;
           for(ll j=n;j>=0;j--)
           {
            if(msm[j].size()==0) continue;

            po = msm[j].back();
            if(po.ff.ff<cou) continue;
            msm[j].pop_back();
            break;
           }
           ans2 += min(cou,po.ff.ss);
           cou--; 
           if(cou<0) break;
       }

    	cout<<ans<<" "<<ans2<<endl;
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