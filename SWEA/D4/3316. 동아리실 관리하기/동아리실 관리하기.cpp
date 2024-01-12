#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

long long dp[10001][16];
string str;
int T, tot_days;

int cnt_cases() {
	int manager;
	long long cnt = 0;

	for (int i = 1; i < tot_days; i++) {
		manager = str[i] - 'A';

		for(int j = 1; j < 16; j++) {
			dp[i][j] = 0;
			if ((j & (1 << manager)) == 0) continue;
			for(int k = 1; k < 16; k++) {
				if ((k & j) != 0) { 
					dp[i][j] += dp[i - 1][k];
					dp[i][j] %= 1000000007;
				}
			}
		}
	}

	for(int i = 1; i < 16; i++) {
		cnt += dp[tot_days - 1][i];
	}

	return (cnt %= 1000000007);
}

int main() {	
	
	cin >> T;

	for(int test_case = 1; test_case <= T; test_case++) {
		cin >> str;
		tot_days = str.length();

		for(int i = 1; i < 16; i++) {
			if ((i & 1) == 1 && (i & (1 << (str[0] - 'A'))) != 0) dp[0][i] = 1;
			else dp[0][i] = 0;
		}
		
		printf("#%d %d\n", test_case, cnt_cases());
	}
	return (0);
}