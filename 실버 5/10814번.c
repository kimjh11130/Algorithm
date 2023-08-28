#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int age;
    char name[101];
} element;
element person[100000];

int comp(const void *a, const void *b) {
    return ((element *) a)->age - ((element *) b)->age;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &person[i].age, person[i].name);
    }
    qsort(person, n, sizeof(person[0]), comp);
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", person[i].age, person[i].name);
    }
}