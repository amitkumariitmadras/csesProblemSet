#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int n, p[20];
int main() {

cin >> n;

ll s = 0, ans = 0;
for(int i = 0; i<n; ++i){
    cin >> p[i], s+=p[i];
}
for(int i = 0; i<(1<<n); ++i){
    ll cs = 0;
    for(int j = 0; j<n; ++j){
        if(i>>j&1) cs +=p[j];
    }
    if(cs <= s/2) ans = max(ans, cs);
}
cout << s - 2*ans;
    
}

// ---

// ### **1. if `(i >> j & 1) cs += p[j];`

// This line checks whether the \(j\)-th bit in the binary representation of \(i\) is set (1). If it is, the value \(p[j]\) is added to the current subset sum `cs`.

// #### **Operators Used**

// 1. **`>>` (Right Shift Operator)**:
//    - Shifts the binary representation of `i` to the right by `j` positions.
//    - The least significant \(j\) bits are discarded, and the higher-order bits are shifted in.
//    - For example:
//      ```
//      i = 5 (binary 101), j = 1
//      i >> 1 = 2 (binary 010)
//      ```

// 2. **`&` (Bitwise AND Operator)**:
//    - Compares the binary representations of two numbers and returns `1` if both bits are `1`.
//    - For example:
//      ```
//      5 (binary 101) & 1 (binary 001) = 1 (binary 001)
//      ```

// 3. **Combined Logic**:
//    - `i >> j & 1`: Checks if the \(j\)-th bit in \(i\) is `1`:
//      - `i >> j`: Right shifts \(i\) by \(j\) bits, bringing the \(j\)-th bit to the least significant position.
//      - `& 1`: Extracts the least significant bit and compares it to `1`.

// #### **Purpose**:
// - This determines whether the \(j\)-th element (`p[j]`) is part of the subset represented by \(i\).
// - If the \(j\)-th bit is `1`, it includes \(p[j]\) in the current subset.

// ---

// #### **Example:**

// Let’s assume:
// - \(n = 3\), \(p = [3, 1, 4]\), and \(i = 5\) (binary `101`).

// ##### Iteration over \(j\) (inner loop):
// 1. \(j = 0\):
//    - \(i >> 0 = 5\) (binary `101`), \(i >> 0 & 1 = 1\).
//    - The 0-th bit is `1`, so include \(p[0] = 3\) in `cs`.

// 2. \(j = 1\):
//    - \(i >> 1 = 2\) (binary `010`), \(i >> 1 & 1 = 0\).
//    - The 1st bit is `0`, so do not include \(p[1]\).

// 3. \(j = 2\):
//    - \(i >> 2 = 1\) (binary `001`), \(i >> 2 & 1 = 1\).
//    - The 2nd bit is `1`, so include \(p[2] = 4\) in `cs`.

// Final subset: \([3, 4]\), \(cs = 3 + 4 = 7\).

// ---

// ### **2. for `(int i = 0; i < (1 << n); ++i)`

// This loop iterates over all possible subsets of the array \(p\) using bitwise representation.

// #### **Operators Used**

// 1. **`<<` (Left Shift Operator)**:
//    - Shifts the binary representation of `1` to the left by `n` positions.
//    - Equivalent to computing \(2^n\).
//    - For example:
//      ```
//      1 << 3 = 8 (binary 1000)
//      ```

// 2. **Logic**:
//    - `(1 << n)` computes the total number of subsets for an array of size \(n\).
//    - For each subset:
//      - \(i\) (from `0` to \(2^n - 1\)) represents the binary encoding of the subset.
//      - Each bit in \(i\) corresponds to whether a particular element of \(p\) is included in the subset:
//        - If bit \(j\) is `1`, \(p[j]\) is included.
//        - If bit \(j\) is `0`, \(p[j]\) is not included.

// ---

// #### **Example:**

// Let’s assume \(n = 3\) and \(p = [3, 1, 4]\). Then:
// - Total subsets: \(1 << 3 = 8\) (from `0` to `7`).

// ##### Iteration:
// - **\(i = 0\)** (binary `000`):
//   - No bits set → Empty subset \([]\), \(cs = 0\).

// - **\(i = 1\)** (binary `001`):
//   - Only the 0th bit set → Subset \([3]\), \(cs = 3\).

// - **\(i = 2\)** (binary `010`):
//   - Only the 1st bit set → Subset \([1]\), \(cs = 1\).

// - **\(i = 3\)** (binary `011`):
//   - 0th and 1st bits set → Subset \([3, 1]\), \(cs = 4\).

// - **\(i = 4\)** (binary `100`):
//   - Only the 2nd bit set → Subset \([4]\), \(cs = 4\).

// - **\(i = 7\)** (binary `111`):
//   - All bits set → Subset \([3, 1, 4]\), \(cs = 8\).

// ---

// ### **Key Insights**

// 1. **Bitwise Representation**:
//    - \(i\) represents subsets as binary numbers:
//      - \(1\): Element is included.
//      - \(0\): Element is excluded.

// 2. **Efficiency**:
//    - Using bitwise operations allows efficient subset generation without explicitly storing or iterating through each subset.

// 3. **Total Subsets**:
//    - \(1 << n = 2^n\), so there are \(2^n\) subsets in total.

// ---

// ### **Summary**

// - **`if (i >> j & 1)`**:
//   - Checks if the \(j\)-th element is part of the current subset represented by \(i\).

// - **`for (int i = 0; i < (1 << n); ++i)`**:
//   - Iterates over all possible subsets of \(n\) elements using bitwise representation.

// This is a clever and efficient way to generate subsets for smaller values of \(n\). Let me know if you have further questions! 🚀