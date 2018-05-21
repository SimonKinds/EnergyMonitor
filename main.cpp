#include <csignal>
#include <cstdio>
#include <thread>

#include "getnode.h"

namespace {
bool running = true;
void signal_handler(int) { running = false; }
} // namespace

int main() {
  GetNode nodes;

  if (nodes.OpenINA231() != 0) {
    puts("Could not open sensors\n");
    return 1;
  }

  std::signal(SIGINT, signal_handler);
  std::signal(SIGTERM, signal_handler);
  std::signal(SIGHUP, signal_handler);

  puts("a15-watt, a17-watt, gpu-watt, mem-watt\n");

  while (running) {
    nodes.GetINA231();

    printf("%f, %f, %f, %f\n", nodes.armuW, nodes.kfcuW, nodes.g3duW,
           nodes.memuW);

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  nodes.CloseINA231();
}
