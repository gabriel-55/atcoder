#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll h, w;
   cin >> h >> w;
   vector a(h, vector<ll>(w));
   rep(i,h) rep(j,w) cin >> a[i][j];

   ll cnt = 0;
   auto dfs = [&](auto dfs, ll x, ll y, vector<ll> v) -> void {
      if(x == h-1 && y == w-1) {
         cnt++;
         return;
      }
      rep(k,2){
         ll nx = x+dx[k], ny = y+dy[k];
         if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
         bool ok = true;
         for(auto &nv : v) {
            if(nv == a[nx][ny]) {
               ok = false;
               break;
            }
         }
         if(!ok) continue;
         v.emplace_back(a[nx][ny]);
         dfs(dfs, nx, ny, v);
         v.pop_back();
      }
   };

   dfs(dfs, 0ll, 0ll, {a[0][0]});
   cout << cnt << '\n';
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
const ll dx[2] = {1, 0}, dy[2] = {0, 1};
#endif