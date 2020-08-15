#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	stack<int>s;
	vector<int>v;
	vector<char>v1;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	vector<int>::iterator it;
	it = v.begin();
	for (int i = 1; i <= n; i++) {
		s.push(i);
		v1.push_back('+');
		while (!s.empty()) {
			if (*it != s.top()) {
				break;
			}
			else {
				s.pop();
				v1.push_back('-');
				it++;
			}
		}
	}
	if (s.empty()) {
		for(int i = 0; i<v1.size(); i++)
			cout << v1[i] << "\n";
	}
		
	else
		cout << "NO";
}