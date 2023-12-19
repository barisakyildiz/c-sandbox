/* How many different ways you can climb a series of stairs*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    printf("Please enter the stair count tha you want to climb: ");
    scanf("%d", &n);
    long long* fib_dynamic = (long long*)malloc(sizeof(long long) * n);
    fib_dynamic[0] = 1;
    fib_dynamic[1] = 2;
    for(int i = 2; i < n; i++){
        fib_dynamic[i] = fib_dynamic[i-1] + fib_dynamic[i-2];
    }

    printf("You can climb the %dth stair %d different ways\n", n, fib_dynamic[n-1]);

    return 0;
}

