#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "src/proto/greeter.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using greeter::GreeterService;
using greeter::HelloRequest;
using greeter::HelloReply;

class GreeterClient {
 public:
  GreeterClient(std::shared_ptr<Channel> channel)
      : stub_(GreeterService::NewStub(channel)) {}

  std::string SayHello(const std::string& user) {
    HelloRequest request;
    request.set_name(user);
    HelloReply reply;
    ClientContext context;

    Status status = stub_->SayHello(&context, request, &reply);

    if (status.ok()) {
      return reply.message();
    } else {
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<GreeterService::Stub> stub_;
};

int main(int argc, char** argv) {
  std::string target_str = "localhost:50051";
  GreeterClient greeter(grpc::CreateChannel(
      target_str, grpc::InsecureChannelCredentials()));
  std::string user("Bazel User");
  std::string reply = greeter.SayHello(user);
  std::cout << "Greeter received: " << reply << std::endl;
  return 0;
}