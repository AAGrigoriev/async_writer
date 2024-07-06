#pragma once

#include "postprocessor_handler.hpp"

namespace async {

class logging_handler : public postprocessor_handler {
 public:
  void handle_command(s_command&& command) override final;
};

}  // namespace async
