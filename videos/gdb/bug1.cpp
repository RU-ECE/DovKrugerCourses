#include <iostream>
#include <immintrin.h>
using namespace std;

void ptr1(int n) {
	int* p = new int[n];
	p++;
	for (int i = 0; i <= n; i++)
		p[i] = i;
	delete [] p;
}

void ptr2(int n) {
	int* p = new int[n];
	for (int i = 0; i < n; i++)
		if (i % 3 == 2)
			delete p;
		else
			p[i] = i;
}

void ptr3(int n) {
	uint64_t* p = new uint64_t[n];
	__m256d x = _mm256_load_pd((double*)p);

	delete [] p;
}

int main() {
	ptr1(10);
	ptr2(100);
	ptr3(40);
	return 0;
}
