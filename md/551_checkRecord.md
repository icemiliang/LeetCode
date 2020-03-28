### 551\. [Student Attendance Record I](https://leetcode.com/problems/student-attendance-record-i/)

You are given a string representing an attendance record for a student. The record only contains the following three characters:

1. 'A' : Absent.
2. 'L' : Late.
3. 'P' : Present.

A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
```
Input: "PPALLP"
Output: True
```
Example 2:
```
Input: "PPALLL"
Output: False
```

#### Solution 1

C++

```
class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0;
        int cntL = 0;
        for (const char c: s) {
            if (c == 'L') {
                cntL++;
                if (cntL > 2) return false;
            }
            else {
                if (c == 'A' and ++cntA > 1) return false;
                cntL = 0;
            }
        }
        return true;
    }
};
```
