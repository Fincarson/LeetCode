// Define the state enum in C style.
typedef enum { q0, q1, q2, qd } State;

// Create a struct to hold the state machine's data.
typedef struct {
    State currentState;
    int result;
    int sign;
} StateMachine;

// Initialize the state machine.
void initStateMachine(StateMachine *machine) {
    machine->currentState = q0;
    machine->result = 0;
    machine->sign = 1;
}

// Transition to state q1.
void toStateQ1(StateMachine *machine, char ch) {
    machine->sign = (ch == '-') ? -1 : 1;
    machine->currentState = q1;
}

// Transition to state q2.
void toStateQ2(StateMachine *machine, int digit) {
    machine->currentState = q2;
    // Append current digit to the result.
    if ((machine->result > INT_MAX / 10) ||
        (machine->result == INT_MAX / 10 && digit > INT_MAX % 10)) {
        if (machine->sign == 1) {
            // If sign is 1, clamp result to INT_MAX.
            machine->result = INT_MAX;
        } else {
            // If sign is -1, clamp result to INT_MIN.
            machine->result = INT_MIN;
            machine->sign = 1;
        }
        // When the 32-bit int range is exceeded, a dead state is reached.
        machine->currentState = qd;
    } else {
        machine->result = machine->result * 10 + digit;
    }
}

// Transition to dead state qd.
void toStateQd(StateMachine *machine) { machine->currentState = qd; }

// Change state based on current input character.
void transition(StateMachine *machine, char ch) {
    if (machine->currentState == q0) {
        if (ch == ' ') {
            return;
        } else if (ch == '-' || ch == '+') {
            toStateQ1(machine, ch);
        } else if (isdigit(ch)) {
            toStateQ2(machine, ch - '0');
        } else {
            toStateQd(machine);
        }
    } else if (machine->currentState == q1 || machine->currentState == q2) {
        if (isdigit(ch)) {
            toStateQ2(machine, ch - '0');
        } else {
            toStateQd(machine);
        }
    }
}

// Return the final result formed with its sign.
int getInteger(StateMachine *machine) {
    return machine->sign * machine->result;
}

// Get current state.
State getState(StateMachine *machine) { return machine->currentState; }

// Function to parse string to integer using the state machine.
int myAtoi(char *s) {
    StateMachine Q;
    initStateMachine(&Q);

    for (int i = 0; s[i] != '\0' && getState(&Q) != qd; ++i) {
        transition(&Q, s[i]);
    }

    return getInteger(&Q);
}
