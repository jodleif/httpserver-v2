#include "binary_file.h"
#include "hash_literal.h"
// Expected files for one-page supplescroll
/*extern "C" const char _binary_dark_css_start;
extern "C" const char _binary_dark_css_end;*/
extern "C" const char _binary_index_html_gz_start;
extern "C" const char _binary_index_html_gz_end;
/*
extern "C" const char _binary_supplescroll_css_start;
extern "C" const char _binary_supplescroll_css_end;
extern "C" const char _binary_supplescroll_min_js_start;
extern "C" const char _binary_supplescroll_min_js_end;*/
constexpr char empty_file[] = "";

namespace blob_files {
namespace {
constexpr boost::beast::string_view
fetch_blob(const char* const start, const char* const end)
{
    const std::size_t len{ static_cast<std::size_t>(end - start) };
    return boost::beast::string_view(start, len);
}
}
using namespace util::literals;

boost::beast::string_view
get_file(std::string path)
{
    switch (util::fnv1a(path.data(), path.length())) {
        case "/"_f:
        case "/index.html"_f:
            return fetch_blob(&_binary_index_html_gz_start, &_binary_index_html_gz_end);
        case "/supplescroll.css"_f:
            /*return fetch_blob(&_binary_supplescroll_css_start,
                              &_binary_supplescroll_css_end);*/
        case "/dark.css"_f:
            /*return fetch_blob(&_binary_dark_css_start, &_binary_dark_css_end);*/
        case "/supplescroll.min.js"_f:
            /*return fetch_blob(&_binary_supplescroll_min_js_start,
                              &_binary_supplescroll_min_js_end);*/
        default:
            return empty_file;
    }
}
}
