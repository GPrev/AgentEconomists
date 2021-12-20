#pragma once
#include "AbstractChoiceFunction.h"

// Ignore warning 4251 (use of STL in a DLL)
#pragma warning( push )
#pragma warning( disable : 4251 )

namespace agenteconomists
{

	/// <summary>
	/// A choice function based on an inverse funciton.
	/// </summary>
	class AELIB_API CfInverse :
		public AbstractChoiceFunction
	{
		CfInverse();

		/// <summary>
		/// The evaluate method is based on an inverse function.
		/// </summary>
		/// <returns>
		/// double : the value of the choice.
		/// </returns>
		virtual double evaluate(double nbPossessed) override;
	};
}
#pragma warning( pop )
