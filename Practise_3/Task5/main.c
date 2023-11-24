#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double x, y, z;
    double mass;
} Point;

double calculateDistance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void initializePoint(Point *point) {
    point->x = (double)rand() / RAND_MAX * 10.0;
    point->y = (double)rand() / RAND_MAX * 10.0;
    point->z = (double)rand() / RAND_MAX * 10.0;
    point->mass = (double)rand() / RAND_MAX * 10.0;
}

void printPoint(Point point, int index) {
    printf("Point %d: (x=%.2f, y=%.2f, z=%.2f) Mass=%.2f\n",
           index, point.x, point.y, point.z, point.mass);
}

int findMinMassIndex(Point *points, int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].mass < points[minIndex].mass) {
            minIndex = i;
        }
    }
    return minIndex;
}

int findNearestPoint(Point *points, int n, int excludeIndex) {
    double minDistance = -1.0;
    int nearestIndex = -1;
    for (int i = 0; i < n; i++) {
        if (i != excludeIndex) {
            double dist = calculateDistance(points[excludeIndex], points[i]);
            if (minDistance < 0 || dist < minDistance) {
                minDistance = dist;
                nearestIndex = i;
            }
        }
    }
    return nearestIndex;
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a valid number of points.\n");
        return 1;
    }

    Point *points = malloc(n * sizeof(Point));
    if (points == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        initializePoint(&points[i]);
    }

    while (n > 1) {
        for (int i = 0; i < n; i++) {
            printPoint(points[i], i);
        }

        int minIndex = findMinMassIndex(points, n);
        int nearestIndex = findNearestPoint(points, n, minIndex);

        points[nearestIndex].mass += points[minIndex].mass;
        printf("Point %d transfers its mass to point %d\n", minIndex, nearestIndex);
        points[minIndex] = points[n - 1];
        n--;
    }

    printf("The remaining point has coordinates (x=%.2f, y=%.2f, z=%.2f) and mass %.2f\n",
           points[0].x, points[0].y, points[0].z, points[0].mass);

    free(points);

    return 0;
}
