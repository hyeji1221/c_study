#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1000
using namespace std;

int n;
int arr[MAX];

bool cmp(int& a, int& b) {
	string ab = to_string(a) + to_string(b);
	string ba = to_string(b) + to_string(a);
	return ab > ba; // ab가 ba보다 크면 true
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);
	string answer = "";
	for (int i = 0; i < n; i++) {
		answer += to_string(arr[i]);
	}
	if (answer[0] == '0' && answer.length() > 1) { // 0만 입력된 경우
		answer = "0";
	}
	cout << answer << "\n";
	return 0;
}
