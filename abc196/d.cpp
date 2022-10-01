#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll h, w, a, b;
   cin >> h >> w >> a >> b;
   vector c(h, vector<int>(w, 0));
   ll ans = 0;

   auto dfs = [&](auto dfs, ll x, ll y) -> void {
      if(a < 0 || b < 0) return;
      if(x >= h) {
         if(a == 0 && b == 0) ans++;
         return;
      }

      ll nx = x, ny = y+1;
      if(ny >= w) {
         nx = x+1;
         ny = 0;
      }

      if(c[x][y]) {
         dfs(dfs, nx, ny);
         return;
      }

      c[x][y] = 1;

      b--;
      dfs(dfs, nx, ny);
      b++;

      a--;
      if(x+1 < h && !c[x+1][y]) {
         c[x+1][y] = 1;
         dfs(dfs, nx, ny);
         c[x+1][y] = 0;
      }

      if(y+1 < w && !c[x][y+1]) {
         c[x][y+1] = 1;
         dfs(dfs, nx, ny);
         c[x][y+1] = 0;
      }
      a++;

      c[x][y] = 0;
   };

   dfs(dfs, 0, 0);
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