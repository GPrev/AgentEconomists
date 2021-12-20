#pragma once

#include "AgentEconomistsLib.h"
#include "Resource.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// A ResourceNode is a tuple gathering the type of resource, its quantity
	/// and its refreshing rate.
	/// </summary>
	class ResourceNode
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="p_resource">The type of resource contained in the node</param>
		/// <param name="p_initAmount">The amount of resources initially contained in the node</param>
		ResourceNode(Resource* p_resource, int p_initAmount = 0) : m_resource(p_resource), m_amount(p_initAmount) {}

		/// <summary>
		/// Returns the type of resource contained in the node
		/// </summary>
		/// <returns>The type of resource contained in the node</returns>
		Resource* getResource() { return m_resource; }

		/// <summary>
		/// Returns the amount of resources contained in the node
		/// </summary>
		/// <returns>The amount of resources contained in the node</returns>
		int getAmount() { return m_amount; }

		/// <summary>
		/// Adds an amount of resources to the node
		/// </summary>
		/// <param name="p_amount">The amount of resources to add</param>
		void addAmount(int p_amount) { m_amount += p_amount; }

	private:
		Resource* m_resource;
		int m_amount;
	};

}

#pragma warning( pop )