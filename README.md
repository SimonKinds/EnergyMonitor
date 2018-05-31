# Requirements
- `cmake`

# Build
```sh
mkdir build
cd build
cmake ..
make
```

# Run
Use pipes to save into files e.g. `./energy-monitor > output-file`
## Instant start
```sh
./energy-monitor
```
## Delayed start
```sh
./energy-monitor 1
```

And then send `SIGUSR1` to start the measurements.
e.g.
```sh
pkill -USR1 energy-monitor
```

# Stopping
Stop with `SIGINT (CTRL-C)` or `SIGTERM`.
