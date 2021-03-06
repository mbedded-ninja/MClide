//!
//! @file 			Global.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2013-04-02
//! @last-modified 	2014-10-07
//! @brief 		 	Contains global functions and variables used by many MClide classes.
//! @details
//!					See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MCLIDE_GLOBAL_H
#define MCLIDE_GLOBAL_H

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== USER SOURCE =====//
#include "Config.hpp"


namespace MbeddedNinja
{
	namespace MClideNs
	{

		//! @brief		Holds all option variables
		//! @details	Object of this type is passed into Rx.RegisterOption() or Tx.RegisterOption().
		class Global
		{

			public:

				//===============================================================================================//
				//=================================== CONSTRUCTORS/DESTRUCTOR ===================================//
				//===============================================================================================//

				//none
			
				//===============================================================================================//
				//========================================= PUBLIC METHODS ======================================//
				//===============================================================================================//

				// none

				//===============================================================================================//
				//======================================= PUBLIC VARIABLES ======================================//
				//===============================================================================================//
			
				//! @brief		Debug buffer for use for creating debug messages from all functions.
				static char debugBuff[clide_DEBUG_BUFF_SIZE];
		};



	} // namespace MClide
} // namespace MbeddedNinja

#endif	// #ifndef MCLIDE_GLOBAL_H

// EOF
