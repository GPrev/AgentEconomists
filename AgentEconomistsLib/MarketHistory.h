#pragma once

#include "AgentEconomistsLib.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	/// <summary>
	/// Class that gathers the history of the simulation to permit to 
	/// save it in a file for instance.
	/// </summary>
	class AELIB_API  MarketHistory
	{
	public:
		MarketHistory() {};
	
	private:
		std::vector<unsigned int> m_numberTraded; //< Quantity of the resource that was traded at each step of the simulation.
		std::vector<double> m_marketPrices; //< Price of the resource at each step of the simulation.
	};
}

#pragma warning( pop )

