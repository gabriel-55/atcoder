#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   int h, w, a, b;
   cin >> h >> w >> a >> b;
   
   ll ans = 0;
   vector ng(h, vector<bool>(w, false));
   
   auto dfs = [&](auto dfs, int x, int y) -> void {
      if(a < 0 || b < 0) return;
      if(y >= w) {
         y = 0;
         x = x+1;
         if(x >= h) {
            ans++;
            return;
         }
      }

      if(!ng[x][y]) {
         ng[x][y] = true;

            b--;
            dfs(dfs, x, y+1);
            b++;

            a--;
            if(x+1 < h && !ng[x+1][y]) {
               ng[x+1][y] = true;
               dfs(dfs, x, y+1);
               ng[x+1][y] = false;
            }
            if(y+1 < w && !ng[x][y+1]) {
               ng[x][y+1] = true;
               dfs(dfs, x, y+1);
               ng[x][y+1] = false;
            }
            a++;

         ng[x][y] = false;
      } else dfs(dfs, x, y+1);
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