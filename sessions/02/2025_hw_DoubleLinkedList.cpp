int main() {
    DoubleLinkedList2 a; // doubly linked list with head and tail
    const int n = 10;
    for (int i =0; i < n; i++) //O(  )
      a.addEnd(i); // 0 1 2 3 4 5 6 7 8 9 
    cout << a << '\n';

    for (int i = 0; i < n; i++)
      a.addStart(i);

    cout << a.length() << '\n'; // O()

    // O(?? )
    cout << a.find(8) << '\n'; // print the location of the first occurrence of number 8 in the list, -1 if it's not there

    DoubleLinkedList2 b(a); // copy constructor
    a.addStart(19);
    cout << b << '\n'; // b should not have a 19 on it
    
}