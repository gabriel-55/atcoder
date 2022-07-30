#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n;
   cin >> n;
   vector<vector<ll>> a(n, vector<ll>(n));
   rep(i,n) rep(j,n) {
      char c;
      cin >> c;
      if(c == '-') a[i][j] = 0;
      if(c == 'W') a[i][j] = 1;
      if(c == 'L') a[i][j] = 2;
      if(c == 'D') a[i][j] = 3;
   }

   rep(i,n) rep(j,n) {
      if(a[i][j] == 1 && a[j][i] != 2) {
         puts("incorrect");
         return 0;
      }
      if(a[i][j] == 2 && a[j][i] != 1) {
         puts("incorrect");
         return 0;
      }
      if(a[i][j] == 3 && a[j][i] != 3) {
         puts("incorrect");
         return 0;
      }
   }

   puts("correct");
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
using G = vector<vector<ll>>;
#define fi first
#define se second
#define rep(i,a) for (ll i = 0, i##_range = (a); i < i##_range; i++)
#define REP(i,a,b) for (ll i = a, i##_range = (b); i < i##_range; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define bs(a, b) binary_search(a.begin(), a.end(), b)
#define lb(a, b) lower_bound(a.begin(), a.end(), b)
#define ub(a, b) upper_bound(a.begin(), a.end(), b)
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