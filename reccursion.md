https://claude.ai/public/artifacts/0d2ba1c7-d003-497d-97ed-2843e3786fc5
https://claude.ai/public/artifacts/0d2ba1c7-d003-497d-97ed-2843e3786fc5
https://claude.ai/public/artifacts/0d2ba1c7-d003-497d-97ed-2843e3786fc5
https://claude.ai/public/artifacts/0d2ba1c7-d003-497d-97ed-2843e3786fc5
-----------------------------------------------------------------------


-1.https://claude.ai/public/artifacts/0aa93351-f78d-4e63-9490-d7e9616829ca
-2.https://claude.ai/chat/629eb672-cdcc-4c35-8c76-cf668b82ce48




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
