#ifndef TEXTURE2DPARAMETERPTR_H_
#define TEXTURE2DPARAMETERPTR_H_
#include<memory>
struct Texture2DParameter;
using Texture2DParameterSPtr = std::shared_ptr<Texture2DParameter>;
using Texture2DParameterWPtr = std::weak_ptr<Texture2DParameter>;
#endif