#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2*1e5;
int a[mxN], n;

void solve() {
	cin >> n;
	//create a map to count the frequency of each value
	map<int, int> mp;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		mp[a[i]]++;
	}
	int mn=INT_MAX;
	//find out if there is a distinct number
	for(auto x : mp)
		mn=min(mn, x.second);
	//if there no is no distinct number then print '-1'
	if(mn>1)
		cout << -1;
	else {
		//this is the algorithm if there is a distinct number
		//using the key which is a[i], find out if it matches the minimum frequency
		//lastly, save the id
		//optional: if there is more than one distinct then keep comparing
		int id=0, prev=INT_MAX;
		for(int i=0; i<n; ++i)
			if(mp[a[i]]==mn&&a[i]<prev) {
				id=i+1;
				prev=a[i];
			}
		cout << id;
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
}
