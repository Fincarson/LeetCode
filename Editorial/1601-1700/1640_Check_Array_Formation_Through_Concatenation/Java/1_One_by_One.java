class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        int n = arr.length;
        int i = 0;
        while (i < n) {
            // find target piece
            int found = -1;
            for (int j = 0; j < pieces.length; j++) {
                if (pieces[j][0] == arr[i]) {
                    found = j;
                    break;
                }
            }
            if (found == -1) {
                return false;
            }
            // check target piece
            int[] targetPiece = pieces[found];
            for (int x : targetPiece) {
                if (x != arr[i]) {
                    return false;
                }
                i++;
            }
        }
        return true;
    }
}
