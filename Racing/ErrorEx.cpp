#include "ErrorEx.h"

TransportException::TransportException(std::string const& what) : std::domain_error(what)
{}