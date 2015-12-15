#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>

#include "poi2D.h"
typedef std::chrono::high_resolution_clock Clock;

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

// Prints convex hull of a set of n points.
vector<poi2D> computeJarvis(vector<poi2D> &points)
{

    int n = points.size();
    // There should be minimum 3 points
    if (n < 3) return points;


    vector<poi2D> hull;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.
    int p = l, q;
    do
    {
        // Add current point to result
        hull.push_back(points[p]);

        // Search for a point 'q' such that checkOrientation(p, x,
        // q) is counterclockwise for all points 'x'. In case
        // there exists a point x such that orientation comes
        // out to be clockwise then update q with this point
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
            // If checkOrientation(p,i,q) is clockwise, then
            // update q
            if (checkOrientation(points[p], points[i], points[q]) == 2)
                q = i;
        }


        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;

    } while (p != l);  // While we don't come to initial point

    // Print Result
    // for (int i = 0; i < hull.size(); i++)
    //     cout << "(" << hull[i].x << ", "
    //     << hull[i].y << ")\n";
    return hull;
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
//     //clock_t begin = clock();
//     //cout<<input.size();
//     auto t1 = Clock::now();    
//     computeJarvis(input);
//     //clock_t end = clock();
//    // clock_t clockticks=end-begin;
// //    double elapsed_secs = clockticks/ double CLOCKS_PER_SEC;

//    // cout << elapsed_secs << endl;
// 	auto t2 = Clock::now();
//     std::cout << "Delta t2-t1: " 
//               << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
//               << " nanoseconds" << std::endl;

// }