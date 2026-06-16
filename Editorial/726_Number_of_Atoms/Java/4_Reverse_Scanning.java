class Solution {

    public String countOfAtoms(String formula) {
        // For multipliers
        int runningMul = 1;
        Stack<Integer> stack = new Stack<>();
        stack.push(1);

        // Map to store the count of atoms
        Map<String, Integer> finalMap = new HashMap<>();

        // Strings to take care of current atom and count
        StringBuilder currAtom = new StringBuilder();
        StringBuilder currCount = new StringBuilder();

        // Index to traverse the formula in reverse
        int index = formula.length() - 1;

        // Parse the formula
        while (index >= 0) {
            // If digit, update the count
            if (Character.isDigit(formula.charAt(index))) {
                currCount.insert(0, formula.charAt(index));
            }
            // If a lowercase letter, prepend to the currAtom
            else if (Character.isLowerCase(formula.charAt(index))) {
                currAtom.insert(0, formula.charAt(index));
            }
            // If UPPERCASE LETTER, update the finalMap
            else if (Character.isUpperCase(formula.charAt(index))) {
                currAtom.insert(0, formula.charAt(index));
                int count = currCount.length() > 0
                    ? Integer.parseInt(currCount.toString())
                    : 1;
                finalMap.put(
                    currAtom.toString(),
                    finalMap.getOrDefault(currAtom.toString(), 0) +
                    count * runningMul
                );

                currAtom = new StringBuilder();
                currCount = new StringBuilder();
            }
            // If the right parenthesis, the currCount if any
            // will be considered as multiplier
            else if (formula.charAt(index) == ')') {
                int currMultiplier = currCount.length() > 0
                    ? Integer.parseInt(currCount.toString())
                    : 1;
                stack.push(currMultiplier);
                runningMul *= currMultiplier;
                currCount = new StringBuilder();
            }
            // If left parenthesis, update the runningMul
            else if (formula.charAt(index) == '(') {
                runningMul /= stack.pop();
            }

            index--;
        }

        // Sort the final map
        TreeMap<String, Integer> sortedMap = new TreeMap<>(finalMap);

        // Generate the answer string
        StringBuilder ans = new StringBuilder();
        for (String atom : sortedMap.keySet()) {
            ans.append(atom);
            if (sortedMap.get(atom) > 1) {
                ans.append(sortedMap.get(atom));
            }
        }

        return ans.toString();
    }
}
