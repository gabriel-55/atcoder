#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, x, y;
   cin >> n >> x >> y;
   vector<ll> a(n), b(n);
   rep(i,n) cin >> a[i] >> b[i];

   vector dp(x+1, vector<ll>(y+1, inf));
   dp[0][0] = 0;
   rep(i,n) {
      vector p(x+1, vector<ll>(y+1, inf));
      swap(dp, p);

      rep(j,x+1) rep(k,y+1) {
         if(p[j][k] == inf) continue;
         chmin(dp[j][k], p[j][k]);
         ll nx = j+a[i], ny = k+b[i];
         chmin(nx, x);
         chmin(ny, y);
         chmin(dp[nx][ny], p[j][k]+1); 
      }
   }

   ll ans = dp[x][y];
   if(ans == inf) ans = -1;
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