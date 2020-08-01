#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector <int> myv;
	myv.push_back(INT_MIN);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (myv.back()< num)
			myv.push_back(num);
		else
		{
			auto ip = lower_bound(myv.begin(), myv.end(), num);
			if (*(ip)!= num)
				myv.insert(ip, 1, num);
		}
	}
	cout << myv.size() - 1;
	return 0;
}