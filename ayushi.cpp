#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include "poi2D.h"
#include <cmath>
#include <time.h>
#include <chrono>

#define PI 3.14159265
typedef std::chrono::high_resolution_clock Clock;



using namespace std;


//comparator function
bool compareX(const poi2D &poi1, const poi2D &poi2){
    return poi1.x < poi2.x;
}

//sees if the slope has increases from p2 to p3 when connected to p1
bool slopeIncreased(const poi2D &p1, const poi2D &p2, const poi2D &p3){
    //if p1 to p3 has greater slope return true
    return (((p3.y - p1.y)/(p3.x - p1.x)) > ((p2.y - p1.y)/(p2.x - p1.x)));
}

//used to order hulls of 3 points
vector<poi2D> orderHullClockwise(vector<poi2D> &hull){
    if(hull.size() == 3){
        //orders the points by x and then determines the correct order of the last 2 points
        sort(hull.begin(), hull.end(), compareX);
        if(slopeIncreased(hull[0], hull[1], hull[2])){
            poi2D temp;
            temp = hull[1];
            hull[1] = hull[2];
            hull[2] = temp;
        }
        return hull;
    } else {
        //combiningHulls is used to make hulls larger than 3 or 4
        cout << "  error ordering hull that has more than 4 points" << endl;
    }
}

//Function to find if a point is above or below the line
bool isAbove(const poi2D &a, const poi2D &b, poi2D &c ) {
    return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x))>0;
}








void checkAngle(std::stack<poi2D> &stack, int &b) {
    //cout<<"value of a in checkangle function is "<<b<<endl;
    if(b==1)
    {//cout<<"Above stack"<<endl;
    }
    else
    {//cout<<"Below stack"<<endl;
    }
    poi2D one;
    poi2D two;
    poi2D three;
    /*vector<poi2D> onef;
    vector<poi2D> twof;
    vector<poi2D> threef;*/
    poi2D onetwo;
    poi2D twothree;
    double dot, pcross, angle;
    one= stack.top();
    stack.pop();
    two = stack.top();
    stack.pop();
    three = stack.top();
    stack.pop();
    /*onef.push_back(one);
    twof.push_back(two);
    threef.push_back(three);*/
    onetwo.x= one.x - two.x;
    onetwo.y= one.y - two.y;
    twothree.x= three.x- two.x;
    twothree.y= three.y- two.y;
    dot=    twothree.x * onetwo.x + twothree.y * onetwo.y;
    pcross= twothree.x * onetwo.y - twothree.y * onetwo.x;
    angle= (atan2(pcross, dot))* 180/ PI;
    //cout<< "The angle is "<<angle<<endl;
    if(b==1){
        if (angle>0 && angle!=180 && angle!=-180) {
            stack.push(three);
            stack.push(two);
            stack.push(one);
        }
        else if (angle<0 && angle!=180 && angle!=-180){
            stack.push(three);
            stack.push(one);
            //cout<<"The size of the stack is "<<stack.size();
            if(stack.size()>=3){
               // cout<<"before calling checkangle for above when angle < 0 recursively"<<endl;
                if (stack.size()>2)
                checkAngle(stack,b);
            }

        }
        else if (angle==180 || angle==-180){
            stack.push(three);
            stack.push(one);
        }
        else
        {
           // cout<<"Some error with checkangle";
        }
    }
    else {
        if (angle<0 && angle!=180 && angle!=-180) {
            stack.push(three);
            stack.push(two);
            stack.push(one);
        }
        else if (angle>0 && angle!=180 && angle!=-180) {
            stack.push(three);
            stack.push(one);
            //cout<<"before calling checkangle for below when angle > 0 recursively"<<endl;
            if(stack.size()>2)
            checkAngle(stack,b);
        }
        else if (angle==180 || angle==-180){
            stack.push(three);
            stack.push(one);
        }
        else
        {
            //cout<<"Some error with checkangle";
        }
    }

}

//prints vector of poi2D's
void printVec(vector<poi2D> & vec){
    //cout<<"Calling Charlie! Inside printVec"<<endl;
    for(int i=0; i<vec.size(); i++) {
        cout << "(" << vec[i].x << ", " << vec[i].y << ")\n";
    }
    //for (vector<poi2D>::iterator it = vec.begin(); it != vec.end(); it++) {
    //  cout << "this is the final result"<< " "<<it->toString() << endl;
    //std::copy(begin(vec), end(vec), std::ostream_iterator<poi2D>(std::cout, " "));
}


//New Algorithm function
vector<poi2D> newalgo(vector<poi2D> &vec) {
   // cout<<"Calling Charlie! Inside newalgo"<<endl;
    bool compare;
   // std::vector<poi2D>::iterator blah;
//    std::stack<vector<poi2D>::iterator> above;
    //  std::stack<vector<poi2D>::iterator> below;
    stack<poi2D> above;
    stack<poi2D> below;
    stack<poi2D> temp;
    vector<poi2D> finalhull;
    int a=2;

    int size = vec.size();
    if (size < 3) { //base case of 2 points
        finalhull= vec;
    } else if (size < 4) { //base case of 3 points
        finalhull= orderHullClockwise(vec);
    }
    else {
        //cout<<"Calling Charlie! Size is"<<" "<<size<<endl;
        sort(vec.begin(), vec.end(), compareX);
//        std::vector<poi2D>::iterator min = vec.begin();
//        std::vector<poi2D>::iterator max = vec.end() -1;
        poi2D min = vec.at(0);
        poi2D max = vec.at(size-1);
        above.push(min);
        below.push(min);
        for (int i = 1; i < size-1; i++) {
            //cout<<"Calling Charlie! Inside for to check above/below line"<<endl;
            compare = isAbove(min, max,vec[i]);
            //cout<<"point is "<<vec[i].x<<" "<<vec[i].y<<" "<<i<<" "<<"line is above/below is "<<compare<<endl;
            if (compare==1) {
                a=1;
                above.push(vec.at(i));
                if (above.size() > 2) {
                  // cout<<"before calling checkangle when stack size more than 2 for above"<<endl;
                    checkAngle(above,a);
                   // cout<<"back in newalgo after iteration "<<i<<endl;
                }
            }
            else {
                a=0;
                //cout<<"value of a in below loop is "<<a<<endl;
                below.push(vec.at(i));
                if (below.size() > 2) {
                   //cout<<"before calling checkangle when stack size more than 2 for below"<<endl;
                    checkAngle(below,a);
                  // cout<<"back in newalgo after iteration "<<i<<endl;
                }
            }
        }
        above.push(max);
        a=1;
        //cout<<"before calling checkangle for last point for above"<<endl;
        checkAngle(above,a);
        below.push(max);
        a=0;
        //cout<<"before calling checkangle for last point for below"<<endl;
        checkAngle(below,a);

        /*  for(int i = 0; i < below.size(); i++) {
              cout << "iteration number "<< i+1;
              temp.push(below.top());
              below.pop();
          }
          */
        int i=0;
        int below_size=below.size();
        while(!below.empty()){
          // cout << "iteration number "<< i+1;
            if(i==below_size-1)
            {
                break;
            }
            else {
                temp.push(below.top());
                below.pop();
                i++;
            }


        }
        //cout<<"size of temp stack is "<<temp.size()<<endl;
        int temp_size=temp.size();
        int k=0;
        while(!temp.empty()) {
            //cout << "iteration number for loop k "<< k+1;
            if (k==temp_size-1)
            {
                break;
            }
            else {
                finalhull.push_back(temp.top());
                temp.pop();
                k++;
            }

        }
        //cout<<"Size of final hull before above is "<<finalhull.size()<<endl;

        int l=0;
        while(!above.empty()) {
           // cout<<"inside loop to move above hull to final "<<l << endl;
            finalhull.push_back(above.top());
            above.pop();
            l++;
        }
       // cout<<"Size of final hull is "<<finalhull.size()<<endl;

        /* int k=0,j=0,l=0;
         cout<<"The size of above hull is "<<above.size()<<endl;
         cout<<"The size of below hull is "<<below.size()<<endl;
         while (j<=below.size()) {
             cout<<"inside loop to move below hull in reverse order to temp "<<endl;
             temp.push(below.top());
             below.pop();
             j++;
         }
         cout<<"size of temp stack is "<<temp.size()<<endl;
         while (k<=temp.size()) {
             cout<<"inside loop to move temp hull to final "<<k<<endl;
             finalhull.push_back(temp.top());
             temp.pop();
             k++;
         }
         cout<<"Size of final hull before above is "<<finalhull.size()<<endl;
         while(l<=above.size()) {
             cout<<"inside loop to move above hull to final "<<endl;
             finalhull.push_back(above.top());
             above.pop();
             l++;
         }
 */
    }
   // cout<<"before calling printvec function "<<endl;
    return finalhull;
   // cout<<"after calling printvec function "<<endl;

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
//     auto t1 = Clock::now();
    
//     //clock_t begin = clock();
//     //cout<<input.size();
//     newalgo(input);
//     auto t2 = Clock::now();
//     std::cout << "Delta t2-t1: " 
//               << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
//               << " nanoseconds" << std::endl;
//     //clock_t end = clock();
//     //clock_t clockticks=end-begin;
//     //double elapsed_secs = clockticks/ double CLOCKS_PER_SEC;

//     //cout << elapsed_secs << endl;

// }