#pragma once

#include "Ice/Core.h"

namespace Ice
{
	class GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffer() = 0;
	};
}
