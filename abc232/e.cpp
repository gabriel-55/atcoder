#if !__INCLUDE_LEVEL__
#include __FILE__

using mint = modint998244353;

int main(void){
   ll h, w, k;
   cin >> h >> w >> k;
   ll x1, y1 ,x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;
   vector<mint> dp(4, 0);
   if(x1 == x2 && y1 == y2) dp[0] = 1;
   else if(x1 == x2) dp[1] = 1;
   else if(y1 == y2) dp[2] = 1;
   else dp[3] = 1;
   while(k--){
      vector<mint> p(4, 0);
      swap(dp, p);
      dp[0] = p[1] + p[2];
      dp[1] = p[0]*(w-1) + p[1]*(w-2) + p[3];
      dp[2] = p[0]*(h-1) + p[2]*(h-2) + p[3];
      dp[3] = p[1]*(h-1) + p[2]*(w-1) + p[3]*(h+w-4);
   }
   cout << dp[0].val() << '\n';
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
const ll dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
#endif