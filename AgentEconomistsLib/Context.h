#pragma once

#include "AgentEconomistsLib.h"
#include "AgentTypeDescription.h"
#include "ResourceDescription.h"
#include "ZoneDescription.h"
#include <vector>

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{
	/// <summary>
	/// Class that describes the context of a simulation
	/// </summary>
	class AELIB_API Context
	{
	public:
		Context() {}

		void clear() { m_agentTypes.clear(); m_resources.clear(); m_zones.clear(); }

		void addAgentType(std::string name) { m_agentTypes.push_back(AgentTypeDescription(name)); }
		void addResource(std::string name) { m_resources.push_back(ResourceDescription(name)); }
		void addZone(std::string name) { m_zones.push_back(ZoneDescription(name)); }

		std::string toString() const;

	private:
		std::vector<AgentTypeDescription> m_agentTypes;
		std::vector<ResourceDescription> m_resources;
		std::vector<ZoneDescription> m_zones;
	};
}

#pragma warning( pop )
