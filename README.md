# Constexpr hosting with Boost/Beast

Linking a unified html / js / css gzipped-bundle into the binary and it hosting directly from memory.

### Compiled on

- debian testing and ubuntu 18.04
- boost 1.62
- gcc 7.3.0 / 7.2.0

### Preview

[jooivind.com](jooivind.com) - Hosted on the smallest Digital Ocean droplet available.

### Building

Clone repo and cd into it, then:
```
mkdir build
cd build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ../

```