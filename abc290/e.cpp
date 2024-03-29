#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
	ll n;
   cin >> n;
   vector v(n, vector<ll>());
   vector s(n, vector<ll>(1, 0));
   vector<ll> a(n);
   rep(i,n) cin >> a[i], a[i]--;

   ll cnt = 0;
   ll now = 1, swt = 1, t = n;
   while(t--){
      cnt += t*now;
      swt ^= 1;
      if(swt) now++;
   }
   
   rep(i,n){
      ll idx = upper_bound(v[a[i]].begin(), v[a[i]].end(), n-i) - v[a[i]].begin();
      if(idx > 0){
         cnt -= s[a[i]][idx];
         cnt -= (v[a[i]].size() - idx) * (n-i);
      } else {
         cnt -= v[a[i]].size() * (n-i);
      }
      v[a[i]].emplace_back(i+1);
      s[a[i]].emplace_back(s[a[i]].back()+i+1);
   }

   cout << cnt << '\n';
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