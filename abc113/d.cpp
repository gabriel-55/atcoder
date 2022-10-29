#if !__INCLUDE_LEVEL__
#include __FILE__

const ll mod = 1e9 + 7;

int main(void){
   ll h, w, q;
   cin >> h >> w >> q;
   vector<ll> dp(w, 0);
   dp[0] = 1;

   rep(ni,h) {
      vector<ll> p(w, 0);
      swap(dp, p);
      rep(bit,(1<<(w-1))) {
         vector<bool> v(w, false);
         for (int i = 0; i < w-1; i++) {
               if ((bit & (1 << i)) == 0) v[i] = true;
         }
         bool ok = true;
         REP(i,1,w-1) {
            if(v[i] && v[i-1]) ok = false;
         }
         if(!ok) continue;

         rep(i,w) {
            if(i != 0 && v[i-1]) dp[i] += p[i-1];
            else if(v[i]) dp[i] += p[i+1];
            else dp[i] += p[i];
            dp[i] %= mod;
         }
      }
   }

   cout << dp[q-1] << '\n';
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