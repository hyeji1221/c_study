#include <iostream>
#include <cmath>
using namespace std;

int result = 0;
int mul(long long a, long long b, long long c)
{
	if (b == 0)
		return 1;
	long long result = mul(a, b / 2, c);
	result = result * result % c;
	if (b % 2 == 0) return result;
	else
		return (result * a) % c;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long a, b, c; // a를 b번 곱한 수 c로 나눈 나머지
	cin >> a >> b >> c;
	cout << mul(a, b, c) << "\n";

}