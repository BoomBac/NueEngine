#pragma once
#include "../Common/Image.h"
#include "../Common/Buffer.h"
namespace Engine
{
	class IIMageParser
	{
	public:
		virtual Image Parse(const Buffer& buf) = 0;
	};
}