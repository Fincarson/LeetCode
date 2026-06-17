/**
 * @param {Array} keysArr
 * @param {Array} valuesArr
 * @return {Object}
 */
var createObject = function(keysArr, valuesArr) {
    const obj = {};
    for (const i in keysArr) {
        if (!obj.hasOwnProperty(keysArr[i])) {
            obj[keysArr[i]] = valuesArr[i];
        }
    }
    return obj;
};
