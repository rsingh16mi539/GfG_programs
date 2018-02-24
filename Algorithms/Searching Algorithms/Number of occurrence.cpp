#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[505],n;
int first_occurance(int l , int h, int x) {
    if(l<=h) {
        int mid = (l+h)/2;
        //cout<<mid<<" ";
        if( (mid == 0 || x > a[mid-1]) && a[mid] == x ) {
            return mid;
        }
        else if(x > a[mid]) return first_occurance(mid+1, h, x);
        else return first_occurance(l, mid-1, x);
    }
    return -1;
}

int last_occurance( int l, int h, int x) {
	if(l<=h) {     
        int mid = (l+h)/2;
        // cout<<mid<<" ";
        if( (mid == n-1 || x < a[mid+1]) && a[mid] == x ) {
            return mid;
        }
        else if(x < a[mid]) return last_occurance(l, mid-1, x);
        else return last_occurance(mid+1, h, x);
    }
            return -1;
}
int main()
 {
	int t,k,l,h,i;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		for(i=0;i<n;i++) {
			cin>>a[i];
		}
		l = first_occurance(0,n-1, k); //cout<<l<<" ";
		h = last_occurance(0,n-1,k); //cout<<h<<" ";
		if(l!=-1) cout<<(h-l+1)<<endl;
		else cout<<"-1\n";

	}
	return 0;
}