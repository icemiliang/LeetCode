### 937\. [Reorder Data in Log Files](https://leetcode.com/problems/reorder-data-in-log-files/)

You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.


Example 1:
```
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 ```

Constraints:

1. 0 <= logs.length <= 100
2. 3 <= logs[i].length <= 100
3. logs[i] is guaranteed to have an identifier, and a word after the identifier.


#### Solution 1

C++

```
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits;
        vector<pair<string, string>> letters;
        
        // assign
        for (string& log : logs) {
            int i = 0;
            while (log[i] != ' ') i++;
            if (isalpha(log[i + 1])) letters.push_back({log.substr(0, i), log.substr(i + 1)});
            else digits.push_back(log);
        }
        
        // sort
        sort(letters.begin(), letters.end(), [&](auto&a, auto&b){
            return a.second == b.second ? a.first < b.first : a.second < b.second; 
        });
        
        // combine
        vector<string> res;
        for (auto& letter : letters) {
            res.push_back(letter.first + " " + letter.second);
        }
        res.insert(res.end(), digits.begin(), digits.end())
        return res;
    }
};
```
