type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Value = undefined | null | boolean | number | string | Value[] | { [key: string]: Value };

type Obj1 = Record<string, Value> | Value[];
type Obj2 = Record<string, JSONValue> | JSONValue[];

function undefinedToNull(obj: Obj1): Obj2 {
    if (typeof obj !== 'object' || obj === null) {
        return obj !== undefined ? obj : null;
    }

    if (Array.isArray(obj)) {
        return obj.map(item => undefinedToNull(item as Value[]));
    }

    const newObj: Record<string, JSONValue> = {};

    for (const key in obj) {
        newObj[key] = undefinedToNull(obj[key] as Value[]) ;
    }

    return newObj;
}
