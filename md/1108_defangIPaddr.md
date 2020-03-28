### 1108\. [Defanging an IP Address](https://leetcode.com/problems/defanging-an-ip-address/)

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:
```
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
```

Example 2:
```
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
```

Constraints:

The given address is a valid IPv4 address.

#### Solution 1

C++

```
class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (char c : address) {
            if (c == '.') res.push_back('[');
            res.push_back(c);
            if (c == '.') res.push_back(']');
        }
        return res;
    }
};
```

Using regex.

```
string defangIPaddr(string address) {
  return regex_replace(address, regex("[.]"), "[.]");
}
```
