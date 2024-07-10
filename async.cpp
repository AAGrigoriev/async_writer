#include "async.hpp"

#include <assert.h>
#include <mutex>

namespace async {

context* connect() {
  static std::mutex output_mutex_;
  return new context(output_mutex_);
}

void receive(context* context, const std::string& data, std::size_t bulk_size) {
  assert(context);

  context->process_command(data, bulk_size);
}

void disconnect(context* context) {
  delete context;
}

}  // namespace async
