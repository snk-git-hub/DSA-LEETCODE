# leetcode
<img width="1172" height="374" alt="image" src="https://github.com/user-attachments/assets/f7d247a2-2170-4636-ba16-6e6491fd8f54" />
maths ::::https://schoolyourself.org/learn
Most problems fall into these categories. Learn to identify them:


| **Pattern** | **Clue Words** | **Common Approach** |
|-------------|----------------|---------------------|
| **Two Pointers** | Sorted array, pairs, palindrome | Left & right pointers |
| **Sliding Window** | Subarray, substring, consecutive | Expand/contract window |
| **Binary Search** | Sorted, find target, log(n) | Left/right boundaries |
| **Hash Map** | Count, frequency, O(1) lookup | Store seen elements |
| **Stack** | Nested, parentheses, next greater | LIFO structure |
| **Queue/BFS** | Level-order, shortest path | FIFO structure |
| **DFS** | All paths, backtracking | Recursion |
| **DP** | Optimal, maximum, count ways | Subproblems + memoization |
| **Greedy** | Maximize/minimize, local optimal | Make best choice now |
| **Prefix Sum** | Range query, subarray sum | Cumulative sum array |

---
<img width="1200" height="922" alt="image" src="https://github.com/user-attachments/assets/41256c05-f646-4659-8f6f-28da79581748" />

https://claude.ai/public/artifacts/36188888-1a5c-47ab-90a5-7164aef178c6
<img width="956" height="419" alt="image" src="https://github.com/user-attachments/assets/006ff105-d532-433a-892c-8a61784c0293" />
<img width="974" height="748" alt="image" src="https://github.com/user-attachments/assets/21788f64-3b2d-434f-92d3-29d10a79c30e" />

Here's a proven strategy for when you get stuck on a problem:

## ⏰ Time-Based Approach

### **For Easy Problems:**
- **0-5 min:** Read, understand, try brute force
- **5-10 min:** If stuck, think about common patterns (hash map, two pointers)
- **10-15 min:** Still stuck? → **LOOK AT HINTS** (LeetCode provides hints)
- **15 min:** If no progress → **READ SOLUTION**, understand it, code it yourself

### **For Medium Problems:**
- **0-10 min:** Understand problem, examples, edge cases
- **10-25 min:** Try solving (brute force → optimize)
- **25-35 min:** Stuck? → **READ HINTS** or look at topic tags
- **35-40 min:** Still struggling? → **READ SOLUTION**
- **40+ min:** Understand solution deeply, implement from scratch

### **For Hard Problems:**
- **0-15 min:** Understand thoroughly, think about approach
- **15-40 min:** Attempt solution
- **40-50 min:** If stuck → **HINTS/TAGS**
- **50-60 min:** No progress? → **READ EDITORIAL**

---

## 🎯 Step-by-Step Problem Solving Framework

### **1. UNDERSTAND (5-10 min)**
```
□ Read problem 2-3 times
□ Identify input/output
□ Work through examples manually
□ Think of edge cases:
  - Empty input
  - Single element
  - All same elements
  - Maximum constraints
  - Negative numbers (if applicable)
□ Can you explain the problem to someone else?
```

### **2. EXPLORE (5-15 min)**
```
□ What's the brute force solution? (Always start here!)
□ What's the time/space complexity?
□ Draw it out on paper
□ Try small examples (n=1, n=2, n=3)
□ Look for patterns
□ Ask yourself:
  - Have I solved something similar?
  - What data structure fits naturally?
  - Is there sorting/searching involved?
  - Can I use hash map for O(1) lookups?
  - Is it about counting/frequency?
  - Does order matter?
```

### **3. PLAN (5-10 min)**
```
□ Choose an approach
□ Write pseudocode
□ Identify data structures needed
□ Think through the algorithm step-by-step
□ Verify with examples
```

### **4. IMPLEMENT (10-20 min)**
```
□ Write clean code
□ Use meaningful variable names
□ Comment complex parts
□ Handle edge cases
```

### **5. TEST (3-5 min)**
```
□ Run provided examples
□ Test edge cases
□ Dry run through your code
□ Check for off-by-one errors
□ Look for array out of bounds
```

---

## 🚨 When You're STUCK - Decision Tree

### **After trying for [time limit above]:**

**Option A: Use Hints** (Recommended first)
- Read first hint only
- Try for 5 more minutes
- Still stuck? Next hint
- This helps you learn the thought process

**Option B: Check Topic Tags**
- LeetCode shows topics (DP, Binary Search, etc.)
- This narrows down the approach
- Try for 10 more minutes with this knowledge

**Option C: Read Solution** (If Options A & B don't help)
- **DON'T just copy the code!**
- Read the **approach/intuition** section only
- Close the solution
- Try implementing yourself
- Stuck again? Read the code
- **THEN**: Close everything and code from scratch

**Option D: Watch Video Editorial** (If you need more explanation)
- NeetCode, Abdul Bari, or LeetCode's official videos
- Understand WHY this approach works
- Code it yourself after watching

---

## 📝 After Solving (CRITICAL STEP)

### **Learning Phase (10-15 min):**
```
1. Write down the key insight/pattern
2. What made this problem tricky?
3. What pattern/technique did it use?
4. Add to your notes:
   "Problem X uses [Pattern Y]"
   Example: "Two Sum uses hash map for O(1) lookup"

5. Mark for review:
   - If you got it: Review in 3 days
   - If you looked at hints: Review tomorrow
   - If you read solution: Review TONIGHT (before sleep)
```

---

## 🎓 Pattern Recognition (THE SECRET SAUCE)


## 💡 Pro Tips

1. **Never spend more than 60 min on one problem** during practice
   - You're practicing, not competing
   - Learning the pattern is more valuable than struggling

2. **The 30-minute rule:**
   - If no progress after 30 min → use hints/tags
   - Don't waste time being completely stuck

3. **Implement the brute force FIRST:**
   - Even if it's slow
   - Then optimize
   - This prevents analysis paralysis

4. **Review > Solving new problems:**
   - Solving 1 problem 3 times (spaced out) > solving 3 new problems once
   - Repetition builds pattern recognition

5. **Keep a "Stuck Log":**
   ```
   Problem: Two Sum
   Got stuck at: Optimizing from O(n²)
   Solution: Hash map for O(1) lookup
   Pattern: Space-time tradeoff
   ```

6. **During contests:**
   - If stuck on Q2 for 20+ min → move to Q3
   - Come back later with fresh eyes
   - Don't waste time on one problem

---

## 📊 Example: You're Stuck on "Container With Most Water"

**0-5 min:** Read problem, understand examples
```
Input: [1,8,6,2,5,4,8,3,7]
Output: 49 (between 8 and 7)
```

**5-15 min:** Try brute force
```cpp
// Check all pairs - O(n²)
int maxArea = 0;
for i in 0 to n:
  for j in i+1 to n:
    area = min(height[i], height[j]) * (j-i)
    maxArea = max(maxArea, area)
```

**15-20 min:** This works but can we optimize?
- **STUCK!** Can't think of better approach

**20 min:** Check **HINT 1**
- "The widest container uses the outermost lines..."
- **Aha!** Start from both ends?

**25 min:** Try implementing two pointers
```cpp
left = 0, right = n-1
while left < right:
  area = min(height[left], height[right]) * (right-left)
  if height[left] < height[right]:
    left++
  else:
    right--
```

**30 min:** Got it! Pattern learned: **Two pointers for optimization**

---

## ✅ Your Action Plan

### **Today:**
1. Pick 2-3 Easy problems
2. Use this framework
3. Time yourself strictly
4. Write down patterns you discover

### **This Week:**
1. Practice this framework on 10-15 problems
2. Build your pattern recognition
3. Create a "Pattern Cheat Sheet"
4. Review problems you solved 3 days ago

**Remember:** Getting stuck is NORMAL. The goal is to learn the pattern, not to solve every problem independently. Even top competitive programmers look up solutions when learning!

Want me to walk through a specific problem with you using this framework?
