function deepFilter(
    obj: Record<string, any>,
    fn: Function
): Record<string, any> | undefined {
    function dfs(node: any): any {
        if (node === null) {
            if (fn(node)) return node;
            return undefined;
        }
        if (typeof node !== 'object') {
            if (fn(node)) return node;
            return undefined;
        }

        if (Array.isArray(node)) {
            const newArr: any[] = [];

            for (let i = 0; i < node.length; i++) {
                const curr = node[i];
                const subRes = dfs(curr);

                if (subRes !== undefined) {
                    newArr.push(subRes);
                }
            }

            if (newArr.length === 0) {
                return undefined;
            }

            return newArr;
        }

        const newObj: Record<string, any> = {};
        let isEmpty = true;

        for (const key in node) {
            if (Object.prototype.hasOwnProperty.call(node, key)) {
                const subRes = dfs(node[key]);
                if (subRes !== undefined) {
                    newObj[key] = subRes;
                    isEmpty = false;
                }
            }
        }

        if (isEmpty) return undefined;

        return newObj;
    }

    return dfs(obj);
}
