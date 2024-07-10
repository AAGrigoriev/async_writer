#include "output_handler.hpp"

#include <iostream>

namespace async {

output_handler::output_handler(std::mutex& mutex) : output_mutex_(mutex) {}

void output_handler::handle_command(s_command&& commands) {
  std::lock_guard _(output_mutex_);
  fill_stream(std::cout, commands->commands_);
}

}  // namespace async
