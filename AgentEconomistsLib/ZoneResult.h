#pragma once

#include <map>

#include "AgentEconomistsLib.h"
#include "ResourceHistory.h"
#include "AgentHistory.h"
#include "MarketHistory.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	/// <summary>
	/// Class that gathers the history of a zone of the simulation to permit to 
	/// save it in a file for instance.
	/// </summary>
	class AELIB_API ZoneResult
	{
	public:
		ZoneResult() {};

	private:
		std::map<std::string, ResourceHistory> m_rh; //< Resource histories for each resource.
		std::map<std::string, AgentHistory> m_rh; //< Agent histories for each type of agent.
		std::map<std::string, MarketHistory> m_rh; //< Market histories for each zone.
	};
}

#pragma warning( pop )

