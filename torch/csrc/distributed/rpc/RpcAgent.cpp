#include <torch/csrc/distributed/rpc/RpcAgent.h>

namespace torch {
namespace distributed {
namespace rpc {

RpcAgent::RpcAgent(std::string workerName, uint64_t id, RequestCallback cb)
    : workerName_(std::move(workerName)), id_(id), cb_(std::move(cb)) {}

RpcAgent::~RpcAgent() = default;

}
}
}
