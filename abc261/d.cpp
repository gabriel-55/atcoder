#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m;
   cin >> n >> m;
   vector<ll> x(n);
   rep(i,n) cin >> x[i];
   vector<ll> c(n+1, 0);
   rep(i,m) {
      ll a, y;
      cin >> a >> y;
      c[a] = y;
   }

   vector<ll> dp(n+1, -1);
   dp[0] = 0;

   rep(i,n) {
      vector<ll> p(n+1, -1);
      swap(dp, p);

      rep(j,n+1) {
         if(p[j] == -1) continue;
         dp[0] = max(dp[0], p[j]);
         if(j+1 <= n) dp[j+1] = max(dp[j+1], p[j]+c[j+1]+x[i]);
      }
   }

   ll ans = 0;
   rep(i,n+1) ans = max(dp[i], ans);
   cout << ans << '\n';
}

/*---------------------------------------------------------------------------------------------------
　　 　　 ○＿＿＿＿＿_
　  　 　 ||　 　 　 |
　 　  　 ||　  ● 　 |
　 　  　 ||　 　 　 |
 　   　  ||￣￣￣￣￣
　　   　 ||  君が代は
   ∧__,,∧||　 千代に八千代に
　 ( ｀･ω･||    さざれ石の巌となりて
　  ヽ  つ０     こけのむすまで
　　 し―-J
---------------------------------------------------------------------------------------------------*/

#else
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using ldb = long double;
using P = pair<ll, ll>;
using G = vector<vector<ll>>;
#define fi first
#define se second
#define rep(i,a) for (ll i = 0, i##_range = (a); i < i##_range; i++)
#define REP(i,a,b) for (ll i = a, i##_range = (b); i < i##_range; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define bs(a, b) binary_search(a.begin(), a.end(), b)
#define lb(a, b) lower_bound(a.begin(), a.end(), b)
#define ub(a, b) upper_bound(a.begin(), a.end(), b)
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