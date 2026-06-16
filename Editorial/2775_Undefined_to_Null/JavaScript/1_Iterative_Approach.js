/**
 * @param {object} obj
 * @return {object}
 */
var undefinedToNull = function(obj) {
    const stack = [obj];

    while (stack.length > 0) {
        const current = stack.pop();

        if (Array.isArray(current)) {
            for (let i = 0; i < current.length; i++) {
                if (current[i] === undefined) {
                    current[i] = null;
                } else if (typeof current[i] === 'object') {
                    stack.push(current[i]);
                }
            }
        } else if (typeof current === 'object' && current !== null) {
            for (const key in current) {
                if (current[key] === undefined) {
                    current[key] = null;
                } else if (typeof current[key] === 'object') {
                    stack.push(current[key]);
                }
            }
        }
    }

    return obj;
};
