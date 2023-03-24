#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m;
   cin >> n >> m;
   n++;
 
   vector<double> x(n+m), y(n+m);
   m_99(i,1,n+m) cin >> x[i] >> y[i];
   vector dp(1<<(n+m), vector<pair<double, ll>>(n+m, {inf, 1}));
   dp[0][0] = {0, 1};

   auto func = [&](ll a, ll b) -> double {
      double ret = (x[a] - x[b]) * (x[a] - x[b]);
      ret += (y[a] - y[b]) * (y[a] - y[b]);
      ret = sqrt(ret);
      return ret;
   };

   double ans = inf;
   rep(i,1<<(n+m)) rep(j,n+m) {
      if(i != 0 && ~i>>j&1) continue;
      rep(k,n+m) {
         if(i>>k&1) continue;
         double val = dp[i][j].fi + func(j, k) / dp[i][j].se;
         if(dp[i|1<<k][k].fi <= val) continue;
         dp[i|1<<k][k].fi = val;
         dp[i|1<<k][k].se = dp[i][j].se;
         if(k >= n) dp[i|1<<k][k].se *= 2;

         if(k == 0) {
            bool ok = true;
            m_99(l,1,n) if(~i>>l&1) ok = false;
            if(ok) chmin(ans, dp[i|1<<0][0].fi); 
         }
      }
   }
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
// #include <atcoder/all>
// using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using ldb = long double;
using P = pair<ll, ll>;
#define fi first
#define se second
#define m_99(i,a,b) for (ll i = a, i##_range = (b); i < i##_range; i++)
#define rep(i,a) m_99(i,0,a)
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