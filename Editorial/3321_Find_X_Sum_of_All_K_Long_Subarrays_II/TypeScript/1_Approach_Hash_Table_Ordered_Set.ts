import { AvlTree } from "@datastructures-js/binary-search-tree";

type FrequencyPair = [number, number];

class Helper {
    private x: number;
    private result: bigint;
    private large: AvlTree<FrequencyPair>;
    private small: AvlTree<FrequencyPair>;
    private occ: Map<number, number>;

    constructor(x: number) {
        this.x = x;
        this.result = 0n;

        const comparator = (a: FrequencyPair, b: FrequencyPair): number => {
            if (a[0] !== b[0]) {
                return a[0] - b[0];
            }
            return a[1] - b[1];
        };

        this.large = new AvlTree<FrequencyPair>(comparator);
        this.small = new AvlTree<FrequencyPair>(comparator);
        this.occ = new Map<number, number>();
    }

    insert(num: number): void {
        const currentFreq = this.occ.get(num) || 0;
        if (currentFreq > 0) {
            this.internalRemove([currentFreq, num]);
        }

        const newFreq = currentFreq + 1;
        this.occ.set(num, newFreq);
        this.internalInsert([newFreq, num]);
    }

    remove(num: number): void {
        const currentFreq = this.occ.get(num);
        if (currentFreq === undefined || currentFreq === 0) {
            return;
        }
        this.internalRemove([currentFreq, num]);
        const newFreq = currentFreq - 1;
        if (newFreq > 0) {
            this.occ.set(num, newFreq);
            this.internalInsert([newFreq, num]);
        } else {
            this.occ.delete(num);
        }
    }

    get(): number {
        return Number(this.result);
    }

    private internalInsert(p: FrequencyPair): void {
        const [freq, value] = p;
        const minLarge = this.large.min();
        if (
            this.large.count() < this.x ||
            (minLarge && this.comparePairs(p, minLarge.getValue()) > 0)
        ) {
            this.result += BigInt(freq) * BigInt(value);
            this.large.insert(p);
            if (this.large.count() > this.x) {
                const smallestLarge = this.large.min();
                if (smallestLarge) {
                    const value = smallestLarge.getValue();
                    this.result -= BigInt(value[0]) * BigInt(value[1]);
                    this.large.remove(value);
                    this.small.insert(value);
                }
            }
        } else {
            this.small.insert(p);
        }
    }

    private internalRemove(p: FrequencyPair): void {
        const [freq, value] = p;

        if (this.large.has(p)) {
            this.result -= BigInt(freq) * BigInt(value);
            this.large.remove(p);
            if (this.small.count() > 0) {
                const largestSmall = this.small.max();
                if (largestSmall) {
                    const value = largestSmall.getValue();
                    this.result += BigInt(value[0]) * BigInt(value[1]);
                    this.small.remove(value);
                    this.large.insert(value);
                }
            }
        } else {
            this.small.remove(p);
        }
    }

    private comparePairs(a: FrequencyPair, b: FrequencyPair): number {
        if (a[0] !== b[0]) {
            return a[0] - b[0];
        }
        return a[1] - b[1];
    }
}

function findXSum(nums: number[], k: number, x: number): number[] {
    const helper = new Helper(x);
    const ans: number[] = [];

    for (let i = 0; i < nums.length; i++) {
        helper.insert(nums[i]);

        if (i >= k) {
            helper.remove(nums[i - k]);
        }

        if (i >= k - 1) {
            ans.push(helper.get());
        }
    }

    return ans;
}
