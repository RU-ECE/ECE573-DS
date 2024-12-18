# Heapsort Pseudocode

```pseudocode
/*
  1 2 3 4 5 6 7 8

         2
     5         7
  4     1   6    3
8


2 5 7 4 1 6 3 | 8
*/
heapsort(a)
  for i = n/2-1; i >= 0; i-- //O(n)
    makesubheap(a, i, n)     //O(log n)
  end
  for i = n-1; i > 0; i--) //O(n)
    swap(a[0], a[i])
    makesubheap(a, 0, i)  //O(log n)
  end
end

makesubheap(a, i, n)
  left = 2i+1
  right = 2i+2
  if right < n
  if a[left] > a[right]
    if a[left] > a[i]
      swap(a[left], a[i])
      makesubheap(a, left, n)
    end
  else
    if a[right] > a[i]
      swap(a[right], a[i])
      makesubheap(a, right, n)
    end
  end
  else if left < n
    if a[left] > a[i]
      swap(a[left], a[i])
      makesubheap(a, left, n)
    end
  end
end
```

## Quiksort

```cpp
a = [8 7 6 5 4 3 2 1]
quiksort(a, 0, n-1)

quiksort(a, L, R)
  pivot = a[random(L, R)]
  i = L, j = R

  while i < j
    while a[i] <= pivot
      i = i + 1
    end
    while a[j] >= pivot
      j = j - 1
    end
    if i < j
      swap(a[i], a[j])
    end
  end
  if i-1 - L > k
    quiksort(a, L, i-1)
  end
  if R - i > k
    quiksort(a, i, R)
  end

end
// 20 19 18 1 16 15 14 13 12 11 17 10 8 9 6 5 4 3 2 7
// 7 2 3 1 4 5 6 8 9 ^ 13 12 11 10  15 16 18 19 20
// 1 2 3 4 5 6 7 8 9  

knuthOptimizedQuicksort(a)
  partialQuicksort(a)
  insertionsort(a)
end

//a = [5 4 3 8 7 6]
//    [4 5]
//    [3 4 5]
//    [3 4 5 8]
//    [3 4 5 7 8]
//    [3 4 5 6 7 8]

// 8 7 6 5 4 3
// 7 8 = 1
// 6 7 8 = 2
// 5 6 7 8 = 3

// 1 + 2 + 3 + .. n = n(n+1)/2 = O(n^2)

//  7 8 6
// temp = 6
// for j = 1; i >= 0; i--)
//   a[j+1] = a[j]  7 7 8

// 2 3 4 5 6 7 4
// temp=4
// for j = 5; j >= 0; j--
//   if a[j]] > temp
//       a[j+1] = a[j]
//      4  4  5 6 7


insertionsort(a)
 for (int i = 1; i < n; i++) {
    int temp = a[i];
    for (int j = i-1; j >= 0; j--)
      if (a[j] > temp)
        a[j+1] = a[j];
      else
        a[j+1] = temp;
        goto out;
      end
    end
    a[0] = temp;
out: ;
}

struct Node {
    int key
    int val
    Node* next
}

hash(x)
  retun x mod table.size
end

class LinearChainingHashmap {
private:
    int* get(int key, int bin) {}
        for (Node* p = table[bin]; p != nullptr; p = p->next)
          if(p->key == key)
             return &p->val
        return nullptr
    }
public:
    LinearChainingHashmap(capacity)
        table = new Node*[capacity]
        for (int i = 0; i < capacity; i++)
        table[i] = nullptr
    end

    add(key, val) {
        int bin = hash(key)
        int* v = get(key, bin);
        table[bin] = new Node(key, val, table[bin])
    }
    int* get(key) {
        int bin = hash(key)
        return get(key, bin)
    }


end







