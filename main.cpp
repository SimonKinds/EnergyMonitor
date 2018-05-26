#include <csignal>
#include <cstdio>
#include <thread>

#include "getnode.h"

namespace {
bool start = true;
bool stop = false;
void signal_handler_start(int) { start = true; }
void signal_handler_stop(int) { stop = true; }
} // namespace

int main(int argc, char **argv) {
  start = argc < 2;

  GetNode nodes;

  if (nodes.OpenINA231() != 0) {
    puts("Could not open sensors\n");
    return 1;
  }

  std::signal(SIGUSR1, signal_handler_start);
  std::signal(SIGINT, signal_handler_stop);
  std::signal(SIGTERM, signal_handler_stop);
  std::signal(SIGHUP, signal_handler_stop);

  while(!start){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  puts("a15-watt, a17-watt, gpu-watt, mem-watt\n");
  while (start && !stop) {
    nodes.GetINA231();

    printf("%f, %f, %f, %f\n", nodes.armuW, nodes.kfcuW, nodes.g3duW,
           nodes.memuW);

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  nodes.CloseINA231();
}
