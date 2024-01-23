int main() {
	constexpr uint32_t n = 100'000'000;
	vector<int> a; // start with 1 double to 2 double 4
	a.reserve(n); // twice as fast!
	for (int i = 0; i < n; i++)
		a.push_back(i);
	int* p = new int[n];


	delete [] p;
	int x[n];


	
}
