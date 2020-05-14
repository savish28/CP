ll sz[1000001],color[1000001],cnt[1000001]={0};
vector<ll> tr[1000001], vec[1000001];

void dfs_size(ll v, ll p) 
{
	sz[v] = 1;
	for(auto u : tr[v]) {
		if(u != p) {
			dfs_size(u, v);
			sz[v] += sz[u];
		}
	}
}

void dfs(ll v, ll p, bool keep) 
{
	ll Max = -1, bigchild = -1;
	for(auto u : tr[v]) {
		if(u != p && Max < sz[u]) {
			Max = sz[u];
			bigchild = u;
		}
	}
	for(auto u : tr[v]) 
	{
		if(u != p && u != bigchild) {
			dfs(u, v, 0);
		}
	}
	if(bigchild != -1) {
		dfs(bigchild, v, 1);
		swap(vec[v], vec[bigchild]);
	}
	vec[v].push_back(v);
	cnt[color[v]]++;
	for(auto u : tr[v]) {
		if(u != p && u != bigchild) {
			for(auto x : vec[u]) {
				cnt[color[x]]++;
				vec[v].push_back(x);
			}
		}
	}
	// there are cnt[c] vertex in subtree v color with c
	// answer here
	if(keep == 0) {
		for(auto u : vec[v]) {
			cnt[color[u]]--;
		}
	}
}