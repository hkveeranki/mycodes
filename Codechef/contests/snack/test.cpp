 
#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
 
#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
 
#define sqr(x) ((x) * (x))
using namespace std;
 
int n, m, c[111][111];
 
int main() {
    ios :: sync_with_stdio(false);
    int test; cin >> test;
    while (test--) {
        cin >> n >> m;
        int u, v;
        memset(c, 0, sizeof c);
        FOR(i,1,m) {
            cin >> u >> v;
            c[u][v] = c[v][u] = 1;
        }
 
        if (n <= 2) {
            cout << 0 << ' ' << 0 << endl;
        }
        else if (n == 3) {
            if (c[1][2] && c[2][3] && c[3][1]) cout << 0 << ' ' << 0 << endl;
            else {
                cout << 2 << ' ' << 3 << endl;
                FOR(u,1,3) FOR(v,u+1,3) if (!c[u][v]) {
                    int w = 6 - u - v;
 
                    cout << w << ' ' << 5 << endl;
                    cout << u << ' ' << 4 << endl;
                    cout << v << ' ' << 4 << endl;
                    break;
                }
            }
        }
        else {
            int x = n + 1, y = n + 2, z = n + 3, t = n + 4;
 
            vector< pair<int,int> > res;
            FOR(i,1,n) res.push_back(make_pair(i, x));
            FOR(i,1,n) res.push_back(make_pair(i, y));
            res.push_back(make_pair(x, z));
            res.push_back(make_pair(y, t));
 
            cout << 4 << ' ' << res.size() << endl;
            REP(i,res.size()) cout << res[i].first << ' ' << res[i].second << '\n';
        }
        cout << endl;
    }
    return 0;
}
 
