#if !__INCLUDE_LEVEL__
#include __FILE__

ll a, b, c, d, e, f;
set<pair<ll, ll>> st;
using mint = modint998244353;
vector dp(301, vector<vector<mint>>(301, vector<mint>(301, -1)));

mint func(ll x, ll y, ll z) {
   if(x < 0 || y < 0 || z < 0) return 0;
   if(dp[x][y][z] != -1) return dp[x][y][z];
   if(st.count({x*a + y*c + z*e, x*b + y*d + z*f})) return 0;
   return dp[x][y][z] = func(x-1, y, z) + func(x, y-1, z) + func(x, y, z-1);
}

int main(void){
   ll n, m;
   cin >> n >> m;
   cin >> a >> b >> c >> d >> e >> f;
   rep(i,m){
      ll x, y;
      cin >> x >> y;
      st.emplace(x, y);
   }

   dp[0][0][0] = 1;
   mint ans = 0;
   rep(i,n+1) rep(j,n+1) rep(k,n+1) {
      if(i+j+k == n) ans += func(i, j, k);
   }
   cout << ans.val() << '\n';
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
// const ll dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
#endif