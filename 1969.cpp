#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector <string>v;
	string dna = "";
	int total = 0;
	int check[26];
	int n, m, index, maxword;
	int maxindex = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < m; i++) {
		maxword = 0;
		memset(check, 0, sizeof(check));
		for (int j = 0; j < n; j++) { // 세로줄 중에서 가장 많이 나온 단어 찾기
			index = v[j][i] - 'A';
			check[index]++;
		}
		for (int j = 0; j < 26; j++) {
			if (maxword < check[j]) {
				maxword = check[j];
				maxindex = j;
			}
		}
		dna += 'A' + maxindex;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] != dna[j])
				total++;
		}
	}
	cout << dna << "\n";
	cout << total << "\n";

}