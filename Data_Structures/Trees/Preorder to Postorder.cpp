
//given a preorder of a BST print the postorder

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canRepresentBST(ll pre[] , ll n){
    stack<ll> s;
    ll root = INT_MIN;
    for(ll i = 0; i<n;i++) {
    	if(root>pre[i]) return false;

    	while(!s.empty() && pre[i] > s.top()) {
    		root = s.top();
    		s.pop();
    	}
    	s.push(pre[i]);
    }
    return true;
}
ll search( ll x, ll in[] , ll n) {
	for(ll i=0 ; i<n; i++) {
		if(in[i] == x) return i;
	}
	return -1;
}
void postorder(ll pre[], ll in[] , ll n) {
	ll root = search(pre[0], in , n);
	// if left tree is not empty
	if(root!=0) {
		postorder(pre+1, in, root);
	}
	if(root!=(n-1)) {
		postorder(pre+root+1, in + root+1, n-root-1);
	}
	cout<<pre[0]<<" ";
}

int main()
 {
	ll pre[1005], in[1005];
	ll t,n,i,j,k;
	cin>>t;
	while(t--) {
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
	        cin>>pre[i];
	        in[i] = pre[i];
	    }
	   	if(!canRepresentBST(pre, n)) cout<<"NO\n";
	   	else {
	   		sort(in, in + n);
	   		postorder(pre, in, n);
	   		cout<<endl;
	   	}
	   	
	}
	return 0;
}