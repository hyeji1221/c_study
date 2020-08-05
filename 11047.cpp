#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool desc(int a, int b)
{
	return a > b;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector <int> myv;
	int num, won;
	int total = 0;
	cin >> num >> won;
	for (int i = 0; i < num; i++)
	{
		int n;
		cin >> n;
		myv.push_back(n);
	}
	
	sort(myv.begin(), myv.end(), desc);

	for (int i = 0; i < num; i++)
	{
		while (won - myv[i] >= 0)
		{
			won -= myv[i];
			total++;
		}
	}
	cout << total << "\n";

}