#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <bits/stdc++.h>
using namespace std;


int hcf(int a, int b){
	return b==0? a:hcf(b,a%b);
}
void solve() {
    int N; cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
    	cin>>arr[i];
    	}
    	cout<<hcf(arr[0],arr[N-1])<<endl;
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
