#if !__INCLUDE_LEVEL__
#include __FILE__

int main() {
   ll n, m, sum = 0;
   cin >> n >> m;
   map<ll, ll> mp;
   rep(i,n) {
      ll a;
      cin >> a;
      mp[a]++;
      sum += a;
   }

   auto itr = mp.end();
   itr--;
   ll x = itr->fi;
   while(itr != mp.begin()) {
      itr--;
      if(itr->fi+1 != x) {
         itr++;
         break;
      }
      x--;
   }
   ll pre = inf, cnt = 0, ans = 0;
   auto f = [&]() -> void {
      while(itr != mp.end()) {
         if(itr->se == 0) {
            itr++;
            cnt = 0;
            continue;
         }
         if(itr->fi != (pre+1)%m) cnt = 0;
         cnt += itr->fi*itr->se;
         chmax(ans, cnt);
         itr->se = 0;
         pre = itr->fi;
         itr++;
      }
   };

   f();
   itr = mp.begin();
   f();

   cout << sum-ans << '\n';
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