//!
//! @file 			Rx.hpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2012-03-19
//! @last-modified 	2014-10-09
//! @brief 			Clide RX controller. The main logic of the RX (decoding) part of Clide. Commands can be registered with the controller.
//! @details
//!					See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MCLIDE_RX_H
#define MCLIDE_RX_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	namespace MClideNs
	{
		class Rx;
	}
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <stdint.h>

//===== USER SOURCE =====//
#include "Config.hpp"
#include "Param.hpp"
#include "Option.hpp"
#include "Cmd.hpp"
#include "GetOpt.hpp"
#include "Comm.hpp"


namespace MbeddedNinja
{
	namespace MClideNs
	{
	
		//! @brief		Class deals with receiving of command-line strings and the decoding/processing of them.
		//! @details	This is one of the most important objects in the Clide library. Inherits from the Comm class.
		class Rx : public Comm
		{
		
			public:
			
				//! @brief		Log IDs for Rx relevant warnings/errors.
				enum class LogIds : uint32_t
				{
					NONE,
					CMD_NOT_RECOGNISED
				};

				//===============================================================================================//
				//=================================== PUBLIC VARIABLES/STRUCTURES ===============================//
				//===============================================================================================//

				//! @brief		Set to true to silence (not print) an error when a received message is not recognised as a valid command.
				//! @details	Default is false, as it is usually helpful to show this error.
				bool silenceCmdNotRecognisedError;

				//! @brief		When set to true, the first element in the argv is ignored by the decoding engine (i.e. is not
				//!				not considered part of the command). The first element of argv in a standard operating system
				//!				is the program name (and path) that was typed to run the program, hence you might want this ignored,
				//!				and treat the second element as the command instead.
				//! @details	Only applicable when calling Run(int argc, char* argv[]). Defaults to true.
				bool ignoreFirstArgvElement;

				//===============================================================================================//
				//======================================= PUBLIC METHODS ========================================//
				//===============================================================================================//

				//! @brief		Base constructor
				Rx(bool enableHelpNoHeaderOption);

				//! @brief		Simplified constructor.
				Rx();

				//! @brief		Destructor.
				~Rx();

				//! @brief		Runs the algorithm. Call this with the received command msg (array of characters).
				//! @details	In a Linux environment, cmdMsg could be equal to a read line of cin. Calls Rx::Run2().
				//! @param		cmdMsg	The message to process.
				//! @returns	true is the command processing of cmdMsg was successful, otherwise false.
				//! @sa			bool Run(int argc, char* argv[])
				bool Run(char * cmdMsg);

				//! @brief		Runs the algorithm, using standard main() variables (argc, argv) as input. Use this function when you are calling a program from the command-line and are passing in variables to argc and argv. These can be passed directly to this function.
				//! @details	Calls Rx::Run2().
				//! @sa			bool Run(char * cmdMsg)
				bool Run(int argc, char * argv[]);

			private:


				//===============================================================================================//
				//======================================= PRIVATE METHODS =======================================//
				//===============================================================================================//

				//! @brief		Initialisation method called by all of Rx constructors.
				void Init(bool enableHelpNoHeaderOption);

				//! @brief		Internal run command, called by the public Run() functions after some specific processing.
				int Run2(uint8_t numArgs, char * _args[]);

				//! @brief		Validates command.
				//! @details	Makes sure cmd is in the registered command list
				Cmd * ValidateCmd(char * cmdName, MVector<Cmd*> cmdA);

				//! @brief		Checks for option in registered command
				Option * ValidateOption(Cmd * detectedCmd, char * optionName);

				//! @brief		Splits packet into arguments, which can be options and/or parameters.
				//! @returns	Number of arguments found
				int SplitPacket(char * packet, char * argv[]);

				//! @brief		Builds the short option string for the getopt_long() function from the list
				//!				of the registered commands.
				void BuildShortOptionString(char * optionString, Cmd * cmd);

				//! @brief		Builds the structure of long options that is required by getopt_long().
				void BuildLongOptionStruct(GetOpt::option * longOptStructA, Cmd * cmd);

				//===============================================================================================//
				//================================== PRIVATE VARIABLES/STRUCTURES ===============================//
				//===============================================================================================//

				//! @brief		Pointer to automatically created (in Rx constructor) help command.
				Cmd * cmdHelp;

				Option * cmdHelpOption;


		};

	} // namespace MClide
} // namespace MbeddedNinja

#endif	// #ifndef MCLIDE_RX_H

// EOF
