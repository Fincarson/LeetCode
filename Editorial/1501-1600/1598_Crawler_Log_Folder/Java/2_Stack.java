class Solution {

    public int minOperations(String[] logs) {
        Stack<String> folderStack = new Stack<>();

        for (String currentOperation : logs) {
            if (currentOperation.equals("../")) {
                // Move up to parent directory if not already at main folder
                if (!folderStack.empty()) {
                    folderStack.pop();
                }
            } else if (!currentOperation.equals("./")) {
                // Enter a new folder
                folderStack.push(currentOperation);
            }
            // Ignore "./" operations as they don't change the current folder
        }

        // The stack size represents the number of folders deep we are
        return folderStack.size();
    }
}
