#include<bits/stdc++.h>

#define F first
#define S second
#define P system("PAUSE");
#define H return 0;
#define pb push_back
#define MOD 1e9+7
const int N = 1e5 + 5;
using namespace std;


int quicksort(vector<int>& a, int left, int right, int pivot = 0) {
	int n = right - left + 1;

	swap(a[left], a[left+pivot]);
	int j = left + 1;
	int i = left + 1;


	for (; j < n; j++) {
		if (a[j] <= a[left]) {
			swap(a[j], a[i++]);
		}
	}

	swap(a[i-1], a[left+pivot]);

	return (n-1) + quicksort(a, left, i-2) + quicksort(a, i, right);
}
void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	
	for (int i = 0;i < n; i++) {
		cin >> a[i];
	}

	int comparisons = quicksort(a, 0, n-1, 0);
	cout << comparisons << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	// cin >> t;

	while (t--) {
		solve();
	}

}
