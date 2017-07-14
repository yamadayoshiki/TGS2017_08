#include "NullBody.h"
#include "../Elements/ContactSet/ContactSet.h"
Body::ContactSet Body::NullBody::IsCollide(IBody* other) { return ContactSet(); }
