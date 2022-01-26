/**
 * Test code for Stack
 *
 * Matt bass
 * 09/21/2021
 */

#include "dynamic_cstk.h"

int main (int argc, char **argv) {
    D_Stack *s = d_stk_create(5);

    int i;
    for(i = 0; i < 10; i++) {
        d_stk_push(s, i);
    }

    printf("The original list: ");
    d_stk_display(s, 0);

    printf("The reversed list: ");
    d_stk_display(s, 1);

    d_stk_destroy(s);

    printf("The First peek value is %d\n", d_stk_peek(s));
    printf("The First pop value is %d\n", d_stk_pop(s));
    printf("The Second pop value is %d\n", d_stk_pop(s));
    return 0;
}