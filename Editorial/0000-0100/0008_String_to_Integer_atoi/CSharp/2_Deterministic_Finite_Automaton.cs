public enum State { q0, q1, q2, qd }

public class StateMachine {
    private State currentState;
    private long result;
    private int sign;

    public StateMachine() {
        currentState = State.q0;
        result = 0;
        sign = 1;
    }

    private void toStateQ1(char ch) {
        sign = (ch == '-') ? -1 : 1;
        currentState = State.q1;
    }

    private void toStateQ2(int digit) {
        currentState = State.q2;
        appendDigit(digit);
    }

    private void toStateQd() {
        currentState = State.qd;
    }

    public void appendDigit(int digit) {
        if ((result > int.MaxValue / 10) ||
            (result == int.MaxValue / 10 && digit > int.MaxValue % 10)) {
            if (sign == 1) {
                result = int.MaxValue;
            } else {
                result = int.MinValue;
                sign = 1;
            }

            toStateQd();
        } else {
            result = result * 10 + digit;
        }
    }

    public void transition(char ch) {
        if (currentState == State.q0) {
            if (ch == ' ') {
                return;
            } else if (ch == '-' || ch == '+') {
                toStateQ1(ch);
            } else if (char.IsDigit(ch)) {
                toStateQ2(ch - '0');
            } else {
                toStateQd();
            }
        } else if (currentState == State.q1 || currentState == State.q2) {
            if (char.IsDigit(ch)) {
                toStateQ2(ch - '0');
            } else {
                toStateQd();
            }
        }
    }

    public int getInteger() {
        return (int)(sign * result);
    }

    public State getState() {
        return currentState;
    }
}

public class Solution {
    public int MyAtoi(string s) {
        StateMachine Q = new StateMachine();
        for (int i = 0; i < s.Length && Q.getState() != State.qd; ++i) {
            Q.transition(s[i]);
        }

        return Q.getInteger();
    }
}
