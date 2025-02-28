#include "ReqPropsNotSpecified.h"

using namespace Exceptions;

const char* ReqPropsNotSpecified::what() const noexcept 
{
    return message.c_str();
}