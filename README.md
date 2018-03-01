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

### Benchmark - hosting on localhost

Piping logs to /dev/null. Running webserver with 4 threads, same with benchmark app.

``` 
~/github/wrk2  ./wrk -c 100 -t 4 -d 15 -R 60000 http://0.0.0.0:8080                                                                                                                                                                                    master  15.00 Dur  00:17:33 
Running 15s test @ http://0.0.0.0:8080
  4 threads and 100 connections
  Thread calibration: mean lat.: 2.095ms, rate sampling interval: 10ms
  Thread calibration: mean lat.: 2.182ms, rate sampling interval: 10ms
  Thread calibration: mean lat.: 2.048ms, rate sampling interval: 10ms
  Thread calibration: mean lat.: 2.142ms, rate sampling interval: 10ms
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency     1.95ms    1.23ms  16.28ms   83.56%
    Req/Sec    15.82k     1.69k   26.44k    76.11%
  882236 requests in 15.00s, 30.73GB read
Requests/sec:  58813.61
Transfer/sec:      2.05GB
```