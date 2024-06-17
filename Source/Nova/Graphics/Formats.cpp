/**
 * @File Formats.cpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/16
 * @Brief This file is part of Nova.
 */

#include "./Formats.hpp"
#include "./NativeFormats.hpp"

namespace nova {
const FormatDesc kFormatDesc[] = {
  // clang-format off
    // Format                           Name,           BytesPerBlock ChannelCount  Type          {bDepth,   bStencil, bCompressed},   {CompressionRatio.Width,     CompressionRatio.Height}    {numChannelBits.x, numChannelBits.y, numChannelBits.z, numChannelBits.w}
    {Format::Unknown,            "Unknown",         0,              0,  FormatType::Unknown,    {false,  false, false,},        {1, 1},                                                  {0, 0, 0, 0    }},
    {Format::R8Unorm,            "R8Unorm",         1,              1,  FormatType::Unorm,      {false,  false, false,},        {1, 1},                                                  {8, 0, 0, 0    }},
    {Format::R8Snorm,            "R8Snorm",         1,              1,  FormatType::Snorm,      {false,  false, false,},        {1, 1},                                                  {8, 0, 0, 0    }},
    {Format::R16Unorm,           "R16Unorm",        2,              1,  FormatType::Unorm,      {false,  false, false,},        {1, 1},                                                  {16, 0, 0, 0   }},
    {Format::R16Snorm,           "R16Snorm",        2,              1,  FormatType::Snorm,      {false,  false, false,},        {1, 1},                                                  {16, 0, 0, 0   }},
    {Format::RG8Unorm,           "RG8Unorm",        2,              2,  FormatType::Unorm,      {false,  false, false,},        {1, 1},                                                  {8, 8, 0, 0    }},
    {Format::RG8Snorm,           "RG8Snorm",        2,              2,  FormatType::Snorm,      {false,  false, false,},        {1, 1},                                                  {8, 8, 0, 0    }},
    {Format::RG16Unorm,          "RG16Unorm",       4,              2,  FormatType::Unorm,      {false,  false, false,},        {1, 1},                                                  {16, 16, 0, 0  }},
    {Format::RG16Snorm,          "RG16Snorm",       4,              2,  FormatType::Snorm,      {false,  false, false,},        {1, 1},                                                  {16, 16, 0, 0  }},
    {Format::RGB5A1Unorm,        "RGB5A1Unorm",     2,              4,  FormatType::Unorm,      {false,  false, false,},        {1, 1},                                                  {5, 5, 5, 1    }},
    {Format::RGBA8Unorm,         "RGBA8Unorm",      4,              4,  FormatType::Unorm,      {false,  false, false,},        {1, 1},                                                  {8, 8, 8, 8    }},
    {Format::RGBA8Snorm,         "RGBA8Snorm",      4,              4,  FormatType::Snorm,      {false,  false, false,},        {1, 1},                                                  {8, 8, 8, 8    }},
    {Format::RGB10A2Unorm,       "RGB10A2Unorm",    4,              4,  FormatType::Unorm,      {false,  false, false,},        {1, 1},                                                  {10, 10, 10, 2 }},
    {Format::RGB10A2Uint,        "RGB10A2Uint",     4,              4,  FormatType::Uint,       {false,  false, false,},        {1, 1},                                                  {10, 10, 10, 2 }},
    {Format::RGBA16Unorm,        "RGBA16Unorm",     8,              4,  FormatType::Unorm,      {false,  false, false,},        {1, 1},                                                  {16, 16, 16, 16}},
    {Format::RGBA16Snorm,        "RGBA16Snorm",     8,              4,  FormatType::Snorm,      {false,  false, false,},        {1, 1},                                                  {16, 16, 16, 16}},
    {Format::RGBA8UnormSrgb,     "RGBA8UnormSrgb",  4,              4,  FormatType::UnormSrgb,  {false,  false, false,},        {1, 1},                                                  {8, 8, 8, 8    }},
    // Format                           Name,           BytesPerBlock ChannelCount  Type          {bDepth,   bStencil, bCompressed},   {CompressionRatio.Width,     CompressionRatio.Height}
    {Format::R16Float,           "R16Float",        2,              1,  FormatType::Float,      {false,  false, false,},        {1, 1},                                                  {16, 0, 0, 0   }},
    {Format::RG16Float,          "RG16Float",       4,              2,  FormatType::Float,      {false,  false, false,},        {1, 1},                                                  {16, 16, 0, 0  }},
    {Format::RGBA16Float,        "RGBA16Float",     8,              4,  FormatType::Float,      {false,  false, false,},        {1, 1},                                                  {16, 16, 16, 16}},
    {Format::R32Float,           "R32Float",        4,              1,  FormatType::Float,      {false,  false, false,},        {1, 1},                                                  {32, 0, 0, 0   }},
    {Format::RG32Float,          "RG32Float",       8,              2,  FormatType::Float,      {false,  false, false,},        {1, 1},                                                  {32, 32, 0, 0  }},
    {Format::RGB32Float,         "RGB32Float",      12,             3,  FormatType::Float,      {false,  false, false,},        {1, 1},                                                  {32, 32, 32, 0 }},
    {Format::RGBA32Float,        "RGBA32Float",     16,             4,  FormatType::Float,      {false,  false, false,},        {1, 1},                                                  {32, 32, 32, 32}},
    {Format::R11G11B10Float,     "R11G11B10Float",  4,              3,  FormatType::Float,      {false,  false, false,},        {1, 1},                                                  {11, 11, 10, 0 }},
    {Format::RGB9E5Float,        "RGB9E5Float",     4,              3,  FormatType::Float,      {false,  false, false,},        {1, 1},                                                  {9, 9, 9, 5    }},
    {Format::R8Int,              "R8Int",           1,              1,  FormatType::Int,       {false,  false, false,},        {1, 1},                                                  {8, 0, 0, 0    }},
    {Format::R8Uint,             "R8Uint",          1,              1,  FormatType::Uint,       {false,  false, false,},        {1, 1},                                                  {8, 0, 0, 0    }},
    {Format::R16Int,             "R16Int",          2,              1,  FormatType::Int,       {false,  false, false,},        {1, 1},                                                  {16, 0, 0, 0   }},
    {Format::R16Uint,            "R16Uint",         2,              1,  FormatType::Uint,       {false,  false, false,},        {1, 1},                                                  {16, 0, 0, 0   }},
    {Format::R32Int,             "R32Int",          4,              1,  FormatType::Int,       {false,  false, false,},        {1, 1},                                                  {32, 0, 0, 0   }},
    {Format::R32Uint,            "R32Uint",         4,              1,  FormatType::Uint,       {false,  false, false,},        {1, 1},                                                  {32, 0, 0, 0   }},
    {Format::RG8Int,             "RG8Int",          2,              2,  FormatType::Int,       {false,  false, false,},        {1, 1},                                                  {8, 8, 0, 0    }},
    {Format::RG8Uint,            "RG8Uint",         2,              2,  FormatType::Uint,       {false,  false, false,},        {1, 1},                                                  {8, 8, 0, 0    }},
    {Format::RG16Int,            "RG16Int",         4,              2,  FormatType::Int,       {false,  false, false,},        {1, 1},                                                  {16, 16, 0, 0  }},
    {Format::RG16Uint,           "RG16Uint",        4,              2,  FormatType::Uint,       {false,  false, false,},        {1, 1},                                                  {16, 16, 0, 0  }},
    {Format::RG32Int,            "RG32Int",         8,              2,  FormatType::Int,       {false,  false, false,},        {1, 1},                                                  {32, 32, 0, 0  }},
    {Format::RG32Uint,           "RG32Uint",        8,              2,  FormatType::Uint,       {false,  false, false,},        {1, 1},                                                  {32, 32, 0, 0  }},
    // Format                           Name,           BytesPerBlock ChannelCount  Type          {bDepth,   bStencil, bCompressed},   {CompressionRatio.Width,     CompressionRatio.Height}
    {Format::RGB32Int,           "RGB32Int",       12,              3,  FormatType::Int,       {false,  false, false,},        {1, 1},                                                  {32, 32, 32, 0 }},
    {Format::RGB32Uint,          "RGB32Uint",      12,              3,  FormatType::Uint,       {false,  false, false,},        {1, 1},                                                  {32, 32, 32, 0 }},
    {Format::RGBA8Int,           "RGBA8Int",        4,              4,  FormatType::Int,       {false,  false, false,},        {1, 1},                                                  {8, 8, 8, 8    }},
    {Format::RGBA8Uint,          "RGBA8Uint",       4,              4,  FormatType::Uint,       {false,  false, false,},        {1, 1},                                                  {8, 8, 8, 8    }},
    {Format::RGBA16Int,          "RGBA16Int",       8,              4,  FormatType::Int,       {false,  false, false,},        {1, 1},                                                  {16, 16, 16, 16}},
    {Format::RGBA16Uint,         "RGBA16Uint",      8,              4,  FormatType::Uint,       {false,  false, false,},        {1, 1},                                                  {16, 16, 16, 16}},
    {Format::RGBA32Int,          "RGBA32Int",      16,              4,  FormatType::Int,       {false,  false, false,},        {1, 1},                                                  {32, 32, 32, 32}},
    {Format::RGBA32Uint,         "RGBA32Uint",     16,              4,  FormatType::Uint,       {false,  false, false,},        {1, 1},                                                  {32, 32, 32, 32}},
    {Format::BGRA4Unorm,         "BGRA4Unorm",      2,              4,  FormatType::Unorm,      {false,  false, false,},        {1, 1},                                                  {4, 4, 4, 4    }},
    {Format::BGRA8Unorm,         "BGRA8Unorm",      4,              4,  FormatType::Unorm,      {false,  false, false,},        {1, 1},                                                  {8, 8, 8, 8    }},
    {Format::BGRA8UnormSrgb,     "BGRA8UnormSrgb",  4,              4,  FormatType::UnormSrgb,  {false,  false, false,},        {1, 1},                                                  {8, 8, 8, 8    }},
    {Format::BGRX8Unorm,         "BGRX8Unorm",      4,              4,  FormatType::Unorm,      {false,  false, false,},        {1, 1},                                                  {8, 8, 8, 8    }},
    {Format::BGRX8UnormSrgb,     "BGRX8UnormSrgb",  4,              4,  FormatType::UnormSrgb,  {false,  false, false,},        {1, 1},                                                  {8, 8, 8, 8    }},
    // Format                           Name,           BytesPerBlock ChannelCount  Type          {bDepth,   bStencil, bCompressed},   {CompressionRatio.Width,     CompressionRatio.Height}
    {Format::R5G6B5Unorm,        "R5G6B5Unorm",     2,              3,  FormatType::Unorm,      {false,  false, false,},        {1, 1},                                                  {5, 6, 5, 0    }},
    {Format::D32Float,           "D32Float",        4,              1,  FormatType::Float,      {true,   false, false,},        {1, 1},                                                  {32, 0, 0, 0   }},
    {Format::D32FloatS8Uint,     "D32FloatS8Uint",  4,              1,  FormatType::Float,      {true,   true,  false,},        {1, 1},                                                  {32, 0, 0, 0   }},
    {Format::D16Unorm,           "D16Unorm",        2,              1,  FormatType::Unorm,      {true,   false, false,},        {1, 1},                                                  {16, 0, 0, 0   }},
    {Format::BC1Unorm,           "BC1Unorm",        8,              3,  FormatType::Unorm,      {false,  false, true, },        {4, 4},                                                  {64, 0, 0, 0   }},
    {Format::BC1UnormSrgb,       "BC1UnormSrgb",    8,              3,  FormatType::UnormSrgb,  {false,  false, true, },        {4, 4},                                                  {64, 0, 0, 0   }},
    {Format::BC2Unorm,           "BC2Unorm",        16,             4,  FormatType::Unorm,      {false,  false, true, },        {4, 4},                                                  {128, 0, 0, 0  }},
    {Format::BC2UnormSrgb,       "BC2UnormSrgb",    16,             4,  FormatType::UnormSrgb,  {false,  false, true, },        {4, 4},                                                  {128, 0, 0, 0  }},
    {Format::BC3Unorm,           "BC3Unorm",        16,             4,  FormatType::Unorm,      {false,  false, true, },        {4, 4},                                                  {128, 0, 0, 0  }},
    {Format::BC3UnormSrgb,       "BC3UnormSrgb",    16,             4,  FormatType::UnormSrgb,  {false,  false, true, },        {4, 4},                                                  {128, 0, 0, 0  }},
    {Format::BC4Unorm,           "BC4Unorm",        8,              1,  FormatType::Unorm,      {false,  false, true, },        {4, 4},                                                  {64, 0, 0, 0   }},
    {Format::BC4Snorm,           "BC4Snorm",        8,              1,  FormatType::Snorm,      {false,  false, true, },        {4, 4},                                                  {64, 0, 0, 0   }},
    {Format::BC5Unorm,           "BC5Unorm",        16,             2,  FormatType::Unorm,      {false,  false, true, },        {4, 4},                                                  {128, 0, 0, 0  }},
    {Format::BC5Snorm,           "BC5Snorm",        16,             2,  FormatType::Snorm,      {false,  false, true, },        {4, 4},                                                  {128, 0, 0, 0  }},

    {Format::BC6HS16,            "BC6HS16",         16,             3,  FormatType::Float,      {false,  false, true, },        {4, 4},                                                  {128, 0, 0, 0  }},
    {Format::BC6HU16,            "BC6HU16",         16,             3,  FormatType::Float,      {false,  false, true, },        {4, 4},                                                  {128, 0, 0, 0  }},
    {Format::BC7Unorm,           "BC7Unorm",        16,             4,  FormatType::Unorm,      {false,  false, true, },        {4, 4},                                                  {128, 0, 0, 0  }},
    {Format::BC7UnormSrgb,       "BC7UnormSrgb",    16,             4,  FormatType::UnormSrgb,  {false,  false, true, },        {4, 4},                                                  {128, 0, 0, 0  }},
  // clang-format on
};

static_assert(std::size(kFormatDesc) == (size_t)Format::BC7UnormSrgb + 1);

struct NativeFormatDesc
{
    Format falcorFormat;
    DXGI_FORMAT dxgiFormat;
    VkFormat vkFormat;
};

const NativeFormatDesc kNativeFormatDescs[] = {
  // clang-format off
    {Format::Unknown,                       DXGI_FORMAT_UNKNOWN,                    VK_FORMAT_UNDEFINED},
    {Format::R8Unorm,                       DXGI_FORMAT_R8_UNORM,                   VK_FORMAT_R8_UNORM},
    {Format::R8Snorm,                       DXGI_FORMAT_R8_SNORM,                   VK_FORMAT_R8_SNORM},
    {Format::R16Unorm,                      DXGI_FORMAT_R16_UNORM,                  VK_FORMAT_R16_UNORM},
    {Format::R16Snorm,                      DXGI_FORMAT_R16_SNORM,                  VK_FORMAT_R16_SNORM},
    {Format::RG8Unorm,                      DXGI_FORMAT_R8G8_UNORM,                 VK_FORMAT_R8G8_UNORM},
    {Format::RG8Snorm,                      DXGI_FORMAT_R8G8_SNORM,                 VK_FORMAT_R8G8_SNORM},
    {Format::RG16Unorm,                     DXGI_FORMAT_R16G16_UNORM,               VK_FORMAT_R16G16_UNORM},
    {Format::RG16Snorm,                     DXGI_FORMAT_R16G16_SNORM,               VK_FORMAT_R16G16_SNORM},
    {Format::RGB5A1Unorm,                   DXGI_FORMAT_B5G5R5A1_UNORM,             VK_FORMAT_B5G5R5A1_UNORM_PACK16},
    {Format::RGBA8Unorm,                    DXGI_FORMAT_R8G8B8A8_UNORM,             VK_FORMAT_R8G8B8A8_UNORM},
    {Format::RGBA8Snorm,                    DXGI_FORMAT_R8G8B8A8_SNORM,             VK_FORMAT_R8G8B8A8_SNORM},
    {Format::RGB10A2Unorm,                  DXGI_FORMAT_R10G10B10A2_UNORM,          VK_FORMAT_A2B10G10R10_UNORM_PACK32},
    {Format::RGB10A2Uint,                   DXGI_FORMAT_R10G10B10A2_UINT,           VK_FORMAT_A2B10G10R10_UINT_PACK32},
    {Format::RGBA16Unorm,                   DXGI_FORMAT_R16G16B16A16_UNORM,         VK_FORMAT_R16G16B16A16_UNORM},
    {Format::RGBA16Snorm,                   DXGI_FORMAT_R16G16B16A16_SNORM,         VK_FORMAT_R16G16B16A16_SNORM},
    {Format::RGBA8UnormSrgb,                DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,        VK_FORMAT_R8G8B8A8_SRGB},
    {Format::R16Float,                      DXGI_FORMAT_R16_FLOAT,                  VK_FORMAT_R16_SFLOAT},
    {Format::RG16Float,                     DXGI_FORMAT_R16G16_FLOAT,               VK_FORMAT_R16G16_SFLOAT},
    {Format::RGBA16Float,                   DXGI_FORMAT_R16G16B16A16_FLOAT,         VK_FORMAT_R16G16B16A16_SFLOAT},
    {Format::R32Float,                      DXGI_FORMAT_R32_FLOAT,                  VK_FORMAT_R32_SFLOAT},
    {Format::RG32Float,                     DXGI_FORMAT_R32G32_FLOAT,               VK_FORMAT_R32G32_SFLOAT},
    {Format::RGB32Float,                    DXGI_FORMAT_R32G32B32_FLOAT,            VK_FORMAT_R32G32B32_SFLOAT},
    {Format::RGBA32Float,                   DXGI_FORMAT_R32G32B32A32_FLOAT,         VK_FORMAT_R32G32B32A32_SFLOAT},
    {Format::R11G11B10Float,                DXGI_FORMAT_R11G11B10_FLOAT,            VK_FORMAT_B10G11R11_UFLOAT_PACK32},
    {Format::RGB9E5Float,                   DXGI_FORMAT_R9G9B9E5_SHAREDEXP,         VK_FORMAT_E5B9G9R9_UFLOAT_PACK32},
    {Format::R8Int,                         DXGI_FORMAT_R8_SINT,                    VK_FORMAT_R8_SINT},
    {Format::R8Uint,                        DXGI_FORMAT_R8_UINT,                    VK_FORMAT_R8_UINT},
    {Format::R16Int,                        DXGI_FORMAT_R16_SINT,                   VK_FORMAT_R16_SINT},
    {Format::R16Uint,                       DXGI_FORMAT_R16_UINT,                   VK_FORMAT_R16_UINT},
    {Format::R32Int,                        DXGI_FORMAT_R32_SINT,                   VK_FORMAT_R32_SINT},
    {Format::R32Uint,                       DXGI_FORMAT_R32_UINT,                   VK_FORMAT_R32_UINT},
    {Format::RG8Int,                        DXGI_FORMAT_R8G8_SINT,                  VK_FORMAT_R8G8_SINT},
    {Format::RG8Uint,                       DXGI_FORMAT_R8G8_UINT,                  VK_FORMAT_R8G8_UINT},
    {Format::RG16Int,                       DXGI_FORMAT_R16G16_SINT,                VK_FORMAT_R16G16_SINT},
    {Format::RG16Uint,                      DXGI_FORMAT_R16G16_UINT,                VK_FORMAT_R16G16_UINT},
    {Format::RG32Int,                       DXGI_FORMAT_R32G32_SINT,                VK_FORMAT_R32G32_SINT},
    {Format::RG32Uint,                      DXGI_FORMAT_R32G32_UINT,                VK_FORMAT_R32G32_UINT},
    {Format::RGB32Int,                      DXGI_FORMAT_R32G32B32_SINT,             VK_FORMAT_R32G32B32_SINT},
    {Format::RGB32Uint,                     DXGI_FORMAT_R32G32B32_UINT,             VK_FORMAT_R32G32B32_UINT},
    {Format::RGBA8Int,                      DXGI_FORMAT_R8G8B8A8_SINT,              VK_FORMAT_R8G8B8A8_SINT},
    {Format::RGBA8Uint,                     DXGI_FORMAT_R8G8B8A8_UINT,              VK_FORMAT_R8G8B8A8_UINT},
    {Format::RGBA16Int,                     DXGI_FORMAT_R16G16B16A16_SINT,          VK_FORMAT_R16G16B16A16_SINT},
    {Format::RGBA16Uint,                    DXGI_FORMAT_R16G16B16A16_UINT,          VK_FORMAT_R16G16B16A16_UINT},
    {Format::RGBA32Int,                     DXGI_FORMAT_R32G32B32A32_SINT,          VK_FORMAT_R32G32B32A32_SINT},
    {Format::RGBA32Uint,                    DXGI_FORMAT_R32G32B32A32_UINT,          VK_FORMAT_R32G32B32A32_UINT},
    {Format::BGRA4Unorm,                    DXGI_FORMAT_B4G4R4A4_UNORM,             VK_FORMAT_UNDEFINED},
    {Format::BGRA8Unorm,                    DXGI_FORMAT_B8G8R8A8_UNORM,             VK_FORMAT_B8G8R8A8_UNORM},
    {Format::BGRA8UnormSrgb,                DXGI_FORMAT_B8G8R8A8_UNORM_SRGB,        VK_FORMAT_B8G8R8A8_SRGB},
    {Format::BGRX8Unorm,                    DXGI_FORMAT_B8G8R8X8_UNORM,             VK_FORMAT_B8G8R8A8_UNORM},
    {Format::BGRX8UnormSrgb,                DXGI_FORMAT_B8G8R8X8_UNORM_SRGB,        VK_FORMAT_B8G8R8A8_SRGB},
    {Format::R5G6B5Unorm,                   DXGI_FORMAT_B5G6R5_UNORM,               VK_FORMAT_B5G6R5_UNORM_PACK16},
    {Format::D32Float,                      DXGI_FORMAT_D32_FLOAT,                  VK_FORMAT_D32_SFLOAT},
    {Format::D32FloatS8Uint,                DXGI_FORMAT_D32_FLOAT_S8X24_UINT,       VK_FORMAT_D32_SFLOAT_S8_UINT},
    {Format::D16Unorm,                      DXGI_FORMAT_D16_UNORM,                  VK_FORMAT_D16_UNORM},
    {Format::BC1Unorm,                      DXGI_FORMAT_BC1_UNORM,                  VK_FORMAT_BC1_RGB_UNORM_BLOCK},
    {Format::BC1UnormSrgb,                  DXGI_FORMAT_BC1_UNORM_SRGB,             VK_FORMAT_BC1_RGB_SRGB_BLOCK},
    {Format::BC2Unorm,                      DXGI_FORMAT_BC2_UNORM,                  VK_FORMAT_BC2_UNORM_BLOCK},
    {Format::BC2UnormSrgb,                  DXGI_FORMAT_BC2_UNORM_SRGB,             VK_FORMAT_BC2_SRGB_BLOCK},
    {Format::BC3Unorm,                      DXGI_FORMAT_BC3_UNORM,                  VK_FORMAT_BC3_UNORM_BLOCK},
    {Format::BC3UnormSrgb,                  DXGI_FORMAT_BC3_UNORM_SRGB,             VK_FORMAT_BC3_SRGB_BLOCK},
    {Format::BC4Unorm,                      DXGI_FORMAT_BC4_UNORM,                  VK_FORMAT_BC4_UNORM_BLOCK},
    {Format::BC4Snorm,                      DXGI_FORMAT_BC4_SNORM,                  VK_FORMAT_BC4_SNORM_BLOCK},
    {Format::BC5Unorm,                      DXGI_FORMAT_BC5_UNORM,                  VK_FORMAT_BC5_UNORM_BLOCK},
    {Format::BC5Snorm,                      DXGI_FORMAT_BC5_SNORM,                  VK_FORMAT_BC5_SNORM_BLOCK},
    {Format::BC6HS16,                       DXGI_FORMAT_BC6H_SF16,                  VK_FORMAT_BC6H_SFLOAT_BLOCK},
    {Format::BC6HU16,                       DXGI_FORMAT_BC6H_UF16,                  VK_FORMAT_BC6H_UFLOAT_BLOCK},
    {Format::BC7Unorm,                      DXGI_FORMAT_BC7_UNORM,                  VK_FORMAT_BC7_UNORM_BLOCK},
    {Format::BC7UnormSrgb,                  DXGI_FORMAT_BC7_UNORM_SRGB,             VK_FORMAT_BC7_SRGB_BLOCK},
  // clang-format on
};

static_assert(std::size(kNativeFormatDescs) == (size_t)Format::Count);

DXGI_FORMAT GetDxgiFormat(Format format)
{
    NOVA_ASSERT(kNativeFormatDescs[(uint32_t)format].falcorFormat == format);
    return kNativeFormatDescs[(uint32_t)format].dxgiFormat;
}

Format GetFormat(DXGI_FORMAT format)
{
    for (auto desc : kNativeFormatDescs) {
        if (desc.dxgiFormat == format)
            return desc.falcorFormat;
    }
    return Format::Unknown;
}

VkFormat NOVA_API GetVulkanFormat(Format format)
{
    NOVA_ASSERT(kNativeFormatDescs[(uint32_t)format].falcorFormat == format);
    return kNativeFormatDescs[(uint32_t)format].vkFormat;
}

Format NOVA_API GetFormat(VkFormat format)
{
    for (auto desc : kNativeFormatDescs) {
        if (desc.vkFormat == format)
            return desc.falcorFormat;
    }
    return Format::Unknown;
}
} // namespace nova