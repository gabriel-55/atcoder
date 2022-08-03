#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll k;
   cin >> k;
   vector<ll> r(10, k);
   vector<ll> t(10, 0), a(10, 0);
   rep(i,10) {
      char c;
      cin >> c;
      if(c == '#') continue;
      r[c-'0']--;
      if(i < 5) t[c-'0']++;
      else a[c-'0']++;
   }

   ll win = 0, cnt = 0;
   REP(i,1,10) REP(j,1,10) {
      if(r[i] == 0 || r[j] == 0) continue;
      if(j == i && r[i] < 2) continue;
      if(j == i) cnt += r[i]*(r[j]-1);
      else cnt += r[i]*r[j];

      ll T = 0, A = 0;
      REP(l,1,10) {
         ll x = 1;
         rep(m,t[l]) x *= 10;
         if(l == i) x *= 10;
         T += x*l;
      }
      REP(l,1,10) {
         ll x = 1;
         rep(m,a[l]) x *= 10;
         if(l == j) x *= 10;
         A += x*l;
      }
      if(T > A) {
         if(j == i) win += r[i]*(r[j]-1);
         else win += r[i]*r[j];
      }
   }

   cout << (ldb)win/cnt << '\n';
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