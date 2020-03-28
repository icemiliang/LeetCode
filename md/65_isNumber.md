### 65\. [Valid Number](https://leetcode.com/problems/valid-number/)

Validate if a given string can be interpreted as a decimal number.

Some examples:
```
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
```

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

* Numbers 0-9
* Exponent - "e"
* Positive/negative sign - "+"/"-"
* Decimal point - "."

Of course, the context of these characters also matters in the input.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.

#### Solution 1

Additional examples:

```
string s1 = "0"; // True
string s2 = " 0.1 "; // True
string s3 = "abc"; // False
string s4 = "1 a"; // False
string s5 = "2e10"; // True

string s6 = "-e10"; // False
string s7 = " 2e-9 "; // True
string s8 = "+e1"; // False
string s9 = "1+e"; // False
string s10 = " "; // False

string s11 = "e9"; // False
string s12 = "4e+"; // False
string s13 = " -."; // False
string s14 = "+.8"; // True
string s15 = " 005047e+6"; // True

string s16 = ".e1"; // False
string s17 = "3.e"; // False
string s18 = "3.e1"; // True
string s19 = "+1.e+5"; // True
string s20 = " -54.53061"; // True

string s21 = ". 1"; // False
```

C++

```
class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();
        int lo = 0;
        int hi = len - 1;
        bool hasE = false;
        bool hasDot = false;
        bool hasDigit = false;
        
        // delete spaces
        while (s[lo] == ' ') ++lo;
        while (s[hi] == ' ') --hi;
        
        // first char
        if (s[lo] == '.') hasDot = true;
        else if (s[lo] >= '0' and s[lo] <= '9') hasDigit = true;
        else if (s[lo] != '+' and s[lo] != '-') return false;
        
        // middle chars
        for (int i = lo + 1; i < hi; ++i) {
            if (s[i] >= '0' and s[i] <= '9') hasDigit = true;
            else if (s[i] == 'e') {
                if (!hasE and s[i - 1] != '+' and s[i - 1] != '-' and hasDigit) hasE = true;
                else return false;
            }
            else if (s[i] == '+' or s[i] == '-') {
                if (s[i - 1] != 'e') return false;
            }
            else if (s[i] == '.') {
                if (!hasDot and !hasE) hasDot = true;
                else return false;
            }
            else return false;
        }
        
        // last char
        if (s[hi] >= '0' and s[hi] <= '9') return true;
        else if (s[hi] == '.' and !hasDot and !hasE and hasDigit) return true;
        else return false;
    }
};
```

#### Solution 2

C++

```
class Solution {
public:
    bool isNumber(string s) {
        bool hasDigit = false, digitAfterE = true, hasDot = false, hasE = false, hasSign = false;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (i < n - 1 and s[i + 1] != ' ' and (hasDigit or hasDot or hasE or hasSign)) return false;
            } 
            else if (s[i] == '+' or s[i] == '-') {
                if (i > 0 and s[i - 1] != 'e' and s[i - 1] != ' ') return false;
                hasSign = true;
            } 
            else if (s[i] >= '0' and s[i] <= '9') {
                hasDigit = true;
                digitAfterE = true;
            } 
            else if (s[i] == '.') {
                if (hasDot or hasE) return false;
                hasDot = true;
            } 
            else if (s[i] == 'e') {
                if (hasE or !hasDigit) return false;
                hasE = true;
                digitAfterE = false;
            } 
            else return false;
        }
        return hasDigit and digitAfterE;
    }
};
```
