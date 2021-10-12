#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<char>> a(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	// if the for-loop encounters a dot (.) character, then check all the
	// adjacent cells if they are also dot (.) characters (if yes, then fill them w/ '#')
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '.') {
				int cnt = (i - 1 >= 0 && a[i - 1][j] == '.');
				cnt += (i + 1 < n && a[i + 1][j] == '.');
				cnt += (j - 1 >= 0 && a[i][j - 1] == '.');
				cnt += (j + 1 < n && a[i][j + 1] == '.');
				if (cnt == 4) {
					a[i][j] = '#';
					a[i - 1][j] = '#';
					a[i + 1][j] = '#';
					a[i][j - 1] = '#';
					a[i][j + 1] = '#';
				}
				cnt = 0;
			}
		}
	}
	// check if the board is full of '#'
	bool checker = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			checker &= (a[i][j] == '#');
		}
	}
	cout << (checker ? "YES" : "NO") << '\n';
	return 0;
}
