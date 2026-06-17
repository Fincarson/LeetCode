class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        int i = 0;
        while (i < n) {
            // find target piece
            int found = -1;
            for (int j = 0; j < pieces.size(); j++) {
                if (pieces[j][0] == arr[i]) {
                    found = j;
                    break;
                }
            }
            if (found == -1) {
                return false;
            }
            // find target piece
            auto targetPiece = pieces[found];
            for (int x : targetPiece) {
                if (x != arr[i]) {
                    return false;
                }
                i++;
            }
        }
        return true;
    }
};
