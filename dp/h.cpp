#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)

int main(void) {
    ll h, w;
    cin >> h >> w;

    vector<string> a(h);
    rep(i,h) cin >> a[i];

    vector<vector<ll>> dp(h, vector<ll>(w, 0));
    dp[0][0] = 1;

    rep(i,h) rep(j,w) {
        if(i+1 < h && a[i+1][j] == '.') {
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= mod;
        }
        if(j+1 < w && a[i][j+1] == '.') {
            dp[i][j+1] += dp[i][j];
            dp[i][j+1] %= mod;
        }
    }

    cout << dp[h-1][w-1] << '\n';
    return 0;
}