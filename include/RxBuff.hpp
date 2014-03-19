//!
//! @file 			RxBuff.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/01/09
//! @last-modified 	2014/03/20
//! @brief 			An input buffer for the Rx engine. This can accept a stream of characters and call Rx::Go when the CR character is detected.
//! @details
//!					See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef CLIDE_RX_BUFF_H
#define CLIDE_RX_BUFF_H

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

// System
#include <stdint.h>

// User
#include "Config.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace Clide
{
	//! @brief		An input buffer for the Rx engine. It can accept a stream of characters and call Rx::Go() when the clide_END_OF_COMMAND_CHAR character is detected.
	class RxBuff
	{
	
		public:
		
			//===============================================================================================//
			//==================================== CONSTRUCTORS/DESTRUCTOR ==================================//
			//===============================================================================================//
			
			//! @brief		Constructor
			RxBuff(Rx* rxController);
			
			//===============================================================================================//
			//======================================= PUBLIC METHODS ========================================//
			//===============================================================================================//

			//! @brief		Write a single character to the RxBuff.
			//! @sa			WriteString()
			bool WriteChar(const char character);

			//! @brief		Writes a null-terminated string of characters to the RxBuff.
			//! @sa			WriteChar()
			bool WriteString(const char* characters);

		private:
			
			//===============================================================================================//
			//================================== PRIVATE VARIABLES/STRUCTURES ===============================//
			//===============================================================================================//

			//! @brief		Pointer to the rx controller RxBuff will send characters too once CR had been detected.
			Rx* rxController;

			//! @brief		Rx buffer for storing characters sent to RxBuff by Write().
			char buff[clide_RX_BUFF_SIZE];

			//! @brief		Pointer to current write location in buffer
			uint8_t buffWritePos;

			//===============================================================================================//
			//======================================= PRIVATE METHODS =======================================//
			//===============================================================================================//

			// none

	};


	// none

} // namespace Clide

#endif	// #ifndef CLIDE_RX_BUFF_H

// EOF
