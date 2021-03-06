#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define dbg(x) cout << (#x) << " is " << (x) << endl;
#define dbg2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << y << endl;
#define dbgarr(x, sz)                                             \
  for (int asdf = 0; asdf < (sz); asdf++) cout << x[asdf] << ' '; \
  cout << endl;
#define dbgarr2(x, rose, colin)                \
  for (int asdf2 = 0; asdf2 < rose; asdf2++) { \
    dbgarr(x[asdf2], colin);                   \
  }
#define dbgitem(x)                                                           \
  for (auto asdf = x.begin(); asdf != x.end(); asdf++) cout << *asdf << ' '; \
  cout << endl;

const int inf = 1e8, MAXN = 101;

int n, m, dist[MAXN][MAXN];
struct Solution {
  vector<string> temp;
  int solve(int s, int t) {
    if (dist[s][t] == inf) return -1;
    int res = 0, d = dist[s][t] + 1;
    while (d > 2) d -= d / 3, res++;
    return res;
  }
  void init() {
    REP(i, m) {
      REP(j, m + n) {
        REP(k, m + n) {
          dist[j][k] = min(dist[j][k], dist[i][j] + dist[i][k]);
        }
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, P, x, y;
  string s;
  cin >> T;
  Solution test;
  REPN(t, T) {
    cin >> m >> n >> P;
    REP(i, m + n)
    fill_n(dist[i], m + n, inf);
    REP(i, m + n) {
      cin >> s;
      REP(j, m + n)
      if (s[j] == 'Y') dist[i][j] = 1;
    }
    printf("Case #%d: ", t);
    test.init();
    REP(i, P) {
      cin >> x >> y, x--, y--;
      printf("%d ", test.solve(x, y));
    }
    printf("\n");
  }
}


/*
Why tf does this work?
Only managers can create new distances, so that's what the Floyd Warshall represents
Every 3 nodes in the shortest path from s to t can be merged into 2 through the manager
This is guaranteed to be feasible bc the shortest path is defined as having at least one manager
every three nodes
There cannot be x1 -- x2 -- x3 where x = non manager, bc then x1 could not reach x3 through the 
way the Floyd-Warshall was defined 


*/