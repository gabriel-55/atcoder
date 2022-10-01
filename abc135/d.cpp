#if !__INCLUDE_LEVEL__
#include __FILE__

const ll m = 13, mod = 1e9+7;

int main(void){
   string s;
   cin >> s;

   reverse(s.begin(), s.end());
   vector<ll> dp(m, 0);
   dp[0] = 1;
   
   ll t = 1;
   rep(x,s.size()) {
      vector<ll> p(m, 0);
      swap(dp, p);
      
      if(s[x] != '?') {
         ll y = (s[x] - '0') * t;
         rep(i,m) {
            dp[(i+y)%m] += p[i];
            dp[(i+y)%m] %= mod;
         }
      } else {
         rep(i,10) {
            ll y = i*t;
            rep(j,m) {
               dp[(j+y)%m] += p[j];
               dp[(j+y)%m] %= mod;
            }
         }
      }

      t *= 10;
      t %= m;
   }


   cout << dp[5] << '\n';
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