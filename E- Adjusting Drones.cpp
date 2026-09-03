#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long int

void solve() {
    int N, K, curr;
    cin >> N >> K;
    
    vector<int> cnt(N + N + N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> curr;
        cnt[curr]++;
    }
    
    int ans = 0;
    for (int val = 1; val <= N + N; val++) {
        int curr = val;
        while (cnt[curr] > K) {
            cnt[curr + 1] += cnt[curr] - 1;
            cnt[curr] = 1;
            curr++;
        }
        ans = max(ans, curr - val);
    }
    
    cout << ans << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) { 
        while (t--) {
            solve();
        }
    }
    
    return 0;
}
