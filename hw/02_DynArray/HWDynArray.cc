class GrowArray {
private:
	int* p;
	uint32_t size; // the number of elements used
	uint32_t capacity; // the amount of memory
	void checkGrow() {
	  if (memory does not need to grow)
	    return;
	  
		// if the memory needs to grow, double in size
		//TODO: YOU IMPLEMENT THIS
	}
public:
	//write constructor, destructor

	//copy constructor + 10%
	//double ended?  + 20% (SEE circularbuffer)
	void addEnd(int v) { //O(____________)
		
		
	}

	void addStart(int v) { //O(____________)

	}
	void removeStart() { //O(____________)

	}
	
	void removeEnd() { //O(____________)

	}
	uint32_t getSize() const { //O(____________)
		return size;
	}
	
};

int main() {
	GrowArray a(5); // empty list, with 500 elements
	const int n = 10;
	for (int i = 0; i < n; i++)   //O(____________)
		a.addEnd(i); // really fast!

	for (int i = 0; i < n; i++)    //O(____________)
		a.addEnd(i); // every time you need to grow, double

	a.addStart(5);
	
	for (int i = 0; i < n/2; i++) //O(____________)
		a.removeEnd();

	for (int i = 0; i < n/2; i++)
		a.removeStart();

	
    a.removeEvens();
	
	cout << a << '\n';
}
