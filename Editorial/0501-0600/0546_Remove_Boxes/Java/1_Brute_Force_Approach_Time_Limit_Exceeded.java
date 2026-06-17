public class Solution {
    public int removeBoxes(int[] boxes) {
        return remove(boxes);
    }
   
    public int remove(int[] boxes) {
        if (boxes.length == 0) {
            return 0;
        }
        
        int res = 0;
    
        for (int i = 0, j = i + 1; i < boxes.length; i++) {
            while (j < boxes.length && boxes[i] == boxes[j]) {
                j++;
            }
            
            int[] newboxes = new int[boxes.length - (j - i)];
            for (int k = 0, p = 0; k < boxes.length; k++) {
                if (k == i) {
                    k = j;
                }
                if (k < boxes.length) {
                    newboxes[p++] = boxes[k];
                }
            }
            res = Math.max(res, remove(newboxes) + (j - i) * (j - i));
        }
    
        return res;
    }
}
