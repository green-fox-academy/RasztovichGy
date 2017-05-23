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
    struct point *ptr_to_point = 0;
    ptr_to_point = (struct point*)malloc(sizeof(struct point)); //létrejön egy pointer egy lefoglglalt memterületre
    (*ptr_to_point).x = a; //a pointerből csináltam egy változót
    //ptr_to_point->x = a; //ez ugyanazt jelenti mint az előző sor!
    ptr_to_point->y = b;
    return ptr_to_point;
   //p.x = a;
  //  p.y = b;
 //   return &p; //visszatérek a felszabadított memóriaterületre mutató pointerrel.
}
// TODO:
// Create a function that takes 2 Points as a pointer and returns the distance between them


float calculate_distance(struct point *p1, struct point *p2)
{
    sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

int main()
{
    struct point var;
    struct point var1;

    var.x = 1;
    var.y = 1;

    var1.x = 2;
    var1.y = 2;

    struct point *ptr_to_point;
    ptr = point_constructor(20,30);

    printf("x:\t%d\ny:\t%d\n", (*ptr).x, (*ptr).y);

    int j = 40;
    int k = 20;
    printf("x:\t%d\ny:\t%d\n", (*ptr).x, (*ptr).y);

    float calculate_distance(struct point p1, struct point p2); //itt valami elbaszódott, be kell fejezni!

    free(ptr);
    return 0;
}
