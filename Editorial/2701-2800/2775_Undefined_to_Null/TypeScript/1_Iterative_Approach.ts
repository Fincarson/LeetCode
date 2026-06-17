type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Value = undefined | null | boolean | number | string | Value[] | { [key: string]: Value };

type Obj1 = Record<string, Value> | Value[];
type Obj2 = Record<string, JSONValue> | JSONValue[];

function undefinedToNull(obj: Obj1): Obj2 {
    const stack: Value[] = [obj];

    while (stack.length > 0) {
        const current = stack.pop();

        if (Array.isArray(current)) {
            for (let i = 0; i < current.length; i++) {
                if (current[i] === undefined) {
                    current[i] = null;
                } else if (typeof current[i] === 'object' && current[i] !== null) {
                    stack.push(current[i] as Value);
                }
            }
        } else if (typeof current === 'object' && current !== null) {
            for (const key in current) {
                if (current[key] === undefined) {
                    current[key] = null;
                } else if (typeof current[key] === 'object' && current[key] !== null) {
                    stack.push(current[key] as Value);
                }
            }
        }
    }

    return obj as Obj2;
}
