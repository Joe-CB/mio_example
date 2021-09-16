#include <iostream>
#include "mio/mmap.hpp"
#include <fstream>
#include <typeinfo>

struct Buffer{
    int a;
    int b;
    int c;
    int d;
};

int handle_error(const std::error_code& error)
{
    const auto& errmsg = error.message();
    std::printf("error mapping file: %s, exiting...\n", errmsg.c_str());
    return error.value();
}

void allocate_file(const std::string& path, const int size)
{
    std::ofstream file(path);
    std::string s(size, '0');
    file << s;
}

int main(int argc, char **argv){

    if (argc < 2){
        std::cout<<"Usage: program path"<<std::endl;
    }
    std::string path = argv[1];

    allocate_file(path, sizeof(Buffer));

    std::error_code error;
    mio::mmap_sink mmap = mio::make_mmap_sink(
            path, 0, mio::map_entire_file, error);
    handle_error(error);
    Buffer* pod = (Buffer*)&(mmap[0]);
    while(true){
        std::cout<<pod->a<<"  " << pod->b << "  " << pod->c << "  " << pod->d <<std::endl;
    }
    return 0;
}