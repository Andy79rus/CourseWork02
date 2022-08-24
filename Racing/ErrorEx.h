#pragma once
#include <stdexcept>

class TransportException : public std::domain_error
{
public:
	TransportException(std::string const& err);
};