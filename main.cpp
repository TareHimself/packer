

#include "rectpack/rectpack.hpp"

int main()
{

    rectpack::Packer packer(200,200);
    while(true)
    {
        if(auto r = packer.Pack(50,50); !r.has_value())
        {
            break;
        }
    }
    
    return 0;
}
