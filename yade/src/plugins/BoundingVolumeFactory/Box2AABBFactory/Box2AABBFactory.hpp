 
#ifndef __BOX2AABBFACTORY_H__
#define __BOX2AABBFACTORY_H__

#include "BoundingVolumeFactory.hpp"

class Box2AABBFactory : public BoundingVolumeFactory
{	
	// construction
	public : Box2AABBFactory ();
	public : ~Box2AABBFactory ();
	
	public : void processAttributes();
	public : void registerAttributes();
	
	public : shared_ptr<BoundingVolume> buildBoundingVolume(const shared_ptr<CollisionModel> cm, const Se3& se3);
	REGISTER_CLASS_NAME(Box2AABBFactory);		
};

REGISTER_CLASS(Box2AABBFactory,false);

#endif // __BOX2AABBFACTORY_H__
