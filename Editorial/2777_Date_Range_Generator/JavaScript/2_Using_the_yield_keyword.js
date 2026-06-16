/**
 * @param {string} start
 * @param {string} end
 * @param {number} step
 * @yields {string}
 */
var dateRangeGenerator = function*(start, end, step) {
    const startDate = new Date(start);
    const endDate = new Date(end).getTime();

    while (startDate.getTime() <= endDate) {
        const date = String(startDate.getDate()).padStart(2, '0');
        const month = String(startDate.getMonth() + 1).padStart(2, '0');
        const year = String(startDate.getFullYear()).padStart(2, '0');
        yield `${year}-${month}-${date}`;

        const next = startDate.getDate() + step;
        startDate.setDate(next);
    }
};
