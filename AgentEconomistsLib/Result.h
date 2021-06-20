#pragma once

#include<map>

#include "AgentEconomistsLib.h"
#include "ZoneResult.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	/// <summary>
	/// Class that gathers the history of the simulation to permit to 
	/// save it in a file for instance.
	/// </summary>
	class AELIB_API Result
	{
	public:
		Result(){}

	private:
		std::map<std::string, ZoneResult> m_resultByZones; //< Contains the results of each zone.
	};
}

#pragma warning(pop)
