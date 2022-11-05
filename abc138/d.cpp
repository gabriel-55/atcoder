#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, q;
   cin >> n >> q;
   vector g(n, vector<ll>());
   rep(i,n-1) {
      ll a, b;
      cin >> a >> b;
      g[--a].emplace_back(--b);
      g[b].emplace_back(a);
   }

   vector<ll> cnt(n, 0);
   rep(i,q) {
      ll p, x;
      cin >> p >> x;
      cnt[--p] += x;
   }
   auto dfs = [&](auto dfs, ll x, ll pre) -> void {
      for(auto &nx : g[x]) {
         if(nx == pre) continue;
         cnt[nx] += cnt[x];
         dfs(dfs, nx, x);
      }
   };

   dfs(dfs, 0, -1);
   rep(i,n) {
      cout << cnt[i] << ' ';
   }
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