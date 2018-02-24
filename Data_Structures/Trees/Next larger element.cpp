#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
 {
	stack<int> s;
	int t,n,a[1005],ans[1005];
	
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cin>>a[0];
	    s.push(0);
	    for(int i=1;i<n;i++)
	    {
	        cin>>a[i];
	        while(!s.empty() && (a[s.top()] < a[i])) {
	            ans[s.top()] = a[i];
	            s.pop();
	        }
	        s.push(i);
	    }
	    while(!s.empty()) {
	        ans[s.top()] = -1;
	        s.pop();
	    }
	    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
	    cout<<"\n";
	}
	return 0;
}