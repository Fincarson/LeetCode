var deepMerge = function(obj1, obj2) {
  function dfs(currNode1, currNode2) {
    // If the first value is not an object or is null, return the second value 
    // as according to the description, the second object overwrites the first
    if (currNode1 === null || typeof currNode1 !== 'object') {
      return currNode2;
    }

    // If currNode1 is an array
    if (Array.isArray(currNode1)) {
      // If currNode2 isn't an array, return currNode2
      if (!Array.isArray(currNode2)) return currNode2;

      // Initialize a new array with the length of the longer of the two arrays
      const newArr = new Array(Math.max(currNode1.length, currNode2.length));

      for (let i = 0; i < currNode1.length; i++) {
        // If the current index exists in currNode1 but not in currNode2,
        // directly copy the value from currNode1 to the merged array
        if (i > currNode2.length - 1) {
          newArr[i] = currNode1[i];
          continue;
        }
        
        // Deep merge common indices
        newArr[i] = dfs(currNode1[i], currNode2[i]);
      }

      // If currNode2 is longer, add the extra elements from currNode2 to newArr
      if (currNode2.length > currNode1.length) {
        for (let i = currNode1.length; i < currNode2.length; i++) {
          newArr[i] = currNode2[i];
        }
      }

      return newArr;
    }

    // If currNode1 is an object but currNode2 isn't, return currNode2
    if (typeof currNode1 === 'object' && (Array.isArray(currNode2) || currNode2 === null || typeof currNode2 !== 'object')) {
      return currNode2;
    }

    // If both currNode1 and currNode2 are objects
    const newObj = {};

    for (const key in currNode1) {
      // If the current key exists in currNode1 but not in currNode2,
      // directly copy the key-value pair from currNode1 to the merged object
      if (!(key in currNode2)) {
        newObj[key] = currNode1[key];
        continue;
      }
      
      // Deep merge common keys
      newObj[key] = dfs(currNode1[key], currNode2[key]);
    }

    // Add keys that only exist in currNode2
    for (const key in currNode2) {
      if (!(key in currNode1)) {
        newObj[key] = currNode2[key];
      }
    }

    return newObj;
  }

  return dfs(obj1, obj2);
};
