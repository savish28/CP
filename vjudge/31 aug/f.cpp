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
vector<ll> tr[1000007];
ll R,C;
ll r,c;
ll ans = 0;
ll fin;
ll val[1000007];
void dfs(ll a, ll co,ll p)
{
	if(val[a]<=co) return;
	val[a]=co;
	if(a==fin)
	{
		ans = min(co,ans);
		return;
	}

	f(i,0,tr[a].size())
	{
		if(tr[a][i]==p) continue;

		dfs(tr[a][i],co+1,a);
	}
}

ll bfs(ll s, ll t){
	queue<ll> q;
	ll n=r*c+1;
	vector<bool> used(n);
	
	vector<ll> d(n), p(n);

	q.push(s);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
	    ll v = q.front();
	    q.pop();
	    for (ll u : tr[v]) {
	        if (!used[u]) {
	            used[u] = true;
	            q.push(u);
	            d[u] = d[v] + 1;
	            p[u] = v;
	        }
	    }
	}
	return d[t];
}

pair<ll,ll> solve(ll i, ll j)
{
	ll stx,sty;
	stx = j/6;
    				if(stx%2==1)
    				{
    					sty = (i-2)/4;
    				}
    				else sty = i/4;
    return mp(sty,stx);
}

void ma(pair<ll,ll> a, pair<ll,ll> b)
{
	ll f1 = a.ff*c + a.ss;
	ll f2 = b.ff*c + b.ss;
	tr[f1].pb(f2);
	tr[f2].pb(f1);
}
signed main()
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
    	
    	cin>>r>>c;
    	f(i,0,r*c+1) val[i] = mod+9;
    	R = 4*r+3, C = 6*c+3;
    	char sb[R][C];
    	string s;
    	getline(cin,s);
    	pair<ll,ll> st,en;
    	f(i,0,R)
    	{
    		
    		getline(cin,s);
    		f(j,0,s.length()) 
    		{
    			sb[i][j] = s[j];
    			if(s[j]=='S')
    			{
    				st= solve(i,j);
    			}
    			if(s[j]=='T')
    			{
    				en = solve(i,j);
    			}
    		}
    		f(j,s.length(),C) sb[i][j]=' ';
    	}
    	
    	//cout<<stx<<" "<<sty<<" "<<enx<<" "<<eny<<endl;

    	for(ll i = 3;i+2<=R;i+=2)
    	{
    		for(ll j = 7;j+6<=C;j+=6)
    		{
    			if(sb[i][j]==' ')
    			{
    				pair<ll,ll> f1 = solve(i,j-2);
    				pair<ll,ll> f2 = solve(i,j+2);
    				ma(f1,f2);
    				//cout<<f1.ff<<" "<<f1.ss<<" "<<f2.ff<<" "<<f2.ss<<endl;
    			}
    		}
    	}

    	for(ll i = 4;i+4<=R;i+=4)
    	{
    		for(ll j = 4;j<=C;j+=12)
    		{
    			if(sb[i][j]==' ')
    			{
    				pair<ll,ll> f1 = solve(i-1,j);
    				pair<ll,ll> f2 = solve(i+1,j);
    				ma(f1,f2);
    				//cout<<f1.ff<<" "<<f1.ss<<" "<<f2.ff<<" "<<f2.ss<<endl;
    			}
    		}
    	}

    	for(ll i = 6;i+4<=R;i+=4)
    	{
    		for(ll j = 10;j<=C;j+=12)
    		{
    			if(sb[i][j]==' ')
    			{
    				pair<ll,ll> f1 = solve(i-1,j);
    				pair<ll,ll> f2 = solve(i+1,j);
    				ma(f1,f2);
    				//cout<<f1.ff<<" "<<f1.ss<<" "<<f2.ff<<" "<<f2.ss<<endl;
    			}
    		}
    	}
    	
    	//f(i,0,tr[0].size()) cout<<tr[0][i]<<" ";
    	//cout<<endl;
    	fin = en.ff*c + en.ss;
    	//cout<<st.ff*C + st.ss<<" "<<en.ff*C + en.ss<<endl;
    	
    	ans = mod;
    	ll che = st.ff*c + st.ss;
    	ans= bfs(che,fin);
    	if(ans == 0)
    	{
    		cout<<-1<<endl;
    		continue;
    	}
    	cout<<ans+1<<endl;
    	//cout<<bfs(en.ff*C + en.ss,st.ff*C + st.ss)<<endl;
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