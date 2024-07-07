#include "output_handler.hpp"

#include <iostream>

namespace async {

void output_handler::handle_command(s_command&& commands) {
  fill_stream(std::cout, commands->commands_);
}

}  // namespace async
