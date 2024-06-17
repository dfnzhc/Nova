/**
 * @File Formats.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/16
 * @Brief This file is part of Nova.
 */

#pragma once

#include "../Base/Enums.hpp"
#include "../Base/Error.hpp"
#include <span>
#include <string>

namespace nova {

enum class TextureChannelFlags : u32
{
    None  = 0x0,
    Red   = 0x1,
    Green = 0x2,
    Blue  = 0x4,
    Alpha = 0x8,
    RGB   = 0x7,
    RGBA  = 0xf,
};

NOVA_ENUM_BIT_OPERATORS(TextureChannelFlags);

enum class BindFlags : u32
{
    None                  = 0x0,        ///< 不会绑定到管线。用于创建暂存资源
    Vertex                = 0x1,        ///< 作为顶点缓冲区绑定
    Index                 = 0x2,        ///< 作为索引缓冲区绑定
    Constant              = 0x4,        ///< 作为常量缓冲区绑定
    StreamOutput          = 0x8,        ///< 作为流输出阶段的输出缓冲区绑定
    ShaderResource        = 0x10,       ///< 作为着色器资源绑定
    UnorderedAccess       = 0x20,       ///< 作为无序访问视图（UAV）绑定
    RenderTarGet          = 0x40,       ///< 作为渲染目标绑定
    DepthStencil          = 0x80,       ///< 作为深度-模板缓冲区绑定
    IndirectArg           = 0x100,      ///< 作为间接参数缓冲区绑定
    Shared                = 0x200,      ///< 与不同的 API 共享, 主要用于与 CUDA 共享资源
    AccelerationStructure = 0x80000000, ///< 作为加速结构绑定

    AllColorViews = ShaderResource | UnorderedAccess | RenderTarGet, ///< 所有颜色视图的组合标志
    AllDepthViews = ShaderResource | DepthStencil                    ///< 所有深度视图的组合标志
};

NOVA_ENUM_BIT_OPERATORS(BindFlags);

enum class Format : u32
{
    Unknown,
    R8Unorm,
    R8Snorm,
    R16Unorm,
    R16Snorm,
    RG8Unorm,
    RG8Snorm,
    RG16Unorm,
    RG16Snorm,
    RGB5A1Unorm,
    RGBA8Unorm,
    RGBA8Snorm,
    RGB10A2Unorm,
    RGB10A2Uint,
    RGBA16Unorm,
    RGBA16Snorm,
    RGBA8UnormSrgb,
    R16Float,
    RG16Float,
    RGBA16Float,
    R32Float,
    RG32Float,
    RGB32Float,
    RGBA32Float,
    R11G11B10Float,
    RGB9E5Float,
    R8Int,
    R8Uint,
    R16Int,
    R16Uint,
    R32Int,
    R32Uint,
    RG8Int,
    RG8Uint,
    RG16Int,
    RG16Uint,
    RG32Int,
    RG32Uint,
    RGB32Int,
    RGB32Uint,
    RGBA8Int,
    RGBA8Uint,
    RGBA16Int,
    RGBA16Uint,
    RGBA32Int,
    RGBA32Uint,

    BGRA4Unorm,
    BGRA8Unorm,
    BGRA8UnormSrgb,

    BGRX8Unorm,
    BGRX8UnormSrgb,
    R5G6B5Unorm,

    // 深度-模板
    D32Float,
    D32FloatS8Uint,
    D16Unorm,

    // 压缩格式
    BC1Unorm, ///< DXT1
    BC1UnormSrgb,
    BC2Unorm, ///< DXT3
    BC2UnormSrgb,
    BC3Unorm, ///< DXT5
    BC3UnormSrgb,
    BC4Unorm, ///< RGTC Unsigned Red
    BC4Snorm, ///< RGTC Signed Red
    BC5Unorm, ///< RGTC Unsigned RG
    BC5Snorm, ///< RGTC Signed RG
    BC6HS16,
    BC6HU16,
    BC7Unorm,
    BC7UnormSrgb,

    Count
};

enum class FormatType
{
    Unknown,   ///< 未知的格式类型
    Float,     ///< 浮点格式
    Unorm,     ///< 无符号标准化格式
    UnormSrgb, ///< 无符号标准化SRGB格式
    Snorm,     ///< 有符号标准化格式
    Uint,      ///< 无符号整数格式
    Int        ///< 有符号整数格式
};

struct FormatDesc
{
    Format format;
    const std::string name;
    u32 bytesPerBlock;
    u32 channelCount;
    FormatType Type;

    struct
    {
        bool isDepth;
        bool isStencil;
        bool isCompressed;
    };

    struct
    {
        u32 width;
        u32 height;
    } compressionRatio;

    u32 numChannelBits[4];
};

extern const NOVA_API FormatDesc kFormatDesc[];

inline u32 GetFormatBytesPerBlock(Format format)
{
    NOVA_ASSERT(kFormatDesc[(u32)format].format == format);
    return kFormatDesc[(u32)format].bytesPerBlock;
}

inline u32 GetFormatPixelsPerBlock(Format format)
{
    NOVA_ASSERT(kFormatDesc[(u32)format].format == format);
    return kFormatDesc[(u32)format].compressionRatio.width * kFormatDesc[(u32)format].compressionRatio.height;
}

inline bool isDepthFormat(Format format)
{
    NOVA_ASSERT(kFormatDesc[(u32)format].format == format);
    return kFormatDesc[(u32)format].isDepth;
}

inline bool isStencilFormat(Format format)
{
    NOVA_ASSERT(kFormatDesc[(u32)format].format == format);
    return kFormatDesc[(u32)format].isStencil;
}

inline bool isDepthStencilFormat(Format format)
{
    return isDepthFormat(format) || isStencilFormat(format);
}

inline bool isCompressedFormat(Format format)
{
    NOVA_ASSERT(kFormatDesc[(u32)format].format == format);
    return kFormatDesc[(u32)format].isCompressed;
}

inline u32 GetFormatWidthCompressionRatio(Format format)
{
    NOVA_ASSERT(kFormatDesc[(u32)format].format == format);
    return kFormatDesc[(u32)format].compressionRatio.width;
}

inline u32 GetFormatHeightCompressionRatio(Format format)
{
    NOVA_ASSERT(kFormatDesc[(u32)format].format == format);
    return kFormatDesc[(u32)format].compressionRatio.height;
}

inline u32 GetFormatChannelCount(Format format)
{
    NOVA_ASSERT(kFormatDesc[(u32)format].format == format);
    return kFormatDesc[(u32)format].channelCount;
}

inline FormatType GetFormatType(Format format)
{
    NOVA_ASSERT(kFormatDesc[(u32)format].format == format);
    return kFormatDesc[(u32)format].Type;
}

inline bool isIntegerFormat(Format format)
{
    FormatType type = GetFormatType(format);
    return type == FormatType::Uint || type == FormatType::Int;
}

inline u32 GetNumChannelBits(Format format, int channel)
{
    return kFormatDesc[(u32)format].numChannelBits[channel];
}

inline u32 GetNumChannelBits(Format format, TextureChannelFlags mask)
{
    u32 bits = 0;
    if (isSet(mask, TextureChannelFlags::Red))
        bits += GetNumChannelBits(format, 0);
    if (isSet(mask, TextureChannelFlags::Green))
        bits += GetNumChannelBits(format, 1);
    if (isSet(mask, TextureChannelFlags::Blue))
        bits += GetNumChannelBits(format, 2);
    if (isSet(mask, TextureChannelFlags::Alpha))
        bits += GetNumChannelBits(format, 3);
    return bits;
}

inline TextureChannelFlags GetChannelMask(Format format)
{
    TextureChannelFlags mask = TextureChannelFlags::None;
    if (kFormatDesc[(u32)format].numChannelBits[0] > 0)
        mask |= TextureChannelFlags::Red;
    if (kFormatDesc[(u32)format].numChannelBits[1] > 0)
        mask |= TextureChannelFlags::Green;
    if (kFormatDesc[(u32)format].numChannelBits[2] > 0)
        mask |= TextureChannelFlags::Blue;
    if (kFormatDesc[(u32)format].numChannelBits[3] > 0)
        mask |= TextureChannelFlags::Alpha;
    return mask;
}

inline u32 GetFormatRowPitch(Format format, u32 width)
{
    NOVA_ASSERT(width % GetFormatWidthCompressionRatio(format) == 0);
    return (width / GetFormatWidthCompressionRatio(format)) * GetFormatBytesPerBlock(format);
}

inline bool isSrgbFormat(Format format)
{
    return (GetFormatType(format) == FormatType::UnormSrgb);
}

inline Format SrgbToLinearFormat(Format format)
{
    switch (format) {
    case Format::BC1UnormSrgb   : return Format::BC1Unorm;
    case Format::BC2UnormSrgb   : return Format::BC2Unorm;
    case Format::BC3UnormSrgb   : return Format::BC3Unorm;
    case Format::BGRA8UnormSrgb : return Format::BGRA8Unorm;
    case Format::BGRX8UnormSrgb : return Format::BGRX8Unorm;
    case Format::RGBA8UnormSrgb : return Format::RGBA8Unorm;
    case Format::BC7UnormSrgb   : return Format::BC7Unorm;
    default                     : NOVA_ASSERT(isSrgbFormat(format) == false); return format;
    }
}

inline Format LinearToSrgbFormat(Format format)
{
    switch (format) {
    case Format::BC1Unorm   : return Format::BC1UnormSrgb;
    case Format::BC2Unorm   : return Format::BC2UnormSrgb;
    case Format::BC3Unorm   : return Format::BC3UnormSrgb;
    case Format::BGRA8Unorm : return Format::BGRA8UnormSrgb;
    case Format::BGRX8Unorm : return Format::BGRX8UnormSrgb;
    case Format::RGBA8Unorm : return Format::RGBA8UnormSrgb;
    case Format::BC7Unorm   : return Format::BC7UnormSrgb;
    default                 : return format;
    }
}

inline Format DepthToColorFormat(Format format)
{
    switch (format) {
    case Format::D16Unorm : return Format::R16Unorm;
    case Format::D32Float : return Format::R32Float;
    default               : NOVA_ASSERT(isDepthFormat(format) == false); return format;
    }
}

inline bool doesFormatHaveAlpha(Format format)
{
    if (GetFormatChannelCount(format) == 4) {
        switch (format) {
        case Format::BGRX8Unorm :
        case Format::BGRX8UnormSrgb : return false;
        default                     : return true;
        }
    }

    return false;
}

inline const std::string& toString(Format format)
{
    NOVA_ASSERT(kFormatDesc[(u32)format].format == format);
    return kFormatDesc[(u32)format].name;
}

inline std::string toString(FormatType Type)
{
#define TypeToString(a)                                                                                                \
    case FormatType::a : return #a
    switch (Type) {
        TypeToString(Unknown);
        TypeToString(Float);
        TypeToString(Unorm);
        TypeToString(UnormSrgb);
        TypeToString(Snorm);
        TypeToString(Uint);
        TypeToString(Int);
    }
#undef TypeToString
    NOVA_UNREACHABLE();
}

inline std::string toString(BindFlags flags)
{
    std::string s;
    if (flags == BindFlags::None) {
        return "None";
    }

#define FlagToStr(f_)                                                                                                  \
    if (isSet(flags, BindFlags::f_))                                                                                   \
    (s += (!s.empty() ? " | " : "") + std::string(#f_))

    FlagToStr(Vertex);
    FlagToStr(Index);
    FlagToStr(Constant);
    FlagToStr(StreamOutput);
    FlagToStr(ShaderResource);
    FlagToStr(UnorderedAccess);
    FlagToStr(RenderTarGet);
    FlagToStr(DepthStencil);
    FlagToStr(IndirectArg);
    FlagToStr(AccelerationStructure);
#undef FlagToStr

    return s;
}

} // namespace nova