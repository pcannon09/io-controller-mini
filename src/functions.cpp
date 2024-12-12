#include "../include/ioController.hpp"

#include <iostream>

int startCallCount = 0;

namespace ioc
{
    /// @brief Makes setup for the program (It's highly recommended)
    void start()
    { 
#if defined(_WIN32)
        platform = "win32";

#elif defined(__linux__) || defined(__APPLE__)
        platform = "linux apple";

#else 
        platform = "linux apple";

#endif
        if (startCallCount < 0)
        {
            errorNoEnd("Error starting code, make sure that variable 'startCallCount' is 0 ( 'startCallCount is'", startCallCount, ")");

            std::exit(1);

        }

        else if (startCallCount > 0)
        {
            warn("Variable 'startCallCount' is bigger than 0, no impact occurred");
        }

        startCallCount++;
    }
}
