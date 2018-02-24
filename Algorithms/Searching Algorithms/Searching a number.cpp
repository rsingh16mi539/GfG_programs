// linear search
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
 {
	ll t,n,k,a,i,ans;
	cin>>t;
	while(t--) {
	    ans = -1;
	    cin>>n>>k;
	    for(i=0;i<n;i++) {
	        cin>>a;
	        if(a == k) { ans = i+1; i++; break; }
	    }
	    for(; i<n;i++) cin>>a;
	    cout<<ans<<endl;
	}
	return 0;
}