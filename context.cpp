#include "context.hpp"

#include "parser.hpp"

namespace async {

context::context() : controller_(logging_queue_, output_queue_) {}

void context::process_command(std::string command, std::size_t bulk_size) {
  auto result = parser().parse_command(command);
  controller_.set_max_depth(bulk_size);
  controller_.process_command(std::move(result));
}

}  // namespace async
