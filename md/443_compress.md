### 443\. [String Compression](https://leetcode.com/problems/string-compression/)

Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

 
Follow up:
Could you solve it using only O(1) extra space?

 
Example 1:
```
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
``` 

Example 2:
```
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
``` 

Example 3:
```
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
```

Note:

1. All characters have an ASCII value in [35, 126].
2. 1 <= len(chars) <= 1000.

#### Solution 1

We need three pointers to solve this problem: a pointer to store the current position of
the new array; a pointer to store the start position of the current character; a pointer
to store the current position. The algorithms becomes pretty clear right now. We scan the
array. For each new character, find its last consecutive appearance. Then, first add the 
char to the new array. Then, if the char appeared more than once, convert the frequency 
into string and put each char of the string to the new array.

C++
```
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int cur = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n and chars[j] == chars[i]) j++;
            chars[cur++] = chars[i];
            if (j - i == 1) continue;
            for (char c : to_string(j - i)) chars[cur++] = c;
        }
        return cur;
    }
};
```

My own ugly implementation.

```
class Solution {
public:
    int compress(vector<char>& chars) {
        int last = 0;
        for (int i = 0; i < chars.size(); ++i) {
            chars[last] = chars[i];
            int j = i;
            while (i < chars.size() - 1 and chars[i] == chars[i + 1]) ++i;
            if (i > j) {
                string s = to_string(i - j + 1);
                for (char c : s) {
                    chars[++last] = c;    
                }                
            }
            ++last;
        }
        return last;
    }
};
```

Python

```
class Solution:
    def compress(self, chars: List[str]) -> int:
        cur = 0
        i = 0
        j = 0
        while i < len(chars):
            while j < len(chars) and chars[j] == chars[i]:
                j += 1
            chars[cur] = chars[i]
            cur += 1
            if j - i != 1:
                for c in str(j - i):
                    chars[cur] = c
                    cur += 1
            i = j
        return cur
```
