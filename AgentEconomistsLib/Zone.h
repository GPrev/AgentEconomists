#pragma once

#include "AgentEconomistsLib.h"
#include "ResourceNode.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// Geographical zone in the simullation, that owns a certain amount of natural resources and a local market.
	/// </summary>
	class Zone
	{
	public:
		std::vector<ResourceNode>& getResourceNodes() { return m_resouceNodes; }

	private:
		std::vector<ResourceNode> m_resouceNodes;
	};

}

#pragma warning( pop )