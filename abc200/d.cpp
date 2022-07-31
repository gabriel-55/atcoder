#if !__INCLUDE_LEVEL__
#include __FILE__

const ll mod = 200;

int main(void){
   ll n;
   cin >> n;
   vector<ll> a(n);
   rep(i,n) {
      cin >> a[i];
      a[i] %= mod;
   }
   n = min(8LL, n);

   vector<vector<ll>> b(201, vector<ll>(0));
   for(ll bit = 0; bit < (1LL << n); bit++) {
      vector<ll> res;
      ll cnt = 0;
      rep(i,n) {
         if((bit & (1LL << i)) == 0) continue;
         res.emplace_back(i);
         cnt += a[i];
         cnt %= mod;
      }

      if(res.empty()) continue;
      if(b[cnt].empty()) {
         b[cnt] = res;
         continue;
      }

      cout << "Yes" << '\n';

      cout << b[cnt].size() << ' ';
      for(auto &nb : b[cnt]) cout << nb+1 << ' ';
      cout << '\n';

      cout << res.size() << ' ';
      for(auto &nr : res) cout << nr+1 << ' ';
      cout << '\n';

      return 0; 
   }

   cout << "No" << '\n';
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