#include "controller.hpp"

#include <assert.h>
#include <memory>

namespace async {

controller::controller(s_command_queue logging_queue,
                       s_command_queue print_queue)
    : logging_queue_(logging_queue), print_queue_(print_queue) {}

void controller::set_max_depth(const std::size_t max_depth) noexcept {
  depth_.max_depth = max_depth;
}

void controller::process_command(std::vector<std::string>&& commands) {
  const auto create_new_command = [this]() {
    assert(command_accumulator_.current_size());

    auto shared_command =
        std::make_shared<command>(command_accumulator_.create_command());
    logging_queue_->push(shared_command);
    print_queue_->push(shared_command);
  };

  for (auto&& command : commands) {
    if (command == "{") {
      if (depth_.current_depth == 0 && command_accumulator_.current_size()) {
        create_new_command();
        ++depth_.current_depth;
      } else {
        ++depth_.current_depth;
      }
    } else if (command == "}") {
      --depth_.current_depth;

      if (depth_.current_depth < 0) {
        throw std::logic_error("incorrect sequence of characters { and }");
      }

      if (depth_.current_depth == 0 && command_accumulator_.current_size()) {
        create_new_command();
      }
    } else {
      command_accumulator_.store_command(std::move(command));
    }
  }
}

}  // namespace async
