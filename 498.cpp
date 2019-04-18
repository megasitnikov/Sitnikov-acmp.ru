#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;

void print(int arr[]) {
	cout << endl;
	for (int i = 0; i < 10; i++) cout << arr[i];
}
int n, k, a[10];
int us[100];

int rec(int cnt) {
	if (cnt == n + 1)
	{
		return 1;
	}
	int ans = 0;
	print(a);
	print(us);
	for (int i = max(1, a[cnt - 1] - k); i <= min(n, a[cnt - 1] + k); i++)
	{
		if (us[i])
			continue;
			a[cnt] = i;
			us[i] = 1;
			ans += rec(cnt + 1);
			us[i] = 0;
	}
	return ans;
}

int main() {
	cin >> n >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		a[1] = i;
		us[i] = 1;
		ans += rec(2);
		us[i] = 0;
	}
	cout << ans;
}
