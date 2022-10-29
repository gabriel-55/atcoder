#if !__INCLUDE_LEVEL__
#include __FILE__

const ll mod = 1e9+7; 

int main(void){
   ll n;
   cin >> n;
   n -= 3;

   vector dp(4, vector<vector<ll>>(4, vector<ll>(4, 0)));
   rep(i,4) rep(j,4) rep(k,4) {
      if(i == 0 && j == 1 && k == 2) continue;
      if(i == 0 && j == 2 && k == 1) continue;
      if(i == 1 && j == 0 && k == 2) continue;
      dp[i][j][k] = 1;
   }

   rep(ni,n) {
      vector p(4, vector<vector<ll>>(4, vector<ll>(4, 0)));
      swap(dp, p);
      rep(i,4) rep(j,4) rep(k,4) {
         vector<bool> b(4, true);
         if(j == 0 && k == 1) b[2] = false;
         if(j == 0 && k == 2) b[1] = false;
         if(j == 1 && k == 0) b[2] = false;
         if(i == 0 && k == 1) b[2] = false;
         if(i == 0 && j == 1) b[2] = false;
         rep(l,4) {
            if(!b[l]) continue;
            dp[j][k][l] += p[i][j][k];
            dp[j][k][l] %= mod;
         }
      }
   }

   ll ans = 0;
   rep(i,4) rep(j,4) rep(k,4) {
      ans += dp[i][j][k];
      ans %= mod;
   }
   cout << ans << '\n';
   return 0;
}

#else
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using ldb = long double;
using P = pair<ll, ll>;
#define fi first
#define se second
#define REP(i,a,b) for (ll i = a, i##_range = (b); i < i##_range; i++)
#define rep(i,a) REP(i,0,a)
template <class T> bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }
#ifdef _DEBUG
#include <debug.hpp>
#define debug(...) debug::dprint(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif
struct initialise { initialise() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }__INI__;
const ll inf = 1LL << 60;
const ll dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
#endif