#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <memory>

using namespace std;

vector<vector<double>> factors;
int n, m;

vector<double> compare_factor(int j) {
	vector<pair<double, int>> goods;
	for (int i = 0; i < n; i++) {
		goods.push_back({ factors[i][j], i });
	}
	sort(goods.rbegin(), goods.rend());
	int l = 0;
	int r = 0;
	vector<double> ans(n);
	while (r != n) {
		while (r < n && goods[r].first == goods[l].first) {
			r++;
		}
		for (int i = l; i < r; i++) {
			ans[goods[i].second] = (double)(l + r - 1) / 2;
		}
		l = r;
	}
	return ans;
}

int main() {
	freopen("data.txt", "r", stdin);
	cin >> n >> m;
	factors = vector<vector<double>>(n, vector<double>(m));
	vector<double> sum(n, 0);
	{
		string tmp;
		getline(cin, tmp);
	}
	for (int i = 0; i < n; i++) {
		stringstream ss;
		{
			string tmp;
			getline(cin, tmp);
			ss << tmp;
			ss.seekg(0);
		}
		vector<double> current;
		double x;
		while (ss >> x) {
			current.push_back(x);
		}
		if (current.size() != m) {
			cout << "Invalid input on product " << i + 1 << ". ";
			cout << "Row size: " << current.size() << '.';
			exit(0);
		}
		factors[i] = move(current);
		// for (int j = 0; j < m; j++) {
		//     cin >> factors[i][j];
		// }
	}
	for (int j = 0; j < m; j++) {
		vector<double> places = compare_factor(j);
		for (int i = 0; i < n; i++) {
			sum[i] += places[i];
		}
	}
	int ans = min_element(sum.begin(), sum.end()) - sum.begin();
	cout << ans + 1 << ' ' << sum[ans] << '\n';
	cout << "Distribution:\n";
	vector<size_t> idx(n);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&sum](int a, int b) { return sum[a] < sum[b]; });
	for (int i = 0; i < n; i++) {
		cout << idx[i] + 1 << ' ' << sum[idx[i]] << '\n';
	}
}