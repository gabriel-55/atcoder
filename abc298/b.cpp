#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n;
   cin >> n;
   vector a(n, vector<ll>(n));
   vector b(n, vector<ll>(n));
   vector c(n, vector<ll>(n));
   rep(i,n) rep(j,n) {
      cin >> a[i][j];
   } 
   rep(i,n) rep(j,n) cin >> b[i][j];
   c = a;
   rep(x,4) {
      bool ok = true;
      rep(i,n) rep(j,n) {
         c[i][j] = a[n-1-j][i];
      }
      rep(i,n) rep(j,n) {
         if(c[i][j] && !b[i][j]) ok = false;
      }
      if(ok) {
         cout << "Yes\n";
         return 0;
      }
      a = c;
   }
   cout << "No\n";
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
const ll dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
#endif