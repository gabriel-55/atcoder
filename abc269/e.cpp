#if !__INCLUDE_LEVEL__
#include __FILE__

ll n;
bool ask(ll L, ll R, ll val) {
   ll x1 = L, y1 = 1, x2 = R-1, y2 = n;
   if(val) swap(x1, y1), swap(x2, y2);
   cout << "? " << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << endl;
   ll a;
   cin >> a;
   if(a >= R-L) return 1;
   else return 0;
}

ll func(ll val) {
   ll ok = 1, ng = n+1;
   while(abs(ok-ng) > 1) {
      ll m = (ok + ng) / 2;
      if(ask(ok, m, val)) ok = m;
      else ng = m;
   }
   return ok;
}

int main(void){
   cin >> n;
   ll x = func(0), y = func(1);
   cout << "! " << x << ' ' << y << endl;
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