#pragma once

#include "AgentEconomistsLib.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	/// <summary>
	/// Class that gathers the history of the agents existing in the simulation..
	/// </summary>
	class AELIB_API  AgentHistory
	{
	public:
		AgentHistory() {}

	private:
		std::vector<unsigned int> m_numberExisting; //< Number of living agents.
		std::vector<unsigned int> m_births; //< Number of biirths at this step of the simulation.
		std::vector<unsigned int> m_deaths; //< Number of deaths at this step of the simulation.
	};
}

#pragma warning(pop)