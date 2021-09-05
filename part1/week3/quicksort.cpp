#include<bits/stdc++.h>

#define F first
#define S second
#define P system("PAUSE");
#define H return 0;
#define pb push_back
#define MOD 1e9+7
const int N = 1e5 + 5;
enum ruleOfPivot{leftPivot = 0, rightPivot = 1, medianPivot = 3};
using namespace std;



int getPivot(vector<int> &a, int left, int right, int pivotRule) {
	if (pivotRule == 0) return left;
	if (pivotRule == 1) return right;

	int x = a[left];
	int y = a[(left + right) / 2];
	int z = a[right];

	int median = max(min(max(x, y), z), min(x, y));

	if (median == x) return left;
	else if (median == y) return (left+right) / 2;
	else return right;	


}


long long int quicksort(vector<int>& a, int left, int right, int pivotRule = 0) {
	int n = right - left + 1;
	if (n <= 0) return 0;

	int pivot = getPivot(a, left, right, pivotRule);

	swap(a[left], a[pivot]);
	int i = left + 1;


	for (int j = left + 1; j <= right; j++) {
		if (a[j] <= a[left]) {
			swap(a[j], a[i++]);
		}
	}

	swap(a[i-1], a[left]);
	return (n-1) + quicksort(a, left, i-2, pivotRule) + quicksort(a, i, right, pivotRule);
}
void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	
	for (int i = 0;i < n; i++) {
		cin >> a[i];
	}

	// cout << quicksort(a, 0, n-1, leftPivot) << endl;
	// cout << quicksort(a, 0, n-1, rightPivot) << endl;
	cout << quicksort(a, 0, n-1, medianPivot) << endl;
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
