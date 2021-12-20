#pragma once

#include <map>
#include "AgentEconomistsLib.h"
#include "Resource.h"
#include "Agent.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// 
	/// </summary>
	class Market
	{
	protected:
		/// <summary>
		/// Market price for each resource.
		/// </summary>
		std::map<Resource*, double> m_marketPrice;
	public:
		Market();

		/// <summary>
		/// Register a buyer price.
		/// </summary>
		/// <param name="p_agent">Agent who wants to buy something.</param>
		/// <param name="p_res">Resource he wants to buy.</param>
		/// <param name="p_qte">Quantity he wants to buy.</param>
		/// <param name="p_price">Price he proposes.</param>
		void registerWTB(Agent* p_agent, Resource* p_res, int p_qte, double p_price);

		/// <summary>
		/// Register a seller price.
		/// </summary>
		/// <param name="p_agent">Agent who wants to sell something.</param>
		/// <param name="p_res">Resource he wants to sell.</param>
		/// <param name="p_qte">Quantity he wants to sell.</param>
		/// <param name="p_price">Price he proposes.</param>
		void registerWTS(Agent* p_agent, Resource* p_res, int p_qte, double p_price);

		/// <summary>
		/// Sort the buying and selling offers, make a sell when possible and update the mean price of each resource.
		/// </summary>
		void matchAndSell();
	};

}

#pragma warning( pop )