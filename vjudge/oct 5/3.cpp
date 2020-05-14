#include<bits/stdc++.h>
#define ll int
#define dd double
using namespace std;
#define mod 100000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
vector< pair<dd,dd> > sb;
ll n;
dd dis(pair<dd,dd>  a, pair<dd,dd> b)
{
	return sqrt((a.ff-b.ff)*(a.ff-b.ff) + (a.ss-b.ss)*(a.ss-b.ss));
}
dd msm(ll a, ll b)
{
	dd mi = dd(mod);
		f(i,a,b+1)
		{
			f(j,i+1,b+1)
			{
				f(k,j+1,b+1)
				{
					mi = min(mi,dis(sb[i],sb[j]) + dis(sb[k],sb[j]) + dis(sb[i],sb[k]));
				}
			}
		}
		return mi;
}
dd solve2(ll a,ll b, ll c, ll d)
{
	dd mi = dd(mod);
	f(i,a,b+1)
	{
		f(j,c,d+1)
		{
			f(k,j+1,d+1)
			{
				mi = min(mi,dis(sb[i],sb[j]) + dis(sb[k],sb[j]) + dis(sb[i],sb[k]));
			}
		}
	}
	return mi;
}
dd solve(ll a, ll b)
{
	//cout<<a<<" "<<b<<endl;
	if(b-a<2)
	{
		return dd(mod);
	}
	if(b-a==2)
	{	
		return msm(a,b);
	}

	ll mid = (b+a)/2;
	dd mit = min(solve(a,mid),solve(mid+1,b));
	//cout<<a<<" "<<b<<" "<<mit<<" "<<solve(a,mid)<<" "<<solve(mid+1,b)<<endl;
	dd ch = mit/2;

	ll le = mid;
	ll ri =mid;
	ll co=0;
	while(le>=a)
	{
		if(abs(sb[le].ff-sb[mid].ff)<=ch) le--;
		else break;
		if(le>=a && le+1<=b)
		{
			if(sb[le].ff!=sb[le+1].ff) co++;
			if(co==17) break;
		}
	}
	le++;
	 co = 0;
	while(ri<=b)
	{
		
		if(abs(sb[ri].ff-sb[mid].ff)<=ch) ri++;
		else break;

		if(ri<=b && ri-1>=a)
		{
			if(sb[ri].ff!=sb[ri-1].ff) co++;
			if(co==17) break;
		}
	}
	ri--;

	dd pol;
	pol = min(solve2(le,mid,mid+1,ri),solve2(mid+1,ri,le,mid));
	//cout<<le<<" lere "<<ri<<" "<<pol<<endl;
	return min(mit,pol);
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
      //  cout<<"s"<<endl;
    ll t;
    cin>>t;
    f(pp,1,t+1)
    {
    	cout<<"Case "<<pp<<": ";
    	sb.clear();
    	cin>>n;
    
    	dd x,y;
    	f(i,0,n)
    	{
    		cin>>x>>y;
    		sb.pb(mp(x,y));
    	}
    	sort(sb.begin(),sb.end());
    	cout<<fixed;
    	cout<<setprecision(10)<<solve(0,n-1)<<endl;
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
