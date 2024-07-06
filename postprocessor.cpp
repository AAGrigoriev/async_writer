#include "postprocessor.hpp"

namespace async {

postprocessor::postprocessor(postprocessor_handler::u_handler&& handler,
                             s_command_queue command_queue) {}

void postprocessor::run() {
  s_command result_command;
  while (command_queue_->try_pop(result_command)) {
    handler_->handle_command(std::move(result_command));
  }
}

}  // namespace async
