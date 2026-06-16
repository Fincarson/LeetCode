# 2043. Simple Bank System

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/simple-bank-system/)  
`Array` `Hash Table` `Design` `Simulation`

**Problem Link:** [LeetCode 2043 - Simple Bank System](https://leetcode.com/problems/simple-bank-system/)

## Problem

You have been tasked with writing a program for a popular bank that will automate all its incoming transactions (transfer, deposit, and withdraw). The bank has n accounts numbered from 1 to n. The initial balance of each account is stored in a 0-indexed integer array balance, with the (i + 1)th account having an initial balance of balance[i].

Execute all the valid transactions. A transaction is valid if:

- The given account number(s) are between 1 and n, and
- The amount of money withdrawn or transferred from is less than or equal to the balance of the account.

Implement the Bank class:

- Bank(long[] balance) Initializes the object with the 0-indexed integer array balance.
- boolean transfer(int account1, int account2, long money) Transfers money dollars from the account numbered account1 to the account numbered account2. Return true if the transaction was successful, false otherwise.
- boolean deposit(int account, long money) Deposit money dollars into the account numbered account. Return true if the transaction was successful, false otherwise.
- boolean withdraw(int account, long money) Withdraw money dollars from the account numbered account. Return true if the transaction was successful, false otherwise.

### Example 1

```text
Input
["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
Output
[null, true, true, true, false, false]

Explanation
Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // return true, account 3 has a balance of $20, so it is valid to withdraw $10.
                         // Account 3 has $20 - $10 = $10.
bank.transfer(5, 1, 20); // return true, account 5 has a balance of $30, so it is valid to transfer $20.
                         // Account 5 has $30 - $20 = $10, and account 1 has $10 + $20 = $30.
bank.deposit(5, 20);     // return true, it is valid to deposit $20 to account 5.
                         // Account 5 has $10 + $20 = $30.
bank.transfer(3, 4, 15); // return false, the current balance of account 3 is $10,
                         // so it is invalid to transfer $15 from it.
bank.withdraw(10, 50);   // return false, it is invalid because account 10 does not exist.
```

## Constraints

- n == balance.length
- 1 <= n, account, account1, account2 <= 105
- 0 <= balance[i], money <= 1012
- At most 104 calls will be made to each function transfer, deposit, withdraw.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Design an ATM Machine](https://leetcode.com/problems/design-an-atm-machine/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2043. Simple Bank System

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
typedef struct {
    long long* balance;
    int balanceSize;
} Bank;

Bank* bankCreate(long long* balance, int balanceSize) {
    Bank* obj = (Bank*)malloc(sizeof(Bank));
    obj->balance = (long long*)malloc(sizeof(long long) * balanceSize);
    obj->balanceSize = balanceSize;
    memcpy(obj->balance, balance, sizeof(long long) * balanceSize);
    return obj;
}

bool bankTransfer(Bank* obj, int account1, int account2, long long money) {
    if (account1 > obj->balanceSize || account2 > obj->balanceSize ||
        obj->balance[account1 - 1] < money) {
        return false;
    }
    obj->balance[account1 - 1] -= money;
    obj->balance[account2 - 1] += money;
    return true;
}

bool bankDeposit(Bank* obj, int account, long long money) {
    if (account > obj->balanceSize) {
        return false;
    }
    obj->balance[account - 1] += money;
    return true;
}

bool bankWithdraw(Bank* obj, int account, long long money) {
    if (account > obj->balanceSize || obj->balance[account - 1] < money) {
        return false;
    }
    obj->balance[account - 1] -= money;
    return true;
}

void bankFree(Bank* obj) { free(obj->balance); }
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Bank {
private:
    vector<long long> balance;

public:
    Bank(vector<long long>& balance) : balance(balance) {}

    bool transfer(int account1, int account2, long long money) {
        if (account1 > balance.size() || account2 > balance.size() ||
            balance[account1 - 1] < money) {
            return false;
        }
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account > balance.size()) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account > balance.size() || balance[account - 1] < money) {
            return false;
        }
        balance[account - 1] -= money;
        return true;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Bank {
    long[] balance;

    public Bank(long[] balance) {
        this.balance = balance;
    }

    public bool Transfer(int account1, int account2, long money) {
        if (account1 > balance.Length || account2 > balance.Length ||
            balance[account1 - 1] < money) {
            return false;
        }
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    public bool Deposit(int account, long money) {
        if (account > balance.Length) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }

    public bool Withdraw(int account, long money) {
        if (account > balance.Length || balance[account - 1] < money) {
            return false;
        }
        balance[account - 1] -= money;
        return true;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
type Bank []int64

func Constructor(balance []int64) Bank {
	return balance
}

func (b Bank) Transfer(account1, account2 int, money int64) bool {
	if account1 > len(b) || account2 > len(b) || b[account1-1] < money {
		return false
	}
	b[account1-1] -= money
	b[account2-1] += money
	return true
}

func (b Bank) Deposit(account int, money int64) bool {
	if account > len(b) {
		return false
	}
	b[account-1] += money
	return true
}

func (b Bank) Withdraw(account int, money int64) bool {
	if account > len(b) || b[account-1] < money {
		return false
	}
	b[account-1] -= money
	return true
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Bank {

    long[] balance;

    public Bank(long[] balance) {
        this.balance = balance;
    }

    public boolean transfer(int account1, int account2, long money) {
        if (
            account1 > balance.length ||
            account2 > balance.length ||
            balance[account1 - 1] < money
        ) {
            return false;
        }
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    public boolean deposit(int account, long money) {
        if (account > balance.length) {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }

    public boolean withdraw(int account, long money) {
        if (account > balance.length || balance[account - 1] < money) {
            return false;
        }
        balance[account - 1] -= money;
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var Bank = function (balance) {
    this.balance = balance;
};

Bank.prototype.transfer = function (account1, account2, money) {
    if (
        account1 > this.balance.length ||
        account2 > this.balance.length ||
        this.balance[account1 - 1] < money
    ) {
        return false;
    }
    this.balance[account1 - 1] -= money;
    this.balance[account2 - 1] += money;
    return true;
};

Bank.prototype.deposit = function (account, money) {
    if (account > this.balance.length) {
        return false;
    }
    this.balance[account - 1] += money;
    return true;
};

Bank.prototype.withdraw = function (account, money) {
    if (account > this.balance.length || this.balance[account - 1] < money) {
        return false;
    }
    this.balance[account - 1] -= money;
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Bank:
    def __init__(self, balance: List[int]):
        self.balance = balance

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if (
            account1 > len(self.balance)
            or account2 > len(self.balance)
            or self.balance[account1 - 1] < money
        ):
            return False
        self.balance[account1 - 1] -= money
        self.balance[account2 - 1] += money
        return True

    def deposit(self, account: int, money: int) -> bool:
        if account > len(self.balance):
            return False
        self.balance[account - 1] += money
        return True

    def withdraw(self, account: int, money: int) -> bool:
        if account > len(self.balance) or self.balance[account - 1] < money:
            return False
        self.balance[account - 1] -= money
        return True
```

</details>
