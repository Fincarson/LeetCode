let reversiblePairs = [
    ['0', '0'], ['1', '1'], 
    ['6', '9'], ['8', '8'], ['9', '6']
];

let findStrobogrammatic = function(n) {
    let currStringsLength;
    let q = [];
    
        
    // When n is even, it means when decreasing by 2 we will go till 0.
    if (n % 2 == 0) {
        // We will start with 0-digit strobogrammatic numbers.
        currStringsLength = 0;
        q = [""];
    } else {
        // We will start with 1-digit strobogrammatic numbers.
        currStringsLength = 1;
        q = ["0", "1", "8"];
    }
    
    while (currStringsLength < n) {
        currStringsLength += 2;
        let nextLevel = []
        
        q.forEach((number) => {
            reversiblePairs.forEach((pair) => {
                if (currStringsLength != n || pair[0] != '0') {
                    nextLevel.push(pair[0] + number + pair[1]);
                }
            });
        });
        
        q = nextLevel;
    }
    
    return q;
};
