class Solution {

    public String countOfAtoms(String formula) {
        // For every index, store the valid multiplier
        int[] muls = new int[formula.length()];
        int runningMul = 1;

        // Stack to take care of nested formula
        Stack<Integer> stack = new Stack<>();
        stack.push(1);

        // Preprocess the formula and extract all multipliers
        int index = formula.length() - 1;
        StringBuilder currNumber = new StringBuilder();
        while (index >= 0) {
            if (Character.isDigit(formula.charAt(index))) {
                currNumber.insert(0, formula.charAt(index));
            }
            // If we encountered a letter, then the scanned
            // number was count and not a multiplier. Discard it.
            else if (Character.isAlphabetic(formula.charAt(index))) {
                currNumber = new StringBuilder();
            }
            // If we encounter a right parenthesis, then the
            // scanned number was multiplier. Store it.
            else if (formula.charAt(index) == ')') {
                int currMultiplier = currNumber.length() > 0
                    ? Integer.parseInt(currNumber.toString())
                    : 1;
                runningMul *= currMultiplier;
                stack.push(currMultiplier);
                currNumber = new StringBuilder();
            }
            // If we encounter a left parenthesis, then the
            // most recent multiplier will cease to exist.
            else if (formula.charAt(index) == '(') {
                runningMul /= stack.pop();
                currNumber = new StringBuilder();
            }

            // For every index, store the valid multiplier
            muls[index] = runningMul;
            index--;
        }

        // Map to store the count of atoms
        Map<String, Integer> finalMap = new HashMap<>();

        // Traverse left to right in the formula
        index = 0;
        while (index < formula.length()) {
            // If UPPER CASE LETTER, extract the entire atom
            if (Character.isUpperCase(formula.charAt(index))) {
                StringBuilder currAtom = new StringBuilder();
                currAtom.append(formula.charAt(index));
                StringBuilder currCount = new StringBuilder();
                index++;
                while (
                    index < formula.length() &&
                    Character.isLowerCase(formula.charAt(index))
                ) {
                    currAtom.append(formula.charAt(index));
                    index++;
                }

                // Extract the count
                while (
                    index < formula.length() &&
                    Character.isDigit(formula.charAt(index))
                ) {
                    currCount.append(formula.charAt(index));
                    index++;
                }

                // Update the final map
                int count = currCount.length() > 0
                    ? Integer.parseInt(currCount.toString())
                    : 1;
                finalMap.put(
                    currAtom.toString(),
                    finalMap.getOrDefault(currAtom.toString(), 0) +
                    count * muls[index - 1]
                );
            } else {
                index++;
            }
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
