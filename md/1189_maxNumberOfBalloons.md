### 1189\. [Maximum Number of Balloons](https://leetcode.com/problems/maximum-number-of-balloons/)

Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 
Example 1:
```
Input: text = "nlaebolko"
Output: 1
```
Example 2:
```
Input: text = "loonbalxballpoon"
Output: 2
```
Example 3:
```
Input: text = "leetcode"
Output: 0
```

Constraints:

1 <= text.length <= 10^4
text consists of lower case English letters only.

#### Solution 1

C++

```
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, double> m;
        for (char c : text) {
            if (c == 'b' or c == 'a' or c == 'n') m[c]++; 
            else if (c == 'l' or c == 'o') m[c] += 0.5;
        }
        
        if (m.size() != 5) return 0;

        double res = INT_MAX;
        for (auto c : m) {
            res = min(res, c.second);
        }

        return int(res);
    }
};
```
