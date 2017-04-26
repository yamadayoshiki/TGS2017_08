#pragma once

#include <string>
#include "../../ActorPtr.h"
#include <GStype.h>
#include <vector>

struct HitInfo
{
public:
	ActorPtr actor;
	std::string name;
	std::vector<GSvector2> intersects;
	GSvector2 closest;
	GSvector2 normal;

public:
	HitInfo() : actor(), name("none"), normal(GSvector2()) {}
};