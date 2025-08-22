#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    int moves = pow(2, n) - 1; // total moves
    char src = 'A', aux = 'B', dest = 'C';

    // If even, swap destination and auxiliary
    if (n % 2 == 0) {
        char temp = dest;
        dest = aux;
        aux = temp;
    }

    for (int i = 1; i <= moves; i++) {
        int disk = __builtin_ctz(i) + 1; // rightmost set bit → disk number
        if (i % 3 == 1) 
            printf("Move disk %d from %c -> %c\n", disk, src, dest);
        else if (i % 3 == 2) 
            printf("Move disk %d from %c -> %c\n", disk, src, aux);
        else 
            printf("Move disk %d from %c -> %c\n", disk, aux, dest);
    }

    return 0;
}
