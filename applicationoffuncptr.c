#include <stdio.h>

int func(int a, int b){
    return a+b;
}
int func1(int a, int b){
    return a-b;
}
int func2(int a, int b){
    return a*b;
}
int func3(int a, int b){
    return a/b;
}

int main(){
    int (*ptr2func[4])(int, int) = {func, func1, func2, func3};
    int choice;
    int a, b;
    printf("select 0, 1, 2, 3\n");
    scanf("%d", &choice);
    printf("Enter 1st number: \n");
    scanf("%d", &a);
    printf("Enter 2nd number: \n");
    scanf("%d", &b);

    int result = ("%d", ptr2func[choice](a, b));


    return 0;
}