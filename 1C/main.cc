

#define _USE_MATH_DEFINES 
#define M_PI 3.14159265358979323846

#include <cmath>
#include <iostream>
#include <cstdio> 

//#define DEBUG 

typedef struct { 
    double x; 
    double y;
} Point;

double Distance(Point a, Point b) {
    double xDiff = a.x - b.x;
    double yDiff = a.y - b.y;
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

Point Equidistant(Point a, Point b, Point c) {

    double d = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));

    Point u;

    u.x = (
        (a.x * a.x + a.y * a.y) * (b.y - c.y) +
        (b.x * b.x + b.y * b.y) * (c.y - a.y) +
        (c.x * c.x + c.y * c.y) * (a.y - b.y)
    ) / d;

    u.y = (
        (a.x * a.x + a.y * a.y) * (c.x - b.x) +
        (b.x * b.x + b.y * b.y) * (a.x - c.x) +
        (c.x * c.x + c.y * c.y) * (b.x - a.x)
    ) / d;

    return u;
}

bool EqualEpsilon(double a, double b, double epsilon=0.001) {
    double diff = a - b;

    if (diff < 0) {
        diff = -diff;
    }

    return diff < epsilon;
}

bool Match(int angles, Point a, Point b, Point c, Point center, double radius) {
    double angleToA = atan2(0, 1) - atan2(a.y - center.y, a.x - center.x);
    double angleDiff = 2 * M_PI / angles;

    bool hitB = false;
    bool hitC = false;

#ifdef DEBUG
    std::cout << "radius = " << radius << std::endl;
    std::cout << "angleToA = " << angleToA << std::endl;
    std::cout << "center = " << center.x << ", " << center.y << std::endl;
#endif

    for (int i = 0; i < angles; i++) {
        double currentAngle = -angleToA + i * angleDiff;

        double x = center.x + (radius * cos(currentAngle));
        double y = center.y + (radius * sin(currentAngle));

#ifdef DEBUG
        std::cout << "(" << x << ", " << y << ")" << std::endl;
#endif

        if (EqualEpsilon(x, b.x) && EqualEpsilon(y, b.y)) {
            hitB = true;
        } else if (EqualEpsilon(x, c.x) && EqualEpsilon(y, c.y)) {
            hitC = true;
        }
    }

    return (hitB && hitC);
}

int main() {

    Point a, b, c;
    std::cin >> a.x >> a.y;
    std::cin >> b.x >> b.y;
    std::cin >> c.x >> c.y;

    Point center = Equidistant(a, b, c);
    double radius = Distance(a, center);

    int n;
    for (n = 3; n <= 100; n++) {
        if (Match(n, a, b, c, center, radius)) {
            break;
        }

        double area = radius * radius * n * sin((2 * M_PI) / (double)n);
        area = area / 2.0;
        //printf("%d = %.6lf\n", n, area);
    }

    // now find the area of n polygon
    double area = radius * radius * n * sin((2 * M_PI) / (double)n);
    area = area / 2.0;

    printf("%.6lf\n", area);

    return 0;
}

