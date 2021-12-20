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
		protected :
			/// <summary>
			/// Coefficient of the inverse function.
			/// </summary>
			double m_coef;
		public:
			CfInverse(double coef);

			/// <summary>
			/// The evaluate method is based on an inverse function.
			/// </summary>
			/// <param name="p_nbPossessed"> Number of possessed samples.</param>
			/// <returns>double : the value of the choice.</returns>
			virtual double evaluate(double p_nbPossessed) override;
	};
}
#pragma warning( pop )
