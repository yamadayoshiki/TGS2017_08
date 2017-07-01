#ifndef TEXTURE2DPARAMETERPTR_H_
#define TEXTURE2DPARAMETERPTR_H_
#include<memory>
class Texture2DParameter;
using Texture2DParameterPtr = std::shared_ptr<Texture2DParameter>;
using Texture2DParameterWPtr = std::weak_ptr<Texture2DParameter>;
#endif // !TEXTURE2DPARAMETERPTR_H_
