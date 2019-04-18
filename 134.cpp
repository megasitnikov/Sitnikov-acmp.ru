#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector <pair <int, pair <int, int> > > g[100500];
int d[100500], t[100500];

int main() {
	int q, n, f, s; cin >> n >> f >> s >> q;

	for (int i = 0; i < q; ++i) {
		int v, t, u, r; cin >> v >> t >> u >> r;
		g[v].push_back({ u, {t, r} });
	}

	set <pair <int, int> > S;
	for (int i = 1; i <= n; ++i)
		t[i] = d[i] = INT_MAX;

	d[f] = t[f] = 0;
	S.insert({ 0, f });

	while (!S.empty()) {
		int v = S.begin()->second;
		S.erase(S.begin());
		for (auto it : g[v]) {
			int to = it.first, fT = it.second.first, tT = it.second.second, w = (fT - t[v]);
			if (t[v] <= fT && d[to] > d[v] + w) {
				S.erase({ d[to], to });
				t[to] = tT;
				S.insert({ d[to] = d[v] + w, to });
			}
		}
	}

	if (d[s] == INT_MAX)
		d[s] = -1;
	cout << d[s];
}
