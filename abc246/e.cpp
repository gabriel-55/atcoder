#if !__INCLUDE_LEVEL__
#include __FILE__

const ll dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};

int main(void){
   ll n;
   cin >> n;
   ll sx, sy, gx, gy;
   cin >> sx >> sy >> gx >> gy;
   sx--; sy--; gx--; gy--;
   vector<string> s(n);
   rep(i,n) cin >> s[i];

   vector dist(4, vector<vector<ll>>(n, vector<ll>(n, 1<<30)));
   deque<pair<ll, P>> dq;
   rep(i,4) dist[i][sx][sy] = 0;
   dq.push_back({-1, {sx, sy}});

   while(!dq.empty()) {
      ll now = dq.front().fi;
      auto [x, y] = dq.front().se;
      dq.pop_front();

      ll nx = 0, ny = 0;
      if(now != -1) {
         nx = dx[now]+x, ny = dy[now]+y;
         if(!(nx < 0 || nx >= n || ny < 0 || ny >= n) && s[nx][ny] != '#') {
            if(dist[now][nx][ny] > dist[now][x][y]) {
               dist[now][nx][ny] = dist[now][x][y];
               dq.push_front({now, {nx, ny}});
            }
         }
      }

      rep(k,4) {
         if(k == now) continue;
         nx = dx[k]+x, ny = dy[k]+y;
         if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
         if(s[nx][ny] == '#') continue;
         if(dist[k][nx][ny] <= dist[max(0ll, now)][x][y]+1) continue;
         dist[k][nx][ny] = dist[max(0ll, now)][x][y]+1;
         dq.push_back({k, {nx, ny}});
      }
   }
   
   ll ans = 1<<30;
   rep(i,4) chmin(ans, dist[i][gx][gy]);
   if(ans == 1<<30) ans = -1;
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
// const ll dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
#endif