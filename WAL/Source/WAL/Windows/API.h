#pragma once

#include <WAL/.BuildInfo>

#include <WAL/Utils.h>

#include <WAL/API.h>



namespace WAL {

    namespace Windows {

        class C_API :
            public I_API
        {

        private:




        public:
            C_API();
            virtual void Release() override;

            virtual bool CheckMessage() override;

        };

    }

}