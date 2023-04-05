#if !__INCLUDE_LEVEL__
#include __FILE__

using mint = modint998244353;
using S = mint;
S op(S a, S b) {
   return a+b;
}
S e(){
   return 0;
}

int main(void){
   ll n;
   cin >> n;
   map<ll, ll> comp;
   ll now = 1;
   vector<ll> a(n), b(n);
   segtree<S, op, e> seg(n);
   mint p = 1, p2 = 1;
   const mint div = mint(1)/2;

   rep(i,n) {
      cin >> a[i];
      b[i] = a[i];
   }
   sort(b.begin(), b.end());
   rep(i,n) {
      if(comp[b[i]] == 0) {
         comp[b[i]] = now;
         now++;
      }
   }

   mint ans = 0;
   rep(i,n){
      a[i] = comp[a[i]]-1;
      mint cnt = seg.prod(0, a[i]+1);
      if(n){
         cnt *= p2;
         p2 *= 2;
      }
      ans += cnt;
      if(n) p *= div;
      seg.set(a[i], seg.get(a[i])+p);
   }

   cout << ans.val() << '\n';
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