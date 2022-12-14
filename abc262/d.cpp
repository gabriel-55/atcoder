#if !__INCLUDE_LEVEL__
#include __FILE__

const ll mod = 998244353;

int main(void){
   ll n;
   cin >> n;
   vector<ll> a(n);
   rep(i,n) cin >> a[i];

   ll ans = 0;
   REP(d,1,n+1) {
      vector dp(d+1, vector<ll>(d+1, 0));
      dp[0][0] = 1;
      rep(i,n) {
         vector p(d+1, vector<ll>(d+1, 0));
         swap(dp, p);

         rep(j,d+1) rep(k,d+1) {
            dp[j][k] += p[j][k];
            dp[j][k] %= mod;
            
            if(j+1 <= d) {
               dp[j+1][(k+a[i])%d] += p[j][k];
               dp[j+1][(k+a[i])%d] %= mod;
            }
         }
      }

      ans += dp[d][0];
      ans %= mod;
   }

   cout << ans << '\n';
   return 0;
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