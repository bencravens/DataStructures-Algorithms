#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n){
    int i;
    int mod;
    for(i=2;i<n;i++){
        mod = n % i;
        if (mod == 0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int x=2;
    int num_printed=0;
    while(num_printed<100){
        if (is_prime(x)==1) {
            printf("%d\n",x);
            num_printed += 1;
        }
        x += 1;
    }
    return 0;
}
