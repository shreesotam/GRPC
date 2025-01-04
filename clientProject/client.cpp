#include <grpcpp/grpcpp.h>
#include "helloworld.grpc.pb.h"

int main() {
    std::string target_str = "localhost:50051";
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials());
    std::unique_ptr<helloworld::Greeter::Stub> stub = helloworld::Greeter::NewStub(channel);

    helloworld::HelloRequest request;
    request.set_name("World");

    helloworld::HelloReply reply;
    grpc::ClientContext context;

    grpc::Status status = stub->SayHello(&context, request, &reply);

    if (status.ok()) {
        std::cout << "Greeting: " << reply.message() << std::endl;
    } else {
        std::cout << "RPC failed" << std::endl;
    }

    return 0;
}
