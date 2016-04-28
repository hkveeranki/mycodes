#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>   pii;
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define MAX(a,b)     (a) = max((a),(b))

#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair

int dr[] = {1,0,-1,0,-1,1,1,-1};
int dc[] = {0,-1,0,1,1,1,-1,-1};
int n, m;
int arr[15][15];
bool flag[15][15];
inline int bfs(int a, int b) {
  queue<pii> q;
  q.push(mp(a, b));
  flag[a][b] = 1;
  int cnt = 0;
  while (!q.empty()){
    pii p = q.front(); q.pop();
    cnt++;
    REP(i,8) {
      int px = p.fi + dr[i], py = p.se + dc[i];
      if (px >= 1 && px <= n && py >= 1 && py <= m && arr[px][py] && !flag[px][py]) {
        flag[px][py] = 1;
        q.push(mp(px,py));
      }
    }
  }
  return cnt;
}
int main(){
  cin >> n >> m;
  REPN(i,n) REPN(j,m) cin >> arr[i][j];

  int ans = 0;
  REPN(i,n) {
    REPN(j,m){
      if (arr[i][j] && !flag[i][j]) {
        MAX(ans, bfs(i, j));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
