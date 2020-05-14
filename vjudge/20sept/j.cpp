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
bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
  
    for (int i=0; i<n1; i++) 
    if (str1[i] < str2[i]) 
        return true; 
    else if (str1[i] > str2[i]) 
        return false; 
  
    return false; 
} 
  
// Function for find difference of larger numbers 
string findDiff(string str1, string str2) 
{ 
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    int carry = 0; 
  
    // Run loop till small string length 
    // and subtract digit of str1 to str2 
    for (int i=0; i<n2; i++) 
    { 
        // Do school mathematics, compute difference of 
        // current digits 
          
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
          
        // If subtraction is less then zero 
        // we add then we add 10 into sub and 
        // take carry as 1 for calculating next step 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of larger number 
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
          
        // if the sub value is -ve, then make it positive 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        str.push_back(sub + '0'); 
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
}
vector<string> ans;
void solve(string s)
{
	
	string s1 = "";
	ll ind = s.size();
	f(i,0,s.size()) 
	{
		if(s[i]!='0')
		{
			ind = i; break;
		}
	}
	
	f(i,ind,s.size()) {s1+=s[i];}
	ll l = s1.length();
	if(l==0) return;
	if(l==1)
	{
		ans.pb(s1);
		return;
	}
	if(s1=="10")
	{
		ans.pb("9");
		ans.pb("1");
		return;
	}
	//cout<<"ss"<<s1<<endl;
	ll ch = (l-1)/2;
	ll base = 9;
	string dif = "";
	ll cp = 0;
	for(ll j = ch; j >=0 ;j--)
	{
		if(base==9)
		{
			//cout<<j<<" "<<s1[j]<<endl;
			if(s1[j]-'0'>0)
			{
				char mi = s1[j];
				mi--;
				if(ch==0 && s1[j]=='1') mi++;
				dif+=mi;
				base = 0;
				//cout<<"mi = "<<mi<<endl;
			}
			else {dif+='9';}
		}
		else dif += s1[j];
	}
	//cout<<"diff "<<dif<<endl;
	ll ld = dif.size();

	string fd = "";

	f(i,0,(l)/2)
	{
		fd+=dif[ld-i-1];
	}
	fd+=dif;
	//cout<<"fd "<<fd<<" "<<s1<<endl;
	if(fd[0]=='0')
	{
		fd.back()='9';
	}
	ans.pb(fd);

	string newstr = findDiff(s1,fd);
	//cout<<"new = "<<newstr<<endl;
	//return;
	solve(newstr);
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
    //cout<<findDiff("4425","4334")<<endl;
    f(t1,1,t+1)
    {	ans.clear();
    	
    	
    	string s;
    	cin>>s;
    	cout<<"Case #"<<t1<<": "<<endl;
    	solve(s);
    	if(ans.size()>50)
    	{
    		bool tr= 1;
    		while(tr)
    		{
    			
    		}
    	}
    	cout<<ans.size()<<endl;
    	f(i,0,ans.size()) 
    	{
    		ll ind = ans[i].size();
    		f(j,0,ans[i].size())
    		{
    			if(ans[i][j]!='0'){ind = j ; break;} 
    		}
    		f(j,ind,ans[i].size()) cout<<ans[i][j];
    		cout<<endl;
    	}
    }
    
   //cout<<999999999990+99+88+1;

    
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