#include <string>

namespace GlobalFunctions
{
    void convertStringToUpperCaps(std::string zeStr)
    {
        for (std::string::iterator it = zeStr.begin(), end = zeStr.end(); it != end; ++it)
        {
            (*it) = toupper(*it);
        }
    }
};