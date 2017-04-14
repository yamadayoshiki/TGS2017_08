#pragma once

#include <string>
#include "../../ActorPtr.h"
#include <GStype.h>

struct HitInfo
{
public:
	ActorPtr actor;
	std::string name;
	GSvector2 intersect;
	GSvector2 normal;

public:
	HitInfo() : actor(), name("none"), intersect(GSvector2()), normal(GSvector2()) {}
};