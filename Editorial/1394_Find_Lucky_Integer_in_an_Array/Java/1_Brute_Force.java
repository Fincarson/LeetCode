public int findLucky(int[] arr) {
    int maxLuckyNumber = -1;
    for (int num : arr) {
        int occurencesOfNum = countOccurences(arr, num);
        //  If num is a lucky number, and is the biggest lucky number so far.
        if (occurencesOfNum == num && num > maxLuckyNumber) {
            maxLuckyNumber = num;
        }
    }
    return maxLuckyNumber;
}

private int countOccurences(int[] arr, int candidateNum) {
    int count = 0;
    for (int num : arr) {
        if (num == candidateNum) {
            count++;
        }
    }
    return count;
}
