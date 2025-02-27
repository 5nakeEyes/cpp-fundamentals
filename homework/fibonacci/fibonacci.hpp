#pragma once

int fibonacci_iterative(int sequence) {
    if (sequence <= 1)
        return sequence;
    int first = 0, second = 1, sum = 0;
    for (int i = 2; i <= sequence; i++) {
        sum = first + second;
        first = second;
        second = sum;
    }
    return sum;
}

int fibonacci_recursive(int sequence) {
    if (sequence <= 1)
        return sequence;
    return fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2);
}
