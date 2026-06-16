# 1912. Design Movie Rental System

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/design-movie-rental-system/)  
`Array` `Hash Table` `Design` `Heap (Priority Queue)` `Ordered Set`

**Problem Link:** [LeetCode 1912 - Design Movie Rental System](https://leetcode.com/problems/design-movie-rental-system/)

## Problem

You have a movie renting company consisting of n shops. You want to implement a renting system that supports searching for, booking, and returning movies. The system should also support generating a report of the currently rented movies.

Each movie is given as a 2D integer array entries where entries[i] = [shopi, moviei, pricei] indicates that there is a copy of movie moviei at shop shopi with a rental price of pricei. Each shop carries at most one copy of a movie moviei.

The system should support the following functions:

- Search: Finds the cheapest 5 shops that have an unrented copy of a given movie. The shops should be sorted by price in ascending order, and in case of a tie, the one with the smaller shopi should appear first. If there are less than 5 matching shops, then all of them should be returned. If no shop has an unrented copy, then an empty list should be returned.
- Rent: Rents an unrented copy of a given movie from a given shop.
- Drop: Drops off a previously rented copy of a given movie at a given shop.
- Report: Returns the cheapest 5 rented movies (possibly of the same movie ID) as a 2D list res where res[j] = [shopj, moviej] describes that the jth cheapest rented movie moviej was rented from the shop shopj. The movies in res should be sorted by price in ascending order, and in case of a tie, the one with the smaller shopj should appear first, and if there is still tie, the one with the smaller moviej should appear first. If there are fewer than 5 rented movies, then all of them should be returned. If no movies are currently being rented, then an empty list should be returned.

Implement the MovieRentingSystem class:

- MovieRentingSystem(int n, int[][] entries) Initializes the MovieRentingSystem object with n shops and the movies in entries.
- List<Integer> search(int movie) Returns a list of shops that have an unrented copy of the given movie as described above.
- void rent(int shop, int movie) Rents the given movie from the given shop.
- void drop(int shop, int movie) Drops off a previously rented movie at the given shop.
- List<List<Integer>> report() Returns a list of cheapest rented movies as described above.

Note: The test cases will be generated such that rent will only be called if the shop has an unrented copy of the movie, and drop will only be called if the shop had previously rented out the movie.

### Example 1

```text
Input
["MovieRentingSystem", "search", "rent", "rent", "report", "drop", "search"]
[[3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]], [1], [0, 1], [1, 2], [], [1, 2], [2]]
Output
[null, [1, 0, 2], null, null, [[0, 1], [1, 2]], null, [0, 1]]

Explanation
MovieRentingSystem movieRentingSystem = new MovieRentingSystem(3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]);
movieRentingSystem.search(1);  // return [1, 0, 2], Movies of ID 1 are unrented at shops 1, 0, and 2. Shop 1 is cheapest; shop 0 and 2 are the same price, so order by shop number.
movieRentingSystem.rent(0, 1); // Rent movie 1 from shop 0. Unrented movies at shop 0 are now [2,3].
movieRentingSystem.rent(1, 2); // Rent movie 2 from shop 1. Unrented movies at shop 1 are now [1].
movieRentingSystem.report();   // return [[0, 1], [1, 2]]. Movie 1 from shop 0 is cheapest, followed by movie 2 from shop 1.
movieRentingSystem.drop(1, 2); // Drop off movie 2 at shop 1. Unrented movies at shop 1 are now [1,2].
movieRentingSystem.search(2);  // return [0, 1]. Movies of ID 2 are unrented at shops 0 and 1. Shop 0 is cheapest, followed by shop 1.
```

## Constraints

- 1 <= n <= 3 * 105
- 1 <= entries.length <= 105
- 0 <= shopi < n
- 1 <= moviei, pricei <= 104
- Each shop carries at most one copy of a movie moviei.
- At most 105 calls in total will be made to search, rent, drop and report.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1912. Design Movie Rental System

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Hash Map + Ordered Set Approach | C++, C#, Java, Python3 |

## Approach: Hash Map + Ordered Set Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class MovieRentingSystem {
private:
    static constexpr auto pairHash =
        [fn = hash<int>()](const pair<int, int>& o) {
            return (fn(o.first) << 16) ^ fn(o.second);
        };
    unordered_map<pair<int, int>, int, decltype(pairHash)> t_price{0, pairHash};

    unordered_map<int, set<pair<int, int>>> t_valid;

    set<tuple<int, int, int>> t_rent;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const auto& entry : entries) {
            t_price[{entry[0], entry[1]}] = entry[2];
            t_valid[entry[1]].emplace(entry[2], entry[0]);
        }
    }

    vector<int> search(int movie) {
        if (!t_valid.count(movie)) {
            return {};
        }

        vector<int> ret;
        auto it = t_valid[movie].begin();
        for (int i = 0; i < 5 && it != t_valid[movie].end(); ++i, ++it) {
            ret.push_back(it->second);
        }
        return ret;
    }

    void rent(int shop, int movie) {
        int price = t_price[{shop, movie}];
        t_valid[movie].erase({price, shop});
        t_rent.emplace(price, shop, movie);
    }

    void drop(int shop, int movie) {
        int price = t_price[{shop, movie}];
        t_valid[movie].emplace(price, shop);
        t_rent.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ret;
        auto it = t_rent.begin();
        for (int i = 0; i < 5 && it != t_rent.end(); ++i, ++it) {
            ret.emplace_back(initializer_list<int>{get<1>(*it), get<2>(*it)});
        }
        return ret;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
struct Pair : IEquatable<Pair> {
    public int First { get; }
    public int Second { get; }

    public Pair(int first, int second) {
        First = first;
        Second = second;
    }

    public bool Equals(Pair other) => First == other.First
                                      && Second == other.Second;
    public override bool Equals(object obj) => obj is Pair other &&
                                               Equals(other);
    public override int GetHashCode() => (First << 16) ^ Second;
}

public class MovieRentingSystem {
    private Dictionary<Pair, int> tPrice = new Dictionary<Pair, int>();
    private Dictionary<int, SortedSet<Pair>> tValid =
        new Dictionary<int, SortedSet<Pair>>();
    private SortedSet<(int price, int shop, int movie)> tRent =
        new SortedSet<(int, int, int)>();

    public MovieRentingSystem(int n, int[][] entries) {
        foreach (var entry in entries) {
            var p = new Pair(entry[0], entry[1]);
            tPrice[p] = entry[2];
            if (!tValid.ContainsKey(entry[1])) {
                tValid[entry[1]] = new SortedSet<Pair>(Comparer<Pair>.Create(
                    (a, b) => a.First != b.First
                                  ? a.First.CompareTo(b.First)
                                  : a.Second.CompareTo(b.Second)));
            }
            tValid[entry[1]].Add(new Pair(entry[2], entry[0]));
        }
    }

    public IList<int> Search(int movie) {
        if (!tValid.ContainsKey(movie)) {
            return new List<int>();
        }
        return tValid[movie].Take(5).Select(p => p.Second).ToList();
    }

    public void Rent(int shop, int movie) {
        var p = new Pair(shop, movie);
        int price = tPrice[p];
        tValid[movie].Remove(new Pair(price, shop));
        tRent.Add((price, shop, movie));
    }

    public void Drop(int shop, int movie) {
        var p = new Pair(shop, movie);
        int price = tPrice[p];
        tValid[movie].Add(new Pair(price, shop));
        tRent.Remove((price, shop, movie));
    }

    public IList<IList<int>> Report() {
        return tRent.Take(5)
            .Select(t => new List<int> { t.shop, t.movie })
            .ToList<IList<int>>();
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Pair {

    int first, second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        Pair pair = (Pair) o;
        return first == pair.first && second == pair.second;
    }

    @Override
    public int hashCode() {
        return (first << 16) ^ second;
    }
}

class Triple implements Comparable<Triple> {

    int price, shop, movie;

    Triple(int price, int shop, int movie) {
        this.price = price;
        this.shop = shop;
        this.movie = movie;
    }

    @Override
    public int compareTo(Triple o) {
        if (price != o.price) {
            return Integer.compare(price, o.price);
        }
        if (shop != o.shop) {
            return Integer.compare(shop, o.shop);
        }
        return Integer.compare(movie, o.movie);
    }
}

class MovieRentingSystem {

    private Map<Pair, Integer> tPrice = new HashMap<>();
    private Map<Integer, TreeSet<Pair>> tValid = new HashMap<>();
    private TreeSet<Triple> tRent = new TreeSet<>();

    public MovieRentingSystem(int n, int[][] entries) {
        for (int[] entry : entries) {
            Pair p = new Pair(entry[0], entry[1]);
            tPrice.put(p, entry[2]);
            tValid
                .computeIfAbsent(entry[1], k ->
                    new TreeSet<>((a, b) ->
                        a.first != b.first
                            ? Integer.compare(a.first, b.first)
                            : Integer.compare(a.second, b.second)
                    )
                )
                .add(new Pair(entry[2], entry[0]));
        }
    }

    public List<Integer> search(int movie) {
        if (!tValid.containsKey(movie)) {
            return Collections.emptyList();
        }
        return tValid
            .get(movie)
            .stream()
            .limit(5)
            .map(p -> p.second)
            .collect(Collectors.toList());
    }

    public void rent(int shop, int movie) {
        int price = tPrice.get(new Pair(shop, movie));
        tValid.get(movie).remove(new Pair(price, shop));
        tRent.add(new Triple(price, shop, movie));
    }

    public void drop(int shop, int movie) {
        int price = tPrice.get(new Pair(shop, movie));
        tValid.get(movie).add(new Pair(price, shop));
        tRent.remove(new Triple(price, shop, movie));
    }

    public List<List<Integer>> report() {
        return tRent
            .stream()
            .limit(5)
            .map(t -> Arrays.asList(t.shop, t.movie))
            .collect(Collectors.toList());
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.t_price = dict()
        self.t_valid = defaultdict(sortedcontainers.SortedList)
        self.t_rent = sortedcontainers.SortedList()

        for shop, movie, price in entries:
            self.t_price[(shop, movie)] = price
            self.t_valid[movie].add((price, shop))

    def search(self, movie: int) -> List[int]:
        t_valid_ = self.t_valid

        if movie not in t_valid_:
            return []

        return [shop for (price, shop) in t_valid_[movie][:5]]

    def rent(self, shop: int, movie: int) -> None:
        price = self.t_price[(shop, movie)]
        self.t_valid[movie].discard((price, shop))
        self.t_rent.add((price, shop, movie))

    def drop(self, shop: int, movie: int) -> None:
        price = self.t_price[(shop, movie)]
        self.t_valid[movie].add((price, shop))
        self.t_rent.discard((price, shop, movie))

    def report(self) -> List[List[int]]:
        return [(shop, movie) for price, shop, movie in self.t_rent[:5]]
```

</details>
