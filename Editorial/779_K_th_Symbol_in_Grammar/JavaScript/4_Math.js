let kthGrammar = function(n, k) {
    const count = (k - 1).toString(2).split('1').length - 1;
    return count % 2 === 0 ? 0 : 1;
};
