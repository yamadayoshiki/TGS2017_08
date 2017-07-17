#ifndef BODYFACTORY_H_
#define BODYFACTORY_H_
#include "../Interface/IBodyPtr.h"
#include "../BodyDataName.h"
#include "../Elements/MotionType.h"
#include <GSvector2.h>
#include <map>
namespace Body {
	struct IPrimitive2D;
	//�H��
	class BodyFactory {
	public:
		BodyFactory();
		~BodyFactory();
		//����
		IBodyPtr Generate(const MotionType type, const BodyDataName name);
		//�ό`
		void Transform(IBodyPtr& body,const BodyDataName name);

	private:
		//�����}�b�v�o�^
		void Register();

	private:
		std::map<BodyDataName, IBodyUPtr> m_GenerateMap;//�����}�b�v
	};
}
#endif