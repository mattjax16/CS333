#include <printf.h>

typedef struct {
    int a;
} Thing;

int main(int argc, char *argv[]) {
         Thing b = {0};
         Thing c;

         b.a = 5;
         c = b;
         b.a = 4;

         printf("%d\n", b.a);
         printf("%d\n", c.a);

    return 0;
}
