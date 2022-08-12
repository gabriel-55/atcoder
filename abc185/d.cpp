#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m;
   cin >> n >> m;
   if(m == 0) {
      cout << 1 << '\n';
      return 0;
   }

   vector<ll> a(m), v;
   rep(i,m) cin >> a[i];
   sort(a.begin(), a.end());
   
   ll mn = inf;
   if(a[0] != 1) {
      v.emplace_back(a[0]-1);
      chmin(mn, v[0]);
   }
   REP(i,1,m) {
      if(a[i]-a[i-1]-1 == 0) continue;
      v.emplace_back(a[i]-a[i-1]-1);
      chmin(mn, v.back());
   }
   if(a[m-1] != n) {
      v.emplace_back(n-a[m-1]);
      chmin(mn, v.back());
   }

   ll ans = 0;
   for(auto &nv : v) {
      if(nv == 0) continue;
      ans += (nv+mn-1)/mn;
   }
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