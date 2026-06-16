# 2115. Find All Possible Recipes from Given Supplies

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/)  
`Array` `Hash Table` `String` `Graph Theory` `Topological Sort`

**Problem Link:** [LeetCode 2115 - Find All Possible Recipes from Given Supplies](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/)

## Problem

You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

### Example 1

```text
Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
```

### Example 2

```text
Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
```

### Example 3

```text
Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
```

## Constraints

- n == recipes.length == ingredients.length
- 1 <= n <= 100
- 1 <= ingredients[i].length, supplies.length <= 100
- 1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
- recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
- All the values of recipes and supplies combined are unique.
- Each ingredients[i] does not contain any duplicate values.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Good Meals](https://leetcode.com/problems/count-good-meals/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2115. Find All Possible Recipes from Given Supplies

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Breadth-First Search (BFS) | C++, Java, Python3 |
| Depth-First Search (DFS) | C++, Java, Python3 |
| Topological Sort (Kahn's Algorithm) | C++, Java, Python3 |

## Approach 1: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        // Track available ingredients and recipes
        unordered_set<string> available(supplies.begin(), supplies.end());

        // Queue to process recipe indices
        queue<int> recipeQueue;
        for (int idx = 0; idx < recipes.size(); ++idx) {
            recipeQueue.push(idx);
        }

        vector<string> createdRecipes;
        int lastSize = -1;

        // Continue while we keep finding new recipes
        while (static_cast<int>(available.size()) > lastSize) {
            lastSize = available.size();
            int queueSize = recipeQueue.size();

            // Process all recipes in current queue
            while (queueSize-- > 0) {
                int recipeIdx = recipeQueue.front();
                recipeQueue.pop();
                bool canCreate = true;

                // Check if all ingredients are available
                for (string& ingredient : ingredients[recipeIdx]) {
                    if (!available.count(ingredient)) {
                        canCreate = false;
                        break;
                    }
                }

                if (!canCreate) {
                    recipeQueue.push(recipeIdx);
                } else {
                    // Recipe can be created - add to available items
                    available.insert(recipes[recipeIdx]);
                    createdRecipes.push_back(recipes[recipeIdx]);
                }
            }
        }

        return createdRecipes;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> findAllRecipes(
        String[] recipes,
        List<List<String>> ingredients,
        String[] supplies
    ) {
        // Track available ingredients and recipes
        Set<String> available = new HashSet<>();
        for (String supply : supplies) {
            available.add(supply);
        }

        // Queue to process recipe indices
        Queue<Integer> recipeQueue = new LinkedList<>();
        for (int idx = 0; idx < recipes.length; ++idx) {
            recipeQueue.offer(idx);
        }

        List<String> createdRecipes = new ArrayList<>();
        int lastSize = -1;

        // Continue while we keep finding new recipes
        while (available.size() > lastSize) {
            lastSize = available.size();
            int queueSize = recipeQueue.size();

            // Process all recipes in current queue
            while (queueSize-- > 0) {
                int recipeIdx = recipeQueue.poll();
                boolean canCreate = true;

                // Check if all ingredients are available
                for (String ingredient : ingredients.get(recipeIdx)) {
                    if (!available.contains(ingredient)) {
                        canCreate = false;
                        break;
                    }
                }

                if (!canCreate) {
                    recipeQueue.offer(recipeIdx);
                } else {
                    // Recipe can be created - add to available items
                    available.add(recipes[recipeIdx]);
                    createdRecipes.add(recipes[recipeIdx]);
                }
            }
        }

        return createdRecipes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findAllRecipes(
        self,
        recipes: list[str],
        ingredients: list[list[str]],
        supplies: list[str],
    ) -> list[str]:
        # Track available ingredients and recipes
        available = set(supplies)

        # Queue to process recipe indices
        recipe_queue = deque(range(len(recipes)))
        created_recipes = []
        last_size = -1  # Tracks last known available count

        # Continue while we keep finding new recipes
        while len(available) > last_size:
            last_size = len(available)
            queue_size = len(recipe_queue)

            # Process all recipes in current queue
            while queue_size > 0:
                queue_size -= 1
                recipe_idx = recipe_queue.popleft()
                if all(
                    ingredient in available
                    for ingredient in ingredients[recipe_idx]
                ):
                    # Recipe can be created - add to available items
                    available.add(recipes[recipe_idx])
                    created_recipes.append(recipes[recipe_idx])
                else:
                    recipe_queue.append(recipe_idx)

        return created_recipes
```

</details>

<br>

## Approach 2: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        vector<string> possibleRecipes;
        // Track if ingredient/recipe can be made
        unordered_map<string, bool> canMake;
        // Map recipe name to its index in ingredients list
        unordered_map<string, int> recipeToIndex;

        // Mark all initial supplies as available
        for (const string& supply : supplies) {
            canMake[supply] = true;
        }

        // Create recipe to index mapping
        for (int idx = 0; idx < recipes.size(); idx++) {
            recipeToIndex[recipes[idx]] = idx;
        }

        // Try to make each recipe using DFS
        for (const string& recipe : recipes) {
            unordered_set<string> visited;
            checkRecipe(recipe, ingredients, visited, canMake, recipeToIndex);
            if (canMake[recipe]) {
                possibleRecipes.push_back(recipe);
            }
        }

        return possibleRecipes;
    }

private:
    void checkRecipe(const string& recipe, vector<vector<string>>& ingredients,
                     unordered_set<string>& visited,
                     unordered_map<string, bool>& canMake,
                     unordered_map<string, int>& recipeToIndex) {
        // Return if we already know if recipe can be made
        if (canMake.find(recipe) != canMake.end()) {
            return;
        }

        // Not a valid recipe or cycle detected
        auto idxIt = recipeToIndex.find(recipe);
        if (idxIt == recipeToIndex.end() || visited.count(recipe)) {
            canMake[recipe] = false;
            return;
        }

        visited.insert(recipe);

        // Check if we can make all required ingredients
        for (const string& ingredient : ingredients[idxIt->second]) {
            checkRecipe(ingredient, ingredients, visited, canMake,
                        recipeToIndex);
            if (!canMake[ingredient]) {
                canMake[recipe] = false;
                return;
            }
        }

        // All ingredients can be made
        canMake[recipe] = true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> findAllRecipes(
        String[] recipes,
        List<List<String>> ingredients,
        String[] supplies
    ) {
        List<String> possibleRecipes = new ArrayList<>();
        // Track if ingredient/recipe can be made
        Map<String, Boolean> canMake = new HashMap<>();
        // Map recipe name to its index in ingredients list
        Map<String, Integer> recipeToIndex = new HashMap<>();

        // Mark all initial supplies as available
        for (String supply : supplies) {
            canMake.put(supply, true);
        }

        // Create recipe to index mapping
        for (int idx = 0; idx < recipes.length; idx++) {
            recipeToIndex.put(recipes[idx], idx);
        }

        // Try to make each recipe using DFS
        for (String recipe : recipes) {
            checkRecipe(
                recipe,
                ingredients,
                new HashSet<String>(),
                canMake,
                recipeToIndex
            );
            if (canMake.get(recipe)) {
                possibleRecipes.add(recipe);
            }
        }

        return possibleRecipes;
    }

    private void checkRecipe(
        String recipe,
        List<List<String>> ingredients,
        Set<String> visited,
        Map<String, Boolean> canMake,
        Map<String, Integer> recipeToIndex
    ) {
        // Return if we already know if recipe can be made
        if (canMake.containsKey(recipe) && canMake.get(recipe)) {
            return;
        }

        // Not a valid recipe or cycle detected
        if (!recipeToIndex.containsKey(recipe) || visited.contains(recipe)) {
            canMake.put(recipe, false);
            return;
        }

        visited.add(recipe);

        // Check if we can make all required ingredients
        List<String> neededIngredients = ingredients.get(
            recipeToIndex.get(recipe)
        );
        for (String ingredient : neededIngredients) {
            checkRecipe(
                ingredient,
                ingredients,
                visited,
                canMake,
                recipeToIndex
            );
            if (!canMake.get(ingredient)) {
                canMake.put(recipe, false);
                return;
            }
        }

        // All ingredients can be made
        canMake.put(recipe, true);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findAllRecipes(
        self,
        recipes: list[str],
        ingredients: list[list[str]],
        supplies: list[str],
    ) -> list[str]:
        # Initialize tracking dictionaries using comprehensions
        can_make = dict.fromkeys(supplies, True)
        recipe_to_idx = {recipe: idx for idx, recipe in enumerate(recipes)}

        def _check_recipe(recipe: str, visited: set) -> bool:
            # Already processed and can be made
            if can_make.get(recipe, False):
                return True

            # Not a valid recipe or cycle detected
            if recipe not in recipe_to_idx or recipe in visited:
                return False

            visited.add(recipe)

            # Check if all ingredients can be made
            can_make[recipe] = all(
                _check_recipe(ingredient, visited)
                for ingredient in ingredients[recipe_to_idx[recipe]]
            )

            return can_make[recipe]

        # Process each recipe and collect those that can be made
        return [recipe for recipe in recipes if _check_recipe(recipe, set())]
```

</details>

<br>

## Approach 3: Topological Sort (Kahn's Algorithm)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        // Store available supplies
        unordered_set<string> availableSupplies;
        // Map recipe to its index
        unordered_map<string, int> recipeToIndex;
        // Map ingredient to recipes that need it
        unordered_map<string, vector<string>> dependencyGraph;

        // Initialize available supplies
        for (string& supply : supplies) {
            availableSupplies.insert(supply);
        }

        // Create recipe to index mapping
        for (int idx = 0; idx < recipes.size(); idx++) {
            recipeToIndex[recipes[idx]] = idx;
        }

        // Count of non-supply ingredients needed for each recipe
        vector<int> inDegree(recipes.size(), 0);

        // Build dependency graph
        for (int recipeIdx = 0; recipeIdx < recipes.size(); recipeIdx++) {
            for (string& ingredient : ingredients[recipeIdx]) {
                if (!availableSupplies.count(ingredient)) {
                    // Add edge: ingredient -> recipe
                    dependencyGraph[ingredient].push_back(recipes[recipeIdx]);
                    inDegree[recipeIdx]++;
                }
            }
        }

        // Start with recipes that only need supplies
        queue<int> queue;
        for (int recipeIdx = 0; recipeIdx < recipes.size(); recipeIdx++) {
            if (inDegree[recipeIdx] == 0) {
                queue.push(recipeIdx);
            }
        }

        // Process recipes in topological order
        vector<string> createdRecipes;
        while (!queue.empty()) {
            int recipeIdx = queue.front();
            queue.pop();
            string recipe = recipes[recipeIdx];
            createdRecipes.push_back(recipe);

            // Skip if no recipes depend on this one
            if (!dependencyGraph.count(recipe)) continue;

            // Update recipes that depend on current recipe
            for (string& dependentRecipe : dependencyGraph[recipe]) {
                if (--inDegree[recipeToIndex[dependentRecipe]] == 0) {
                    queue.push(recipeToIndex[dependentRecipe]);
                }
            }
        }

        return createdRecipes;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<String> findAllRecipes(
        String[] recipes,
        List<List<String>> ingredients,
        String[] supplies
    ) {
        // Store available supplies
        Set<String> availableSupplies = new HashSet<>();
        // Map recipe to its index
        Map<String, Integer> recipeToIndex = new HashMap<>();
        // Map ingredient to recipes that need it
        Map<String, List<String>> dependencyGraph = new HashMap<>();

        // Initialize available supplies
        for (String supply : supplies) {
            availableSupplies.add(supply);
        }

        // Create recipe to index mapping
        for (int idx = 0; idx < recipes.length; idx++) {
            recipeToIndex.put(recipes[idx], idx);
        }

        // Count of non-supply ingredients needed for each recipe
        int[] inDegree = new int[recipes.length];

        // Build dependency graph
        for (int recipeIdx = 0; recipeIdx < recipes.length; recipeIdx++) {
            for (String ingredient : ingredients.get(recipeIdx)) {
                if (!availableSupplies.contains(ingredient)) {
                    // Add edge: ingredient -> recipe
                    dependencyGraph.putIfAbsent(
                        ingredient,
                        new ArrayList<String>()
                    );
                    dependencyGraph.get(ingredient).add(recipes[recipeIdx]);
                    inDegree[recipeIdx]++;
                }
            }
        }

        // Start with recipes that only need supplies
        Queue<Integer> queue = new LinkedList<>();
        for (int recipeIdx = 0; recipeIdx < recipes.length; recipeIdx++) {
            if (inDegree[recipeIdx] == 0) {
                queue.add(recipeIdx);
            }
        }

        // Process recipes in topological order
        List<String> createdRecipes = new ArrayList<>();
        while (!queue.isEmpty()) {
            int recipeIdx = queue.poll();
            String recipe = recipes[recipeIdx];
            createdRecipes.add(recipe);

            // Skip if no recipes depend on this one
            if (!dependencyGraph.containsKey(recipe)) continue;

            // Update recipes that depend on current recipe
            for (String dependentRecipe : dependencyGraph.get(recipe)) {
                if (--inDegree[recipeToIndex.get(dependentRecipe)] == 0) {
                    queue.add(recipeToIndex.get(dependentRecipe));
                }
            }
        }

        return createdRecipes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findAllRecipes(
        self,
        recipes: list[str],
        ingredients: list[list[str]],
        supplies: list[str],
    ) -> list[str]:
        # Store available supplies
        available_supplies = set(supplies)
        # Map recipe to its index
        recipe_to_index = {recipe: idx for idx, recipe in enumerate(recipes)}
        # Map ingredient to recipes that need it
        dependency_graph = defaultdict(list)
        # Count of non-supply ingredients needed for each recipe
        in_degree = [0] * len(recipes)

        # Build dependency graph
        for recipe_idx, ingredient_list in enumerate(ingredients):
            for ingredient in ingredient_list:
                if ingredient not in available_supplies:
                    dependency_graph[ingredient].append(recipes[recipe_idx])
                    in_degree[recipe_idx] += 1

        # Start with recipes that only need supplies
        queue = deque(idx for idx, count in enumerate(in_degree) if count == 0)
        created_recipes = []

        # Process recipes in topological order
        while queue:
            recipe_idx = queue.popleft()
            recipe = recipes[recipe_idx]
            created_recipes.append(recipe)

            # Skip if no recipes depend on this one
            for dependent_recipe in dependency_graph[recipe]:
                in_degree[recipe_to_index[dependent_recipe]] -= 1
                if in_degree[recipe_to_index[dependent_recipe]] == 0:
                    queue.append(recipe_to_index[dependent_recipe])

        return created_recipes
```

</details>
