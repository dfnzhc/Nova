/**
 * @File NativeFormats.hpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/16
 * @Brief This file is part of Nova.
 */

#pragma once

#include <dxgiformat.h>
#include <vulkan/vulkan.h>
#include "./Formats.hpp"

namespace nova {

DXGI_FORMAT NOVA_API GetDxgiFormat(Format format);

Format NOVA_API GetFormat(DXGI_FORMAT format);

VkFormat NOVA_API GetVulkanFormat(Format format);

Format NOVA_API GetFormat(VkFormat format);

} // namespace nova