#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
    ll h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    ll sx = 0, sy = 0;
    rep(i,h) rep(j,w) {
            if(c[i][j] == 'S') {
                sx = i;
                sy = j;
            }
    }

    bool ok = false;
    vector seen(h, vector<bool>(w, 0));
    auto dfs = [&](auto dfs, ll x, ll y, ll cnt) -> void {
        rep(k,4) {
            ll nx = x+dx[k], ny = y+dy[k];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(nx == sx && ny == sy) {
                if(cnt+1 < 4) continue;
                else {
                    ok = true;
                    return;
                }
            }
            if(seen[nx][ny] || c[nx][ny] == '#') continue;
            seen[nx][ny] = true;
            dfs(dfs, nx, ny, cnt+1);
        }
    };

    seen[sx][sy] = true;
    dfs(dfs, sx, sy, 0);
    if(ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
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