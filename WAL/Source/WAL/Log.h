#pragma once

#include <WAL/.BuildInfo>

#include <iostream>
#include <exception>

#include <WAL/AbstractObject.h>
#include <WAL/Singleton.h>



namespace WAL {

    struct I_Exception;



    enum class E_LogLevel {

        INFO = 0,
        WARN = 1,
        ERROR_ = 2,
        FATAL = 3

    };



	namespace HN_Log
	{

        extern void Info(const std::string& content);
        extern void Warn(const std::string& content);
        extern void Error(const std::string& content);
        extern void Fatal(const std::string& content);

        extern void Exception(const I_Exception& e);

	};

}