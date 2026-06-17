var getResults = function (queries) {
    const mx = 50000;
    const st = [0, mx];

    const bisectLeft = (arr, x) => {
        let lo = 0,
            hi = arr.length;
        while (lo < hi) {
            const mid = (lo + hi) >>> 1;
            if (arr[mid] < x) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    };

    const insort = (arr, x) => {
        const idx = bisectLeft(arr, x);
        arr.splice(idx, 0, x);
    };

    for (const q of queries) {
        if (q[0] === 1) {
            insort(st, q[1]);
        }
    }

    const bt = new Array(mx + 1).fill(0);

    const update = (x, v) => {
        while (x <= mx) {
            if (v > bt[x]) bt[x] = v;
            x += x & -x;
        }
    };

    const query = (x) => {
        let res = 0;
        while (x > 0) {
            if (bt[x] > res) res = bt[x];
            x -= x & -x;
        }
        return res;
    };

    let pre = 0;
    for (const x of st) {
        if (x === 0) {
            continue;
        }
        update(x, x - pre);
        pre = x;
    }

    const ans = [];
    for (let i = queries.length - 1; i >= 0; i--) {
        const q = queries[i];
        if (q[0] === 2) {
            const x = q[1],
                sz = q[2];
            const idx = bisectLeft(st, x);
            let preVal;

            if (idx < st.length && st[idx] === x) {
                preVal = x;
            } else {
                preVal = st[idx - 1];
            }

            let maxSpace = query(preVal);
            maxSpace = Math.max(maxSpace, x - preVal);
            ans.push(maxSpace >= sz);
        } else {
            const x = q[1];
            const idx = bisectLeft(st, x);
            const preVal = st[idx - 1];
            const nxt = st[idx + 1];

            update(nxt, nxt - preVal);
            st.splice(idx, 1);
        }
    }

    return ans.reverse();
};
