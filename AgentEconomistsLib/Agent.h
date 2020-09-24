#pragma once

#include "AgentType.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// An independent entity capable of a number of actions, depending on its type
	/// </summary>
	class AELIB_API Agent
	{
	private:
		AgentType* m_type;
	};

}

#pragma warning( pop )