#pragma once

#include <memory>

#include "utility.hpp"

namespace async {

class postprocessor_handler {
 public:
  using u_handler = std::unique_ptr<postprocessor_handler>;

 public:
  virtual void handle_command(s_command&& command) = 0;
};

}  // namespace async
