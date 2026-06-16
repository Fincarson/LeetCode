func maxBottlesDrunk(numBottles int, numExchange int) int {
	ans := numBottles
	for empty := numBottles; empty >= numExchange; numExchange++ {
		ans++
		empty -= numExchange - 1
	}
	return ans
}
