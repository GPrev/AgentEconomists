#pragma once

#include <string>
#include "AgentEconomistsLib.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

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

	private:
		/// <summary>
		/// The name of the action.
		/// </summary>
		std::string m_name; 
	};

}

#pragma warning( pop )