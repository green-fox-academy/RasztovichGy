#include <stdio.h>
#include <stdlib.h>
/*
typedef struct {
    int x;
    int y;
} point_t;
*/

struct point {
    int x;
    int y;
};

// TODO:
// Create a function the constructs a Point (returns a pointer to a new point)
// It should take it's x and y coordinate as parameter
struct point *point_constructor(int a, int b)
{
    struct point p;
    p.x = a;
    p.y = b;
    return &p; //visszatérek a felszabadított memóriaterületre mutató pointerrel.
}
// TODO:
// Create a function that takes 2 Points as a pointer and returns the distance between them

int main()
{
    int k;

    struct point var;
    struct point var1;
    struct point var2;

    var.x = 10;
    var.y = 12;

    var1.x = 1234;
    var1.y = 2345;

    struct point *ptr;
    ptr = point_constructor(20,30);

    printf("x:\t%d\ny:\t%d\n", (*ptr).x, (*ptr).y);

    return 0;
}
