#if !__INCLUDE_LEVEL__
#include __FILE__

ll n;
vector<vector<bool>> func(vector<vector<bool>> &c) {
   ll h = 0, w = 0, nh = n, nw = n;
   rep(i,n) {
      bool ok = true;
      rep(j,n) if(c[i][j]) ok = false;
      if(ok) h++;
      else break;
   }
   rep(j,n) {
      bool ok = true;
      rep(i,n) if(c[i][j]) ok = false;
      if(ok) w++;
      else break;
   }
   for(ll i = n-1; i >= 0; i--) {
      bool ok = true;
      rep(j,n) if(c[i][j]) ok = false;
      if(ok) nh--;
      else break;
   }
   for(ll j = n-1; j >= 0; j--) {
      bool ok = true;
      rep(i,n) if(c[i][j]) ok = false;
      if(ok) nw--;
      else break;
   }

   vector ret(nh-h, vector<bool>(nw-w));
   REP(i,h,nh) REP(j,w,nw) {
      ret[i-h][j-w] = c[i][j];
   }
   return ret;
}

vector<vector<bool>> func2(vector<vector<bool>> &t) {
   ll x = t.size(), y = t[0].size();
   vector ret(y, vector<bool>(x));
   rep(i,x) rep(j,y) {
      ret[j][x-1-i] = t[i][j];
   }
   return ret;
}

void check(vector<vector<bool>> &s, vector<vector<bool>> &t, bool &ok) {
   if(s.size() != t.size() || s[0].size() != t[0].size()) return;
   bool ng = false;
   rep(i,s.size()) rep(j,s[0].size()) {
      if(s[i][j] != t[i][j]) ng = true;
   }
   if(!ng) ok = true;
   return;
}

int main(void){
   cin >> n;
   vector s(n, vector<bool>(n)), t(n, vector<bool>(n));
   rep(i,n) rep(j,n) {
      char a;
      cin >> a;
      if(a == '#') s[i][j] = 1;
   }
   rep(i,n) rep(j,n) {
      char a;
      cin >> a;
      if(a == '#') t[i][j] = 1;
   }

   bool ok = false;
   s = func(s), t = func(t);
   
   rep(i,3) {
      check(s, t, ok);
      t = func2(t);
   }
   check(s, t, ok);

   ok?puts("Yes"):puts("No");
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