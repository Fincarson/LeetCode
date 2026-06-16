var isValidSudoku = function (board) {
    var N = 9;
    var rows = Array.from(Array(N), () => new Array(N).fill(0));
    var cols = Array.from(Array(N), () => new Array(N).fill(0));
    var boxes = Array.from(Array(N), () => new Array(N).fill(0));
    for (var r = 0; r < N; r++) {
        for (var c = 0; c < N; c++) {
            if (board[r][c] == ".") {
                continue;
            }
            var pos = board[r][c].charCodeAt(0) - "1".charCodeAt(0);
            if (rows[r][pos] == 1) {
                return false;
            }
            rows[r][pos] = 1;
            if (cols[c][pos] == 1) {
                return false;
            }
            cols[c][pos] = 1;
            var idx = Math.floor(r / 3) * 3 + Math.floor(c / 3);
            if (boxes[idx][pos] == 1) {
                return false;
            }
            boxes[idx][pos] = 1;
        }
    }
    return true;
};
