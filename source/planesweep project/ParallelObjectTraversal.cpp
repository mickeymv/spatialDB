//
// Created by Djundi on 11/3/15.
//



#include "ParallelObjectTraversal.h"

// *** begin test temp
using namespace std;
#include <iostream>
// *** end test temp




ParallelObjectTraversal::ParallelObjectTraversal(Object2D &F, Object2D &G) {

    // 11/04/2015 DT
    // note that for the symmetrical object combination, only one instance is created, but the passing of the object is swapped accordingly
    if (F.isPoint2D()) {
            objF = Point2D(F);
            objFIterator = ConstPoiIterator(F);
        if (G.isPoint2D()) {
            ExplorePoint2DPoint2D(F, G);

            objG = Point2D(G);
            objGIterator = ConstPoiIterator(G);
            
        } else if (G.isLine2D()) {
            ExplorePoint2DLine2D(F, G);

            objG = Line2D(G);
            objGIterator = ConstLineIterator(G);
            
        } else if (G.isRegion2D()) {
            ExplorePoint2DRegion2D(F, G);
			objG = Region2D(G);
            objGIterator = ConstRegionIterator(G); 
                   }
    } else
    if (F.isLine2D()) {
    		objF = Line2D(F);
            objFIterator = ConstLineIterator(F);
            
        if (G.isPoint2D()) {
            // swap parameters because it is symmetrical
            ExplorePoint2DLine2D(G, F);

            objG = Point2D(G);
            objGIterator = ConstPoiIterator(G);
            
        } else if (G.isLine2D()) {
            ExploreLine2DLine2D(F, G);
            objG = Line2D(G);
            objGIterator = ConstLine2DIterator(G);

        } else if (G.isRegion2D()) {
            ExploreLine2DRegion2D(F, G);
			objG = Region2D(G);
            objGIterator = ConstRegionIterator(G);          }
    } else
    if (F.isRegion2D()) {
    	objF = Region2D(F);
        objFIterator = ConstRegionIterator(F);
            
        if (G.isPoint2D()) {
            // swap parameters because it is symmetrical
            ExplorePoint2DRegion2D(G, F);
            objG = Point2D(G);
            objGIterator = ConstPoiIterator(G);

        } else if (G.isLine2D()) {
            // swap parameters because it is symmetrical
            ExploreLine2DRegion2D(G, F);
            objG = Line2D(G);
            objGIterator = ConstLine2DIterator(G);

        } else if (G.isRegion2D()) {

            rr = new POT_Region2DRegion2D(F, G);
            vF = rr->getVF();
            vG = rr->getVG();
            sizeofvFG = rr->getVFGSize();
			objG = Region2D(G);
            objGIterator = ConstRegionIterator(G);

        }
    }


	//Call the selectFirst function to initialize the object and status variables.
	selectFirst();

}

ParallelObjectTraversal::~ParallelObjectTraversal() {
    if (pp) delete pp;
    if (pl) delete pl;
    if (pr) delete pr;
    if (ll) delete ll;
    if (lr) delete lr;
    if (rr) delete rr;

}


     object getObject() {
     	return object;
     }
     
     status getStatus(){
     	return status;
     }
    
void selectFirst() 
{
	if (!(objFIterator->isEmpty())
    {
		objFIterator = objF->cbegin();
	}
	if (!(objGIterator->isEmpty())
    {
			objGIterator = objG->cbegin();
	}
	
	if (objFIterator->isEmpty() && objGIterator->isEmpty()) 
	{
	    object = NONE;
		status = END_OF_BOTH;
	} 
	else 
	{
		if (objGIterator->isEmpty())
			object = FIRST;
		else if (objFIterator->isEmpty())
			object = SECOND;
		else
			object = BOTH;

		if(objFIterator->getCurrent() == objFIterator->cend() 
     		&& objGIterator->getCurrent() == objGIterator->cend())
		    status = END_OF_BOTH;
	    else if(objFIterator->getCurrent() == objFIterator->cend())
		    status = END_OF_FIRST;
	    else if (objGIterator->getCurrent() == objGIterator->cend())
            status = END_OF_SECOND;            
	    else
		    status = END_OF_NONE;
    }
	
    
}
    
    
      
    void selectNext() {

      // increments the iterators for objects F and G
      // depending on the value of 'object' variable
       
      if (object == BOTH) {
       	objFIterator++;
       	objGIterator++;
      } else if (object == FIRST) {
      	objFIterator++;
      } else if (object == SECOND) {
      	objGIterator++;
      } else if (object == NONE) {
      // Because if both objects elements are over, don't update object and 
      // status variables or object pointers.
      	return;
      }
      
      
    if (objFIterator->getCurrent() == objF->cend()) {
        if (objGIterator->getCurrent() == objG->cend())
        {
            status = END_OF_BOTH;
        }
        else {
         status = END_OF_FIRST;
         }
    } else if (objGIterator->getCurrent() == objG->cend()) {
            status = END_OF_SECOND;
    } else 
     {
     	status = END_OF_NONE;
     }
  
    
        if (objFIterator->.getCurrent() == objF->ctail() && objGIterator->getCurrent() == objG->ctail())
    	{
    		object = NONE;	
    	} else if (objFIterator->getCurrent() == objGIterator->getCurrent())
    	{
        	object = BOTH;
        } else if (objFIterator->getCurrent() < objGIterator->getCurrent()) 
        {
        	object = FIRST;
        } else if (objFIterator->getCurrent() > objGIterator->getCurrent())
    	{
    		object = SECOND;	
    	}
   

    
      }

const bool *ParallelObjectTraversal::getVF() {
    return vF;
}

// get vector array vG
const bool *ParallelObjectTraversal::getVG() {
    return vG;
}

// returns the size of vector F (or vector G, they both have the same size)
const size_t ParallelObjectTraversal::getVFGSize() {
    return sizeofvFG;
}


bool ParallelObjectTraversal::ExplorePoint2DPoint2D(Object2D &F, Object2D &G) {
    // create new instance
    pp = new POT_Point2DPoint2D(F, G);

    // set vF and vG
    vF = pp->getVF();
    vG = pp->getVG();

    // set size of vF (and vG)
    sizeofvFG = pp->getVFGSize();

    // "do while" ... implement "ExplorePoint2DPoint2D" algorithm below as described in the paper



    return true; // return true if no error, else false

}

bool ParallelObjectTraversal::ExplorePoint2DLine2D(Object2D &F, Object2D &G) {
    // create new instance
    pp = new POT_Point2DPoint2D(F, G);

    // set vF and vG
    vF = pp->getVF();
    vG = pp->getVG();

    // set size of vF (and vG)
    sizeofvFG = pp->getVFGSize();

    // "do while" ... implement "ExplorePoint2DPoint2D" algorithm below as described in the paper



    return true; // return true if no error, else false

}

bool ParallelObjectTraversal::ExplorePoint2DRegion2D(Object2D &F, Object2D &G) {
    // create new instance
    pr = new POT_Point2DRegion2D(F, G);

    // set vF and vG
    vF = pr->getVF();
    vG = pr->getVG();

    // set size of vF (and vG)
    sizeofvFG = pr->getVFGSize();

    // "do while" ... implement "ExplorePoint2DRegion2D" algorithm below as described in the paper



    return true; // return true if no error, else false

}

bool ParallelObjectTraversal::ExploreLine2DLine2D(Object2D &F, Object2D &G) {
    // create new instance
    ll = new POT_Line2DLine2D(F, G);

    // set vF and vG
    vF = ll->getVF();
    vG = ll->getVG();

    // set size of vF (and vG)
    sizeofvFG = ll->getVFGSize();

    // "do while" ... implement "ExploreLine2DLine2D" algorithm below as described in the paper



    return true; // return true if no error, else false

}

bool ParallelObjectTraversal::ExploreLine2DRegion2D(Object2D &F, Object2D &G) {
    // create new instance
    lr = new POT_Line2DRegion2D(F, G);

    // set vF and vG
    vF = lr->getVF();
    vG = lr->getVG();

    // set size of vF (and vG)
    sizeofvFG = lr->getVFGSize();

    // "do while" ... implement "ExploreLine2DRegion2D" algorithm below as described in the paper



    return true; // return true if no error, else false

}

bool ParallelObjectTraversal::ExploreRegion2DRegion2D(Object2D &F, Object2D &G) {
    // create new instance
    rr = new POT_Region2DRegion2D(F, G);

    // set vF and vG
    vF = rr->getVF();
    vG = rr->getVG();

    // set size of vF (and vG)
    sizeofvFG = rr->getVFGSize();

    // "do while" ... implement "ExploreRegion2DRegion2D" algorithm below as described in the paper



    return true; // return true if no error, else false

}