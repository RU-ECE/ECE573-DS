#Midterm Review

1. Complexity
    // O(n), O(n^2), O(log n)
   for (int i = a; i < b; i += s)

      for (int i = a; i < b; i += s)
         for (int j = a; j < b; j += s)

   recursion

   f(x) //O(n)
     if (x < 51)
       return 3;
     return f(x-2);

   f(x)//O(log n)
     if (x < 51)
       return 3;
     return f(x/2);
   

   g(x)
     if (x < 1000)
        return 10x;

    h(x)
      if (x < 10)
        return 5
    return h(x-2) + h(x-1) + h(x)

        fibo(x)
      if (x < 10)
        return 5
    return fibo(x-2) + fibo(x-1)

2. Dynamic Array
n=10^6
DynArray a(1000); // preallocate 1000
for (int i  = 0; i < n; i++) // O(______)
  a.addStart(i); // O(______)

3. LinkedList
    DoubleLinkedList a;
    for (int i = 0; i < n; i++)
      a.addStart(i);

      Node temp = new Node(); // hint: DRAW A PICTURE!!! partial credit
      temp.next = head
      head.prev = temp
      temp.val = v;
      head = temp
3b. queue, stack
    enqueue, dequeue, isempty()

    push() pop() isempty()

4. tree (NO RED BLACK TREE, no BTREE)
   TRIE
    insert
    isWord(w)
    startWith(w)
   expression tree
     inorder, preorder, postorder

     5 4 + 6 x - *  in RPNshow the tree
          *
      +     -
     5 4   6 x
5. Hashing
   linear probing
   linear chaining
   perfect hashing (only data)



   n=16
   show 5, 6, 8, 16, 21, 18, 2
   birthday paradox
   hash(X) = x mod n
   write linear chaining...

// demonstrate that you understand hashing
   hash(string s) {
     int sum = 0;
    for each c in s
       sum = sum * 31 + c;
   }
6. sorting
   1. insertion
      1. know special cases omega(n) sorting where 3 are wrong
   2. quicksort (original Hoare, Lomuto)
      1. demonstrate knowledge of pivot  O(n^2) pick pivot badly
      2. know that random pivot is best
   3. heapsort

    1 2 3 4 5 6 7 8 9

           9
        8     7
    4    5   6    3
  2  1


  makeheap() {
    for i = n/2-1 downto 0
  }





   4. mergesort
        5 1 4 2 6 7 8 9   = n
        1 5 2 4 6 7 8 9   = n
        1 2 4 5

7. shuffling & searching
   1. Fischer-Yates
   2. linear search
   3. binary search (recursive and iterative)

