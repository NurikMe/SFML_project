#pragma once

#include <exception>;
#include <string>

namespace Exceptions {
	class ReqPropsNotSpecified : public std::exception {
    public:
        ReqPropsNotSpecified(const std::string& message = "Body and Textures must be specified") : message{message} {}

        const char* what() const noexcept override;
    private:
        std::string message;    // error message
	};
}