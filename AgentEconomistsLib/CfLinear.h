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
		protected:
			/// <summary>
			/// Coefficient of the linear function.
			/// </summary>
			double m_coef; 
		public:
			CfLinear(double coef);

			/// <summary>
			/// The evaluate method is based on a linear function.
			/// </summary>
			/// <param name="p_nbPossessed"> Number of possessed samples.</param>
			/// <returns>double : the value of the choice.</returns>
			virtual double evaluate(double p_nbPossessed) override;
	};
}

#pragma warning( pop )