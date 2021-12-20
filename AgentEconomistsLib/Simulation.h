#pragma once

#include "Context.h"
#include "Agent.h"
#include "Encyclopedia.h"
#include "Zone.h"
#include "AgentEconomistsLib.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// Class in charge of the simulation: contains all the agents, zones etc and run the iterations
	/// </summary>
	class Simulation
	{
	protected:
		/// <summary>
		/// Zone that contains the agents, the market and the resources.
		/// </summary>
		Zone m_zone;

		/// <summary>
		/// Contains the agents, the available resources and the possible actions.
		/// </summary>
		Encyclopedia m_e;

	public:
		Simulation();

		/// <summary>
		/// Run the whole simulation.
		/// </summary>
		void run();

		/// <summary>
		/// Execute one step of simulation : go to market, match and sell, update resources values.
		/// </summary>
		void oneStep();

	};

}

#pragma warning( pop )