#pragma once

#include <map>
#include "AgentType.h"
#include "Resource.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	class Market;

	/// <summary>
	/// An independent entity capable of a number of actions, depending on its type
	/// </summary>
	class AELIB_API Agent
	{
	private:
		AgentType* m_type;
		std::map<Resource*, int> m_resources;
		int m_money;

	public:
		Agent();

		/// <summary>
		/// Make the agent perform an action in the zone.
		/// </summary>
		/// <param name="p_zone">Zone in which the agent will perform the action.</param>
		void act(Zone* p_zone);

		/// <summary>
		/// Make the agent go to the market to buy and sell stuffs.
		/// </summary>
		/// <param name="p_market">Market in which he will buy and sell stuffs.</param>
		void goToMarket(Market* p_market);
	};

}

#pragma warning( pop )