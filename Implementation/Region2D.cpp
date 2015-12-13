/******************************************************************************
 *  File: Region2D.cpp
 /******************************************************************************
 *  Purpose:  This file implements interfaces to the class Region2D defined 
 *  in the Region2D.h file and all the nested iterator classes that enable 
 *  access to components (that is, faces and cycles) of Region2D objects.

 *  Created on: Oct 8, 2015

 *  Authors: Ahmed Khaled, Revathi Kadari, Namrata Choudhury, Deepa Narain

 * Date: Fall Semester 2015
*******************************************************************************/
#include <sstream>
#include <cstring>
#include "Region2D.h"
using namespace std;

  //ConstFaceIterator structure
  struct Region2D::ConstFaceIterator::ConstFaceIteratorImplementation{
      int iteratorIndex = -1;
      Region2D::Region2DImplementation* current = NULL;     //pointer to the full structure
  };
  
  //ConstCycleIterator structure
  struct Region2D::ConstCycleIterator::ConstCycleIteratorImplementation{
      int iteratorIndex = -1;
      Region2D::Region2DImplementation* current = NULL;     //pointer to the full structure
  };

  //Region2DImplementation structure
  struct Region2D::Region2DImplementation
  {
      std::vector<AttrHalfSeg2D> segments;         //ordered set of all attributed half segments regarding the full Region2D structure   
      std::map<int, std::vector<AttrHalfSeg2D *>> cycles;
      std::map<int, std::map<int, std::vector<AttrHalfSeg2D *>>> faces;
  };
  
  //++++++++++++++++++++++++++++
  // Constructors and destructor
  //++++++++++++++++++++++++++++

  //Empty constructor. Represents the empty region object.
  Region2D::Region2D()
  {
    handle = new Region2DImplementation;
    handle->segments.clear();
    handle->faces.clear();
  }

  //Constructor for complex Region2D object. It takes
  //inputs as a vector of seg2D objects and creates a
  //Region2D object after checking if a valid Region2D
  //object can be created from the input.
  Region2D::Region2D(std::vector<Seg2D> segmentList)
  {
    handle = new Region2DImplementation;
    handle->segments.clear();
    handle->faces.clear();

    //splitting the input of segments into left and right attributed half segments
    std::vector<AttrHalfSeg2D> attrhalfsegments;
    AttrHalfSeg2D* ahl;
    AttrHalfSeg2D* ahr;
    for(int i=0;i<segmentList.size();i++)
    {
      ahl = new AttrHalfSeg2D(false, true, segmentList.at(i));
      ahr = new AttrHalfSeg2D(false, false, segmentList.at(i));
      attrhalfsegments.push_back(*ahl);
      attrhalfsegments.push_back(*ahr);
      delete ahl;
      delete ahr;
    }
	 
    //ordering the attributed half segments
    AttrHalfSeg2D swap;
    for (int c = 0 ; c < (attrhalfsegments.size()-1); c++)
    {
      for (int d = 0 ; d < (attrhalfsegments.size()-c-1); d++)
      {
        if (attrhalfsegments.at(d+1) < attrhalfsegments.at(d))
        {
	        swap = attrhalfsegments.at(d);
	        attrhalfsegments.at(d) = attrhalfsegments.at(d+1);
	        attrhalfsegments.at(d+1) = swap;
	      }
      }
    }
    
    AttrHalfSeg2D ahe;
    handle->segments.push_back(ahe);
    for (int i = 0 ; i < attrhalfsegments.size(); i++)
    {
	  if(attrhalfsegments.at(i).hseg.isLeft)
      {
	    handle->segments.push_back(attrhalfsegments.at(i));
	  }
    }
    handle->segments.push_back(ahe);
 
    
	//Grouping all the segments into cycles
    std::vector<AttrHalfSeg2D *> ce; //empty cycle 
    
    int size = handle->segments.size();
    std::vector<AttrHalfSeg2D *> currentVector;  // currentVector collects all the segments that make up the next cycle
    std::vector<AttrHalfSeg2D *> tempVector;
    int mbc = 0;
    int index = 0;
    int flags[size];
    int notCycle = 0;

    handle->cycles[mbc++] = ce;    //empty cycle created for chead
    
	//intializing vector of flags to 0
    for (int i = 1; i<size-1; i++)
    {
	    flags[i] = 0;
    }	
    
	for (int k = 1; k<size-1; k++)
    {
      if (flags[k] == 0)  // unflaged segment.
      {
		// the Kth has not been put into any cycle
	    index = 0;
	    currentVector.clear();   
	    currentVector.push_back(&handle->segments.at(k));  //segment has been allotted to a cycle
	    flags[k]=1;   // Flag set to 1
		
	    for (int i = 1; i<size-1; i++)  // all segments belonging to the current cycle are collected
        {
	      if (flags[i] == 0)   // unflaged segment.
          {
	        for ( int j = 0; j<currentVector.size(); j++)
            {       
	          if (Meet(currentVector.at(j)->hseg.seg, handle->segments.at(i).hseg.seg))
              {
	            tempVector.push_back(&handle->segments.at(i));
		        flags[i] = 1;
	          }
	        }
	        index = currentVector.size();
	        for (int c = 0; c <tempVector.size(); c++)
            {
	          currentVector.push_back(tempVector[c]);
	        }
  	        tempVector.clear();
          }
        }// inner for loop

	    if ((currentVector.at(currentVector.size()-1)->hseg.seg) == (currentVector.at(currentVector.size()-2)->hseg.seg))
	    {
		  currentVector.pop_back();  // last 2 segs are same, so last is being removed
	    }
        handle->cycles[mbc++] = currentVector;  // current cycle is being added to cycles	
      }
    }//outer for loop 

    handle->cycles[mbc++] = ce;    //empty cycle created for ctail
    
	
	//Checking if each cycle is a valid cycle
	int c;
	for (int x = 1; x<handle->cycles.size()-1; x++)
	{
	  for (int i = 0; i<handle->cycles[x].size(); i++)
      {
        c = 0;  
        for (int j = 0; j<handle->cycles[x].size(); j++)
        {
          if ( i!= j)
          {
            if (Meet (handle->cycles[x][i]->hseg.seg, handle->cycles[x][j]->hseg.seg))
			{
			  c++;
            }
          }
        } 
        if ( c == 2)  // Checking if current segment is meeting only 2 other segments present in the cycle
        {
          continue;        
        }
        else
		{
		  handle->cycles.clear();  
          handle->faces.clear();  
	      std::cout<<"REGION NOT VALID!!!!!\n";
		  break;
		}
	  } 
	} 

    //to get the min bounding rectangle coordinates for each cycle
    //Number mbrCoordinates[ handle->cycles.size()][4];

    Number** mbrCoordinates = new Number*[handle->cycles.size()];
    for(int i = 0; i < handle->cycles.size(); ++i)
      mbrCoordinates[i] = new Number[4];


    for (int i = 1; i<handle->cycles.size()-1; i++)
    {
      Number minx = Number(std::to_string(999));
	  Number(miny) = Number(std::to_string(999));
	  Number(maxx) = Number(std::to_string(-999));
	  Number(maxy) = Number(std::to_string(-999));
      for (int j = 0; j<handle->cycles.at(i).size(); j++)
      {
        if (handle->cycles[i][j]->hseg.seg.p1.x < minx)
	    {
		  minx = handle->cycles[i][j]->hseg.seg.p1.x;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p1.x > maxx)
	    {
    	  maxx = handle->cycles[i][j]->hseg.seg.p1.x;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p1.y < miny)
	    {
		  miny = handle->cycles[i][j]->hseg.seg.p1.y;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p1.y > maxy)
	    {
    	  maxy = handle->cycles[i][j]->hseg.seg.p1.y;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p2.x < minx)
	    {
		  minx = handle->cycles[i][j]->hseg.seg.p2.x;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p2.x > maxx)
	    {
    	  maxx = handle->cycles[i][j]->hseg.seg.p2.x;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p2.y < miny)
	    {
		  miny = handle->cycles[i][j]->hseg.seg.p2.y;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p2.y > maxy)
	    {
    	  maxy = handle->cycles[i][j]->hseg.seg.p2.y;
	    }
      }
      mbrCoordinates[i][0] = minx;
      mbrCoordinates[i][1] = miny;
      mbrCoordinates[i][2] = maxx;
      mbrCoordinates[i][3] = maxy;
    }
    
	
	// Grouping all cycles into faces
    std::map<int, std::vector<AttrHalfSeg2D *>> fe;
    
    size = handle->cycles.size();
    int checked[size];
	int flagy = 0;
    int faceCount = 0;
    int cycleCount = 0;

    handle->faces[faceCount++] = fe;
	
	// intializing vector of flags to 0
    for (int i = 1; i<size-1; i++)
    {
      checked[i] = 0;
    }
	
    for (int i = 1; i<size-1; i++)  // Checking if any other cycles lie inside this cycle
    {
      if (checked[i] == 0)  // If cycle hasn't already been placed in a face
      {
        for (int j = 1; j<size-1; j++)
        {
          if (i!=j)
	      {
            // if current cycle is inside cycle being compared with
            if ((mbrCoordinates[j][0] > mbrCoordinates[i][0]) && (mbrCoordinates[j][2] < mbrCoordinates[i][2]) && 
                (mbrCoordinates[j][1] > mbrCoordinates[i][1]) && (mbrCoordinates[j][3] < mbrCoordinates[i][3]))
            {
              if (checked[i] == 0)
              {
                checked[i] = 1;
                handle->faces[faceCount][cycleCount++] = handle->cycles[i];
				flagy = 1;
              }
              checked[j] = 1;
              handle->faces[faceCount][cycleCount++] = handle->cycles[j];
            }
          }
        } // inner for loop
		if (flagy ==1)
		{
		  faceCount++;
		  cycleCount = 0;
		  flagy = 0;
		}
      }   
    } // outer for loop  

	// All remaining unchecked cycles are simple faces without holes. Create seperate faces for all
    for (int i = 1; i<size-1; i++)  
	{
	  if (checked[i] == 0)
	  {
		checked[i] = 1;
        handle->faces[faceCount++][0] = handle->cycles[i]; 
	  }
	}
    
   handle->faces[faceCount++] = fe;
   delete[] mbrCoordinates;
    
	
    //To set AttrHalfSeg flags.
    //loop over face
    for( int i=1; i < handle->faces.size()-1 ; i++)
    {
    for ( int a = 0; a < handle->faces[i].size() ; a++)
    {  
      std::vector<AttrHalfSeg2D *> CycleSegs = handle->faces[i][a];    //every cycle of every face
 
      for (int j =0 ; j < CycleSegs.size() ; j++)
      {  
        if( handle->faces[i][a][j]->hseg.seg.p1.x != handle->faces[i][a][j]->hseg.seg.p2.x)
        {
		  // calculate midx and midy of the segment
          Number midx = (handle->faces[i][a][j]->hseg.seg.p1.x + handle->faces[i][a][j]->hseg.seg.p2.x)/Number(std::to_string(2)) ;
          Number midy = (handle->faces[i][a][j]->hseg.seg.p1.y + handle->faces[i][a][j]->hseg.seg.p2.y)/Number(std::to_string(2)) ;  
     
	      // create the reference line for the segment
          Poi2D P1(midx, Number(std::to_string(999)));
          Poi2D P2(midx, Number(std::to_string(-999)));         
          Seg2D refLine(P1,P2);
   
          std::vector<Number> midPoints;
          std::vector<int> meetflag;
          double countless = 0;
          double countmore = 0;
          for(int k = 0; k < CycleSegs.size() ; k++)
          { 
            if(j != k )
            {
              Seg2D S = handle->faces[i][a][k]->hseg.seg;
             
              //checking if S and the reference line are intersecting
              if(IntersectsAndNotCollinearAndNotEndpoints(refLine, S))
              {             
                midPoints.push_back((S.p1.y + S.p2.y)/Number(std::to_string(2)));
                meetflag.push_back(0);
              } 
			  //checking if S and the reference line are touching
              else if(Touch(S, refLine))
              {   
                midPoints.push_back((S.p1.y + S.p2.y)/Number(std::to_string(2)));
                meetflag.push_back(1);
              } 
            }
          }
        //make groups to filter. 
        for ( int l = 0; l < midPoints.size() ; l++ )
        { 
          // Before filtering groups and counting 
          if( midy < midPoints[l] && meetflag[l] == 0  )  
            countmore++;
           
          if ( midy > midPoints[l] && meetflag[l] == 0 )
            countless++;
            
          if ( midy < midPoints[l] && meetflag[l] == 1  )
            countmore = countmore + 0.5;  // increment by 0.5 if meet condition is true since 2 segments meet the refLine
           
          if ( midy > midPoints[l] && meetflag[l] == 1 )
            countless = countless + 0.5;
        } 
         
        if( a == 0 ) // outer cycle logic
        {         
          if ( (int)countmore % 2 != 0)
          { 
            //Region is above mid so set flag to true 
            handle->faces[i][a][j]->insideAbove = true;
          }
          else if ( (int)countless % 2 != 0 )
          { 
            //Region is below mid so set flag to false 
            handle->faces[i][a][j]->insideAbove = false;
          }
        }
        else  // inner hole logic
        {   
          if ( (int)countmore % 2 != 0)
          { 
            //Region is below mid for hole so set flag to false 
            handle->faces[i][a][j]->insideAbove = false;
          }
          else if ( (int)countless % 2 != 0 )
          { 
            //Region is above mid for hole so set flag to true 
            handle->faces[i][a][j]->insideAbove = true;
          }
        }
      }
	  
      else // Handles vertical segments condition
      {   
	    // calculate midx and midy of the segment
        Number midx = (handle->faces[i][a][j]->hseg.seg.p1.x + handle->faces[i][a][j]->hseg.seg.p2.x)/Number(std::to_string(2)) ;
        Number midy = (handle->faces[i][a][j]->hseg.seg.p1.y + handle->faces[i][a][j]->hseg.seg.p2.y)/Number(std::to_string(2)) ;  
     
	    // creates the reference line for the segment
        Poi2D P1(Number(std::to_string(999)), midy);
        Poi2D P2(Number(std::to_string(-999)), midy);
        Seg2D refLine(P1,P2);
   
        std::vector<Number> midPoints;
        std::vector<int> meetflag;
        double countless = 0;
        double countmore = 0;
        for(int k = 0; k < CycleSegs.size() ; k++)
        { 
          if(j != k )
          {
            Seg2D S = handle->faces[i][a][k]->hseg.seg;
             
			//checking if S and the reference line are intersecting
            if(IntersectsAndNotCollinearAndNotEndpoints(refLine, S))
            {             
               midPoints.push_back((S.p1.x + S.p2.x)/Number(std::to_string(2)));
               meetflag.push_back(0);
            } 
			//checking if S and the reference line are intersecting
            else if(Touch(S, refLine))
            {  
              midPoints.push_back((S.p1.x + S.p2.x)/Number(std::to_string(2)));
              meetflag.push_back(1);
            }
          }
        }

		//make groups to filter 
        for ( int l = 0; l < midPoints.size() ; l++ )
        { 
          if( midx < midPoints[l] && meetflag[l] == 0  )
            countmore++;
           
          if ( midx > midPoints[l] && meetflag[l] == 0 )
            countless++;
            
          if ( midx < midPoints[l] && meetflag[l] == 1  )
            countmore = countmore + 0.5;   // increment by 0.5 if meet condition is true since 2 segments meet the refLine
           
          if ( midx > midPoints[l] && meetflag[l] == 1 )
          {
			countless = countless + 0.5; 
          }
        }
 
        if(a == 0)
        {
          if ( (int)countmore % 2 != 0)
          { 
            // Region is to the right so set flag to false 
            handle->faces[i][a][j]->insideAbove = false;
          }
          else if ( (int)countless % 2 != 0 )
          { 
            // Region is to the left so set flag to true 
            handle->faces[i][a][j]->insideAbove = true;
          }
        }
        else
        {
          if ( (int)countmore % 2 != 0)
          { 
            // Region is to the left so set flag to true 
            handle->faces[i][a][j]->insideAbove = true;
          }
          else if ( (int)countless % 2 != 0 )
          { 
            // Region is to the right so set flag to false 
            handle->faces[i][a][j]->insideAbove = false;
          }
        }
      }
      }
    }
    }
  }
  

    // Constructor for complex region structure. It takes as input a string name that represents:
    // string that textually represents the input vector of segments.
    //
    // The grammar for representing a segment vector in both cases 1 and 2 are structured as follows:
    // Expression := '(' Segment+ ')'
    // Segment:= '(' Point ',' Point ')'
    // Point:= '(' Number ',' Number ')'
    // Number := Sign ((DigitWithoutZero Digit* '.' Digit+) | ('0' '.' Digit+ ))
    // Sign := ['+' | '-']
    // DigitWithoutZero := '1' | '2' |'3' | '4' | '5' | '6' | '7' | '8' | '9'
    // Digit:= '0' | DigitWithoutZero
    //
    // example input: "(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))"

  Region2D::Region2D(std::string textualRegionList)
  {  
    handle = new Region2DImplementation;
	handle->segments.clear();
	handle->cycles.clear();
    handle->faces.clear();
	textualRegionList.erase(std::remove(textualRegionList.begin(), textualRegionList.end(), ')'), textualRegionList.end());
	textualRegionList.erase(std::remove(textualRegionList.begin(), textualRegionList.end(), '('), textualRegionList.end());
	std::istringstream ss(textualRegionList);
	    
    vector<Seg2D> segmentList;
	std::string token;
	Number N1,N2,N3;
	int count=0;
	while(std::getline(ss, token, ','))
    {
	  if(count==0)
      {
	    count=1;
	    N1= Number(token.c_str());
	  }
      else if(count==1)
      {
	    count=2;
	    N2= Number(token.c_str());
	  }
      else if(count==2)
      {
	    count=3;
	    N3= Number(token.c_str());
	  }
      else if(count==3)
      {
	    count=0; 
	    segmentList.push_back(Seg2D(Poi2D(N1,N2),Poi2D(N3,Number(token.c_str()))));
	  }
	 }
	           
	 if(segmentList.empty())
     {
	   return;
	 }
         
    handle = new Region2DImplementation;
    handle->segments.clear();
    handle->faces.clear();

    //splitting the input of segments into left and right attributed half segments
    std::vector<AttrHalfSeg2D> attrhalfsegments;
    AttrHalfSeg2D* ahl;
    AttrHalfSeg2D* ahr;
    for(int i=0;i<segmentList.size();i++)
    {
      ahl = new AttrHalfSeg2D(false, true, segmentList.at(i));
      ahr = new AttrHalfSeg2D(false, false, segmentList.at(i));
      attrhalfsegments.push_back(*ahl);
      attrhalfsegments.push_back(*ahr);
      delete ahl;
      delete ahr;
    }
	 
    //ordering the attributed half segments
    AttrHalfSeg2D swap;
    for (int c = 0 ; c < (attrhalfsegments.size()-1); c++)
    {
      for (int d = 0 ; d < (attrhalfsegments.size()-c-1); d++)
      {
        if (attrhalfsegments.at(d+1) < attrhalfsegments.at(d))
        {
	        swap = attrhalfsegments.at(d);
	        attrhalfsegments.at(d) = attrhalfsegments.at(d+1);
	        attrhalfsegments.at(d+1) = swap;
	      }
      }
    }
    
    AttrHalfSeg2D ahe;
    handle->segments.push_back(ahe);
    for (int i = 0 ; i < attrhalfsegments.size(); i++)
    {
	  if(attrhalfsegments.at(i).hseg.isLeft)
      {
	    handle->segments.push_back(attrhalfsegments.at(i));
	  }
    }
    handle->segments.push_back(ahe);
 
    
	//Grouping all the segments into cycles
    std::vector<AttrHalfSeg2D *> ce; //empty cycle 
    
    int size = handle->segments.size();
    std::vector<AttrHalfSeg2D *> currentVector;  // currentVector collects all the segments that make up the next cycle
    std::vector<AttrHalfSeg2D *> tempVector;
    int mbc = 0;
    int index = 0;
    int flags[size];
    int notCycle = 0;

    handle->cycles[mbc++] = ce;    //empty cycle created for chead
    
	//intializing vector of flags to 0
    for (int i = 1; i<size-1; i++)
    {
	    flags[i] = 0;
    }	
    
	for (int k = 1; k<size-1; k++)
    {
      if (flags[k] == 0)  // unflaged segment.
      {
		// the Kth has not been put into any cycle
	    index = 0;
	    currentVector.clear();   
	    currentVector.push_back(&handle->segments.at(k));  //segment has been allotted to a cycle
	    flags[k]=1;   // Flag set to 1
		
	    for (int i = 1; i<size-1; i++)  // all segments belonging to the current cycle are collected
        {
	      if (flags[i] == 0)   // unflaged segment.
          {
	        for ( int j = 0; j<currentVector.size(); j++)
            {       
	          if (Meet(currentVector.at(j)->hseg.seg, handle->segments.at(i).hseg.seg))
              {
	            tempVector.push_back(&handle->segments.at(i));
		        flags[i] = 1;
	          }
	        }
	        index = currentVector.size();
	        for (int c = 0; c <tempVector.size(); c++)
            {
	          currentVector.push_back(tempVector[c]);
	        }
  	        tempVector.clear();
          }
        }// inner for loop

	    if ((currentVector.at(currentVector.size()-1)->hseg.seg) == (currentVector.at(currentVector.size()-2)->hseg.seg))
	    {
		  currentVector.pop_back();  // last 2 segs are same, so last is being removed
	    }
        handle->cycles[mbc++] = currentVector;  // current cycle is being added to cycles	
      }
    }//outer for loop 

    handle->cycles[mbc++] = ce;    //empty cycle created for ctail
    
	
	//Checking if each cycle is a valid cycle
	int c;
	for (int x = 1; x<handle->cycles.size()-1; x++)
	{
	  for (int i = 0; i<handle->cycles[x].size(); i++)
      {
        c = 0;  
        for (int j = 0; j<handle->cycles[x].size(); j++)
        {
          if ( i!= j)
          {
            if (Meet (handle->cycles[x][i]->hseg.seg, handle->cycles[x][j]->hseg.seg))
			{
			  c++;
            }
          }
        } 
        if ( c == 2)  // Checking if current segment is meeting only 2 other segments present in the cycle
        {
          continue;        
        }
        else
		{
		  handle->cycles.clear();  
          handle->faces.clear();  
	      std::cout<<"REGION NOT VALID!!!!!\n";
		  break;
		}
	  } 
	} 

    //to get the min bounding rectangle coordinates for each cycle
    //Number mbrCoordinates[ handle->cycles.size()][4];
    Number** mbrCoordinates = new Number*[handle->cycles.size()];
    for(int i = 0; i < handle->cycles.size(); ++i)
      mbrCoordinates[i] = new Number[4];

    for (int i = 1; i<handle->cycles.size()-1; i++)
    {
      Number minx = Number(std::to_string(999));
	  Number(miny) = Number(std::to_string(999));
	  Number(maxx) = Number(std::to_string(-999));
	  Number(maxy) = Number(std::to_string(-999));
      for (int j = 0; j<handle->cycles.at(i).size(); j++)
      {
        if (handle->cycles[i][j]->hseg.seg.p1.x < minx)
	    {
		  minx = handle->cycles[i][j]->hseg.seg.p1.x;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p1.x > maxx)
	    {
    	  maxx = handle->cycles[i][j]->hseg.seg.p1.x;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p1.y < miny)
	    {
		  miny = handle->cycles[i][j]->hseg.seg.p1.y;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p1.y > maxy)
	    {
    	  maxy = handle->cycles[i][j]->hseg.seg.p1.y;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p2.x < minx)
	    {
		  minx = handle->cycles[i][j]->hseg.seg.p2.x;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p2.x > maxx)
	    {
    	  maxx = handle->cycles[i][j]->hseg.seg.p2.x;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p2.y < miny)
	    {
		  miny = handle->cycles[i][j]->hseg.seg.p2.y;
	    }
	    if (handle->cycles[i][j]->hseg.seg.p2.y > maxy)
	    {
    	  maxy = handle->cycles[i][j]->hseg.seg.p2.y;
	    }
      }
      mbrCoordinates[i][0] = minx;
      mbrCoordinates[i][1] = miny;
      mbrCoordinates[i][2] = maxx;
      mbrCoordinates[i][3] = maxy;
    }
    
	
	// Grouping all cycles into faces
    std::map<int, std::vector<AttrHalfSeg2D *>> fe;
    
    size = handle->cycles.size();
    int checked[size];
	int flagy = 0;
    int faceCount = 0;
    int cycleCount = 0;

    handle->faces[faceCount++] = fe;
	
	// intializing vector of flags to 0
    for (int i = 1; i<size-1; i++)
    {
      checked[i] = 0;
    }
	
    for (int i = 1; i<size-1; i++)  // Checking if any other cycles lie inside this cycle
    {
      if (checked[i] == 0)  // If cycle hasn't already been placed in a face
      {
        for (int j = 1; j<size-1; j++)
        {
          if (i!=j)
	      {
            // if current cycle is inside cycle being compared with
            if ((mbrCoordinates[j][0] > mbrCoordinates[i][0]) && (mbrCoordinates[j][2] < mbrCoordinates[i][2]) && 
                (mbrCoordinates[j][1] > mbrCoordinates[i][1]) && (mbrCoordinates[j][3] < mbrCoordinates[i][3]))
            {
              if (checked[i] == 0)
              {
                checked[i] = 1;
                handle->faces[faceCount][cycleCount++] = handle->cycles[i];
				flagy = 1;
              }
              checked[j] = 1;
              handle->faces[faceCount][cycleCount++] = handle->cycles[j];
            }
          }
        } // inner for loop
		if (flagy ==1)
		{
		  faceCount++;
		  cycleCount = 0;
		  flagy = 0;
		}
      }   
    } // outer for loop  

	// All remaining unchecked cycles are simple faces without holes. Create seperate faces for all
    for (int i = 1; i<size-1; i++)  
	{
	  if (checked[i] == 0)
	  {
		checked[i] = 1;
        handle->faces[faceCount++][0] = handle->cycles[i]; 
	  }
	}
    
   handle->faces[faceCount++] = fe;
   delete[] mbrCoordinates;
    
	
    //To set AttrHalfSeg flags.
    //loop over face
    for( int i=1; i < handle->faces.size()-1 ; i++)
    {
    for ( int a = 0; a < handle->faces[i].size() ; a++)
    {  
      std::vector<AttrHalfSeg2D *> CycleSegs = handle->faces[i][a];    //every cycle of every face
 
      for (int j =0 ; j < CycleSegs.size() ; j++)
      {  
        if( handle->faces[i][a][j]->hseg.seg.p1.x != handle->faces[i][a][j]->hseg.seg.p2.x)
        {
		  // calculate midx and midy of the segment
          Number midx = (handle->faces[i][a][j]->hseg.seg.p1.x + handle->faces[i][a][j]->hseg.seg.p2.x)/Number(std::to_string(2)) ;
          Number midy = (handle->faces[i][a][j]->hseg.seg.p1.y + handle->faces[i][a][j]->hseg.seg.p2.y)/Number(std::to_string(2)) ;  
     
	      // create the reference line for the segment
          Poi2D P1(midx, Number(std::to_string(999)));
          Poi2D P2(midx, Number(std::to_string(-999)));         
          Seg2D refLine(P1,P2);
   
          std::vector<Number> midPoints;
          std::vector<int> meetflag;
          double countless = 0;
          double countmore = 0;
          for(int k = 0; k < CycleSegs.size() ; k++)
          { 
            if(j != k )
            {
              Seg2D S = handle->faces[i][a][k]->hseg.seg;
             
              //checking if S and the reference line are intersecting
              if(IntersectsAndNotCollinearAndNotEndpoints(refLine, S))
              {             
                midPoints.push_back((S.p1.y + S.p2.y)/Number(std::to_string(2)));
                meetflag.push_back(0);
              } 
			  //checking if S and the reference line are touching
              else if(Touch(S, refLine))
              {   
                midPoints.push_back((S.p1.y + S.p2.y)/Number(std::to_string(2)));
                meetflag.push_back(1);
              } 
            }
          }
        //make groups to filter. 
        for ( int l = 0; l < midPoints.size() ; l++ )
        { 
          // Before filtering groups and counting 
          if( midy < midPoints[l] && meetflag[l] == 0  )  
            countmore++;
           
          if ( midy > midPoints[l] && meetflag[l] == 0 )
            countless++;
            
          if ( midy < midPoints[l] && meetflag[l] == 1  )
            countmore = countmore + 0.5;  // increment by 0.5 if meet condition is true since 2 segments meet the refLine
           
          if ( midy > midPoints[l] && meetflag[l] == 1 )
            countless = countless + 0.5;
        } 
         
        if( a == 0 ) // outer cycle logic
        {         
          if ( (int)countmore % 2 != 0)
          { 
            //Region is above mid so set flag to true 
            handle->faces[i][a][j]->insideAbove = true;
          }
          else if ( (int)countless % 2 != 0 )
          { 
            //Region is below mid so set flag to false 
            handle->faces[i][a][j]->insideAbove = false;
          }
        }
        else  // inner hole logic
        {   
          if ( (int)countmore % 2 != 0)
          { 
            //Region is below mid for hole so set flag to false 
            handle->faces[i][a][j]->insideAbove = false;
          }
          else if ( (int)countless % 2 != 0 )
          { 
            //Region is above mid for hole so set flag to true 
            handle->faces[i][a][j]->insideAbove = true;
          }
        }
      }
	  
      else // Handles vertical segments condition
      {   
	    // calculate midx and midy of the segment
        Number midx = (handle->faces[i][a][j]->hseg.seg.p1.x + handle->faces[i][a][j]->hseg.seg.p2.x)/Number(std::to_string(2)) ;
        Number midy = (handle->faces[i][a][j]->hseg.seg.p1.y + handle->faces[i][a][j]->hseg.seg.p2.y)/Number(std::to_string(2)) ;  
     
	    // creates the reference line for the segment
        Poi2D P1(Number(std::to_string(999)), midy);
        Poi2D P2(Number(std::to_string(-999)), midy);
        Seg2D refLine(P1,P2);
   
        std::vector<Number> midPoints;
        std::vector<int> meetflag;
        double countless = 0;
        double countmore = 0;
        for(int k = 0; k < CycleSegs.size() ; k++)
        { 
          if(j != k )
          {
            Seg2D S = handle->faces[i][a][k]->hseg.seg;
             
			//checking if S and the reference line are intersecting
            if(IntersectsAndNotCollinearAndNotEndpoints(refLine, S))
            {             
               midPoints.push_back((S.p1.x + S.p2.x)/Number(std::to_string(2)));
               meetflag.push_back(0);
            } 
			//checking if S and the reference line are intersecting
            else if(Touch(S, refLine))
            {  
              midPoints.push_back((S.p1.x + S.p2.x)/Number(std::to_string(2)));
              meetflag.push_back(1);
            }
          }
        }

		//make groups to filter 
        for ( int l = 0; l < midPoints.size() ; l++ )
        { 
          if( midx < midPoints[l] && meetflag[l] == 0  )
            countmore++;
           
          if ( midx > midPoints[l] && meetflag[l] == 0 )
            countless++;
            
          if ( midx < midPoints[l] && meetflag[l] == 1  )
            countmore = countmore + 0.5;   // increment by 0.5 if meet condition is true since 2 segments meet the refLine
           
          if ( midx > midPoints[l] && meetflag[l] == 1 )
          {
			countless = countless + 0.5; 
          }
        }
 
        if(a == 0)
        {
          if ( (int)countmore % 2 != 0)
          { 
            // Region is to the right so set flag to false 
            handle->faces[i][a][j]->insideAbove = false;
          }
          else if ( (int)countless % 2 != 0 )
          { 
            // Region is to the left so set flag to true 
            handle->faces[i][a][j]->insideAbove = true;
          }
        }
        else
        {
          if ( (int)countmore % 2 != 0)
          { 
            // Region is to the left so set flag to true 
            handle->faces[i][a][j]->insideAbove = true;
          }
          else if ( (int)countless % 2 != 0 )
          { 
            // Region is to the right so set flag to false 
            handle->faces[i][a][j]->insideAbove = false;
          }
        }
      }
      }
    }
    }
   }

  //copy constructor that constructs a new Region2D object with the same 
  //properties as the inputted Region2D object.
  Region2D::Region2D(Region2D& source) 
   { 
     
    handle = new Region2DImplementation;
    handle->segments.clear();
    handle->faces.clear();
    std::copy(source.handle->segments.begin(), source.handle->segments.end(),std::back_inserter(handle->segments));
    std::copy(source.handle->cycles.begin(), source.handle->cycles.end(), std::inserter(handle->cycles,handle->cycles.end()) );
    std::copy(source.handle->faces.begin(), source.handle->faces.end(), std::inserter(handle->faces,handle->faces.end()) );

   }

   // Move constructor that moves a given Region2D object "source" to a
   // Region2D object. The Region2D object "source" gets the empty Region2D
   // object as its value.
  Region2D::Region2D(Region2D&& source)
  {
    
    handle = new Region2DImplementation;
    handle->segments.clear();
    handle->faces.clear();
    std::move(source.handle->segments.begin(), source.handle->segments.end(),std::back_inserter(handle->segments));
    std::move(source.handle->cycles.begin(), source.handle->cycles.end(), std::inserter(handle->cycles,handle->cycles.end()) );
    std::move(source.handle->faces.begin(), source.handle->faces.end(), std::inserter(handle->faces,handle->faces.end()) );


  }

  //Destructor
  Region2D::~Region2D()
  {
    delete handle;
  }

  //+++++++++++++++++++++
  // Assignment operators
  //+++++++++++++++++++++

  //copy assignment operator that copies the inputted object
  //to the Region2D object
  Region2D& Region2D::operator = (Region2D& source)
  {
    handle = new Region2DImplementation;
    handle->segments.clear();
    handle->faces.clear();
    std::copy(source.handle->segments.begin(), source.handle->segments.end(),std::back_inserter(handle->segments));
    std::copy(source.handle->cycles.begin(), source.handle->cycles.end(), std::inserter(handle->cycles,handle->cycles.end()) );
    std::copy(source.handle->faces.begin(), source.handle->faces.end(), std::inserter(handle->faces,handle->faces.end()) );
 
  }

  // Move assignment operator that moves the inputted Region2D object to the
  // Region2D object. The inputted object gets the empty Region2D
  // object as its value.
  Region2D& Region2D::operator = (Region2D&& source)
  {
    handle = new Region2DImplementation;
    handle->segments.clear();
    handle->faces.clear();
    std::move(source.handle->segments.begin(), source.handle->segments.end(),std::back_inserter(handle->segments));
    std::move(source.handle->cycles.begin(), source.handle->cycles.end(), std::inserter(handle->cycles,handle->cycles.end()) );
    std::move(source.handle->faces.begin(), source.handle->faces.end(), std::inserter(handle->faces,handle->faces.end()) );

  }

  //+++++++++++++++++++++
  // Comparison operators
  //+++++++++++++++++++++

  //equal operator that checks if the Region2D object and inputted Region2D
  //object are the same spatial region.
  bool Region2D::operator == (Region2D& operand)
  {
               if(handle->faces.size() != operand.handle->faces.size())  
		  return false;
		for (unsigned i=0; i < handle->faces.size(); i++){
		  if(handle->faces.at(i) != operand.handle->faces.at(i))
			return false;
		}
		return true;
  }

  //unequal operator that checks if the Region2D object and the inputted
  //Region2D object are different spatial regions. It is the logical opposite
  //of the == operator.
  bool Region2D::operator != (Region2D& operand)
  {
    		if(handle->faces.size() != operand.handle->faces.size())  
		  return true;
		for (unsigned i=0; i < handle->faces.size(); i++){
		  if(handle->faces.at(i) != operand.handle->faces.at(i))
		     return true;
		}
		return false;
  }

  // less than operator that compares 2 Region2D objects through comparing their sorted attributed half segments in lexicographic order.
  // Eg: Region1(((0,0),(1,1)),((0,0),(2,0)),((1,1),(2,0))) < Region2(((5,5),(6,6)),((5,5),(7,5)),((6,6),(7,5))) returns true since 
  // ((0,0),(1,1)) < ((5,5),(6,6))
  bool Region2D::operator < (Region2D& operand)
  {
   if(isEmptyRegion2D() || operand.isEmptyRegion2D()) 
		return false;
	  int x = (handle->segments.size() < operand.handle->segments.size()) ? handle->segments.size() : operand.handle->segments.size();
      for (unsigned i=1; i < x; i++) {
	    if (handle->segments.at(i) < operand.handle->segments.at(i))
	      return true;
	    else if (handle->segments.at(i) > operand.handle->segments.at(i))
	      return false;
	    else
	      continue;
	  }
	  if (handle->segments.size() < operand.handle->segments.size())   
	    return true;
	  return false;
  }
    
  // less than or equal operator that compares 2 Region2D objects through comparing their sorted attributed half segments in lexicographic 
  //order. Eg: Region1(((0,0),(1,1)),((0,0),(2,0)),((1,1),(2,0))) <= Region2(((5,5),(6,6)),((5,5),(7,5)),((6,6),(7,5))) returns true since 
  // ((0,0),(1,1)) <= ((5,5),(6,6))
  bool Region2D::operator <= (Region2D& operand)
  {
    if(isEmptyRegion2D() || operand.isEmptyRegion2D()) 
		return false;
	  int x = (handle->segments.size() < operand.handle->segments.size()) ? handle->segments.size() : operand.handle->segments.size();
      for (unsigned i=1; i < x; i++) {
	    if (handle->segments.at(i) < operand.handle->segments.at(i) || handle->segments.at(i) == operand.handle->segments.at(i))
	      return true;
	    else if (handle->segments.at(i) > operand.handle->segments.at(i))
	      return false;
	    else
	      continue;
	  }
	  if (handle->segments.size() <= operand.handle->segments.size())   
	    return true;
	  return false;
  
  }
    
  // greater than operator that compares 2 Region2D objects through comparing their sorted attributed half segments in lexicographic order.
  // Eg: Region1(((0,0),(1,1)),((0,0),(2,0)),((1,1),(2,0))) > Region2(((5,5),(6,6)),((5,5),(7,5)),((6,6),(7,5))) returns false since 
  // ((0,0),(1,1)) < ((5,5),(6,6)).
  bool Region2D::operator > (Region2D& operand)
  { 
    if(isEmptyRegion2D() || operand.isEmptyRegion2D()) 
		return false;
	  int x = (handle->segments.size()  < operand.handle->segments.size()) ? handle->segments.size() : operand.handle->segments.size();
      for (unsigned i=1; i < x; i++) {
	    if (handle->segments.at(i) > operand.handle->segments.at(i))
	      return true;
	    else if (handle->segments.at(i) < operand.handle->segments.at(i))
	      return false;
	    else
	      continue;
	  }
	  if (handle->segments.size() > operand.handle->segments.size())   
	    return true;
	  return false;
  
  }
    
  // greater than or equal operator that compares 2 Region2D objects through comparing their sorted attributed half segments in lexicographic 
  //order. Eg: Region1(((0,0),(1,1)),((0,0),(2,0)),((1,1),(2,0))) >= Region2(((5,5),(6,6)),((5,5),(7,5)),((6,6),(7,5))) returns false since 
  // ((0,0),(1,1)) <= ((5,5),(6,6))
  bool Region2D::operator >= (Region2D& operand)
  {   
      if(isEmptyRegion2D() || operand.isEmptyRegion2D()) 
		return false;
	  int x = (handle->segments.size()  < operand.handle->segments.size()) ? handle->segments.size() : operand.handle->segments.size();
      for (unsigned i=1; i < x; i++) {
            
	    if (handle->segments.at(i) > operand.handle->segments.at(i) || handle->segments.at(i) == operand.handle->segments.at(i) )
	      return true;
	    else if (handle->segments.at(i) < operand.handle->segments.at(i))
	      return false;
	    else
	      continue;
	  }
	  if (handle->segments.size() >= operand.handle->segments.size())   
	    return true;
	  return false;
  }

  //++++++++++++++++++++++++++++++++
  // Unary predicates and operations
  //++++++++++++++++++++++++++++++++

  // Predicate that checks whether the inputted Region2D object is an 
  //empty Region2D object.
  bool Region2D::isEmptyRegion2D() const
  {
    if((handle->segments.size() == 0)||(handle->segments.size() == 2))
	        return true;
		return false;       
  }

  // Predicate that checks whether the inputted Region2D object is a simple Region2D
  // object, that is, a single-component Region2D object without holes. The
  // predicate yields false for an empty Region2D object.
  bool Region2D::isSimpleRegion2D()
  {
   if((handle->faces.size() == 1)||(handle->faces.size() == 3))
     if((handle->cycles.size() == 1)||(handle->cycles.size() == 3))
	        return true;
		
		return false;
  }

  // Predicate that checks whether the inputted Region2D object is a simple (that is,
  // single-component) Region2D object with at least one hole. The predicate
  // yields false for an empty Region2D object.
  bool Region2D::isSimpleRegion2DWithHoles()
  {   
    if((handle->faces.size() == 1)||(handle->faces.size() == 3))
     if((handle->cycles.size() > 3))
	        return true;
		
		return false;
  }

  // Predicate that checks whether the inputted Region2D object is a face object, that
  // is, a single-component Region2D object with or without holes. The
  // predicate yields false for an empty Region2D object.
  bool Region2D::isFace()
  { 
    if(isSimpleRegion2D() || isSimpleRegion2DWithHoles() )
      return true;
      return false;
  }

  // Method that yields the number of faces of the inputted Region2D object. The
  // number of faces of an empty Region2D object is 0.
  Number Region2D::getNumberOfFaces()
  {   
     if(isEmptyRegion2D()) 
        return Number(std::to_string(0));
     return(Number(std::to_string(handle->faces.size()-2)));
  }

  // Method that yields the number of hole cycles of a face, which is
  // represented as a simple Region2D object with or without holes. If the
  // Region2D object is a multi-component object, that is, has more than one
  // face, the value -1 is returned. Otherwise, if the face does not contain
  // holes, the value 0 is returned. If the face is an empty Region2D object,
  // the value -2 is returned.
  Number Region2D::getNumberOfHoleCycles()
  { 
    if(isEmptyRegion2D()) 
        return Number(std::to_string(-2));
    if(isSimpleRegion2D())
       return(Number(std::to_string(handle->cycles.size()-3))); //minus head,tail,outer cycle
    else
      return Number(std::to_string(-1)); 
  }

  // Method that yields the number of segments of a cycle (outer cycle or
  // hole cycle), which is represented as a simple Region2D object (without
  // holes). If the Region2D object is an empty Region2D object, the value
  // -2 is returned. If the Region2D object is not simple, the value -1 is
  // returned.
  Number Region2D::getNumberOfSegments()
  {
     if(isEmptyRegion2D()) 
        return Number(std::to_string(-2));
     if(isSimpleRegion2D())
       return(Number(std::to_string(handle->segments.size()-3)));
     else
      return Number(std::to_string(-1));
  }

  // Method that returns the outer cycle of a face, which is a simple
  // Region2D object with or without holes. If the Region2D is complex, that
  // is, has multiple faces, the empty Region2D object is returned. If the
  // Region2D object is simple and thus has no holes, then a copy of the
  // object is returned. Otherwise, the outer cycle is determined and
  // returned.
  Region2D Region2D::getOuterCycle()
  { 
    std::vector<Seg2D> Segs; 
   
    if(isFace()) 
     { for ( int i = 0; i < handle->faces[1][0].size(); i++)
       {
          Segs.push_back(handle->faces[1][0][i]->hseg.seg);
       }
       return(Region2D(Segs));
     }
    else 
      return(Region2D());
   
  }

  //++++++++++++++++
  // Output function
  //++++++++++++++++

  // Textual output of segments of a Region2D object
  std::ostream& operator << (std::ostream& os, const Region2D& output)
  {
    int numberOfFaces = output.handle->faces.size();
    
    if (numberOfFaces == 0 )
    { 
       cout << " Region is Empty! \n " ;
       return os;
    }
    std::cout<<"numberOfFaces is: "<<numberOfFaces-2<<std::endl;
	
    for(int i = 1; i < numberOfFaces-1; i++)
    { 
      std::cout<<"Printing number of cycles in face "<<i<<":";
	  std::cout<<output.handle->faces[i].size()<<std::endl;
	  for (int j = 0; j<output.handle->faces[i].size(); j++)
	  {
		  for (int k = 0; k<output.handle->faces[i][j].size(); k++)
		  {
			  std::cout<<*output.handle->faces[i][j][k]<<std::endl;
		  }
	  }
    } 
    return os;
  }

  //++++++++++++++++++++
  // Iterator functions
  //++++++++++++++++++++

  // Default constructor that creates an empty constant face iterator.
  Region2D::ConstFaceIterator::ConstFaceIterator()
  {
   handlei = new ConstFaceIteratorImplementation;
   handlei->iteratorIndex = -1;
   handlei->current = NULL;
  }

  // Copy constructor that constructs a constant face iterator from a
  // given constant face iterator "source".
  Region2D::ConstFaceIterator::ConstFaceIterator(const ConstFaceIterator& source)
  {
   handlei = new ConstFaceIteratorImplementation;
   handlei->iteratorIndex = source.handlei->iteratorIndex;
   handlei->current = source.handlei->current;
  }

  // Move constructor that moves a given constant face iterator "source"
  // to a constant face iterator. The constant face iterator "source"
  // gets the empty constant face iterator as its value.
  Region2D::ConstFaceIterator::ConstFaceIterator(const ConstFaceIterator&& source)
  { 
   handlei = new ConstFaceIteratorImplementation;
   handlei->iteratorIndex = std::move(source.handlei->iteratorIndex);
   handlei->current = std::move(source.handlei->current);
  }

  // Destructor that frees the main memory space allocated for a constant
  // face iterator.
  Region2D::ConstFaceIterator::~ConstFaceIterator()
  {
   delete handlei;
  }


  // Assignment operator that assigns another constant face iterator
  // "rhs" to the constant face iterator.
  Region2D::ConstFaceIterator& Region2D::ConstFaceIterator::operator = (const ConstFaceIterator& rhs)
  {
   handlei->iteratorIndex = rhs.handlei->iteratorIndex; 
   handlei->current = rhs.handlei->current;
  }

  // Predicate that tests whether a constant face iterator is empty.
  bool Region2D::ConstFaceIterator::isEmpty() const
  {
   return (handlei->current == NULL);
  }

  // Increment/decrement operators '++', '--'
  Region2D::ConstFaceIterator& Region2D::ConstFaceIterator::operator ++ () //prefix
  {
   handlei->iteratorIndex++;
   return(*this);
  }

  Region2D::ConstFaceIterator Region2D::ConstFaceIterator::operator ++ (int postfix) //postfix
  {
   ConstFaceIterator tmp(*this);
   handlei->iteratorIndex++;
   return(tmp);
  }

  Region2D::ConstFaceIterator& Region2D::ConstFaceIterator::operator -- ()   // prefix
  {
   handlei->iteratorIndex--;
   return(*this);
  }

  Region2D::ConstFaceIterator Region2D::ConstFaceIterator::operator -- (int postfix) // postfix
  {
   ConstFaceIterator tmp(*this);
   handlei->iteratorIndex--;
   return(tmp);
  }

  // Dereferencing operators that return the value at the constant face
  // iterator position. Dereferencing is only allowed if the iterator
  // points to a face. The dereferenced value cannot be changed.
  const Region2D Region2D::ConstFaceIterator::operator *() const
  { 
   int i = this->handlei->iteratorIndex;
   std::vector<Seg2D> Segs1;
   
   for( int k = 0; k < this->handlei->current->faces[i].size(); k++)
    
      for ( int l = 0; l < this->handlei->current->faces[i][k].size(); l++)
       {
          Segs1.push_back(this->handlei->current->faces[i][k][l]->hseg.seg);
       }
   return(Region2D(Segs1)); 
  }

  const Region2D Region2D::ConstFaceIterator::operator ->() const
  {  
    int i = this->handlei->iteratorIndex;
   std::vector<Seg2D> Segs2;
   
   for( int k = 0; k < this->handlei->current->faces[i].size(); k++)
    
      for ( int l = 0; l < this->handlei->current->faces[i][k].size(); l++)
       {
          Segs2.push_back(this->handlei->current->faces[i][k][l]->hseg.seg);
       }
   return(Region2D(Segs2)); 
  }

  // Comparison operators that compare a constant face iterator position
  // with another const face iterator position "rhs"
  bool Region2D::ConstFaceIterator::operator == (const ConstFaceIterator& rhs) const
  {
    return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex == rhs.handlei->iteratorIndex));
  }

  bool Region2D::ConstFaceIterator::operator != (const ConstFaceIterator& rhs) const
  {
   return ((this->handlei->current != rhs.handlei->current)||(this->handlei->iteratorIndex != rhs.handlei->iteratorIndex));
  }

  bool Region2D::ConstFaceIterator::operator <  (const ConstFaceIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex < rhs.handlei->iteratorIndex));
  }

  bool Region2D::ConstFaceIterator::operator <= (const ConstFaceIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex <= rhs.handlei->iteratorIndex));
  }

  bool Region2D::ConstFaceIterator::operator >  (const ConstFaceIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex > rhs.handlei->iteratorIndex));
  }

  bool Region2D::ConstFaceIterator::operator >= (const ConstFaceIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex >= rhs.handlei->iteratorIndex));
  }
  

   std::ostream&operator<<(std::ostream& os, const Region2D::ConstFaceIterator& output)
   {
      os << "index Value:" << output.handlei->iteratorIndex<<" ";
      os << "number of cycles in face:" << output.handlei->current->faces.at(output.handlei->iteratorIndex).size()<<" "<<endl;
      for(int x=0;x<output.handlei->current->faces.at(output.handlei->iteratorIndex).size();x++)
        { 
        for(int y=0;y<output.handlei->current->faces[output.handlei->iteratorIndex][x].size();y++)
	 os << "segments" << *output.handlei->current->faces[output.handlei->iteratorIndex][x][y]<<" "<<endl;
	}
      return os;
   }
  // Method that returns a constant face iterator to the first face of a
  // Region2D object.
  Region2D::ConstFaceIterator Region2D::cFbegin() const
  {
   ConstFaceIterator begin;
   begin.handlei->iteratorIndex = 1;
   begin.handlei->current = handle;
   return begin;
  }

  // Method that returns a constant face iterator to the last face of a
  // Region2D object.
  Region2D::ConstFaceIterator Region2D::cFend() const
  {
   ConstFaceIterator begin;
   begin.handlei->iteratorIndex = handle->faces.size()-2;
   begin.handlei->current = handle;
   return begin;
  }

  // Method that returns a constant face iterator to the position before the
  // first face of a Region2D object. Note that dereferencing this iterator
  // yields the empty constant face iterator.
  Region2D::ConstFaceIterator Region2D::cFhead() const  
  {
   ConstFaceIterator begin;
   begin.handlei->iteratorIndex = 0;
   begin.handlei->current = handle;
   return begin;
  }

  // Method that returns a constant face iterator to the position after the
  // last face of a Region2D object. Note that dereferencing this iterator
  // yields the empty constant face iterator.
  Region2D::ConstFaceIterator Region2D::cFtail() const
  {
   ConstFaceIterator begin;
   begin.handlei->iteratorIndex = handle->faces.size()-1;
   begin.handlei->current = handle;
   return begin;
  }


  // Default constructor that creates an empty constant cycle iterator.
  Region2D::ConstCycleIterator::ConstCycleIterator()
  {
   handlei = new ConstCycleIteratorImplementation;
   handlei->iteratorIndex = -1;
   handlei->current = NULL;
  }

  // Copy constructor that constructs a constant cycle iterator from a
  // given constant cycle iterator "source".
  Region2D::ConstCycleIterator::ConstCycleIterator(const ConstCycleIterator& source)
  {
   handlei = new ConstCycleIteratorImplementation;
   handlei->iteratorIndex = source.handlei->iteratorIndex;
   handlei->current = source.handlei->current;
  }

  // Move constructor that moves a given constant cycle iterator "source"
  // to a constant  cycle iterator. The constant  cycle iterator "source"
  // gets the empty constant cycle iterator as its value.
  Region2D::ConstCycleIterator::ConstCycleIterator(const ConstCycleIterator&& source)
  {
   handlei = new ConstCycleIteratorImplementation;
   handlei->iteratorIndex = std::move(source.handlei->iteratorIndex);
   handlei->current = std::move(source.handlei->current);
  }

  // Destructor that frees the main memory space allocated for a constant
  // cycle iterator.
  Region2D::ConstCycleIterator::~ConstCycleIterator()
  {
   delete handlei;
  }

  // Assignment operator that assigns another constant cycle iterator
  // "rhs" to the constant face iterator.
  Region2D::ConstCycleIterator& Region2D::ConstCycleIterator::operator = (const ConstCycleIterator& rhs)
  {
    handlei->iteratorIndex = rhs.handlei->iteratorIndex; 
    handlei->current = rhs.handlei->current; 
  }

  // Predicate that tests whether a constant Cycle iterator is empty.
  bool Region2D::ConstCycleIterator::isEmpty() const
  {
   return (handlei->current == NULL);   
  }

  // Increment/decrement operators '++', '--'
  Region2D::ConstCycleIterator& Region2D::ConstCycleIterator::operator ++ ()  // prefix
  {
    handlei->iteratorIndex++;
    return(*this);
  }

  Region2D::ConstCycleIterator Region2D::ConstCycleIterator::operator ++ (int postfix) // postfix
  {
    ConstCycleIterator tmp(*this);
    handlei->iteratorIndex++;
    return(tmp);
  }

  Region2D::ConstCycleIterator& Region2D::ConstCycleIterator::operator -- ()   // prefix
  {
    handlei->iteratorIndex--;
    return(*this);
  }

  Region2D::ConstCycleIterator Region2D::ConstCycleIterator::operator -- (int postfix) // postfix
  {
    ConstCycleIterator tmp(*this);
    handlei->iteratorIndex--;
    return(tmp);
  }

  // Dereferencing operators that return the value at the constant Cycle
  // iterator position. Dereferencing is only allowed if the iterator
  // points to a cycle. The dereferenced value cannot be changed.
  const Region2D Region2D::ConstCycleIterator::operator *() const
  {
   
   int i = this->handlei->iteratorIndex;
   std::vector<Seg2D> newSegs1;
   for ( int j = 0; j < this->handlei->current->cycles[i].size(); j++)
   {
     newSegs1.push_back(this->handlei->current->cycles[i][j]->hseg.seg);
   }
   return(Region2D(newSegs1)); 
   
  }
  

  const Region2D Region2D::ConstCycleIterator::operator ->() const
  { 
   int i = this->handlei->iteratorIndex;
   std::vector<Seg2D> newSegs2;
   for ( int j = 0; j < this->handlei->current->cycles[i].size(); j++)
   {
     newSegs2.push_back(this->handlei->current->cycles[i][j]->hseg.seg);
   }
   return(Region2D(newSegs2));
    
   }

  // Comparison operators that compare a constant Cycle iterator position
  // with another const Cycle iterator position "rhs"
  bool Region2D::ConstCycleIterator::operator == (const ConstCycleIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex == rhs.handlei->iteratorIndex));
  }

  bool Region2D::ConstCycleIterator::operator != (const ConstCycleIterator& rhs) const
  {
   return ((this->handlei->current != rhs.handlei->current)||(this->handlei->iteratorIndex != rhs.handlei->iteratorIndex));
  }

  bool Region2D::ConstCycleIterator::operator <  (const ConstCycleIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex < rhs.handlei->iteratorIndex));
  }

  bool Region2D::ConstCycleIterator::operator <= (const ConstCycleIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex <= rhs.handlei->iteratorIndex));
  }

  bool Region2D::ConstCycleIterator::operator >  (const ConstCycleIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex > rhs.handlei->iteratorIndex));
  }

  bool Region2D::ConstCycleIterator::operator >= (const ConstCycleIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex >= rhs.handlei->iteratorIndex));
  }

  std::ostream&operator<<(std::ostream& os, const Region2D::ConstCycleIterator& output)
   {
      os << "index Value:" << output.handlei->iteratorIndex<<" ";
      os << "number of segments in cycle:" << output.handlei->current->cycles.at(output.handlei->iteratorIndex).size()<<" "<<endl;
      for(int x=0;x<output.handlei->current->cycles.at(output.handlei->iteratorIndex).size();x++)
        { 
	 os << "segments" << *output.handlei->current->cycles[output.handlei->iteratorIndex][x]<<" "<<endl;
	}
      return os;
   }

  // Method that returns a constant Cycle iterator to the first Cycle of a
  // Region2D object.
  Region2D::ConstCycleIterator Region2D::cHbegin() const
  {
    ConstCycleIterator begin;
    begin.handlei->iteratorIndex = 1;
    begin.handlei->current = handle;
    return begin;
  }

  // Method that returns a constant Cycle iterator to the last Cycle of a
  // Region2D object.
  Region2D::ConstCycleIterator Region2D::cHend() const
  {
    ConstCycleIterator last;
    last.handlei->iteratorIndex = handle->cycles.size()-2;
    last.handlei->current = handle;
    return last;
  }


  // Method that returns a constant Cycle iterator to the position before the
  // first Cycle of a Region2D object. Note that dereferencing this iterator
  // yields the empty constant Cycle iterator.
  Region2D::ConstCycleIterator Region2D::cHhead() const
  {
     ConstCycleIterator h;
     h.handlei->iteratorIndex = 0;
     h.handlei->current = handle;
     return h;
  }

  // Method that returns a constant Cycle iterator to the position after the
  // last Cycle of a Region2D object. Note that dereferencing this iterator
  // yields the empty constant Cycle iterator.
  Region2D::ConstCycleIterator Region2D::cHtail() const
  {
     ConstCycleIterator t;
     t.handlei->iteratorIndex = handle->cycles.size()-1; //segments.size replace by no.ofcycles method?
     t.handlei->current = handle;
     return t;
  }

