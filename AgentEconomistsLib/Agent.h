#pragma once

#include "AgentType.h"
#include "Resource.h"
#include <map>

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// An independent entity capable of a number of actions, depending on its type
	/// </summary>
	class AELIB_API Agent
	{
	public:
		/// <summary>
		/// Returns the amount of a certain resource that the agent posesses
		/// </summary>
		/// <param name="p_resource">The resource in question</param>
		/// <returns>The amount posessed</returns>
		int getQuantity(Resource* p_resource) { return m_inventory[p_resource]; }

		/// <summary>
		/// Adds a certain quantity of a resource to the agent's inventory
		/// </summary>
		/// <param name="p_resource">The resouce to add</param>
		/// <param name="p_amount">The quantity to add</param>
		void addResoucre(Resource* p_resource, int p_amount);

	private:
		AgentType* m_type;
		std::map<Resource*, int> m_inventory;
	};

}

#pragma warning( pop )