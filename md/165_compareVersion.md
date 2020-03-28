### 165\. [Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/)

Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.

 
Example 1:
```
Input: version1 = "0.1", version2 = "1.1"
Output: -1
```

Example 2:
```
Input: version1 = "1.0.1", version2 = "1"
Output: 1
```

Example 3:
```
Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
```

Example 4:
```
Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”
```

Example 5:
```
Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"
```

Note:

1. Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
2. Version strings do not start or end with dots, and they will not be two consecutive dots.


#### Solution 1

According to the definition of the version string, we need to convert the substring between each two 
dots to a number and compare which string has a larger number. We can scan the string until the 
end of the string or until a dot. During the scan, use a carry number to covner the substring to a
number. The only case where two versions equal is when all the carry numbers equal. Otherwise,
we can immediately determine which version is larger. There are two variants. The first variant
computes the carry numbers for both versions parallely. The second variant individually. The 
code structures look like 2_add_two_numbers.

Very similar to [2. Add Two Numbers](2_addTwoNumbers.md).

C++

```
class Solution {
public:
    int compareVersion(string version1, string version2) {
        unsigned int p1 = 0, p2 = 0;
        int carry1 = 0, carry2 = 0;
        while (p1 < version1.size() and p2 < version2.size()) {
            while (p1 < version1.size() and version1[p1] != '.') {
                carry1 = carry1 * 10 + (version1[p1] - '0');
                p1++;
            }
            while (p2 < version2.size() and version2[p2] != '.') {
                carry2 = carry2 * 10 + (version2[p2] - '0');
                p2++;
            }
            if (carry1 < carry2) return -1;
            if (carry1 > carry2) return 1;
            carry1 = 0;
            carry2 = 0;
            p1++;
            p2++;
        }
        while (p1 < version1.size()) {
            if (version1[p1] != '0' and version1[p1] != '.') return 1;
            p1++;

        } 
        while (p2 < version2.size()) {
            if (version2[p2] != '0' and version2[p2] != '.') return -1;
            p2++;
        }
        return 0;
    }
};
```

The above solution is tedious. We can simplify it as below. 

```
class Solution {
public:
    int compareVersion(string version1, string version2) {
        unsigned int p1 = 0, p2 = 0;
        int carry1 = 0, carry2 = 0;
        while (p1 < version1.size() or p2 < version2.size()) {
            while (p1 < version1.size() and version1[p1] != '.') {
                carry1 = carry1 * 10 + (version1[p1] - '0');
                p1++;
            }
            while (p2 < version2.size() and version2[p2] != '.') {
                carry2 = carry2 * 10 + (version2[p2] - '0');
                p2++;
            }
            if (carry1 < carry2) return -1;
            if (carry1 > carry2) return 1;
            carry1 = 0;
            carry2 = 0;
            p1++;
            p2++;
        }
        return 0;
    }
};
```

Python

```
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        p1 = 0
        p2 = 0
        carry1 = 0
        carry2 = 0
        while p1 < len(version1) or p2 < len(version2):
            while p1 < len(version1) and version1[p1] != '.':
                carry1 = carry1 * 10 + (ord(version1[p1]) - ord('0'))
                p1 += 1
            while p2 < len(version2) and version2[p2] != '.':
                carry2 = carry2 * 10 + (ord(version2[p2]) - ord('0'))
                p2 += 1
            if carry1 < carry2:
                return -1
            if carry1 > carry2:
                return 1
            carry1 = 0
            carry2 = 0
            p1 += 1
            p2 += 1
        return 0
```

#### Solution 2

istringstream

```

```
