#include <iostream>

using namespace std;
int a[11];
int check(int n)
{
	a[1] = 1; // 1
	a[2] = 2; // 2, 1+1
	a[3] = 4; // 3, 2+1, 1+2, 1+!+1
	for (int i = 4; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}
	return a[n];
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int num, sum;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int n;
		cin >> n;
		cout<< check(n)<<"\n";
	}

}