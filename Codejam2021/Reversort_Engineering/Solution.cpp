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

const int mod = 1e9 + 7;

int n, c;
struct Solution {
  vi solve() {
    vi res(n);
    if (c > n * (n + 1) / 2 - 1 || c < n - 1) return {};
    c -= n - 1;
    bool flip[100] = {0};
    REP(i, n) {
      int x = n - i - 1;  // would be cost
      res[i] = i + 1;
      if (c >= x) {
        iota(res.begin() + i, res.end(), i + 1);
        reverse(res.begin() + i + 1, res.end());
        flip[i] = true, c -= x;
        // dbg2(i, x);
      }
      // print(res);
    }
    FORD(i, n - 1, 0) {
      if (flip[i]) reverse(res.begin() + i, res.end());
    }
    return res;
  }
  void print(vector<int>& nums) {
    if (nums.empty())
      printf("IMPOSSIBLE");
    for (auto num : nums) printf("%d ", num);
    printf("\n");
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  Solution test;
  REPN(t, T) {
    cin >> n >> c;
    printf("Case #%d: ", t);
    auto res = test.solve();
    test.print(res);
  }
}