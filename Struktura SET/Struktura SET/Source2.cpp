#include <iostream>
#include <set>
#include <cstdlib>
#include <string>
using namespace std;
int main() {
	multiset<string> iminja;
	multiset<string>::iterator it = iminja.begin();
	int n, i, br = 0;
	string ime, moe;
	cin >> n;
	cout << "Vnesi gi iminjata na ucenicite:  " << endl;
	for (i = 0; i<n; i++) {
		std::cin >> ime;
		iminja.insert(ime);
	}

	for (it = iminja.begin(); it != iminja.end(); it++) {
		cout << *it << endl;
	}

	cout << "Vase ime" << endl;
	cin >> moe;
	it = iminja.find(moe);
	for (i = 0; i<n; i++) {
		if (it != iminja.end()) {
			iminja.count(moe);
		}
	}
	cout << iminja.count(moe);
	system("pause");
	return 0;
}