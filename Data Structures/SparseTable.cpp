#include <bits/stdc++.h>
using namespace std;

class SparseTable {
	public:
	vector<int> logs;
	vector<vector<int>> table;
	
	SparseTable(int n, vector<int>& vals) {
		logs = vector<int>(n+1);
		for(int i = 2; i <= n; i++) {
			logs[i] = logs[i/2]+1;
		}
		
		table = vector<vector<int>>(logs[n]+1, vector<int>(n));
		for(int i = 0; i < n; i++) {
			table[0][i] = vals[i];
		}
		for(int i = 1; i <= logs[n]; i++) {
			for(int j = 0; j + (1 << i) <= n; j++) {
				int diff = j+(1 << (i-1));
				table[i][j] = min(table[i-1][j], table[i-1][diff]);
			}
		}
	}
	
	int getRange(int l, int r) {
		int diff = r - l + 1;
		int range = logs[diff];
		return min(table[range][l], table[range][r-(1<<range)+1]);
	}
};
