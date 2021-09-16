#include <iostream>
#include "mio/mmap.hpp"
#include <fstream>
#include <typeinfo>
#include <cstdlib>

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

    if (argc < 3){
        std::cout<<"Usage: program path"<<std::endl;
    }
    std::string path = argv[1];
    int val = std::atoi(argv[2]);

    std::error_code error;
    mio::mmap_sink rw_mmap = mio::make_mmap_sink(
            path, 0, mio::map_entire_file, error);
    handle_error(error);
    Buffer* pod = (Buffer*)&(rw_mmap[0]);
    std::cout<< "Old is: " << pod->a<<std::endl;
    pod->a = val;
    // rw_mmap.sync(error);
    // handle_error(error);
    return 0;
}