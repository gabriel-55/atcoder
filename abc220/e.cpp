#if !__INCLUDE_LEVEL__
#include __FILE__

using mint = modint998244353;

int main(void){
   ll n;
   cin >> n;
   vector<ll> a(n);
   rep(i,n){
      char c;
      cin >> c;
      a[i] = c-'A';
   }
   vector dp(1<<10, vector<mint>(10, 0));
   dp[0][0] = 1;
   rep(i,n) {
      vector p(1<<10, vector<mint>(10, 0));
      swap(dp, p);
      rep(j,1<<10) {
         rep(k,10) {
            //選ばない
            dp[j][k] += p[j][k];
            if(j>>a[i]&1 && k != a[i]) continue;
            //選ぶ
            dp[j|1<<a[i]][a[i]] += p[j][k];
         }
      }
   }
   mint ans = 0;
   rep(i,1<<10) rep(j,10) ans += dp[i][j];
   cout << (ans-1).val() << '\n';
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