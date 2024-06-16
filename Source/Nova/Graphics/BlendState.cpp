/**
 * @File BlendState.cpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/16
 * @Brief This file is part of Nova.
 */

#include "./BlendState.hpp"

using namespace nova;

Ref<BlendState> BlendState::Create(const BlendState::Desc& desc)
{
    return Ref<BlendState>(new BlendState(desc));
}

BlendState::Desc::Desc()
{
    // TODO
    //    mRtDesc.resize(Fbo::getMaxColorTargetCount());
}

BlendState::Desc& BlendState::Desc::setRtParams(uint32_t rtIndex,
                                                BlendOp rgbOp,
                                                BlendOp alphaOp,
                                                BlendFunc srcRgbFunc,
                                                BlendFunc dstRgbFunc,
                                                BlendFunc srcAlphaFunc,
                                                BlendFunc dstAlphaFunc)
{
    ASSERT(rtIndex < mRtDesc.size());

    mRtDesc[rtIndex].rgbBlendOp   = rgbOp;
    mRtDesc[rtIndex].alphaBlendOp = alphaOp;
    mRtDesc[rtIndex].srcRgbFunc   = srcRgbFunc;
    mRtDesc[rtIndex].dstRgbFunc   = dstRgbFunc;
    mRtDesc[rtIndex].srcAlphaFunc = srcAlphaFunc;
    mRtDesc[rtIndex].dstAlphaFunc = dstAlphaFunc;
    return *this;
}

BlendState::Desc& BlendState::Desc::setRenderTargetWriteMask(u32 rtIndex, ColorMask writeRgb)
{
    ASSERT(rtIndex < mRtDesc.size());

    mRtDesc[rtIndex].writeMask = writeRgb;
    return *this;
}
