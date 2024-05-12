# HevSocks5Server

[![status](https://github.com/heiher/hev-socks5-server/actions/workflows/build.yaml/badge.svg?branch=master&event=push)](https://github.com/heiher/hev-socks5-server)

HevSocks5Server is a simple, lightweight socks5 server for Unix.

## Features

* IPv4/IPv6. (dual stack)
* Standard `CONNECT` command.
* Standard `UDP ASSOCIATE` command.
* Extended `FWD UDP` command. (UDP in TCP)
* Multiple username/password authentication.

## Benchmarks

See [here](https://github.com/heiher/hev-socks5-server/wiki/Benchmarks) for more details.

### Speed

![](https://github.com/heiher/hev-socks5-server/wiki/res/upload-speed.png)
![](https://github.com/heiher/hev-socks5-server/wiki/res/download-speed.png)

### CPU usage

![](https://github.com/heiher/hev-socks5-server/wiki/res/upload-cpu.png)
![](https://github.com/heiher/hev-socks5-server/wiki/res/download-cpu.png)

### Memory usage

![](https://github.com/heiher/hev-socks5-server/wiki/res/upload-mem.png)
![](https://github.com/heiher/hev-socks5-server/wiki/res/download-mem.png)

## How to Build

### Unix

```bash
git clone --recursive https://github.com/heiher/hev-socks5-server
cd hev-socks5-server
make

# statically link
make ENABLE_STATIC=1
```

### Android

```bash
mkdir hev-socks5-server
cd hev-socks5-server
git clone --recursive https://github.com/heiher/hev-socks5-server jni
cd jni
ndk-build
```

## How to Use

### Config

```yaml
main:
  # Worker threads
  workers: 4
  # Listen port
  port: 1080
  # Listen address (ipv4|ipv6)
  listen-address: '::'
  # UDP listen port
  udp-port: 1080
  # UDP listen address (ipv4|ipv6)
# udp-listen-address: '::1'
  # Listen ipv6 only
  listen-ipv6-only: false
  # Bind source address (ipv4|ipv6)
  bind-address: '::'
  # Domain address type (ipv4|ipv6|unspec)
  domain-address-type: unspec

#auth:
#  file: conf/auth.txt
#  username:
#  password:

#misc:
   # task stack size (bytes)
#  task-stack-size: 8192
   # connect timeout (ms)
#  connect-timeout: 5000
   # read-write timeout (ms)
#  read-write-timeout: 60000
   # stdout, stderr or file-path
#  log-file: stderr
   # debug, info, warn or error
#  log-level: warn
   # If present, run as a daemon with this pid file
#  pid-file: /run/hev-socks5-server.pid
   # If present, set rlimit nofile; else use default value
#  limit-nofile: 65535
```

### Authentication file

```
<USERNAME> <SPACE> <PASSWORD> <SPACE> <MARK> <LF>
```

### Run

```bash
bin/hev-socks5-server conf/main.yml
```

### Live updating authentication file

Send signal `SIGUSR1` to socks5 server process after the authentication file is updated.

```bash
killall -SIGUSR1 hev-socks5-server
```

## Contributors

* **Ammar Faizi** - https://github.com/ammarfaizi2
* **hev** - https://hev.cc
* **pexcn** - <i@pexcn.me>

## License

GPLv3
