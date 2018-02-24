#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int binary(int l, int h, int m) {
    int mid = (l+h)/2;
    if(m == mid) return 1;
    else if(m < mid) {
        return 1+binary(0,mid-1, m);
    }
    else {
        return 1+binary(mid+1, h,m);
    }
}
int main()
{
	ll t,n,m,g,s;
	cin>>t;
	while(t--) {
	    cin>>n>>m>>g>>s;
	    g = g*m;
	    s = s*binary(0,n-1,m-1);
	    if(g<s) cout << "1\n";
	    else if(g>s) cout<<"2\n";
	    else cout<<"0\n";
	}
	return 0;
}