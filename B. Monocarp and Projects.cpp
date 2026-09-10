#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long x,y,k;cin>>x>>y>>k;
	long long ans=0,ctr=0;
	while(ctr<k){
		long long rem=(y+ctr)%(x+ctr);
		if(rem==y-x) break;
		ans+=rem;ctr++;
	}
	if(k>ctr){
		ans+=(k-ctr)*(y-x);
	}
	cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}
