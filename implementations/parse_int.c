//
// Created by JAW on 23/08/2024.
//

#include <stdio.h>

int char_to_int(const char input) {
    return input - '0';
}

int _pow(const int value, const int n) {
    long long final = 1;
    for (int i = 0; i < n; i++) {
        final *= value;
    }
    return final;
}

int _strlen(const char *value) {
    int t = 0;
    while (*value != '\000') {
        t++;
        value++;
    }
    return t;
}

int string_to_int(const char *value) {
    const int tamanho = _strlen(value);
    int sum = 0;
    int t = tamanho;

    for (int i = 0; i < tamanho; i++, t--) {
        sum += char_to_int(value[i]) * _pow(10, t - 1);
    }
    return sum;
}
