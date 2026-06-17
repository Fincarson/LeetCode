public int numberOfSteps(int num) {
    // Get the binary for num, as a String.
    String binaryString = Integer.toBinaryString(num);

    int steps = 0;
    // Iterate over all the bits in the binary string.
    for (char bit : binaryString.toCharArray()) {
        if (bit == '1') { // If the bit is a 1
            steps = steps + 2; // Then it'll take 2 to remove.
        } else { // bit == '0'
            steps = steps + 1; // Then it'll take 1 to remove.
        }
    }

    // We need to subtract 1, because the last bit was over-counted.
    return steps - 1;
}
