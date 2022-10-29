#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m, q;
   cin >> n >> m >> q;

   vector v(n+1, vector<ll>(n+1, 0));
   rep(i,m) {
      ll l, r;
      cin >> l >> r;
      v[l][r]++;
   }

   rep(i,n+1) rep(j,n+1) {
      if(i-1 >= 0) v[i][j] += v[i-1][j];
      if(j-1 >= 0) v[i][j] += v[i][j-1];
      if(i-1 >= 0  && j-1 >= 0) v[i][j] -= v[i-1][j-1];
   }

   while(q--) {
      ll l, r;
      cin >> l >> r;
      
      ll ans = 0;
      ans += v[r][r];
      ans -= v[l-1][r];
      ans -= v[r][l-1];
      ans += v[l-1][l-1];
      cout << ans << '\n';
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