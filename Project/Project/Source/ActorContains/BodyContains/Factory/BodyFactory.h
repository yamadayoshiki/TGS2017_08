#ifndef BODYFACTORY_H_
#define BODYFACTORY_H_
#include "../Interface/IBodyPtr.h"
#include "../BodyDataName.h"
#include "../Elements/MotionType.h"
#include <GSvector2.h>
#include <map>
namespace Body {
	struct IPrimitive2D;
	//工場
	class BodyFactory {
	public:
		BodyFactory();
		~BodyFactory();
		//生成
		IBodyPtr Generate(const MotionType type, const BodyDataName name);
		//変形
		void Transform(IBodyPtr& body,const BodyDataName name);

	private:
		//生成マップ登録
		void Register();

	private:
		std::map<BodyDataName, IBodyUPtr> m_GenerateMap;//生成マップ
	};
}
#endif