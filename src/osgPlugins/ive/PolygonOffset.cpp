/**********************************************************************
 *
 *	FILE:			PolygonOffset.cpp
 *
 *	DESCRIPTION:	Read/Write osg::PolygonOffset in binary format to disk.
 *
 *	CREATED BY:		Auto generated by iveGenerator
 *					and later modified by Rune Schmidt Jensen.
 *
 *	HISTORY:		Created 27.3.2003
 *
 *	Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "PolygonOffset.h"
#include "Object.h"

using namespace ive;

void PolygonOffset::write(DataOutputStream* out){
	// Write CullFace's identification.
	out->writeInt(IVEPOLYGONOFFSET);
	// If the osg class is inherited by any other class we should also write this to file.
	osg::Object*  obj = dynamic_cast<osg::Object*>(this);
	if(obj){
		((ive::Object*)(obj))->write(out);
	}
	else
		throw Exception("PolygonOffset::write(): Could not cast this osg::PolygonOffset to an osg::Object.");
	// Write PolygonOffset's properties.
	out->writeFloat(getFactor());
	out->writeFloat(getUnits());
}

void PolygonOffset::read(DataInputStream* in){
	// Peek on PolygonOffset's identification.
	int id = in->peekInt();
	if(id == IVEPOLYGONOFFSET){
		// Read PolygonOffset's identification.
		id = in->readInt();
		// If the osg class is inherited by any other class we should also read this from file.
		osg::Object*  obj = dynamic_cast<osg::Object*>(this);
		if(obj){
			((ive::Object*)(obj))->read(in);
		}
		else
			throw Exception("PolygonOffset::read(): Could not cast this osg::PolygonOffset to an osg::Object.");
		// Read PolygonOffset's properties
		setFactor(in->readFloat());
		setUnits(in->readFloat());
	}
	else{
		throw Exception("PolygonOffset::read(): Expected PolygonOffset identification.");
	}
}
