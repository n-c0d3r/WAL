#pragma once

#include <WAL/.BuildInfo>

#include <iostream>
#include <exception>

#include <WAL/AbstractObject.h>
#include <WAL/Singleton.h>
#include <WAL/Log.h>



namespace WAL {

    struct I_Exception {

        WAL::E_LogLevel logLevel;
        std::string content;

    };



	struct S_ErrorException : public I_Exception {

        S_ErrorException(const std::string& content) {
        
            this->content = content;
            logLevel = E_LogLevel::ERROR_;
        
        }

    };



    struct S_FatalException : public I_Exception {

        S_FatalException(const std::string& content) {

            this->content = content;
            logLevel = E_LogLevel::FATAL;

        }

    };

}