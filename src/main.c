#include <stdio.h>
#include <stdlib.h>
#include "hello.h"
#include "sum.h"
#include "mult.h"

int main(void)
{
    int res = 1;
    int s = 0;
    int m = 0;

    res = hello();

    s = sum(2,2);
    printf("%d\n",s);

    m = mult(2,3);
    printf("%d\n",m);

    return EXIT_SUCCESS;
}
