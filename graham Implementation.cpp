#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <stack>
#include <chrono>
#include <time.h>

#include "poi2D.h"
#include "Number.h"

typedef std::chrono::high_resolution_clock Clock;

poi2D p0;

// A utility function to swap two points
Number swap(poi2D &p1, poi2D &p2)
{
    poi2D temp = p1;
    p1 = p2;
    p2 = temp;
}

// A utility function to return square of distance
// between p1 and p2
Number distSq(poi2D p1, poi2D p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
           (p1.y - p2.y)*(p1.y - p2.y);
}

// A utility function to find next to top in a stack
poi2D nextToTop(stack<poi2D> &S)
{
    poi2D p = S.top();
    S.pop();
    poi2D res = S.top();
    S.push(p);
    return res;
}

// To find orientation of ordered triplet (p1, p2, p3).
// The function returns following values
// 0 --> p1, p2 and p3 are co-linear
// 1 --> Clockwise
// 2 --> Counter-clockwise
int checkOrientation(poi2D p1, poi2D p2, poi2D p3)
{
    Number calc = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);

    if (calc == Number("0"))
    {
        return 0;  // colinear
    }
    else if(calc > Number("0"))
    {
        return 1;  // clockwise
    }
    else return 2; // counter-clockwise
}



// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
    poi2D *p1 = (poi2D *)vp1;
    poi2D *p2 = (poi2D *)vp2;

    // Find orientation
    int o = checkOrientation(p0, *p1, *p2);
    if (o == 0)
        if(distSq(p0, *p2) >= distSq(p0, *p1))
            return -1;
        else return 1;

    if(o == 2)
        return -1;
    else return 1;
}

// Prints convex hull of a set of n points
vector<poi2D> computeGraham(vector<poi2D> points)
{
    // Find the bottommost point
    int min = 0;
    int n = points.size();
    Number ymin = points[0].y;
    for (int i = 1; i < n; i++)
    {
        Number y = points[i].y;

        // Pick the bottom-most or chose the left
        // most point in case of tie
        if ((y < ymin) || (ymin == y &&
                           points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at first position
    swap(points[0], points[min]);

    // Sort n-1 points with respect to the bottom-most point.
    // A point p1 comes before p2 in sorted output if p2
    // has larger angle (in counterclockwise
    // direction) than p1
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(poi2D), compare);

    // If two or more points make same angle with p0,
    // Remove all the points except the one that is farthest from p0
    // The idea is
    // to keep the farthest point at the end when more than
    // one points have same angle.
    int m = 1;
    for (int i=1; i<n; i++)
    {
        // Keep removing i while angle of i and i+1 is same
        // with respect to p0
        while (i < n-1 && checkOrientation(p0, points[i],
                                      points[i+1]) == 0)
            i++;


        points[m] = points[i];
        m++;
    }

    // If modified array of points has less than 3 points,
    // convex hull is not possible
    if (m < 3) return points;

    // Create an empty stack and push first three points
    // to it.
    stack<poi2D> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Process remaining n-3 points
    for (int i = 3; i < m; i++)
    {
        // Keep removing top while the angle formed by
        // points next-to-top, top, and points[i] makes
        // a right turn
        while (checkOrientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    // print contents of stack
    while (!S.empty())
    {
        poi2D p = S.top();
        cout << "(" << p.x << ", " << p.y <<")" << endl;
        S.pop();
    }
}

// int main(){
//     vector<poi2D> input;
//     ifstream infile;
//     infile.open("points.bin",ios::binary|ios::in);

//     poi2D fileRead;

//     while(infile.read((char *)&fileRead,sizeof(poi2D)))
//     {
//         input.push_back(fileRead);
//     }
//     // cout<<input.size();
//     infile.close();
//     auto t1= Clock ::now();

//     //clock_t begin = clock();
//     //cout<<input.size();
//     computeGraham(input);
//     auto t2 = Clock ::now();
//     std::cout << "Delta t2-t1: "
//     << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
//     << " nanoseconds" << std::endl;
//     //clock_t end = clock();
//     //clock_t clockticks=end-begin;
//     //double elapsed_secs = clockticks/ double CLOCKS_PER_SEC;

//     //cout << elapsed_secs << endl;

// }