#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
 {
	ll x,y,z,tc,n,even_distance, odd_distance, answer;
	bool visited[10005];
	ll distance_from_root[10005];
	cin>>tc;
	while(tc--) {
		cin>>n;
		vector<ll> v[n+1];
		
		for(ll i=1;i<n;i++) {
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
			visited[i+1] = false;
		}
		visited[1] = true;
		distance_from_root[1] = 0;
		stack<ll> s;
		s.push(1);
		while(!s.empty()) {
			z = s.top();
			s.pop();
			for(ll i=0;i<v[z].size();i++) {
				if(visited[v[z][i]] == false) {
					distance_from_root[v[z][i]] = distance_from_root[z] + 1;
					 visited[v[z][i]] = true ;
					 s.push(v[z][i]);
				}
			}
		}
		even_distance = odd_distance = 0;
		for(ll i=1;i<=n;i++) {
			if(distance_from_root[i]%2) odd_distance++;
			else even_distance++;
		}
		answer = (odd_distance*(odd_distance-1))/2 + (even_distance*(even_distance-1))/2 ;
		cout<<answer<<endl;
	}
	return 0;
}