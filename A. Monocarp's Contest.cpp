#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N;cin>>N;
	vector<int> arr(N);
	int oc=0;
	for(int i=0;i<+N;i++){
		cin>>arr[i];
		oc+=arr[i];
	}
	int zc=N-oc;
	if(zc<2){
		cout<<"-1\n";return;
	}
	int ans=0;
	if(arr[0]) ans++;
	if(arr[N-1]) ans++;
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
