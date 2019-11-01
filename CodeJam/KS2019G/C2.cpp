#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
using ll = long long;

vector<int> a, b;
int h;

const int INF = 1e9 + 5;

// oh, both

vector<pair<int,int>> vec;

void rec(int i, int limit, long long A, long long B) {
	if(i == limit) {
		vec.emplace_back((int) min((ll) INF, A), (int) min((ll) INF, B));
		return;
	}
	rec(i + 1, limit, A + a[i], B);
	rec(i + 1, limit, A, B + b[i]);
	rec(i + 1, limit, A + a[i], B + b[i]);
}

const int QUERY = 0, POINT = 1;

struct Event {
	int x, y, type;
	bool operator <(const Event &he) const {
		return make_pair(x, make_pair(y, type)) > make_pair(he.x, make_pair(he.y, he.type));
	}
};

void test_case() {
	int n;
	scanf("%d%d", &n, &h);
	a.clear();
	a.resize(n);
	b.clear();
	b.resize(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}
	int half = n / 2;
	rec(0, half, 0LL, 0LL);
	vector<pair<int,int>> L = vec;
	vec.clear();
	rec(half, n, 0LL, 0LL);
	vector<pair<int,int>> R = vec;
	vec.clear();
	debug() << imie(L);
	debug() << imie(R);
	debug();
	
	long long answer = 0;
	
	vector<Event> events;
	
	for(pair<int,int> p : L) {
		int x = max(0, h - p.first);
		int y = max(0, h - p.second);
		events.push_back(Event{x, y, QUERY});
	}
	for(pair<int,int> p : R) {
		events.push_back(Event{p.first, p.second, POINT});
	}
	vector<int> values;
	for(Event e : events) {
		values.push_back(e.x);
		values.push_back(e.y);
	}
	sort(values.begin(), values.end());
	values.resize( unique(values.begin(), values.end()) - values.begin() );
	auto get = [&](int x) {
		return lower_bound(values.begin(), values.end(), x) - values.begin();
	};
	for(Event& e : events) {
		e.x = get(e.x);
		e.y = get(e.y);
		debug() << imie(e.x) imie(e.y) imie(e.type);
	}
	sort(events.begin(), events.end());
	
	int B = 1;
	while(B <= (int) values.size()) {
		B *= 2;
	}
	debug() << imie(answer);
	vector<int> tree(2 * B);
	for(Event e : events) {
		int y = e.y;
		if(e.type == QUERY) {
			debug() << "P";
			// all >= y
			answer += tree[B+y];
			for(int i = (B + y); i >= 2; i /= 2) {
				if(i % 2 == 0) {
					answer += tree[i+1];
				}
			}
		}
		else {
			debug() << "Q";
			for(int i = B + y; i >= 2; i /= 2) {
				tree[i]++;
			}
		}
		debug() << imie(answer);
	}
	
	//~ for(pair<int,int> p : L) {
		//~ for(pair<int,int> q : R) {
			//~ if(p.first + q.first >= h && p.second + q.second >= h) {
				//~ ++answer;
			//~ }
		//~ }
	//~ }
	
	printf("%lld\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	debug() << imie(T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}


