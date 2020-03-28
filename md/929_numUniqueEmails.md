### 929\. [Unique Email Addresses](https://leetcode.com/problems/unique-email-addresses/)

Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 


Example 1:
```
Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
```

Note:

1 <= emails[i].length <= 100
1 <= emails.length <= 100
Each emails[i] contains exactly one '@' character.


#### Solution 1

Build a set to store unique emails and at the end return its size.
Loop the email array and for each email do the following:
	1. extract the local name
	2. discard everything after '+'
	3. erase every '.'
	4. combine whatever left and the domain name and put it in the set.

C++

```
class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> receivers;
		for (string email : emails) {
			auto idxAt = email.find_last_of('@');
			string local = email.substr(0, idxAt); // 1. 
			local = local.substr(0, local.find_first_of('+')); // 2. 
			while (local.find_first_of('.') != -1) {
				local.erase(local.find_first_of('.')); // 3.
			}
			receivers.insert(local + email.substr(idxAt)); // 4.
		}
		return receivers.size();
	}
}
```

A slightly different version of solution 1. Directly erase chars.

```
class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> receivers;
		for (string email : emails) {
			if (email.find_first_of('+') != -1) {
				email.erase(email.find_first_of('+'), email.find_first_of('@'));
			}
			while (email.find_first_of('.') < email.find_first_of('@')) {
				email.erase(email.find_first_of('.'));
			}
			receivers.insert(email);
		}
		return receivers.size();
	}
}
```

A slightly different version of solution 2.

```
class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> receivers;
		for (string email : emails) {
			for (int i = 0; i < email.size(); i++) {
				if (email[i] == '.') email.erase(i); 
				else if (email[i] == '@') break;
				else if (email[i] == '+') { 
					email.erase(i, email.find_first_of('@')); 
					break; 
				}
			}
			receivers.insert(email);
		}
		return receivers.size();
	}
}
```
