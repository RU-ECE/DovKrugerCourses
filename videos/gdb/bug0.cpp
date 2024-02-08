#include <iostream>
#include <random>
using namespace std;

int sum1ton(int n) {
	int sum;
	for (int i = 1; i < n; i++)
		sum += i;
	return sum;
}

int fact(int n) {
	int prod = 0;
	while (n > 1)
		prod *= n--;
	return prod;
}

int partition(int a[], int low, int high) {
	int pivot = a[(low+high)/2];
	int i = low, j = high;
	while (i < j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		swap(a[i], a[j]);
	}
	return i;
}


int main() {
	cout << sum1ton(10) << '\n';
	cout << fact(10) << '\n';
	int a[] = {10, 9, 8, 7, 6, 4, 3, 2, 1};
	int p = partition(a, 0, 8);
	cout << "pivot=" << p << '\n';
	for (int i = 0; i < sizeof(a)/sizeof(int); i++)
		cout << a[i] << ' ';
	cout << '\n';
	return 0;
}
