#include "AABB2D.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../../../Utility/Contact/Contact.h"
#include "../../../../../Utility/Collide2D/IsCollide2D.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../AASegment2D/AASegment2D.h"
#include <iostream>
namespace Body
{
	void AABB2D::SetParam(const GSvector2 & position, const float angle, const GSvector2 & offsetVec) {
		GSvector2 l_offsetVec = MathSupport::RotateVector(offsetVec, angle);
		centerPoint = position + l_offsetVec;
		FourDirection four = FourDirection(angle);
		switch (four.name)
		{
		case FourDirectionName::Left:
		case FourDirectionName::Right:
			halfLength = staticHalfLength;
			break;

		case FourDirectionName::Up:
		case FourDirectionName::Down:
			halfLength = { staticHalfLength.y, staticHalfLength.x };
			break;
		}
	}

	Contact AABB2D::IsCollide(IPrimitive2D & p) {
		Contact result;

		//é©êgÇ™âüÇµèoÇ∑ë§
		switch (p.GetName())
		{
		case PrimitiveName::AABB2D:
			result = IsCollide2D::AABB2DToAABB2D(*this, *dynamic_cast<AABB2D*>(&p));
			return result;

		case PrimitiveName::AASegment:
			result = IsCollide2D::AABB2DToAASegment2D(*this, *dynamic_cast<AASegment2D*>(&p));
			return result;
		}
		std::cout << "Ç±Ç±Ç…Ç±Ç»Ç¢Ç≈";
		return result;
	}

	IPrimitive2D * AABB2D::Clone() {
		return new AABB2D(centerPoint, halfLength);
	}

}