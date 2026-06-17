function groupAnagrams(strs: string[]): string[][] {
    // Create a map to store the anagrams, where the keys are the sorted strings and the values are the lists of anagrams
    let map = new Map<string, string[]>();
    // Iterate over the given strings
    for (let str of strs) {
        // Convert the string to a char array and sort it
        let chars = Array.from(str);
        chars.sort();
        // Use the sorted string as a key
        // If the string is an anagram of another string, they will have the same key and thus be grouped together
        let key = chars.join("");
        // If the key is not already in the map, add it with a new list as its value
        if (!map.has(key)) map.set(key, []);
        // Add the original string to the list of its key
        map.get(key).push(str);
    }
    // Return the lists of anagrams
    return Array.from(map.values());
}
