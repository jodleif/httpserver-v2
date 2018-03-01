#pragma once

namespace util {
constexpr static uint64_t fnv_prime_64{ 1'099'511'628'211ull };
constexpr static uint64_t offset_basis_64{ 14'695'981'039'346'656'037ull };

constexpr uint64_t
fnv1a(const char* str, std::size_t len)
{
    uint64_t hash{ offset_basis_64 };
    auto * end = str + len;
    while(str!=end) {
        hash ^= uint64_t(*str++);
        hash *= fnv_prime_64;
    }
    return hash;
}

namespace literals {
constexpr uint64_t operator"" _f(const char* str, std::size_t len)
{
    return fnv1a(str, len);
}
} // end namespace literals
} // end namespace util
