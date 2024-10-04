#pragma once
#include <vector>
#include <optional>
#include <stb/stb_rect_pack.h>
namespace rpack
{
    
    class Packer
    {
    public:
        struct Rect
        {
            int id{0};
            int x{0};
            int y{0};
            int width{0};
            int height{0};
        };
    private:
        std::vector<stbrp_node> _nodes{};
        stbrp_context _context{};
        std::vector<Rect> _rects{};
        int _padding = 0;

    public:
        Packer(int width, int height,int padding = 0);

        std::optional<int> Pack(int width,int height);

        std::vector<Rect> GetRects() const;
    };
}