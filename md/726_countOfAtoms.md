### 726\. [Number of Atoms](https://leetcode.com/problems/number-of-atoms/)

Given a chemical formula (given as a string), return the count of each atom.

An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

1 or more digits representing the count of that element may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

Example 1:
```
Input: 
formula = "H2O"
Output: "H2O"
Explanation: 
The count of elements are {'H': 2, 'O': 1}.
```

Example 2:
```
Input: 
formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: 
The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
```

Example 3:
```
Input: 
formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: 
The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
```

Note:

* All atom names consist of lowercase letters, except for the first character which is uppercase.
* The length of ```formula``` will be in the range ```[1, 1000]```.
* ```formula``` will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.


#### Solution 1

Recursion. Parse string inside each parentheses.

parse(str, pos) {
    while pos < str.size():
        if '(':  start a new sequence by recursion
        else if ')': parse count after ) and return 
        else: parse atom & parse count
}

C++

```
class Solution {
public:
    string countOfAtoms(string formula) {
        string res = "";
        int pos = 0;
        // get {atom, count} sorted
        map<string, int> m = parse(formula, pos);
        for (auto& a : m) {
            // add atom
            res += a.first;
            // add frequency
            if (a.second > 1) res += to_string(a.second);
        }
        return res;
    }
    
    map<string, int> parse(string& str, int& pos) {
        map<string, int> res;
        while (pos < str.size()) {
            // start a new sequence by recursion
            if (str[pos] == '(') {
                ++pos;
                map<string, int> m = parse(str, pos);
                for (auto& a : m) {
                    res[a.first] += a.second;
                }
            }
            // parse count after ) and return 
            else if (str[pos] == ')') {
                int i = ++pos;
                while (pos < str.size() and isdigit(str[pos])) ++pos;
                int cnt = stoi(str.substr(i, pos - i));
                for (auto& a : res) {
                    a.second *= cnt;
                }
                return res;
            }
            // parse an atom and a count
            else {
                // parse atom
                int i = pos++; // skip a big letter, all folloing small
                // letters are part of the name of the atom
                while (pos < str.size() and islower(str[pos])) ++pos;
                string atom = str.substr(i, pos - i);
                // parse count
                i = pos;
                while (pos < str.size() and isdigit(str[pos])) ++pos;
                string cnt = str.substr(i, pos - i);
                // if count string is empty, count is 1
                res[atom] += cnt.empty() ? 1 : stoi(cnt);
            }
        }
        return res;
    }
};
```
