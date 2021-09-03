#pragma once

#include <string>
#include "AgentEconomistsLib.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	class Zone;
	class Agent;


	/// <summary>
	/// Represents an action that an agent of the correct type can perform
	/// </summary>
	class AELIB_API Action
	{
	public:
		Action(std::string name) { m_name = name; }

		/// <summary>
		/// Return the name of the action.
		/// </summary>
		/// <returns>The name of the action</returns>
		std::string getName() { return m_name; }

		/// <summary>
		/// Check if an Agent is allowed to perform an action.
		/// </summary>
		/// <returns>True if the Agent can perform the action, false otherwise</returns>
		virtual bool canExecute(Agent* p_agent, Zone* p_zone) = 0;

		/// <summary>
		/// Make an Agent perform an action.
		/// </summary>
		virtual void execute(Agent* p_agent, Zone* p_zone) = 0;
	private:
		/// <summary>
		/// The name of the action.
		/// </summary>
		std::string m_name; 
	};

}

#pragma warning( pop )