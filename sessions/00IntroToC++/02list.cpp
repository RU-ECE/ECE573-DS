class List {
private:
    int* data;
    int size;

public:
//bug #1 forgot to initialize data to null
    List() : /*data(nullptr);*/  size(0){
    }
    ~List() {
        delete [] data;        
    }

    void add(int v) {
        int* old = data;
        data = new int[size+1];
        for (int i = 0; i < size; i++)
            data[i] = old[i];
        delete[] old;
        data[size] = v;
        size++;

    }

};

int main() {
    List a;
    for (int i = 0; i < 10; i++)
        a.add(i);
}