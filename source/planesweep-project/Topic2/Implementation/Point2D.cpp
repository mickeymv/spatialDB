/******************************************************************************
 *  File: Point2D.cpp
******************************************************************************
 *  Purpose:  This file implements the interface to the class Point2D and to
 *  the nested iterator class that enables access to the simple ponts of the
 *  Point2D objects.

 *  Created on: Oct 8, 2015

 *  Authors: Ahmed Khaled, Revathi Kadari, Deepa Narain, Namrata Choudhury

 *  Date: Fall Semester 2015
*******************************************************************************/


#include "Point2D.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <regex>
#include <string>
#include <iterator>
  
  // Forward struct declaration for the hidden implementation of a
  // constant point iterator that holds the different variables of the iterator
  struct Point2D::ConstPoiIterator::ConstPoiIteratorImplementation 
  {
    int iteratorIndex = 0;
    Point2D::point2DImplementation* current;
  };
  
  //Structure that holds all required information for building the Point2D structure
  struct Point2D::point2DImplementation 
  {
    std::vector<Poi2D> vecPoints;
    Point2D::ConstPoiIterator::ConstPoiIteratorImplementation first;
    Point2D::ConstPoiIterator::ConstPoiIteratorImplementation last;
    Point2D::ConstPoiIterator::ConstPoiIteratorImplementation head;
    Point2D::ConstPoiIterator::ConstPoiIteratorImplementation tail;
    
  };
  
  //function used for sorting points
  bool lessFunction (Poi2D a, Poi2D b)
  {
    return a<b;
  }

  // Empty constructor. Represents the empty point object.
  Point2D::Point2D()
  {
	  points = new point2DImplementation;
	  points->first.iteratorIndex = 0;   //no elements in empty vector
	  points->last.iteratorIndex = 0;    //no elements in empty vector
      points->head.iteratorIndex = 0;
      points->tail.iteratorIndex = 0;
	  points->vecPoints.clear();
	  points->first.current = points;
	  points->last.current = points;
      points->head.current = NULL;
      points->tail.current = NULL;
  }

  // Constructor for complex Point2D object. It takes inputs as a vector of poi2D objects and creates a
  // Point2D object after checking if a valid Point2D object can be created from the input.
  Point2D::Point2D(std::vector<Poi2D> pointList)
  {
      points = new point2DImplementation;
      points->vecPoints.clear();
      std::sort(pointList.begin(), pointList.end(), lessFunction);
      points->vecPoints.push_back(Poi2D(Number( ),Number( )));
      std::copy(pointList.begin(), pointList.end(),std::back_inserter(points->vecPoints));
	  points->vecPoints.push_back(Poi2D(Number( ),Number( )));
      points->first.iteratorIndex = 1;
	  points->last.iteratorIndex = points->vecPoints.size();
      points->tail.iteratorIndex = points->vecPoints.size()+1; 
	  points->first.current = points;
	  points->last.current = points;  
  }

  // Constructor for complex point structure. It takes as input a string name that represents the
  // string that textually represents the input vector of points.
  Point2D::Point2D(std::string textualPointList)
  {
      points = new point2DImplementation;

      if (std::regex_match( textualPointList, std::regex( "\\(\\(.*\\)\\)" ) ))  // means the string is point representation
      { 
	      points->vecPoints.clear();
          points->vecPoints.push_back(Poi2D(Number( ),Number( )));
	      textualPointList.erase(std::remove(textualPointList.begin(), textualPointList.end(), ')'), textualPointList.end());
	      textualPointList.erase(std::remove(textualPointList.begin(), textualPointList.end(), '('), textualPointList.end());
	      std::istringstream ss(textualPointList);
	      
	      std::string token;
	      Number N1;
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
	            count=0;
	            points->vecPoints.push_back(Poi2D(N1,Number(token.c_str())));
	          }
	      }
          points->vecPoints.push_back(Poi2D(Number( ),Number( )));
	      if(count==1)
		  {
                points->vecPoints.clear(); 
                return;
	      }   // not complete set of points  
      }
      else
	  { 
        // throw error for invalid input 
        cout << "Invalid input for point object";
      }  
  }

  // Copy constructor that constructs a new Point2D object with the same
  // properties as the inputted Point2D object.
  Point2D::Point2D(const Point2D& orginalPoint)
  {
    points = new point2DImplementation;
    points->vecPoints.clear();
    std::copy(orginalPoint.points->vecPoints.begin(), orginalPoint.points->vecPoints.end(),std::back_inserter(points->vecPoints));
    points->first.iteratorIndex = orginalPoint.points->first.iteratorIndex;
    points->last.iteratorIndex = orginalPoint.points->last.iteratorIndex;
    points->head.iteratorIndex = orginalPoint.points->head.iteratorIndex;
    points->tail.iteratorIndex = orginalPoint.points->tail.iteratorIndex;
    points->first.current = orginalPoint.points->first.current;
    points->last.current = orginalPoint.points->last.current;
    points->head.current = orginalPoint.points->head.current;
    points->tail.current = orginalPoint.points->tail.current;
  }

  // Move constructor that moves the inputed Point2D object to a
  // Point2D object. The inputed Point2D object gets the empty Point2D
  // object as its value.
  Point2D::Point2D(Point2D&& orginalPoint)
  {
    points = new point2DImplementation;
    points->vecPoints.clear();
    std::move(orginalPoint.points->vecPoints.begin(), orginalPoint.points->vecPoints.end(),std::back_inserter(points->vecPoints));
    points->first.iteratorIndex = orginalPoint.points->first.iteratorIndex;
    points->last.iteratorIndex = orginalPoint.points->last.iteratorIndex;
    points->head.iteratorIndex = orginalPoint.points->head.iteratorIndex;
    points->tail.iteratorIndex = orginalPoint.points->tail.iteratorIndex;
    points->first.current = orginalPoint.points->first.current;
    points->last.current = orginalPoint.points->last.current;
    points->head.current = orginalPoint.points->head.current;
    points->tail.current = orginalPoint.points->tail.current;
  }

  // Destructor, that clears the internal objects of the Point2D structure.
  Point2D::~Point2D()
  {
    delete points;
  }
  
  
  //+++++++++++++++++++++
  // Assignment operators
  //+++++++++++++++++++++

  
  //copy assignment operator that copies the inputted object
  //to the Point2D object  
  Point2D& Point2D::operator = (const Point2D& orginalPoint)
  {
	points = new point2DImplementation;
    points->vecPoints.clear();
	std::copy(orginalPoint.points->vecPoints.begin(), orginalPoint.points->vecPoints.end(),std::back_inserter(points->vecPoints));
    points->first.iteratorIndex = orginalPoint.points->first.iteratorIndex;
	points->last.iteratorIndex = orginalPoint.points->last.iteratorIndex;
    points->head.iteratorIndex = orginalPoint.points->head.iteratorIndex;
    points->tail.iteratorIndex = orginalPoint.points->tail.iteratorIndex;
	points->first.current = orginalPoint.points->first.current;
	points->last.current = orginalPoint.points->last.current;
    points->head.current = orginalPoint.points->head.current;
    points->tail.current = orginalPoint.points->tail.current;
    return(*this);
  }

  // Move assignment operator that moves the inputted Point2D object to the
  // Point2D object. The inputted object gets the empty Point2D
  // object as its value.
  Point2D& Point2D::operator = (Point2D&& orginalPoint)
  {  
	points = new point2DImplementation;
    points->vecPoints.clear();
	std::move(orginalPoint.points->vecPoints.begin(), orginalPoint.points->vecPoints.end(),std::back_inserter(points->vecPoints));
    points->first.iteratorIndex = orginalPoint.points->first.iteratorIndex;
	points->last.iteratorIndex = orginalPoint.points->last.iteratorIndex;
	points->head.iteratorIndex = orginalPoint.points->head.iteratorIndex;
    points->tail.iteratorIndex = orginalPoint.points->tail.iteratorIndex;
    points->first.current = orginalPoint.points->first.current;
	points->last.current = orginalPoint.points->last.current;
    points->head.current = orginalPoint.points->head.current;
    points->tail.current = orginalPoint.points->tail.current; 
    return(*this);
  }
  
  // +++++++++++++++++++++
  // operators and Comparison operators
  // +++++++++++++++++++++
  
  // Equal operator that checks if the Point2D object and the operand Point2D are the same spatial point.
  bool Point2D::operator == (Point2D& operand)
  {
		if(points->vecPoints.size() != operand.points->vecPoints.size())  
		  return false;
		for (unsigned i=1; i < points->vecPoints.size()-2; i++)
		{
		  if(points->vecPoints.at(i) != operand.points->vecPoints.at(i))		
			return false;
		}
		return true;
  }
  
  // unequal operator that checks if the Point2D object and the operand
  // Point2D are different spatial structures. It is the logical opposite
  // of the == operator.
  bool Point2D::operator != (Point2D& operand)
  {
		if(points->vecPoints.size() != operand.points->vecPoints.size())  
		  return true;
		for (unsigned i=0; i < points->vecPoints.size(); i++)
		{
		  if(points->vecPoints.at(i) != operand.points->vecPoints.at(i))
			return true;
		}
		return false;
  }

  // less than comparision of lexicographic order of points
  bool Point2D::operator < (Point2D& operand)
  {
	  if(isEmptyPoint2D() || operand.isEmptyPoint2D()) 
		return false;
	  int x = (points->vecPoints.size() < operand.points->vecPoints.size()) ? points->vecPoints.size() : operand.points->vecPoints.size();
      for (unsigned i=1; i < x; i++) 
	  {
	    Poi2D poi1=points->vecPoints.at(i);
	    Poi2D poi2=operand.points->vecPoints.at(i);
	    if (poi1 < poi2)
	      return true;
	    else
	      continue;
	  }
	  if (operand.points->vecPoints.size() > points->vecPoints.size())   
	    return true;

	  return false;
  }

  
  // less than or equal comparision of lexicographic order of points
  bool Point2D::operator <= (Point2D& operand)
  {
	  if(isEmptyPoint2D() || operand.isEmptyPoint2D()) 
		return false;
	  int x = (points->vecPoints.size() < operand.points->vecPoints.size()) ? points->vecPoints.size() : operand.points->vecPoints.size();
      for (unsigned i=1; i < x-1; i++)
	  {
	    if (points->vecPoints.at(i) > operand.points->vecPoints.at(i))
	      return false;
	  } 
	  
	  if ((operand.points->vecPoints.size() == points->vecPoints.size())||(operand.points->vecPoints.size() > points->vecPoints.size()))   
	    return true;

	  return false;
  }
  
  // greater than comparision of lexicographic order of points
  bool Point2D::operator > (Point2D& operand)
  {
	  if(isEmptyPoint2D() || operand.isEmptyPoint2D()) 
		return false;
	  int x = (points->vecPoints.size() < operand.points->vecPoints.size()) ? points->vecPoints.size() : operand.points->vecPoints.size();
      for (unsigned i=1; i < x-1; i++)
	  {
	    if (points->vecPoints.at(i) > operand.points->vecPoints.at(i))
	      return true;
	  } 
	  if (operand.points->vecPoints.size() < points->vecPoints.size())   
	    return true;

	  return false;
  }
  
  // greater or equal comparision of lexicographic order of points
  bool Point2D::operator >= (Point2D& operand)
  {
	  if(isEmptyPoint2D() || operand.isEmptyPoint2D()) 
		return false;
	  int x = (points->vecPoints.size() < operand.points->vecPoints.size()) ? points->vecPoints.size() : operand.points->vecPoints.size();
      for (unsigned i=1; i < x-1; i++)
	  {
	    if (points->vecPoints.at(i) < operand.points->vecPoints.at(i))
	      return false;
	  } 
	  
	  if ((operand.points->vecPoints.size() == points->vecPoints.size())||(operand.points->vecPoints.size() < points->vecPoints.size()))   
	    return true;

	  return false;
  }

  // Display function, that displayes the information of Point2D structure as follows:
  // the number of points contained in the structure, then information of each point in the point-vector structure.
  std::ostream&operator<<(std::ostream& os, const Point2D& output)
  {
	if((output.points->vecPoints.size() == 0)||(output.points->vecPoints.size() == 2))
	{
	  os << "Empty Point structure with zero number of points";
      os<<endl;
	}else
	{
	  os << "number of points: " << output.points->vecPoints.size()-2<<" "<<endl;
      for (unsigned i=1; i<output.points->vecPoints.size()-1; i++) 
	    os << "point " << i <<":"<< output.points->vecPoints[i]<<" "<<endl;
	}
    return os;
	
  }
  
  //++++++++++++++++++++++++++++++++
  // Unary predicates and operations
  //++++++++++++++++++++++++++++++++
  
  // get number of single points of the structure.
  Number Point2D::numPoints()
  {
		if((points->vecPoints.size() == 0)||(points->vecPoints.size() == 2))
	        return Number(std::to_string(0));
		return Number(std::to_string(points->vecPoints.size()-2));  
  }
  
  // Predicate that checks whether the inputted Point2D object is an
  // empty Point2D object.
  bool Point2D::isEmptyPoint2D() const
  {
		if((points->vecPoints.size() == 0)||(points->vecPoints.size() == 2))
	        return true;
		return false;
  }


  // +++++++++++++++++++
  // Iterator functions
  // +++++++++++++++++++


  // Default constructor that creates an empty constant poi iterator.
  Point2D::ConstPoiIterator::ConstPoiIterator()
  {
	handle = new ConstPoiIteratorImplementation;
	handle->iteratorIndex = 0; 	  
  }

  // Copy constructor that constructs a constant poi iterator from a
  // given constant poi iterator "source".
  Point2D::ConstPoiIterator::ConstPoiIterator(const ConstPoiIterator& source)
  {
    handle = new ConstPoiIteratorImplementation;
	handle->iteratorIndex = source.handle->iteratorIndex;
	handle->current = source.handle->current;
  }

  // Move constructor that moves a given constant poi iterator "source"
  // to a constant poi iterator. The constant poi iterator "source"
  // gets the empty constant poi iterator as its value.
  Point2D::ConstPoiIterator::ConstPoiIterator(ConstPoiIterator&& source)
  {
    handle = new ConstPoiIteratorImplementation;
	handle->iteratorIndex = std::move(source.handle->iteratorIndex);
	handle->current = std::move(source.handle->current);
  }

  // Destructor that frees the main memory space allocated for a constant
  // poi iterator.
  Point2D::ConstPoiIterator::~ConstPoiIterator()
  {
	delete handle;
  }
  // Assignment operator that assigns another constant poi iterator
  // "rhs" to the constant poi iterator.
  Point2D::ConstPoiIterator& Point2D::ConstPoiIterator::operator = (const ConstPoiIterator& rhs)
  {
	handle->iteratorIndex = rhs.handle->iteratorIndex; 
	handle->current = rhs.handle->current;
    return(*this);
  }

  // Predicate that tests whether a constant poi iterator is empty.
  bool Point2D::ConstPoiIterator::isEmpty() const
  {
	return (handle->current == NULL);
  }

  // Increment/decrement operators '++', '--'
  // prefix
  Point2D::ConstPoiIterator& Point2D::ConstPoiIterator::operator ++ ()
  {
    handle->iteratorIndex++;
    return(*this);
  }

  // postfix
  Point2D::ConstPoiIterator Point2D::ConstPoiIterator::operator ++ (int postfix)
  {   
    ConstPoiIterator tmp(*this);//*tmp= new ConstPoiIterator(*this);
    handle->iteratorIndex++;
    return(tmp);
  }

  // prefix
  Point2D::ConstPoiIterator& Point2D::ConstPoiIterator::operator -- ()
  { 
    handle->iteratorIndex--;
    return(*this);
  }

  // postfix
  Point2D::ConstPoiIterator Point2D::ConstPoiIterator::operator -- (int postfix)
  {
    ConstPoiIterator tmp(*this);//*tmp= new ConstPoiIterator(*this);
    handle->iteratorIndex--;
    return(tmp);
  }

  // Dereferencing operators that return the value at the constant poi
  // iterator position. Dereferencing is only allowed if the iterator
  // points to a point. The dereferenced value cannot be changed.
  const Poi2D& Point2D::ConstPoiIterator::operator *() const
  {
    return(this->handle->current->vecPoints.at(this->handle->iteratorIndex));     
  }
  const Poi2D* Point2D::ConstPoiIterator::operator ->() const
  {
    return(&this->handle->current->vecPoints.at(this->handle->iteratorIndex));   
  }

  // Comparison operators that compares a constant poi iterator position
  // with another const poi iterator position "rhs"
  bool Point2D::ConstPoiIterator::operator == (const ConstPoiIterator& rhs) const
  {
    return ((this->handle->current == rhs.handle->current)&&(this->handle->iteratorIndex == rhs.handle->iteratorIndex));
  }
  bool Point2D::ConstPoiIterator::operator != (const ConstPoiIterator& rhs) const
  {
    return ((this->handle->current == rhs.handle->current)&&(this->handle->iteratorIndex != rhs.handle->iteratorIndex));
  }
  bool Point2D::ConstPoiIterator::operator <  (const ConstPoiIterator& rhs) const
  {
    return ((this->handle->current == rhs.handle->current)&&(this->handle->iteratorIndex < rhs.handle->iteratorIndex));
  }
  bool Point2D::ConstPoiIterator::operator <= (const ConstPoiIterator& rhs) const
  {
    return ((this->handle->current == rhs.handle->current)&&(this->handle->iteratorIndex <= rhs.handle->iteratorIndex));
  }
  bool Point2D::ConstPoiIterator::operator >  (const ConstPoiIterator& rhs) const
  {
    return ((this->handle->current == rhs.handle->current)&&(this->handle->iteratorIndex > rhs.handle->iteratorIndex));    
  }
  bool Point2D::ConstPoiIterator::operator >= (const ConstPoiIterator& rhs) const
  {
    return ((this->handle->current == rhs.handle->current)&&(this->handle->iteratorIndex >= rhs.handle->iteratorIndex));
  }
  
  // Method that returns a constant poi iterator to the first point of a
  // Point2D object.
  Point2D::ConstPoiIterator Point2D::cbegin() const
  {		  
	ConstPoiIterator begin;
	begin.handle->iteratorIndex = 1;
	begin.handle->current = points;
  	return begin;
  }

  // Method that returns a constant poi iterator to the last point of a
  // Point2D object.
  Point2D::ConstPoiIterator Point2D::cend() const
  {		  
	ConstPoiIterator last;
    if(points->vecPoints.size() >= 2)
        last.handle->iteratorIndex = points->vecPoints.size()-2;
    else 
        last.handle->iteratorIndex = 0;
	last.handle->current = points;
  	return last;
  }
  
  std::ostream&operator<<(std::ostream& os, const Point2D::ConstPoiIterator& output)
  {
	os << "index Value:" << output.handle->iteratorIndex<<" ";
    os << "point Value:" << output.handle->current->vecPoints.at(output.handle->iteratorIndex)<<" ";
	return os;
  }

  // Method that returns a constant poi iterator to the position before the
  // first face of a Point2D object. Note that dereferencing this iterator
  // yields the empty constant poi iterator.
  //(Currently, yields default value set at BigRational constructor i.e (0/1,0/1) )
  Point2D::ConstPoiIterator Point2D::chead() const
  {
   ConstPoiIterator h;
   h.handle->iteratorIndex = 0;
   h.handle->current = points;
   return h;
  }

  // Method that returns a constant poi iterator to the position after the
  // last face of a Point2D object. Note that dereferencing this iterator
  // yields the empty constant poi iterator.
  //(Currently, yields default value set at BigRational constructor i.e (0/1,0/1) )
  Point2D::ConstPoiIterator Point2D::ctail() const
  {
    ConstPoiIterator t;
    if(points->vecPoints.size() >= 1)
      t.handle->iteratorIndex = points->vecPoints.size()-1;
    else 
      t.handle->iteratorIndex = 0;
    t.handle->current = points;
    return t;
  }
