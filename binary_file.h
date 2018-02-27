#pragma once

#include <boost/beast/core/string.hpp>
#include <string>
namespace blob_files {
boost::beast::string_view
get_file(std::string path);
}
