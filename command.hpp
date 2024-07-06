#pragma once

#include <chrono>
#include <string>
#include <vector>

namespace async {

struct command {
  using commands = std::vector<std::string>;
  using time_point = std::chrono::time_point<std::chrono::steady_clock>;

  command(command&& command) ;
  command(commands commands, time_point time_point);

  std::vector<std::string> commands_;
  time_point time_point_;
};

}  // namespace async
