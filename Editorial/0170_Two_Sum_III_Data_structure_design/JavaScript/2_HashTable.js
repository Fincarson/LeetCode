const TwoSum = function () {
    this.num_counts = {};
};

/**
 * Add the number to an internal data structure.
 * @param {number} number
 * @return {void}
 */
TwoSum.prototype.add = function (number) {
    if (number in this.num_counts) this.num_counts[number]++;
    else this.num_counts[number] = 1;
};

/**
 * Find if there exists any pair of numbers which sum is equal to the value.
 * @param {number} value
 * @return {boolean}
 */
TwoSum.prototype.find = function (value) {
    for (let num in this.num_counts) {
        let complement = value - num;
        if (complement != num) {
            if (complement in this.num_counts) return true;
        } else {
            if (this.num_counts[num] > 1) return true;
        }
    }
    return false;
};
