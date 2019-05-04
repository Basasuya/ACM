/**
 *    author:  tourist
 *    created: 04.05.2019 15:30:39       
**/
#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

bool Stays(int len, int pos, vector<int> mv, vector<int> who) {
  debug(len, pos, mv, who);
  int L = 1;
  int R = len;
  for (int it = (int) mv.size() - 1; it >= 0; it--) {
    int m = mv[it];
    int w = who[it];
    if (w == 1) {
      if (m == -1) R = min(R + 1, len);
      else L = max(L - 1, 1);
    } else {
      if (m == -1) L++;
      else R--;
    }
    debug(it, L, R);
    if (L > R) return false;
  }
  return (L <= pos && pos <= R);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, n, sr, sc;
  cin >> h >> w >> n >> sr >> sc;
  string s, t;
  cin >> s >> t;
  vector<int> move_h, who_h;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') {
      move_h.push_back(-1);
      who_h.push_back(0);
    }
    if (s[i] == 'D') {
      move_h.push_back(1);
      who_h.push_back(0);
    }
    if (t[i] == 'U') {
      move_h.push_back(-1);
      who_h.push_back(1);
    }
    if (t[i] == 'D') {
      move_h.push_back(1);
      who_h.push_back(1);
    }
  }
  vector<int> move_w, who_w;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      move_w.push_back(-1);
      who_w.push_back(0);
    }
    if (s[i] == 'R') {
      move_w.push_back(1);
      who_w.push_back(0);
    }
    if (t[i] == 'L') {
      move_w.push_back(-1);
      who_w.push_back(1);
    }
    if (t[i] == 'R') {
      move_w.push_back(1);
      who_w.push_back(1);
    }
  }
  if (Stays(h, sr, move_h, who_h) && Stays(w, sc, move_w, who_w)) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}
