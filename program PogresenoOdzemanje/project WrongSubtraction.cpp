#include <iostream>
using namespace std;
int main()
{
	int n, i, k;
	cin >> n >> k;
	for (i = 0; i < k; i++) {
		if (n % 10 == 0) {
			n /= 10;
		}
		else
			n--;
	}
	cout << n;
}