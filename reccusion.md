# Recursion Tricks/Patterns in LeetCode

Here are the key **decision-making patterns** and tricks used in recursion problems:

## 1. **Take / Not Take Pattern**
For subset/combination problems where you decide whether to include an element.

```cpp
// Example: Subset Sum
void subsetSum(vector<int>& nums, int idx, int target, int sum) {
    if (idx == nums.size()) {
        if (sum == target) {
            // found valid subset
        }
        return;
    }
    
    // Take current element
    subsetSum(nums, idx + 1, target, sum + nums[idx]);
    
    // Not take current element
    subsetSum(nums, idx + 1, target, sum);
}

// Example: 0/1 Knapsack
int knapsack(vector<int>& wt, vector<int>& val, int idx, int W) {
    if (idx == 0 || W == 0) return 0;
    
    if (wt[idx-1] <= W) {
        // Take or Not take
        return max(
            val[idx-1] + knapsack(wt, val, idx-1, W - wt[idx-1]), // take
            knapsack(wt, val, idx-1, W)                            // not take
        );
    }
    return knapsack(wt, val, idx-1, W); // can't take
}
```

## 2. **Try All Choices Pattern**
For permutation/combination problems where you try each available choice.

```cpp
// Example: Generate Parentheses
void generate(int open, int close, int n, string current, vector<string>& result) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }
    
    if (open < n) {
        generate(open + 1, close, n, current + '(', result);
    }
    if (close < open) {
        generate(open, close + 1, n, current + ')', result);
    }
}

// Example: Letter Combinations of Phone Number
void combinations(string& digits, int idx, string& current, 
                  vector<string>& result, vector<string>& mapping) {
    if (idx == digits.size()) {
        result.push_back(current);
        return;
    }
    
    string letters = mapping[digits[idx] - '0'];
    for (char c : letters) {
        current.push_back(c);
        combinations(digits, idx + 1, current, result, mapping);
        current.pop_back(); // backtrack
    }
}
```

## 3. **Include-Exclude Pattern**
Similar to take/not-take but tracks which elements are included.

```cpp
// Example: Subsets
void subsets(vector<int>& nums, int idx, vector<int>& current, 
             vector<vector<int>>& result) {
    result.push_back(current);
    
    for (int i = idx; i < nums.size(); i++) {
        current.push_back(nums[i]);      // include
        subsets(nums, i + 1, current, result);
        current.pop_back();              // exclude (backtrack)
    }
}
```

## 4. **Up-Down-Left-Right (4-Direction) Pattern**
For grid/matrix problems.

```cpp
// Example: Number of Islands
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() 
        || grid[i][j] == '0') {
        return;
    }
    
    grid[i][j] = '0'; // mark visited
    
    for (int k = 0; k < 4; k++) {
        dfs(grid, i + dx[k], j + dy[k]);
    }
}
```

## 5. **Express in Terms of Index Pattern**
Define recursion in terms of array indices or positions.

```cpp
// Example: Longest Increasing Subsequence
int lis(vector<int>& nums, int idx, int prevIdx) {
    if (idx == nums.size()) return 0;
    
    // Not take
    int notTake = lis(nums, idx + 1, prevIdx);
    
    // Take (if valid)
    int take = 0;
    if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
        take = 1 + lis(nums, idx + 1, idx);
    }
    
    return max(take, notTake);
}
```

## 6. **Partition Pattern**
Try all possible ways to partition/split.

```cpp
// Example: Palindrome Partitioning
void partition(string& s, int start, vector<string>& current, 
               vector<vector<string>>& result) {
    if (start == s.size()) {
        result.push_back(current);
        return;
    }
    
    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));
            partition(s, end + 1, current, result);
            current.pop_back(); // backtrack
        }
    }
}
```

## 7. **Pick from Both Ends Pattern**
For problems where you can pick from start or end.

```cpp
// Example: Stone Game / Predict the Winner
int maxScore(vector<int>& nums, int left, int right) {
    if (left > right) return 0;
    
    // Pick from left
    int pickLeft = nums[left] + min(
        maxScore(nums, left + 2, right),
        maxScore(nums, left + 1, right - 1)
    );
    
    // Pick from right
    int pickRight = nums[right] + min(
        maxScore(nums, left + 1, right - 1),
        maxScore(nums, left, right - 2)
    );
    
    return max(pickLeft, pickRight);
}
```

## 8. **Match/Skip Pattern**
For string matching problems.

```cpp
// Example: Wildcard Matching
bool isMatch(string& s, string& p, int i, int j) {
    if (j == p.size()) return i == s.size();
    
    bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '?'));
    
    if (p[j] == '*') {
        // Skip * or use *
        return isMatch(s, p, i, j + 1) ||           // skip *
               (i < s.size() && isMatch(s, p, i + 1, j)); // use *
    }
    
    return firstMatch && isMatch(s, p, i + 1, j + 1);
}
```

## 9. **Generate vs Validate Pattern**
Generate all possibilities then validate, or validate while generating.

```cpp
// Example: N-Queens
void solveNQueens(int row, int n, vector<string>& board, 
                  vector<vector<string>>& result) {
    if (row == n) {
        result.push_back(board);
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {    // validate
            board[row][col] = 'Q';            // place
            solveNQueens(row + 1, n, board, result);
            board[row][col] = '.';            // backtrack
        }
    }
}
```

## 10. **Nested Recursion Pattern**
One recursive call depends on another.

```cpp
// Example: Ackermann function
int ackermann(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return ackermann(m - 1, 1);
    return ackermann(m - 1, ackermann(m, n - 1));
}
```

## 11. **Return vs Modify Pattern**
Either return result or modify data structure in-place.

```cpp
// Return pattern
int countPaths(int i, int j) {
    if (i == m && j == n) return 1;
    return countPaths(i+1, j) + countPaths(i, j+1);
}

// Modify pattern (pass by reference)
void generateSubsets(vector<int>& nums, int idx, vector<int>& current,
                     vector<vector<int>>& result) {
    result.push_back(current); // modify result
    for (int i = idx; i < nums.size(); i++) {
        current.push_back(nums[i]);
        generateSubsets(nums, i + 1, current, result);
        current.pop_back();
    }
}
```

## Key Tips for Mastering These Patterns:

1. **Identify the decision space** - What choices do you have at each step?
2. **Define base case clearly** - When does recursion stop?
3. **Maintain state properly** - What needs to be passed/tracked?
4. **Backtrack when needed** - Undo changes after exploring a path
5. **Add memoization** - Cache results to avoid redundant computation
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
✓
---
##  Recursion Roadmap [✓]
---
##  Easy Problems
* [✓] Factorial
* [✓] Print 1 to n
* [✓] Print n to 1
* [✓] Sum of array
* [✓] Reverse a string
* [✓] Decimal to binary
* [✓] Sum of digits
* [✓] Array Min and Max
* [✓] Palindrome Check
---
## Medium Problems
* [✓] Mean of Array
* [✓] Adjacent duplicates
* [✓] Coin Change
* [ ] Binary to Gray
* [ ] Longest Palindromic Substring
* [ ] Tower of Hanoi
* [ ] Compute nCr
* [ ] Permutations
* [ ] Subsets
* [ ] Possible paths in matrix
* [ ] Combinations of Parentheses
---
##  Hard Problems
* [ ] Sort a Queue
* [ ] Sort a Stack
* [ ] Palindromic Partitions
* [ ] Scrambled Strings
* [ ] Word Break Problem
* [ ] N Queen Problem
* [ ] Sudoku Solver
* [ ] Knight's Tour
---



]















https://claude.ai/public/artifacts/0d2ba1c7-d003-497d-97ed-2843e3786fc5
https://claude.ai/public/artifacts/0d2ba1c7-d003-497d-97ed-2843e3786fc5
https://claude.ai/public/artifacts/0d2ba1c7-d003-497d-97ed-2843e3786fc5
https://claude.ai/public/artifacts/0d2ba1c7-d003-497d-97ed-2843e3786fc5
-----------------------------------------------------------------------


-1.https://claude.ai/public/artifacts/0aa93351-f78d-4e63-9490-d7e9616829ca


-2.https://claude.ai/public/artifacts/01db16f1-4977-4353-8bbc-644af8abe0d4



-3.https://claude.ai/chat/629eb672-cdcc-4c35-8c76-cf668b82ce48


-4.https://www.geeksforgeeks.org/dsa/top-100-data-structure-and-algorithms-dsa-interview-questions-topic-wise/


-5.https://www.geeksforgeeks.org/dsa/recursion-algorithms/





#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ============================================
// 1. LINEAR RECURSION - Single recursive call
// ============================================

// Example: Calculate factorial
int factorial(int n) {
    // BASE CASE
    if (n <= 1) return 1;
    
    // RECURSIVE CASE: n! = n * (n-1)!
    return n * factorial(n - 1);
}

// Example: Sum of array elements
int arraySum(int arr[], int n) {
    // BASE CASE
    if (n == 0) return 0;
    
    // RECURSIVE CASE: sum = last element + sum of rest
    return arr[n-1] + arraySum(arr, n-1);
}

// ============================================
// 2. BINARY RECURSION - Two recursive calls
// ============================================

// Example: Fibonacci number
int fibonacci(int n) {
    // BASE CASES
    if (n <= 1) return n;
    
    // RECURSIVE CASE: fib(n) = fib(n-1) + fib(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Example: Binary search in sorted array
int binarySearch(int arr[], int left, int right, int target) {
    // BASE CASE: not found
    if (left > right) return -1;
    
    int mid = left + (right - left) / 2;
    
    // BASE CASE: found
    if (arr[mid] == target) return mid;
    
    // RECURSIVE CASES: search left or right half
    if (arr[mid] > target)
        return binarySearch(arr, left, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, right, target);
}

// ============================================
// 3. TAIL RECURSION - Optimizable pattern
// ============================================

// Regular recursion (NOT tail recursive)
int factorialRegular(int n) {
    if (n <= 1) return 1;
    return n * factorialRegular(n - 1);  // Multiplication AFTER recursive call
}

// Tail recursion - last operation is the recursive call
int factorialTail(int n, int accumulator = 1) {
    // BASE CASE
    if (n <= 1) return accumulator;
    
    // RECURSIVE CASE: Pass result forward
    return factorialTail(n - 1, n * accumulator);  // Nothing after this!
}

// ============================================
// 4. BACKTRACKING - Try and backtrack
// ============================================

// Example: Generate all permutations of a string
void permute(string str, int left, int right, vector<string>& result) {
    // BASE CASE: one permutation complete
    if (left == right) {
        result.push_back(str);
        return;
    }
    
    // RECURSIVE CASE: Try each character at current position
    for (int i = left; i <= right; i++) {
        swap(str[left], str[i]);           // Make choice
        permute(str, left + 1, right, result);  // Explore
        swap(str[left], str[i]);           // Backtrack (undo choice)
    }
}

// ============================================
// 5. DIVIDE AND CONQUER - Break, solve, combine
// ============================================

// Example: Merge sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    // BASE CASE
    if (left >= right) return;
    
    // DIVIDE
    int mid = left + (right - left) / 2;
    
    // CONQUER (recursive calls)
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    
    // COMBINE
    merge(arr, left, mid, right);
}

// ============================================
// 6. TREE RECURSION - Natural for tree structures
// ============================================

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Preorder traversal: Root -> Left -> Right
void preorder(TreeNode* root) {
    // BASE CASE
    if (root == nullptr) return;
    
    // Process root
    cout << root->val << " ";
    
    // RECURSIVE CASES
    preorder(root->left);
    preorder(root->right);
}

// Calculate height of tree
int height(TreeNode* root) {
    // BASE CASE
    if (root == nullptr) return 0;
    
    // RECURSIVE CASE: 1 + max of subtree heights
    return 1 + max(height(root->left), height(root->right));
}

// ============================================
// MAIN - Testing examples
// ============================================

int main() {
    cout << "=== LINEAR RECURSION ===" << endl;
    cout << "Factorial(5) = " << factorial(5) << endl;
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Array sum = " << arraySum(arr, 5) << endl;
    
    cout << "\n=== BINARY RECURSION ===" << endl;
    cout << "Fibonacci(7) = " << fibonacci(7) << endl;
    int sorted[] = {1, 3, 5, 7, 9, 11};
    cout << "Binary search for 7: index = " << binarySearch(sorted, 0, 5, 7) << endl;
    
    cout << "\n=== TAIL RECURSION ===" << endl;
    cout << "Tail factorial(5) = " << factorialTail(5) << endl;
    
    cout << "\n=== BACKTRACKING ===" << endl;
    vector<string> perms;
    string str = "ABC";
    permute(str, 0, str.length() - 1, perms);
    cout << "Permutations of ABC: ";
    for (const string& s : perms) cout << s << " ";
    cout << endl;
    
    cout << "\n=== DIVIDE AND CONQUER ===" << endl;
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr2) / sizeof(arr2[0]);
    mergeSort(arr2, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl;
    
    cout << "\n=== TREE RECURSION ===" << endl;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << "Preorder: ";
    preorder(root);
    cout << "\nHeight: " << height(root) << endl;
    
    return 0;
}

