#pragma once

#include "AgentEconomistsLib.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	/// <summary>
	/// Class that describes the context of a simulation
	/// </summary>
	class AELIB_API ZoneDescription
	{
	public:
		ZoneDescription() {}
		ZoneDescription(std::string _name) : m_name(_name) {}

	private:
		std::string m_name;
	};
}

#pragma warning( pop )
