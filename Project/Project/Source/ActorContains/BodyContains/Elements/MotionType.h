#ifndef MOTIONTYPE_H_
#define MOTIONTYPE_H_
namespace Body {
	//ふるまい
	enum class MotionType
	{
		/*静的*/
		Static,
		Enemy,
		Player,
		/*動的*/
		None,
	};
}
#endif // !MOTIONTYPE_H_
