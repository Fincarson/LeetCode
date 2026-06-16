var isReachableAtTime = function(sx, sy, fx, fy, t) {
    var width = Math.abs(sx - fx);
    var height = Math.abs(sy - fy);
    if (width === 0 && height === 0 && t === 1) {
        return false;
    }
    return t >= Math.max(width, height);
};
