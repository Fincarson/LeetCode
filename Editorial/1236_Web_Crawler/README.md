# 1236. Web Crawler

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/web-crawler/)  
`String` `Depth-First Search` `Breadth-First Search` `Interactive`

**Problem Link:** [LeetCode 1236 - Web Crawler](https://leetcode.com/problems/web-crawler/)

## Problem

Given a url startUrl and an interface HtmlParser, implement a web crawler to crawl all links that are under the same hostname as startUrl.

Return all urls obtained by your web crawler in any order.

Your crawler should:

- Start from the page: startUrl
- Call HtmlParser.getUrls(url) to get all urls from a webpage of given url.
- Do not crawl the same link twice.
- Explore only the links that are under the same hostname as startUrl.

As shown in the example url above, the hostname is example.org. For simplicity sake, you may assume all urls use http protocol without any port specified. For example, the urls http://leetcode.com/problems and http://leetcode.com/contest are under the same hostname, while urls http://example.org/test and http://example.com/abc are not under the same hostname.

The HtmlParser interface is defined as such:

```text
interface HtmlParser {
  // Return a list of all urls from a webpage of given url.
  public List<String> getUrls(String url);
}
```

Below are two examples explaining the functionality of the problem, for custom testing purposes you'll have three variables urls, edges and startUrl. Notice that you will only have access to startUrl in your code, while urls and edges are not directly accessible to you in code.

Note: Consider the same URL with the trailing slash "/" as a different URL. For example, "http://news.yahoo.com", and "http://news.yahoo.com/" are different urls.

### Example 1

```text
Input:
urls = [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.google.com",
  "http://news.yahoo.com/us"
]
edges = [[2,0],[2,1],[3,2],[3,1],[0,4]]
startUrl = "http://news.yahoo.com/news/topics/"
Output: [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.yahoo.com/us"
]
```

### Example 2

```text
Input:
urls = [
  "http://news.yahoo.com",
  "http://news.yahoo.com/news",
  "http://news.yahoo.com/news/topics/",
  "http://news.google.com"
]
edges = [[0,2],[2,1],[3,2],[3,1],[3,0]]
startUrl = "http://news.google.com"
Output: ["http://news.google.com"]
Explanation: The startUrl links to all other pages that do not share the same hostname.
```

## Constraints

- 1 <= urls.length <= 1000
- 1 <= urls[i].length <= 300
- startUrl is one of the urls.
- Hostname label must be from 1 to 63 characters long, including the dots, may contain only the ASCII letters from 'a' to 'z', digits  from '0' to '9' and the hyphen-minus character ('-').
- The hostname may not start or end with the hyphen-minus character ('-').
- See:  https://en.wikipedia.org/wiki/Hostname#Restrictions_on_valid_hostnames
- You may assume there're no duplicates in url library.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Web Crawler Multithreaded](https://leetcode.com/problems/web-crawler-multithreaded/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1236. Web Crawler

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-first search | C++, Java, Python3 |
| Breadth-first search | C++, Java, Python3 |

## Approach 1: Depth-first search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        function<string(string)> getHostname = [](string url) -> string {
            // find the next slash in the url after "http://"
            // that is after the 7-th position inclusively
            // if there is no such slash, pos will be equal to url.size()
            int pos = min(url.size(), url.find('/', 7));
            // return the substring that starts after "http://" and ends
            // before the next slash of at the end of the string
            return url.substr(7, pos - 7);
        };

        string startHostname = getHostname(startUrl);
        unordered_set<string> visited;

        function<void(string)> dfs = [&](string url) -> void {
            visited.insert(url);
            for (string nextUrl : htmlParser.getUrls(url)) {
                if (getHostname(nextUrl) == startHostname && !visited.count(nextUrl)) {
                    dfs(nextUrl);
                }
            }
        };

        dfs(startUrl);
        return vector<string>(visited.begin(), visited.end());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private String startHostname;
    private HashSet<String> visited = new HashSet<String>();

    private String getHostname(String url) {
        // split url by slashes
        // for instance, "http://example.org/foo/bar" will be split into
        // "http:", "", "example.org", "foo", "bar"
        // the hostname is the 2-nd (0-indexed) element
        return url.split("/")[2];
    }

    private void dfs(String url, HtmlParser htmlParser) {
        visited.add(url);
        for (String nextUrl : htmlParser.getUrls(url)) {
            if (getHostname(nextUrl).equals(startHostname) && !visited.contains(nextUrl)) {
                dfs(nextUrl, htmlParser);
            }
        }
    }

    public List<String> crawl(String startUrl, HtmlParser htmlParser) {
        startHostname = getHostname(startUrl);
        dfs(startUrl, htmlParser);
        return new ArrayList<>(visited);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        def get_hostname(url):
            # split url by slashes
            # for instance, "http://example.org/foo/bar" will be split into
            # "http:", "", "example.org", "foo", "bar"
            # the hostname is the 2-nd (0-indexed) element
            return url.split('/')[2]

        start_hostname = get_hostname(startUrl)
        visited = set()

        def dfs(url, htmlParser):
            visited.add(url)
            for next_url in htmlParser.getUrls(url):
                if get_hostname(next_url) == start_hostname and next_url not in visited:
                    dfs(next_url, htmlParser)

        dfs(startUrl, htmlParser)
        return visited
```

</details>

<br>

## Approach 2: Breadth-first search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        function<string(string)> getHostname = [](string url) -> string {
            // find the next slash in the url after "http://"
            // that is after the 7-th position inclusively
            // if there is no such slash, pos will be equal to url.size()
            int pos = min(url.size(), url.find('/', 7));
            // return the substring that starts after "http://" and ends
            // before the next slash or at the end of the string
            return url.substr(7, pos - 7);
        };

        queue<string> q;
        q.push(startUrl);
        unordered_set<string> visited{startUrl};
        string startHostname = getHostname(startUrl);
        while (!q.empty()) {
            string url = q.front();
            q.pop();
            for (string nextUrl : htmlParser.getUrls(url)) {
                if (getHostname(nextUrl) == startHostname && !visited.count(nextUrl)) {
                    q.push(nextUrl);
                    visited.insert(nextUrl);
                }
            }
        }
        return vector<string>(visited.begin(), visited.end());
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private String getHostname(String url) {
        // split url by slashes
        // for instance, "http://example.org/foo/bar" will be split into
        // "http:", "", "example.org", "foo", "bar"
        // the hostname is the 2-nd (0-indexed) element
        return url.split("/")[2];
    }

    public List<String> crawl(String startUrl, HtmlParser htmlParser) {
        String startHostname = getHostname(startUrl);
        Queue<String> q = new LinkedList<String>(Arrays.asList(startUrl));
        HashSet<String> visited = new HashSet<String>(Arrays.asList(startUrl));
        while (!q.isEmpty()) {
            String url = q.remove();
            for (String nextUrl : htmlParser.getUrls(url)) {
                if (getHostname(nextUrl).equals(startHostname) && !visited.contains(nextUrl)) {
                    q.add(nextUrl);
                    visited.add(nextUrl);
                }
            }
        }
        return new ArrayList<>(visited);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        def get_hostname(url):
            # split url by slashes
            # for instance, "http://example.org/foo/bar" will be split into
            # "http:", "", "example.org", "foo", "bar"
            # the hostname is the 2-nd (0-indexed) element
            return url.split('/')[2]

        start_hostname = get_hostname(startUrl)
        q = collections.deque([startUrl])
        visited = set([startUrl])
        while q:
            url = q.popleft()
            for next_url in htmlParser.getUrls(url):
                if get_hostname(next_url) == start_hostname and next_url not in visited:
                    q.append(next_url)
                    visited.add(next_url)
        return visited
```

</details>
