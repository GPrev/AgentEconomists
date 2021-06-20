#pragma once

#include "AgentEconomistsLib.h"
#include "ActionDescription.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	/// <summary>
	/// Class that describes the type of agents that can exist in the simulation
	/// and the different actions that they can perform.
	/// </summary>
	class AELIB_API AgentTypeDescription
	{
	public:
		AgentTypeDescription() {}
		AgentTypeDescription(std::string _name) : m_name(_name) {}

	private:
		std::string m_name;
		std::vector<ActionDescription> m_allowedActions;
	};
}

#pragma warning( pop )
