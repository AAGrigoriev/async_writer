#pragma once

#include <thread>

#include "controller.hpp"
#include "utility.hpp"

namespace async {

class context {
 public:
  context();

  void process_command(std::string command, std::size_t bulk_count);

 private:
  s_command_queue logging_queue_;
  s_command_queue output_queue_;
  controller controller_;

  std::jthread first_logger_thread_;
  std::jthread second_logger_thread_;
  std::jthread output_thread_;
};

}  // namespace async
