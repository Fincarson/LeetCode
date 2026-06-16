class WeightedSumTriplet {
    int maxDepth;
    int sumOfElements;
    int sumOfProducts;

    WeightedSumTriplet(int maxDepth, int sumOfElements, int sumOfProducts) {
        this.maxDepth = maxDepth;
        this.sumOfElements = sumOfElements;
        this.sumOfProducts = sumOfProducts;
    }
}

class Solution {
    public int depthSumInverse(List<NestedInteger> nestedList) {
        WeightedSumTriplet weightedSumTriplet = getWeightedSumTriplet(nestedList, 1);
        int maxDepth = weightedSumTriplet.maxDepth;
        int sumOfElements = weightedSumTriplet.sumOfElements;
        int sumOfProducts = weightedSumTriplet.sumOfProducts;
        
        return (maxDepth + 1) * sumOfElements - sumOfProducts;
    }

    private WeightedSumTriplet getWeightedSumTriplet(List<NestedInteger> list, int depth) {
        int sumOfProducts = 0;
        int sumOfElements = 0;
        int maxDepth = 0;
        
        for (NestedInteger nested : list) {
            if (nested.isInteger()) {
                sumOfProducts += nested.getInteger() * depth;
                sumOfElements += nested.getInteger();
                maxDepth = Math.max(maxDepth, depth);
            } else {
                WeightedSumTriplet result = getWeightedSumTriplet(nested.getList(), depth + 1);
                sumOfProducts += result.sumOfProducts;
                sumOfElements += result.sumOfElements;
                maxDepth = Math.max(maxDepth, result.maxDepth);
            }
        }
        
        return new WeightedSumTriplet(maxDepth, sumOfElements, sumOfProducts);
    }
}
