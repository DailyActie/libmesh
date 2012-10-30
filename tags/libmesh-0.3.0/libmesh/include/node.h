// $Id: node.h,v 1.7 2003-02-13 22:56:07 benkirk Exp $

// The Next Great Finite Element Library.
// Copyright (C) 2002  Benjamin S. Kirk, John W. Peterson
  
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
  
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA



#ifndef __node_h__
#define __node_h__

// C++ includes

// Local includes
#include "point.h"
#include "dof_object.h"
#include "reference_counted_object.h"


// forward declarations
class Node;



/**
 * A \p Node is like a \p Point, but with more information.  A \p Node
 * is located in space and is associated with some \p (x,y,z)
 * coordinates.  Additionally, a \p Node may be enumerated with a
 * global \p id.  Finally, a \p Node may have an arbitrary number of
 * degrees of freedom associated with it.
 *
 * \author Benjamin S. Kirk
 * \date 2003
 * \version $Revision: 1.7 $
 */

class Node : public Point,
	     public DofObject,      
	     public ReferenceCountedObject<Node>
{
  
public:
  
  /**
   * Constructor.  By default sets all entries to 0.  Gives the point 0 in
   * \p DIM dimensions with an \p id of \p Node::invalid_id
   */
  Node  (const Real x,
	 const Real y,
	 const Real z,
	 const unsigned int id);

  /**
   * Copy-constructor.
   */
  Node (const Node& n);

  /**
   * Copy-constructor from a \p Point.  Optionally assigned the \p id.
   */
  Node (const Point& p,
	const unsigned int id = invalid_id);

  /**
   * Builds a \p Node and returns a \p Node* to the
   * newly-created object.  The \p id is copied from \p n.id()
   */
  static Node* build (const Node& n);

  /**
   * Builds a \p Node from \p Point p and returns a \p Node* to the
   * newly-created object.  Optionally assignes the \p id.
   */
  static Node* build (const Point& p,
		      const unsigned int id);
  
  /**
   * Builds a \p Node from specified points and returns a \p Node* to the
   * newly-created object.  Optionally assigned the \p id.
   */
  static Node* build (const Real x,
		      const Real y,
		      const Real z,
		      const unsigned int id);

  /**
   * Destructor.
   */ 
  ~Node ();
  
//   /**
//    * \returns the \p id for this \p Node
//    */
//   const unsigned int & id () const { return _id; }

//   /**
//    * \returns the \p id for this \p Node as a writeable reference.
//    */
//   unsigned int & set_id () { return _id; }

//   /**
//    * An invaild \p id to distinguish an uninitialized \p Node
//    */
//   static const unsigned int invalid_id;

  
private:

  
//   /**
//    * The \p id of the \p Node
//    */
//   unsigned int _id;

};



//------------------------------------------------------
// Inline functions
inline
Node::Node (const Real x,
	    const Real y,
	    const Real z,
	    const unsigned int id) :
  Point(x,y,z)
{
  set_id() = id;
}



inline
Node::Node (const Node& n) :
  Point(n),
  DofObject(n),
  ReferenceCountedObject<Node>()
{
//  _id = n._id;
}



inline
Node::Node (const Point& p,
	    const unsigned int id) :
  Point(p)
{
  // optionally assign the id.  We have
  // to do it like this otherwise
  // Node n = Point p would erase
  // the id!
  if (id != invalid_id)
    set_id() = id;
//    _id = id;
}



inline
Node::~Node ()
{
}



inline
Node* Node::build(const Node& n)
{
  return new Node(n);  
}



inline
Node* Node::build(const Point& p,
		  const unsigned int id)
{
  return new Node(p, id);  
}



inline
Node* Node::build(const Real x,
		  const Real y,
		  const Real z,
		  const unsigned int id)
{
  return new Node(x,y,z,id);  
}



#endif