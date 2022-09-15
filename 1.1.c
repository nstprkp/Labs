#include <stdio.h>

int main()
{
    float x1,x2,y1,y2;
    printf("Coordinates of the first point: ");
    scanf("%f %f",&x1, &y1);
    printf("Coordinates of the second point: "); scanf("%f %f",&x2, &y2);

    float dist=0;
    dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    printf("Distance = %.2f", dist);
    return 0;
}