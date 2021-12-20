#pragma once
#include "AbstractChoiceFunction.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// A choice function based on a Bezier function.
	/// </summary>
	class AELIB_API CfBezier :
		public AbstractChoiceFunction
	{
		CfBezier();

		/// <summary>
		/// The evaluate method is based on a bezier function.
		/// </summary>
		/// /// <param name="p_nbPossessed"> Number of possessed samples.</param>
		/// <returns>double: the value of the choice.</returns>
		virtual double evaluate(double p_nbPossessed) override;
	};
}

