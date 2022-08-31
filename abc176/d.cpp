#if !__INCLUDE_LEVEL__
#include __FILE__

const int INF = 1 << 30;

int main(void){
   int h, w;
   cin >> h >> w;
   int sx, sy, gx, gy;
   cin >> sx >> sy >> gx >> gy;
   sx--; sy--; gx--; gy--;
   vector<string> s(h);
   rep(i,h) cin >> s[i];

   vector cost(h, vector<int>(w, INF));
   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
   pq.push({0, {sx, sy}});
   cost[sx][sy] = 0;

   while(!pq.empty()) {
      ll x = pq.top().se.fi, y = pq.top().se.se;
      pq.pop();

      rep(i,4) {
         ll nx = x+dx[i], ny = y+dy[i];
         if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
         if(s[nx][ny] == '#') continue;
         if(cost[nx][ny] <= cost[x][y]) continue;
         cost[nx][ny] = cost[x][y];
         pq.push({0, {nx, ny}});
      }

      REP(i,-2,3) REP(j,-2,3) {
         ll nx = x+i, ny = y+j;
         if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
         if(s[nx][ny] == '#') continue;
         if(cost[nx][ny] <= cost[x][y]+1) continue;
         cost[nx][ny] = cost[x][y]+1;
         pq.push({1, {nx, ny}});
      }
   }

   if(cost[gx][gy] == INF) cost[gx][gy] = -1;
   cout << cost[gx][gy] << '\n';
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