#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n;
   cin >> n;
   vector<ll> c(9);
   rep(i,9) cin >> c[i];

   vector dp(n+1, vector<ll>(10, -1));
   dp[0].assign(10, 0);
   rep(i,n) {
      if(dp[i][0] == -1) continue;
      rep(j,9) {
         ll nx = i+c[j];
         if(nx > n) continue;
         if(dp[nx][0] > dp[i][0]+1) continue;
         bool ok = true;
         if(dp[nx][0] == dp[i][0]+1) {
            for(ll k = 9; k > 0; k--) {
               ll nk = k-1 == j ? dp[i][k]+1 : dp[i][k];
               if(dp[nx][k] == nk) continue;
               if(dp[nx][k] > nk) ok = false;
               break;
            }
         }
         if(!ok) continue;
         dp[nx] = dp[i];
         dp[nx][0]++;
         dp[nx][j+1]++;
      }
   }
   vector<ll> v(10, 0);
   rep(i,n+1) {
      if(dp[i][0] < v[0]) continue;
      bool ok = true;
      if(dp[i][0] == v[0]) {
         for(ll k = 9; k > 0; k--) {
            if(dp[i][k] == v[k]) continue;
            if(dp[i][k] < v[k]) ok = false;
            break;
         }
      }
      if(!ok) continue;
      v = dp[i];
   }

   string ans;
   for(ll i = 9; i > 0; i--) {
      while(v[i]) {
         ans += i+'0';
         v[i]--;
      }
   }
   cout << ans << '\n';
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