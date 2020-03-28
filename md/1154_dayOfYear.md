### 1154\. [Day of the Year](https://leetcode.com/problems/day-of-the-year/)

Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

 

Example 1:
```
Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
```

Example 2:
```
Input: date = "2019-02-10"
Output: 41
```

Example 3:
```
Input: date = "2003-03-01"
Output: 60
```

Example 4:
```
Input: date = "2004-03-01"
Output: 61
```

Constraints:

* date.length == 10
* date[4] == date[7] == '-', and all other date[i]'s are digits
* date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.

#### Solution 1

C++

```
class Solution {
    int daysUntilMonth[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
public:
    int dayOfYear(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8));
        d += y % 4 == 0 and m > 2 and (y % 100 != 0 or y % 400 == 0) != 0 ? 1 : 0;
        d += daysUntilMonth[m - 1];
        return d;
    }
};
```
