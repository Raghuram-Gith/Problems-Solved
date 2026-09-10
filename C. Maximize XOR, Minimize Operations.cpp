#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x,y; cin>>x>>y;
	int sum=x+y,rx=0,ry=0;
	for (int sh=30;sh>=0;sh--){
		if((sum&(1<<sh))!=0){
			if((rx|(1<<sh))<=x){
				rx=rx| (1<<sh);
			}else{
				ry=ry|(1<<sh);
			}
		}
	}
	cout<<sum<< " "<<x-rx<<endl;
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
