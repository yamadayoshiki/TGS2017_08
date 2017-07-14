#include "AASegment2D.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../../../Utility/Contact/Contact.h"
#include "../../../../../Utility/Collide2D/IsCollide2D.h"
#include <iostream>
namespace Body
{
	PrimitiveName AASegment2D::GetName() const
	{
		return PrimitiveName::AASegment;
	}
	void AASegment2D::SetParam(const GSvector2& position, const float angle, const GSvector2& offsetVec) {
		GSvector2 l_offsetVec = MathSupport::RotateVector(offsetVec, angle);
		point = position + l_offsetVec;
		vector = MathSupport::RotateVector(staticVector,angle);
	}

	Contact AASegment2D::IsCollide(IPrimitive2D & p) {
		Contact result;

		//é©êgÇ™âüÇµèoÇ∑ë§
		switch (p.GetName())
		{
		case PrimitiveName::AABB2D:
			std::cout << "Ç±Ç±Ç…Ç±Ç»Ç¢Ç≈";
			return result;

		case PrimitiveName::AASegment:
			std::cout << "Ç±Ç±Ç…Ç±Ç»Ç¢Ç≈";
			return result;
		}
		return result;
	}
	IPrimitive2D * AASegment2D::Clone() {
		return new AASegment2D(point, vector);
	}
}