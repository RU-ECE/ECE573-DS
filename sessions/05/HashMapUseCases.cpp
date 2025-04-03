#include <iostream>

/*
When to use hashing (and not)        
1. Store numbers for rapid retrieval [0, 1'000'000]
    if (list.contains(500010))
2. Same as 1 but there are only 50 numbers
    could have a hash map (slower, more complexity)
3. Store numbers for rapid retrieval [a, b]  a= 10^8, b=10^9
    are they all there? if so 950999201 (USE AN ARRAY OF BITS!!!)
3b. same as 3, but only 1000 numbers
4. store numbers between 396.05 and 587.62 (2 digits after the decimal)
  if (list.contains(396.08))
  use an array
  bool x[int(h * 100) - 396]

5. Never use hashing on  floating point numbers
 float x = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 ;
 if (x == 1)
 you can only hash if you round off and do the equality test on INTEGERS
6. We want to identify movies quickly for an anti-piracy software
hash each movie to a unique 64-bit number to identify???
7. Suppose we have drivers licenses K76...   Car license place numbers
how to do a 2-way lookup?

    unordered_map<driverslicense, licenseplate> findcar;
    unordered_map<licenseplate, driverslicense> finddriver;
*/

int main() {
    float x = 0.5 + .25;
    float sum = 0;
    for (int i = 0; i < 100; i++)
      sum += 0.1;
    if (sum == 10.0) {
        cout << "this will never happen";
    }
}