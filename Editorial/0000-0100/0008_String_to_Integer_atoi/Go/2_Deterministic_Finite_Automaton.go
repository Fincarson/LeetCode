type State int

const (
    q0 State = iota
    q1
    q2
    qd
)

type StateMachine struct {
    currentState State
    result, sign int
}

func (sm *StateMachine) toStateQ1(ch byte) {
    if ch == '-' {
        sm.sign = -1
    } else {
        sm.sign = 1
    }
    sm.currentState = q1
}

func (sm *StateMachine) toStateQ2(digit int) {
    sm.currentState = q2
    sm.appendDigit(digit)
}

func (sm *StateMachine) toStateQd() {
    sm.currentState = qd
}

func (sm *StateMachine) appendDigit(digit int) {
    if (sm.result > math.MaxInt32/10) ||
        (sm.result == math.MaxInt32/10 && digit > math.MaxInt32%10) {
        if sm.sign == 1 {
            sm.result = math.MaxInt32
        } else {
            sm.result = math.MinInt32
            sm.sign = 1
        }
        sm.toStateQd()
    } else {
        sm.result = sm.result*10 + digit
    }
}

func (sm *StateMachine) Transition(ch byte) {
    switch sm.currentState {
    case q0:
        if ch == ' ' {
            return
        }
        if ch == '-' || ch == '+' {
            sm.toStateQ1(ch)
        } else if ch >= '0' && ch <= '9' {
            sm.toStateQ2(int(ch - '0'))
        } else {
            sm.toStateQd()
        }
    case q1, q2:
        if ch >= '0' && ch <= '9' {
            sm.toStateQ2(int(ch - '0'))
        } else {
            sm.toStateQd()
        }
    }
}

func (sm *StateMachine) GetInteger() int {
    return sm.sign * sm.result
}

func (sm *StateMachine) getState() State {
    return sm.currentState
}

func myAtoi(s string) int {
    Q := StateMachine{currentState: q0, result: 0, sign: 1}
    for i := 0; i < len(s) && Q.getState() != qd; i++ {
        Q.Transition(s[i])
    }
    return Q.GetInteger()
}
