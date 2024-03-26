# Linked Lists
Name __________________ NetID ____________

```cpp
class LinkedList {
private:
  struct Node {
    int val;
    Node* next;
  };
  Node* head;
};
```

1. How big is an empty LinkedList object? ______
2. How big is a pointer in C++ on a 64-bit computer? _______
3. How much memory is each Node? _________
   * How would you find out how big a Node is on your computer?
4. What is the complexity of...
   1. inserting n nodes into the list using addStart? O(_____)
   2. inserting n nodes into the list using addEnd? O(_____)
   3. If we have a Node*, inserting just after it in the list? O(_____)

```cpp
class LinkedList2 {
private:
  struct Node {
    int val;
    Node* next;
  };
  Node* head;
  Node* tail;
};
```

5. What is the difference with LinkedList2 vs LinkedList?