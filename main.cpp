#include "async.hpp"

using namespace std;

int main() {
  auto context = async::connect();
  async::receive(context, "1", 1);
  async::disconnect(context);

  std::this_thread::sleep_for(std::chrono::minutes(1));

  return 0;
}
