class Router {
    private memoryLimit: number;
    private packetQ: {
        source: number;
        destination: number;
        timestamp: number;
    }[] = [];
    private packetSet: Set<string> = new Set();
    private destToTimestamps: Map<
        number,
        { timestamps: number[]; head: number }
    > = new Map();

    constructor(memoryLimit: number) {
        this.memoryLimit = memoryLimit;
    }

    private key(p: {
        source: number;
        destination: number;
        timestamp: number;
    }): string {
        return `${p.source},${p.destination},${p.timestamp}`;
    }

    addPacket(source: number, destination: number, timestamp: number): boolean {
        const packet = { source, destination, timestamp };
        const key = this.key(packet);
        if (this.packetSet.has(key)) return false;
        if (this.packetQ.length === this.memoryLimit) this.forwardPacket();
        this.packetQ.push(packet);
        this.packetSet.add(key);
        if (!this.destToTimestamps.has(destination))
            this.destToTimestamps.set(destination, { timestamps: [], head: 0 });
        this.destToTimestamps.get(destination)!.timestamps.push(timestamp);
        return true;
    }

    forwardPacket(): number[] {
        if (this.packetQ.length === 0) return [];
        const packet = this.packetQ.shift()!;
        this.packetSet.delete(this.key(packet));
        this.destToTimestamps.get(packet.destination)!.head++;
        return [packet.source, packet.destination, packet.timestamp];
    }

    getCount(destination: number, startTime: number, endTime: number): number {
        const p = this.destToTimestamps.get(destination);
        if (!p) return 0;
        const left = this.lowerBound(p.timestamps, startTime, p.head);
        const right = this.lowerBound(p.timestamps, endTime + 1, p.head);
        return right - left;
    }

    private lowerBound(nums: number[], target: number, left: number): number {
        let right = nums.length;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return right;
    }
}
