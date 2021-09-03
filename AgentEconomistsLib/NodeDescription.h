#pragma once

#include "AgentEconomistsLib.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	/// <summary>
	/// Class that describes a resource node
	/// </summary>
	class AELIB_API NodeDescription
	{
	public:
		NodeDescription() {}
		NodeDescription(std::string _name, std::string _reourceName = "", int _initAmount = 0, int _growth = 0)
			: m_name(_name), m_reourceName(_reourceName), m_initAmount(_initAmount), m_growth(_growth) {}

	private:
		std::string m_name = "";
		std::string m_reourceName = "";
		int m_initAmount = 0;
		int m_growth = 0;
	};
}

#pragma warning( pop )
