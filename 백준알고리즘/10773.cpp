#include <iostream>
#include <stack>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	int sum = 0;
	cin >> n;
	stack<int>s;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0) {
				s.pop();
		}
		else {
			s.push(num);
		}

	}
	for (int i = 0; !s.empty(); i++) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}