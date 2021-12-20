#pragma once
#include "AbstractChoiceFunction.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// A choice function based on a linear funciton.
	/// </summary>
	class AELIB_API CfLinear :
		public AbstractChoiceFunction
	{
		CfLinear();

		/// <summary>
		/// The evaluate method is based on a linear function.
		/// </summary>
		/// <param name="nbPossessed"> Number of possessed samples.</param>
		/// <returns>double : the value of the choice.</returns>
		virtual double evaluate(double nbPossessed) override;
	};
}

#pragma warning( pop )