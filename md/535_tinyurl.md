### 535\. [Encode and Decode TinyURL](https://leetcode.com/problems/encode-and-decode-tinyurl/submissions/)

```Note: This is a companion problem to the System Design problem: Design TinyURL.```
TinyURL is a URL shortening service where you enter a URL such as 
```https://leetcode.com/problems/design-tinyurl``` and it returns a short URL 
such as ```http://tinyurl.com/4e9iAk```.

Design the ```encode``` and ```decode``` methods for the TinyURL service. There is no
restriction on how your encode/decode algorithm should work. You just need 
to ensure that a URL can be encoded to a tiny URL and the tiny URL can be 
decoded to the original URL.


#### Solution 1

Use a vector to store longurl and its index as the shorturl.

C++

```
class Solution {
    vector<string> url;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        url.push_back(longUrl);
        return "http://tinyurl.com/" + to_string(url.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto pos = shortUrl.find_last_of("/");
        return url[stoi(shortUrl.substr(pos + 1))];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```

#### Solution 2

Build two hashmaps from long to short and from short to long.
If the long url exists in the hashmap, return the corresponding short url.
Othewise,randomly generate a 6-digit string as the short url.
Note, the short url cannot be already used for other long urls.

C++

```
class Solution {
    unordered_map<string, string> short2long;
    unordered_map<string, string> long2short;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "1qA2wS";
        while (short2long.count(shortUrl)) {
            int pos = rand() % 6;
            shortUrl[pos] = rand() % 128;
        }
            
        long2short[longUrl] = shortUrl;
        short2long[shortUrl] = longUrl;
        return "http://tinyurl.com/" + shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short2long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```
