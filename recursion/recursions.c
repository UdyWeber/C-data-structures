//
// Created by USER on 08/01/2024.
//
#include <stdio.h>

void b_call_a(int n);

void add_till_ascending_time(int value, int target) {
    if (value != target) {
        printf("Value: %d, Target: %d\n", value, target);
        add_till_ascending_time(++value, target);
    }
}

void add_till_descending_time(int value, int target) {
    if (value != target) {
        add_till_descending_time(++value, target);
        printf("Value: %d, Target: %d\n", value, target);
    }
}

void multiplication_table(int value) {
    static int n = 0;

    if (n == 0) {
        printf("============= Table of %d ============\n", value);
    }

    if (n < 10) {
        n++;
        printf("Var n address: %p; ", &n);
        printf("%d x %d = %d\n", value, n, value * n);

        return multiplication_table(value);
    }

    printf("======================================\n");
}

void tree_recursion(int n) {
    if (n > 0) {
        printf("%d", n);
        tree_recursion(n - 1);
        tree_recursion(n - 1);
    }
}

// Defining Circular calling of functions
void a_call_b(int n) {
    if (n > 0) {
        printf("%d\n", n);
        b_call_a(n - 1);
    }
}

void b_call_a(int n) {
    if (n > 1) {
        printf("%d\n", n);
        a_call_b(n/2);
    }
}

int nested(int n) {
    if (n > 100)
        return n - 10;

    return nested(nested(n + 11));
}

int sum_of_first_n_natural_numbers(int n) {
    // 0(1) solution: return (n * (n + 1)) / 2

    if (n == 0)
        return n;

    return sum_of_first_n_natural_numbers(n - 1) + 1;
}

int factorial_of_n(int n) {
    if (n <= 1) {
        return 1;
    }

    return factorial_of_n(n - 1) * n;
}

int m_power_n(int m, int n) {
    if (n == 0) {
        return 1;
    }

    // mine
    // return m_power_n(m, --n) * m;

    // Optimized using divide and conquer
    if (n % 2 == 0) {
        return m_power_n(m * m, n / 2);
    } else {
        return m * m_power_n(m * m, (n - 1) / 2);
    }
}

double taylor_series_of_n(int x, int n) {
    static double p = 1, f = 1;
    double r;

    if (n == 0) {
        return 1;
    }

    r = taylor_series_of_n(x, n - 1);
    p = p * x;
    f = f * n;

    return r + p / f;
}

double taylor_series_of_n_using_horner(int x, int n) {
    static double s;

    if (n == 0) {
        // return the last calculation of the formula
        return s;
    }

    s = 1 + x * s / n;
    return taylor_series_of_n_using_horner(x, n-1);
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }

    return fib(n - 2) + fib(n - 1);
}

int combination_formula(int n, int r) {
    int t1, t2, t3;

    t1 = factorial_of_n(n);
    t2 = factorial_of_n(r);
    t3 = factorial_of_n(n - r);

    return t1 / (t2 * t3);
}

int combination_formula_pascal_triangle(int n, int r) {
    if (r == 0 || r == n) {
        // Value of the extremities of the triangle are 1
        return 1;
    }

    // n - 1 = Level in the triangle or tree
    // contiguous value in the triangle
    return combination_formula_pascal_triangle(n-1, r-1) + combination_formula_pascal_triangle(n - 1, r);
}