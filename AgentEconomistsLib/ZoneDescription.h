#pragma once

#include<map>

#include "AgentEconomistsLib.h"
#include "NodeDescription.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	/// <summary>
	/// Class that describes a zone of the simulation.
	/// </summary>
	class AELIB_API ZoneDescription
	{
	public:
		ZoneDescription() {}
		ZoneDescription(std::string _name) : m_name(_name) {}

		void addNode(std::string _name, std::string _reourceName = "", int _initAmount = 0, int _growth = 0)
			{ m_nodes.push_back(NodeDescription(_name, _reourceName, _initAmount, _growth)); }

	private:
		std::string m_name;
		std::map<std::string, int> m_nbAgents;
		std::vector<NodeDescription> m_nodes;
	};
}

#pragma warning( pop )
