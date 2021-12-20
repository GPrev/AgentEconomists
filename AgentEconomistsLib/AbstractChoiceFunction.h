#pragma once

#include "AgentEconomistsLib.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// An abstract class that will be reimplemented by child classes to evaluate the gain of an action.
	/// </summary>
	class AELIB_API AbstractChoiceFunction {
	protected:

	public:
		AbstractChoiceFunction();

		/// <summary>
		/// Evaluate the gain of an action.
		/// </summary>
		/// <param name="p_nbPossessed"> Number of possessed samples.</param>
		/// <returns>double: the "value" of the action.</returns>
		virtual double evaluate(double p_nbPossessed) = 0;
	};
}

#pragma warning( pop )