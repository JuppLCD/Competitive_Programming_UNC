// https://codeforces.com/problemset/problem/339/A

#include <bits/stdc++.h>

using namespace std;

static void swap(int a[], unsigned int i, unsigned int j) {
    unsigned int temp = a[i];

    a[i] = a[j];
    a[j] = temp;
}

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = izq;
    unsigned int i = izq + 1;
    unsigned int j = der;

    while (i <= j) {
        if (a[i] <= a[ppiv]) { i++; }
        else if (a[ppiv] <= a[j]) { j--; }
        else if (a[ppiv] <= a[i] && a[j] <= a[ppiv]) {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if (izq < der) {
        unsigned int ppiv = partition(a, izq, der);
        quick_sort_rec(a, izq, (ppiv == 0u ? 0u : ppiv - 1));
        quick_sort_rec(a, ppiv + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    string line;
    cin >> line;

    unsigned int len = 0;
    if (line.length() <= 1) len = line.length();
    else len = line.length() - line.length() / 2;

    int a[len];
    for (size_t i = 0; i < len; i++) {
        a[i] = line[i * 2] - '0';
    }

    quick_sort(a, len);

    for (size_t i = 0; i < len; i++) {
        cout << a[i];
        if (i + 1 < len) cout << "+";
    }

    cout << endl;

    return EXIT_SUCCESS;
}