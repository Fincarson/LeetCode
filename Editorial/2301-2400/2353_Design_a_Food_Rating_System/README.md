# 2353. Design a Food Rating System

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/design-a-food-rating-system/)  
`Array` `Hash Table` `String` `Design` `Heap (Priority Queue)` `Ordered Set`

**Problem Link:** [LeetCode 2353 - Design a Food Rating System](https://leetcode.com/problems/design-a-food-rating-system/)

## Problem

Design a food rating system that can do the following:

- Modify the rating of a food item listed in the system.
- Return the highest-rated food item for a type of cuisine in the system.

Implement the FoodRatings class:

- FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system. The food items are described by foods, cuisines and ratings, all of which have a length of n.

		foods[i] is the name of the ith food,
		cuisines[i] is the type of cuisine of the ith food, and
		ratings[i] is the initial rating of the ith food.
- void changeRating(String food, int newRating) Changes the rating of the food item with the name food.
- String highestRated(String cuisine) Returns the name of the food item that has the highest rating for the given type of cuisine. If there is a tie, return the item with the lexicographically smaller name.

Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

### Example 1

```text
Input
["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
[[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
Output
[null, "kimchi", "ramen", null, "sushi", null, "ramen"]

Explanation
FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
foodRatings.highestRated("korean"); // return "kimchi"
                                    // "kimchi" is the highest rated korean food with a rating of 9.
foodRatings.highestRated("japanese"); // return "ramen"
                                      // "ramen" is the highest rated japanese food with a rating of 14.
foodRatings.changeRating("sushi", 16); // "sushi" now has a rating of 16.
foodRatings.highestRated("japanese"); // return "sushi"
                                      // "sushi" is the highest rated japanese food with a rating of 16.
foodRatings.changeRating("ramen", 16); // "ramen" now has a rating of 16.
foodRatings.highestRated("japanese"); // return "ramen"
                                      // Both "sushi" and "ramen" have a rating of 16.
                                      // However, "ramen" is lexicographically smaller than "sushi".
```

## Constraints

- 1 <= n <= 2 * 104
- n == foods.length == cuisines.length == ratings.length
- 1 <= foods[i].length, cuisines[i].length <= 10
- foods[i], cuisines[i] consist of lowercase English letters.
- 1 <= ratings[i] <= 108
- All the strings in foods are distinct.
- food will be the name of a food item in the system across all calls to changeRating.
- cuisine will be a type of cuisine of at least one food item in the system across all calls to highestRated.
- At most 2 * 104 calls in total will be made to changeRating and highestRated.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Design a Number Container System](https://leetcode.com/problems/design-a-number-container-system/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Most Popular Video Creator](https://leetcode.com/problems/most-popular-video-creator/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2353. Design a Food Rating System

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hash Maps and Priority Queue | C++, Java, Python3 |
| Hash Maps and Sorted Set | C++, Java, Python3 |

## Approach 1: Hash Maps and Priority Queue

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Food {
public:
    // Store the food's rating.
    int foodRating;
    // Store the food's name.
    string foodName;

    Food(int foodRating, string foodName) {
        this->foodRating = foodRating;
        this->foodName = foodName;
    }

    // Overload the less than operator for comparison
    bool operator<(const Food& other) const {
        // If food ratings are the same sort on the basis of their name. (lexicographically smaller name food will be on top)
        if (foodRating == other.foodRating) {
            return foodName > other.foodName;
        }
        // Sort on the basis of food rating. (bigger rating food will be on top)
        return foodRating < other.foodRating;
    }
};

class FoodRatings {
    // Map food with its rating.
    unordered_map<string, int> foodRatingMap;
    // Map food with the cuisine it belongs to.
    unordered_map<string, string> foodCuisineMap;

    // Store all food of a cuisine in priority queue (to sort them on ratings/name)
    // Priority queue element -> Food: (foodRating, foodName)
    unordered_map<string, priority_queue<Food>> cuisineFoodMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            // Store 'rating' and 'cuisine' of current 'food' in 'foodRatingMap' and 'foodCuisineMap' maps.
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            // Insert the '(rating, name)' element in current cuisine's priority queue.
            cuisineFoodMap[cuisines[i]].push(Food(ratings[i], foods[i]));
        }
    }

    void changeRating(string food, int newRating) {
        // Update food's rating in 'foodRating' map.
        foodRatingMap[food] = newRating;
        // Insert the '(new rating, name)' element in respective cuisine's priority queue.
        auto cuisineName = foodCuisineMap[food];
        cuisineFoodMap[cuisineName].push(Food(newRating, food));
    }

    string highestRated(string cuisine) {
        // Get the highest rated 'food' of 'cuisine'.
        auto highestRated = cuisineFoodMap[cuisine].top();

        // If the latest rating of 'food' doesn't match the 'rating' on which it was sorted in the priority queue,
        // then we discard this element of the priority queue.
        while (foodRatingMap[highestRated.foodName] != highestRated.foodRating) {
            cuisineFoodMap[cuisine].pop();
            highestRated = cuisineFoodMap[cuisine].top();
        }
        // Return name of the highest rated 'food' of 'cuisine'.
        return highestRated.foodName;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Food implements Comparable<Food> {
    // Store the food's rating.
    public int foodRating;
    // Store the food's name.
    public String foodName;

    public Food(int foodRating, String foodName) {
        this.foodRating = foodRating;
        this.foodName = foodName;
    }

    // Implement the compareTo method for comparison
    @Override
    public int compareTo(Food other) {
        // If food ratings are the same, sort based on their names (lexicographically smaller name food will be on top)
        if (foodRating == other.foodRating) {
            return foodName.compareTo(other.foodName);
        }
        // Sort based on food rating (bigger rating food will be on top)
        return -1 * Integer.compare(foodRating, other.foodRating);
    }
}

class FoodRatings {
    // Map food with its rating.
    private Map<String, Integer> foodRatingMap;
    // Map food with the cuisine it belongs to.
    private Map<String, String> foodCuisineMap;

    // Store all food of a cuisine in a priority queue (to sort them on ratings/name)
    // Priority queue element -> Food: (foodRating, foodName)
    private Map<String, PriorityQueue<Food>> cuisineFoodMap;

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        foodRatingMap = new HashMap<>();
        foodCuisineMap = new HashMap<>();
        cuisineFoodMap = new HashMap<>();

        for (int i = 0; i < foods.length; ++i) {
            // Store 'rating' and 'cuisine' of the current 'food' in 'foodRatingMap' and 'foodCuisineMap' maps.
            foodRatingMap.put(foods[i], ratings[i]);
            foodCuisineMap.put(foods[i], cuisines[i]);
            // Insert the '(rating, name)' element into the current cuisine's priority queue.
            cuisineFoodMap.computeIfAbsent(cuisines[i], k -> new PriorityQueue<>()).add(new Food(ratings[i], foods[i]));
        }
    }

    public void changeRating(String food, int newRating) {
        // Update food's rating in the 'foodRating' map.
        foodRatingMap.put(food, newRating);
        // Insert the '(new food rating, food name)' element into the respective cuisine's priority queue.
        String cuisineName = foodCuisineMap.get(food);
        cuisineFoodMap.get(cuisineName).add(new Food(newRating, food));
    }

    public String highestRated(String cuisine) {
        // Get the highest rated 'food' of 'cuisine'.
        Food highestRated = cuisineFoodMap.get(cuisine).peek();

        // If the latest rating of 'food' doesn't match the 'rating' on which it was sorted in the priority queue,
        // then we discard this element from the priority queue.
        while (foodRatingMap.get(highestRated.foodName) != highestRated.foodRating) {
            cuisineFoodMap.get(cuisine).poll();
            highestRated = cuisineFoodMap.get(cuisine).peek();
        }

        // Return the name of the highest-rated 'food' of 'cuisine'.
        return highestRated.foodName;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Food:
    def __init__(self, food_rating, food_name):
        # Store the food's rating.
        self.food_rating = food_rating
        # Store the food's name.
        self.food_name = food_name

    def __lt__(self, other):
        # Overload the less-than operator for comparison.
        # If food ratings are the same, sort based on their name (lexicographically smaller name food will be on top).
        if self.food_rating == other.food_rating:
            return self.food_name < other.food_name
        # Sort based on food rating (bigger rating food will be on top).
        return self.food_rating > other.food_rating

class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        # Map food with its rating.
        self.food_rating_map = {}
        # Map food with the cuisine it belongs to.
        self.food_cuisine_map = {}
        # Store all food of cuisine in a priority queue (to sort them on ratings/name).
        # Priority queue element -> Food: (food_rating, food_name)
        self.cuisine_food_map = defaultdict(list)

        for i in range(len(foods)):
            # Store 'rating' and 'cuisine' of the current 'food' in 'food_rating_map' and 'food_cuisine_map' maps.
            self.food_rating_map[foods[i]] = ratings[i]
            self.food_cuisine_map[foods[i]] = cuisines[i]
            # Insert the '(rating, name)' element into the current cuisine's priority queue.
            heapq.heappush(self.cuisine_food_map[cuisines[i]], Food(ratings[i], foods[i]))

    def changeRating(self, food: str, newRating: int) -> None:
        # Update food's rating in 'food_rating' map.
        self.food_rating_map[food] = newRating
        # Insert the '(new rating, name)' element in the respective cuisine's priority queue.
        cuisineName = self.food_cuisine_map[food]
        heapq.heappush(self.cuisine_food_map[cuisineName], Food(newRating, food))

    def highestRated(self, cuisine: str) -> str:
        # Get the highest rated 'food' of 'cuisine'.
        highest_rated = self.cuisine_food_map[cuisine][0]

        # If the latest rating of 'food' doesn't match with the 'rating' on which it was sorted in the priority queue,
        # then we discard this element from the priority queue.
        while self.food_rating_map[highest_rated.food_name] != highest_rated.food_rating:
            heapq.heappop(self.cuisine_food_map[cuisine])
            highest_rated = self.cuisine_food_map[cuisine][0]

        # Return the name of the highest-rated 'food' of 'cuisine'.
        return highest_rated.food_name
```

</details>

<br>

## Approach 2: Hash Maps and Sorted Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class FoodRatings {
    // Map food with its rating.
    unordered_map<string, int> foodRatingMap;
    // Map food with the cuisine it belongs to.
    unordered_map<string, string> foodCuisineMap;

    // Store all food of cuisine in set (to sort them on ratings/name)
    // Set element -> Pair: (-1 * foodRating, foodName)
    unordered_map<string, set<pair<int, string>>> cuisineFoodMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            // Store 'rating' and 'cuisine' of current 'food' in 'foodRatingMap' and 'foodCuisineMap' maps.
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            // Insert the '(-1 * rating, name)' element in current cuisine's set.
            cuisineFoodMap[cuisines[i]].insert({ -ratings[i], foods[i] });
        }
    }

    void changeRating(string food, int newRating) {
        // Fetch cuisine name for food.
        auto cuisineName = foodCuisineMap[food];

        // Find and delete the element from the respective cuisine's set.
        auto oldElementIterator = cuisineFoodMap[cuisineName].find({ -foodRatingMap[food], food });
        cuisineFoodMap[cuisineName].erase(oldElementIterator);

        // Update food's rating in 'foodRating' map.
        foodRatingMap[food] = newRating;
        // Insert the '(-1 * new rating, name)' element in respective cuisine's set.
        cuisineFoodMap[cuisineName].insert({ -newRating, food });
    }

    string highestRated(string cuisine) {
        auto highestRated = *cuisineFoodMap[cuisine].begin();
        // Return name of the highest rated 'food' of 'cuisine'.
        return highestRated.second;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class FoodRatings {
    // Map food with its rating.
    private Map<String, Integer> foodRatingMap = new HashMap<>();
    // Map food with cuisine it belongs to.
    private Map<String, String> foodCuisineMap = new HashMap<>();

    // Store all food of cuisine in set (to sort them on ratings/name)
    // Set element -> Pair: (-1 * foodRating, foodName)
    private Map<String, TreeSet<Pair<Integer, String>>> cuisineFoodMap = new HashMap<>();

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.length; ++i) {
            // Store 'rating' and 'cuisine' of current 'food' in 'foodRatingMap' and 'foodCuisineMap' maps.
            foodRatingMap.put(foods[i], ratings[i]);
            foodCuisineMap.put(foods[i], cuisines[i]);

            // Insert the '(-1 * rating, name)' element in the current cuisine's set.
            cuisineFoodMap
                .computeIfAbsent(cuisines[i], k -> new TreeSet<>((a, b) -> {
                    int compareByRating = Integer.compare(a.getKey(), b.getKey());
                    if (compareByRating == 0) {
                        // If ratings are equal, compare by food name (in ascending order).
                        return a.getValue().compareTo(b.getValue());
                    }
                    return compareByRating;
                }))
                .add(new Pair(-ratings[i], foods[i]));
        }
    }

    public void changeRating(String food, int newRating) {
        // Fetch cuisine name for food.
        String cuisineName = foodCuisineMap.get(food);

        // Find and delete the element from the respective cuisine's set.
        TreeSet<Pair<Integer, String>> cuisineSet = cuisineFoodMap.get(cuisineName);
        Pair<Integer, String> oldElement = new Pair<>(-foodRatingMap.get(food), food);
        cuisineSet.remove(oldElement);

        // Update food's rating in 'foodRating' map.
        foodRatingMap.put(food, newRating);
        // Insert the '(-1 * new rating, name)' element in the respective cuisine's set.
        cuisineSet.add(new Pair<>(-newRating, food));
    }

    public String highestRated(String cuisine) {
        Pair<Integer, String> highestRated = cuisineFoodMap.get(cuisine).first();
        // Return name of the highest rated 'food' of 'cuisine'.
        return highestRated.getValue();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedSet

class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        # Map food with its rating.
        self.food_rating_map = {}
        # Map food with the cuisine it belongs to.
        self.food_cuisine_map = {}

        # Store all food of cuisine in a set (to sort them on ratings/name)
        # Set element -> Tuple: (-1 * food_rating, food_name)
        self.cuisine_food_map = defaultdict(SortedSet)

        for i in range(len(foods)):
            # Store 'rating' and 'cuisine' of the current 'food' in 'food_rating_map' and 'food_cuisine_map' maps.
            self.food_rating_map[foods[i]] = ratings[i]
            self.food_cuisine_map[foods[i]] = cuisines[i]
            # Insert the '(-1 * rating, name)' element in the current cuisine's set.
            self.cuisine_food_map[cuisines[i]].add((-ratings[i], foods[i]))

    def changeRating(self, food: str, newRating: int) -> None:
        # Fetch cuisine name for food.
        cuisine_name = self.food_cuisine_map[food]

        # Find and delete the element from the respective cuisine's set.
        old_element = (-self.food_rating_map[food], food)
        self.cuisine_food_map[cuisine_name].remove(old_element)

        # Update food's rating in 'food_rating' map.
        self.food_rating_map[food] = newRating
        # Insert the '(-1 * new rating, name)' element in the respective cuisine's set.
        self.cuisine_food_map[cuisine_name].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        highest_rated = self.cuisine_food_map[cuisine][0]
        # Return name of the highest-rated 'food' of 'cuisine'.
        return highest_rated[1]
```

</details>
