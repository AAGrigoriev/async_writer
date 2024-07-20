#pragma once

#include "postprocessor_handler.hpp"

namespace async {

class output_handler : public postprocessor_handler {
 public:
  output_handler();
  void handle_command(s_command&& command) override final;

 private:
  static std::mutex output_mutex;
};

}  // namespace async
