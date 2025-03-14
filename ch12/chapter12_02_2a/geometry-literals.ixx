export module geometry:literals;

import :core;
import :details;

namespace geometry_literals
{
   export int_point operator ""_ip(const char* ptr, std::size_t)
   {
     auto [x, y]  = split(ptr);
     return {x, y};
   }
}
