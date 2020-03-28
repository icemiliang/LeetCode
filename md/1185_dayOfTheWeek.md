### 1185\. [Day of the Week](https://leetcode.com/problems/day-of-the-week/)

Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

Example 1:
```
Input: day = 31, month = 8, year = 2019
Output: "Saturday"
```

Example 2:
```
Input: day = 18, month = 7, year = 1999
Output: "Sunday"
```

Example 3:
```
Input: day = 15, month = 8, year = 1993
Output: "Sunday"
```

Constraints:

* The given dates are valid dates between the years 1971 and 2100.

#### Solution 1

Tomohiko Sakamoto Algorithm

C++

```
class Solution {
    string daysInWeek [7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; // 1
public:
    string dayOfTheWeek(int day, int month, int year) {
        int DaysByMonthMod7[12] = {0,3,2,5,0,3,5,1,4,6,2,4}; // 2
        if(month < 3) year -= 1; // 3
        return daysInWeek[(year + (year/4 - year/100 + year/400) + DaysByMonthMod7[month-1] + day) % 7]; // 4
    }
};
```

#### Solution 2

Zeller Formula

C++

```
class Solution {
public:
    vector<string> days= {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string dayOfTheWeek(int d, int m, int y, int c = 0) {
        if (m < 3) m += 12, y -= 1;
        c = y / 100, y = y % 100;
        int w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
        return days[(w + 7) % 7];
    }
};
```
