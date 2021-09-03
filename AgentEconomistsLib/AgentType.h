#pragma once

#include <vector>
#include "Action.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// Represent a type of agent, capable of a set of actions
	/// </summary>
	class AELIB_API AgentType
	{
	public:
		AgentType(std::string name) { m_name = name; }

		std::string getName() { return m_name; }

	private:
		std::string m_name;
		std::vector<Action*> m_actions;
	};

}

#pragma warning( pop )