# GRPC

1.Install dependencies:

sudo apt-get install build-essential autoconf libtool pkg-config cmake

sudo apt-get install libgflags-dev libgtest-dev clang libclang-dev

2.Clone the gRPC repository:

git clone --recurse-submodules -b v1.53.0 https://github.com/grpc/grpc

cd grpc

3.Build and install gRPC:

mkdir -p cmake/build

cd cmake/build

cmake ../..

make

sudo make install

4.Install Protocol Buffers: gRPC relies on Protocol Buffers (protobuf) for defining services.

sudo apt-get install protobuf-compiler


5. create .proto file and to generate code:
for example: helloworld.proto
# Run the command to generate C++ files
protoc -I=. --cpp_out=. --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` helloworld.proto