/**
 * @File BlendState.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/16
 * @Brief This file is part of Nova.
 */

#pragma once

#include <atomic>
#include <cstdint>
#include <type_traits>
#include <utility>
#include <vector>

#include "./Math/Vector.hpp"
#include "./Base/Object.hpp"
#include "./Base/Enums.hpp"

namespace nova {

// Src 意为来源，通常指片段着色器中的颜色
// Dst 意为目标，通常指渲染目标中的颜色
enum class BlendFunc : u8
{
    Zero,             ///< (0, 0, 0, 0)
    One,              ///< （1, 1, 1, 1）
    SrcColor,         ///< 片段着色器输出的颜色
    InvSrcColor,      ///< 片段着色器输出颜色的反色
    SrcAlpha,         ///< 片段着色器输出的 Alpha 值
    InvSrcAlpha,      ///< 片段着色器输出 Alpha 值的反色
    DstColor,         ///< 渲染目标的颜色
    InvDstColor,      ///< 渲染目标颜色的反色
    DstAlpha,         ///< 渲染目标的 Alpha 值
    InvDstAlpha,      ///< 渲染目标 Alpha 值的反色
    ConstantColor,    ///< 常量颜色
    InvConstantColor, ///< 常量颜色的反色
    SrcAlphaSaturate, ///< （f, f, f, 1），其中 f = min(片段着色器输出 Alpha, 1 - 渲染目标像素 Alpha)
    Src1Color,        ///< 片段着色器输出的颜色
    InvSrc1Color,     ///< 片段着色器输出颜色的反色
    Src1Alpha,        ///< 片段着色器输出的 Alpha
    InvSrc1Alpha,     ///< 片段着色器输出 Alpha 的反色

    OneMinusSrcColor      = InvSrcColor,
    OneMinusSrcAlpha      = InvSrcAlpha,
    OneMinusDstAlpha      = InvDstAlpha,
    OneMinusDstColor      = InvDstColor,
    OneMinusConstantColor = InvConstantColor,
    OneMinusSrc1Color     = InvSrc1Color,
    OneMinusSrc1Alpha     = InvSrc1Alpha,
};

enum class BlendOp : u8
{
    Add,             ///< 将 src1 和 src2 相加
    Subtract,        ///< 从 src2 中减去 src1
    ReverseSubtract, ///< 从 src1 中减去 src2
    Min,             ///< 在源之间找到最小值（按通道）
    Max              ///< 在源之间找到最大值（按通道）
};

enum class ColorMask : u8
{
    None  = 0,
    Red   = 1,
    Green = 2,
    Blue  = 4,
    Alpha = 8,
    All   = 0xF
};

NOVA_ENUM_BIT_OPERATORS(ColorMask);

class BlendState : public Object
{
public:
    class Desc
    {
    public:
        Desc();
        friend class BlendState;

        Desc& setBlendFactor(const float4& factor)
        {
            mBlendFactor = factor;
            return *this;
        }

        Desc& setIndependentBlend(bool enabled)
        {
            mEnableIndependentBlend = enabled;
            return *this;
        }

        Desc& setRtParams(uint32_t rtIndex,
                          BlendOp rgbOp,
                          BlendOp alphaOp,
                          BlendFunc srcRgbFunc,
                          BlendFunc dstRgbFunc,
                          BlendFunc srcAlphaFunc,
                          BlendFunc dstAlphaFunc);

        Desc& setRtBlend(uint32_t rtIndex, bool enable)
        {
            mRtDesc[rtIndex].blendEnabled = enable;
            return *this;
        }

        Desc& setAlphaToCoverage(bool enabled)
        {
            mAlphaToCoverageEnabled = enabled;
            return *this;
        }

        Desc& setRenderTargetWriteMask(u32 rtIndex, ColorMask writeRgb);

        struct RenderTargetDesc
        {
            bool blendEnabled      = false;           // 是否启用混合
            BlendOp rgbBlendOp     = BlendOp::Add;    // RGB通道的混合操作
            BlendOp alphaBlendOp   = BlendOp::Add;    // Alpha通道的混合操作
            BlendFunc srcRgbFunc   = BlendFunc::One;  // 片段着色器输出RGB通道的混合函数
            BlendFunc srcAlphaFunc = BlendFunc::One;  // 片段着色器输出Alpha通道的混合函数
            BlendFunc dstRgbFunc   = BlendFunc::Zero; // 渲染目标RGB通道的混合函数
            BlendFunc dstAlphaFunc = BlendFunc::Zero; // 渲染目标Alpha通道的混合函数
            ColorMask writeMask    = ColorMask::All;  // 颜色写入掩码
        };

    protected:
        std::vector<RenderTargetDesc> mRtDesc;             // 渲染目标描述数组
        bool mEnableIndependentBlend = false;              // 是否启用独立混合
        bool mAlphaToCoverageEnabled = false;              // 是否启用 alpha-to-coverage
        float4 mBlendFactor          = float4(0, 0, 0, 0); // 常量混合因子
    };

    ~BlendState() override = default;

    /**
     * 创建一个新的混合状态对象。
     * @param[in] desc 混合状态描述符。
     * @return 新的对象，如果创建失败则抛出异常。
     */
    static Ref<BlendState> Create(const Desc& desc);

    const float4& getBlendFactor() const { return mDesc.mBlendFactor; }

    // clang-format off

    BlendOp   getRgbBlendOp(uint32_t rtIndex) const { return mDesc.mRtDesc[rtIndex].rgbBlendOp; }
    BlendOp getAlphaBlendOp(uint32_t rtIndex) const { return mDesc.mRtDesc[rtIndex].alphaBlendOp; }

    BlendFunc   getSrcRgbFunc(uint32_t rtIndex) const { return mDesc.mRtDesc[rtIndex].srcRgbFunc; }
    BlendFunc getSrcAlphaFunc(uint32_t rtIndex) const { return mDesc.mRtDesc[rtIndex].srcAlphaFunc; }

    BlendFunc   getDstRgbFunc(uint32_t rtIndex) const { return mDesc.mRtDesc[rtIndex].dstRgbFunc; }
    BlendFunc getDstAlphaFunc(uint32_t rtIndex) const { return mDesc.mRtDesc[rtIndex].dstAlphaFunc; }

    bool isBlendEnabled(uint32_t rtIndex) const { return mDesc.mRtDesc[rtIndex].blendEnabled; }

    bool  isAlphaToCoverageEnabled() const { return mDesc.mAlphaToCoverageEnabled; }
    bool isIndependentBlendEnabled() const { return mDesc.mEnableIndependentBlend; }

    const Desc::RenderTargetDesc& getRtDesc(size_t rtIndex) const { return mDesc.mRtDesc[rtIndex]; }

    uint32_t getRtCount() const { return static_cast<uint32_t>(mDesc.mRtDesc.size()); }

    // clang-format on

private:
    explicit BlendState(Desc Desc) : mDesc(std::move(Desc)) { }

    const Desc mDesc;
};

} // namespace nova
