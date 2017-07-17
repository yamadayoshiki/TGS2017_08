#include "NullBody.h"
#include "../Elements/ContactSet/ContactSet.h"
#include "../Elements/Collidable/BodyCollidable.h"
Body::ContactSet Body::NullBody::IsCollide(IBody* other) { return ContactSet(); }

Body::BodyCollidable Body::NullBody::GetBodyCollidable(){
	return Body::BodyCollidable();
}
