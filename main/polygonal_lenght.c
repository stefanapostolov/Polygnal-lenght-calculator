/*

	Define a type of data that can represent the coordinates of a point
	and a type of data that can represent a polygonal chain of a maximum
	of 50. The program asks the user how many points should be inserted
	to form the polygonal. In the end it calculates the lenght of the
	polygonal and prints the result

*/

#include <stdio.h>
#include <math.h>

#define MAX_POINTS 50

typedef struct point_s {

	float x;
	float y;

} point_t;

typedef struct polygonal_s {

	point_t points[MAX_POINTS];
	int nPoints;

} polygonal_t;

float distance(point_t p1, point_t p2);

point_t readpoint();

int main(int argc, char * argv[]){

	polygonal_t polygonal;
	int i;
	float lenght, curDistance;

	do{
		printf("How many points would you like to insert?\n");
		scanf("%d", &polygonal.nPoints);
		if(!(polygonal.nPoints > 2 && polygonal.nPoints <= 50)){
			printf("The input is ivalid. Try again!\n");
		}
	} while (!(polygonal.nPoints > 2 && polygonal.nPoints <= 50));

	for(i=0; i<polygonal.nPoints; i++)
		polygonal.points[i] = readpoint();
	printf("\n");

	curDistance = 0;
	lenght = 0;
	for(i=0; i<polygonal.nPoints-1; i++){
		curDistance = distance(polygonal.points[i], polygonal.points[i+1]);
		lenght = lenght + curDistance;
	}

	printf("The lenght of the polygonal is: %f\n", lenght);
	printf("\n");

	return 0;
}

point_t readpoint(){

	point_t result;

	printf("The x-coordinate of the point is:\n");
	scanf("%f", &result.x);

	printf("The y-coordinate of the point is:\n");
	scanf("%f", &result.y);

	return result;

}

float distance(point_t p1, point_t p2){

	float result;
	float dX, dY;

	dX = p2.x - p1.x;
	dY = p2.y - p1.y;

	result = sqrt((dX*dX)+(dY*dY));

	return result;
}




