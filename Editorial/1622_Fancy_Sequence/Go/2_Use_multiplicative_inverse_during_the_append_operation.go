const MOD = 1000000007

type Fancy struct {
	v []int
	a int
	b int
}

func Constructor() Fancy {
	return Fancy{
		v: []int{},
		a: 1,
		b: 0,
	}
}

// fast exponentiation
func (this *Fancy) quickMul(x, y int) int {
	ret := 1
	cur := x
	for y > 0 {
		if y&1 != 0 {
			ret = (ret * cur) % MOD
		}
		cur = (cur * cur) % MOD
		y >>= 1
	}
	return ret
}

// multiplicative inverse
func (this *Fancy) inv(x int) int {
	return this.quickMul(x, MOD-2)
}

func (this *Fancy) Append(val int) {
	adjustedVal := ((val - this.b + MOD) % MOD) * this.inv(this.a) % MOD
	this.v = append(this.v, adjustedVal)
}

func (this *Fancy) AddAll(inc int) {
	this.b = (this.b + inc) % MOD
}

func (this *Fancy) MultAll(m int) {
	this.a = (this.a * m) % MOD
	this.b = (this.b * m) % MOD
}

func (this *Fancy) GetIndex(idx int) int {
	if idx >= len(this.v) {
		return -1
	}
	ans := (this.a*this.v[idx]%MOD + this.b) % MOD
	return ans
}
