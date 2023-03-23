#if !__INCLUDE_LEVEL__
#include __FILE__

const ll mod = 998244353;

int main(void){
   ll n, m;
   cin >> n >> m;
   vector<ll> cnt(n, 0);
   vector<ll> v(m);
   dsu uf(n);
   rep(i,m) {
      ll a, b;
      cin >> a >> b;
      a--; b--;
      v[i] = a;
      uf.merge(a, b);
   }
   rep(i,m) cnt[uf.leader(v[i])]++;
   vector<bool> seen(n, 0);
   ll ans = 1;
   rep(i,n){
      if(seen[uf.leader(i)]) continue;
      if(cnt[uf.leader(i)] != uf.size(i)) {
         cout << 0 << '\n';
         return 0;
      }
      seen[uf.leader(i)] = true;
      ans *= 2;
      ans %= mod;
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