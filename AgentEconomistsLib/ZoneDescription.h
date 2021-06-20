#pragma once

#include<map>

#include "AgentEconomistsLib.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	/// <summary>
	/// Class that describes a zone of the simulation.
	/// </summary>
	class AELIB_API ZoneDescription
	{
	public:
		ZoneDescription() {}
		ZoneDescription(std::string _name) : m_name(_name) {}

	private:
		std::string m_name;
		std::map<std::string, int> m_nbAgents;
	};
}

class ZoneDescription
{
};

#pragma warning( pop )
