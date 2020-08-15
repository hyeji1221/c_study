#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool check(string str)
{
	stack<char> st;
	int len = (int)str.length();
	for (int i = 0; i < len; i++)
	{
		char c = str[i];
		if (c == '(')
			st.push(str[i]);
		else if (c == ')')
		{
			if (!st.empty())
				st.pop();
			else
				return false;
		}
	}
	return st.empty();

}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (check(str))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";

	}




}