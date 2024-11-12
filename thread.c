#include <stdio.h>
#include <pthread.h>

#define SIZE 10

int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int even_count = 0;
int odd_count = 0;

void* count_even(void* arg) {
    for (int i = 0; i < SIZE; i++) {
        if (array[i] % 2 == 0) {
            even_count++;
        }
    }
    printf("Jumlah angka genap: %d\n", even_count);
    return NULL;
}

void* count_odd(void* arg) {
    for (int i = 0; i < SIZE; i++) {
        if (array[i] % 2 != 0) {
            odd_count++;
        }
    }
    printf("Jumlah angka ganjil: %d\n", odd_count);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, count_even, NULL);
    pthread_create(&thread2, NULL, count_odd, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    int total_count = even_count + odd_count;
    printf("Jumlah total elemen dalam array: %d\n", total_count);

    return 0;
}
