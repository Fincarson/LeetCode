var beforeAndAfterPuzzles = function (phrases) {
    const n = phrases.length;
    const sp = phrases.map((phrase) => {
        const words = phrase.split(" ");
        return { first: words[0], last: words[words.length - 1] };
    });

    const m = new Set();
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (i === j) continue;
            if (sp[i].first === sp[j].last) {
                const combined =
                    phrases[j] + phrases[i].slice(sp[i].first.length);
                m.add(combined);
            }
        }
    }

    const ret = Array.from(m).sort();
    return ret;
};
