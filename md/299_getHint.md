### 299\. [Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/)

You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:
```
Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
```

Example 2:
```
Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
```
Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

#### Solution 1

C++

```
class Solution {
public:
    string getHint(string secret, string guess) {
        int m1[10] = {0};
        int m2[10] = {0};
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) bulls++;
            else {
                m1[secret[i] - '0']++;
                m2[guess[i] - '0']++;
            }
        }
        
        for (int i = 0; i < 10; i++) {
            cows += min(m1[i], m2[i]);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
```

#### Solution 2

C++

```
class Solution {
public:
    string getHint(string secret, string guess) {
        int m[10] = {0};
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) bulls++;
            else {
                if (m[secret[i] - '0']++ < 0) cows++; // appeared in guess
                if (m[guess[i] - '0']-- > 0) cows++; // appeared in secret
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
```
