#if !__INCLUDE_LEVEL__
#include __FILE__

using mint = static_modint<1000000007>;

const ll MAX = 1000100; //10^6

mint fac[MAX], finv[MAX], inv[MAX];

void modcombinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i;
    inv[i] = ((mint)i).inv();
    finv[i] = finv[i - 1] * inv[i];
  }
}

ll modcomb(int n, int k) {
  mint tmp;
  ll ans;
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  tmp = finv[k] * finv[n - k];
  tmp *= fac[n];
  ans = (ll)(tmp.val());
  return ans;
}

int main(void){
   ll x, y;
   cin >> x >> y;
   if((x+y)%3 != 0) {
      cout << 0 << '\n';
      return 0;
   }

   ll k = x+y;
   x -= k/3; y -= k/3;
   if(x < 0 || y < 0) {
      cout << 0 << '\n';
      return 0;
   }

   modcombinit();
   cout << modcomb(x+y, x) << '\n';
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