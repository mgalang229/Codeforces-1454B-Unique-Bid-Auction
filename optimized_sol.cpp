#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	cin >> n;
	vector<int> cnt(n+1), idx(n+1);
	//using the 'cnt' vector, count the no. of frequencies
	//using the 'idx' vector, store the index of the number
	for(int i=0; i<n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
		idx[x]=i+1;
	}
	//store -1 in variable as the initial value if there is no distinct number
	int ans=-1;
	//iterate from 1 to the max number and check whether the frequency is one
	//if the frequency is one, then save the index and break the loop
	for(int i=0; i<=n; ++i)
		if(cnt[i]==1) {
			ans=idx[i];
			break;
		}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
}
