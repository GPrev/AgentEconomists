#pragma once

#include "AgentEconomistsLib.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	/// <summary>
	/// Class that gathers the history of the resources.
	/// </summary>
	class AELIB_API  ResourceHistory
	{
	public:
		ResourceHistory() {}
	private:
		std::vector<unsigned int> m_numberExisting; //< Keep trace of the quantity of the resource.
		std::vector<unsigned int> m_numberOwned; //< Keep trace of the quantity owned by the agents of the resource.
	};
}

#pragma warning(pop)
