#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N,M; cin>>N>>M;
    vector<int> cnt(M+1,0);
    for(int ctr=0;ctr<N;ctr++){
    	int curr; cin>>curr;
    	cnt[curr]++;
    }
    vector<int>	psum(M+1,0);
    for(int i=1;i<=M;i++){
    	psum[i]=psum[i-1]+cnt[i];
    }
    int ans=0;
    for (int x=1;x<=M;x++){
    	int carrotcnt=psum[M]-psum[x-1];
    	if(2*x<=M){
    		carrotcnt+=cnt[2*x];
    	}
    	ans= max(ans,carrotcnt);
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
