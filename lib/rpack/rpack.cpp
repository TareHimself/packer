#define STB_RECT_PACK_IMPLEMENTATION
#include <rpack/rpack.hpp>

namespace rpack
{
    Packer::Packer() : Packer(0,0,0)
    {
        
    }

    Packer::Packer(int width, int height, int padding)
    {
        _padding = padding;
        _nodes.resize(width);
        stbrp_init_target(&_context,width,height,_nodes.data(),static_cast<int>(_nodes.size()));
    }

    std::optional<int> Packer::Pack(int width, int height)
    {
        auto id = static_cast<int>(_rects.size());
        
        auto padding2x = _padding * 2;
        
        stbrp_rect rect{id,width + padding2x,height + padding2x,0,0,false};
        
        if(stbrp_pack_rects(&_context,&rect,1) == 0)
        {
            return {};
        }
        
        _rects.emplace_back(id,rect.x - _padding,rect.y - _padding,rect.w - padding2x,rect.h - padding2x);
        
        return id;
    }

    std::vector<Packer::Rect>& Packer::GetRects()
    {
        return _rects;
    }

    int Packer::GetWidth() const
    {
        return _context.width;
    }

    int Packer::GetHeight() const
    {
        return _context.height;
    }

    // std::o Packer::Pack(int width, int height)
    // {
    //     stbrp_
    //     stbrp_pack_rects()
    // }
}
