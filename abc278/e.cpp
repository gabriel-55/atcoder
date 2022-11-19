#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll h, w, n, x, y;
   cin >> h >> w >> n >> x >> y;
   vector g(h, vector<vector<ll>>(w, vector<ll>(301)));
   vector<ll> a(301, 0);
   rep(i,h) rep(j,w) {
      ll A;
      cin >> A;
      a[A]++;
      g[i][j][A]++;
      rep(k,301) {
         if(i) g[i][j][k] += g[i-1][j][k];
         if(j) g[i][j][k] += g[i][j-1][k];
         if(i && j) g[i][j][k] -= g[i-1][j-1][k];
      }
   }

   for(ll i = 0; i <= h-x; i++) {
      for(ll j = 0; j <= w-y; j++) {
         vector<ll> b(301, 0);
         ll cnt = 0;
         rep(k,301) {
            b[k] += g[i+x-1][j+y-1][k];
            if(i) b[k] -= g[i-1][j+y-1][k];
            if(j) b[k] -= g[i+x-1][j-1][k];
            if(i && j) b[k] += g[i-1][j-1][k];
            if(a[k]-b[k] > 0) cnt++;
         }
         cout << cnt << ' ';
      }
      cout << '\n';
   }
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