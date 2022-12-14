#include "Log.h"
#include <WAL/Exception.h>
#include <WAL/Utils.h>



#ifdef _WIN32
#define WAL_SET_CONSOLE_COLOR(color) \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#endif



namespace WAL {

	namespace HN_Log
	{

        void Info(const std::string& content){

            WAL_SET_CONSOLE_COLOR(0xF0);

            std::cout << " INFO ";

            WAL_SET_CONSOLE_COLOR(0x07);

            std::cout << " " << content << std::endl;

        }
        void Warn(const std::string& content) {

            WAL_SET_CONSOLE_COLOR(0xE0);

            std::cout << " WARN ";

            WAL_SET_CONSOLE_COLOR(0x06);

            std::cout << " " << content << std::endl;

        }
        void Error(const std::string& content) {

            WAL_SET_CONSOLE_COLOR(0xC0);

            std::cout << " Error ";

            WAL_SET_CONSOLE_COLOR(0x0C);

            std::cout << " " << content << std::endl;

        }
        void Fatal(const std::string& content) {

            WAL_SET_CONSOLE_COLOR(0xD0);

            std::cout << " Fatal ";

            WAL_SET_CONSOLE_COLOR(0x50);

            std::cout << " " << content << " " << std::endl;

            exit(1);

        }

        void Exception(const I_Exception& e) {

            switch (e.logLevel)
            {
            case WAL::E_LogLevel::INFO:
                Info(e.content);
                break;
            case WAL::E_LogLevel::WARN:
                Warn(e.content);
                break;
            case WAL::E_LogLevel::ERROR_:
                Error(e.content);
                break;
            case WAL::E_LogLevel::FATAL:
                Fatal(e.content);
                break;
            default:
                break;
            }

        }

	};

}