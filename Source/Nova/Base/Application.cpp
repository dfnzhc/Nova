/**
 * @File Application.cpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/15
 * @Brief This file is part of Nova.
 */

#include "./Application.hpp"

using namespace nova;

Application::Application(const AppConfig& config)
{
    LogInfo("Nova 开始运行...");

    _showUI  = config.showUI;
    _vsyncOn = config.windowDesc.enableVSync;

    /// 创建初始化各种部件
    if (!config.headless) {
        auto windowDesc = config.windowDesc;
        // Vulkan 无法在最小化时创建窗口

        // Create the window
        _pWindow = Window::Create(windowDesc, this);
        _pWindow->setWindowIcon(std::filesystem::current_path() / "Data/Image/Icons/Fairy-Tale-Dark-Moon.ico");
    }
}

Application::~Application()
{
    /// 销毁各种部件

    _pWindow.reset();
    
    
    LogInfo("Nova 已停止运行");
}

int Application::run()
{
    _runInternal();
    return _returnCode;
}

void Application::resizeFrameBuffer(uint32_t width, uint32_t height)
{
    // 有窗口与无窗口
    if (_pWindow) {
        _pWindow->resize(width, height);
    }
    else {
        _resizeTargetFBO(width, height);
    }
}

void Application::renderFrame()
{
    /// 这里执行主要的渲染逻辑

    _inputState.endFrame();
}

void Application::shutdown(int returnCode)
{
    _shouldTerminate = true;
    _returnCode      = returnCode;
    if (_pWindow)
        _pWindow->shutdown();
}

AppConfig Application::getConfig() const
{
    AppConfig c;
    c.windowDesc = _pWindow->getDesc();
    c.showUI     = _showUI;
    return c;
}

std::string Application::getKeyboardShortcutsStr()
{
    constexpr char help[] = "ESC - Quit\n"
                            "V - Toggle VSync\n"
                            "MouseWheel - Change level of zoom\n";

    return help;
}

void Application::handleWindowSizeChange()
{
    /// 处理窗口尺寸改变逻辑
    // TODO：交换链、帧缓冲

    ASSERT(_pWindow);

    // Tell the device to resize the swap chain
    auto newSize    = _pWindow->getClientAreaSize();
    uint32_t width  = newSize.x;
    uint32_t height = newSize.y;
}

void Application::handleRenderFrame()
{
    renderFrame();
}

void Application::handleKeyboardEvent(const KeyboardEvent& keyEvent)
{
    _inputState.onKeyEvent(keyEvent);
    if (onKeyEvent(keyEvent))
        return;

    if (keyEvent.type == KeyboardEvent::Type::KeyPressed) {
        if (keyEvent.hasModifier(Modifier::Ctrl)) {
        }
        else if (keyEvent.mods == ModifierFlags::None) {
            switch (keyEvent.key) {
            case Key::Escape : _pWindow->shutdown(); break;
            default          : break;
            }
        }
    }
}

void Application::handleMouseEvent(const MouseEvent& mouseEvent)
{
    _inputState.onMouseEvent(mouseEvent);
    if (onMouseEvent(mouseEvent))
        return;
}

void Application::handleDroppedFile(const std::filesystem::path& path)
{
    onDroppedFile(path);
}

void Application::_resizeTargetFBO(uint32_t width, uint32_t height)
{
    onResize(width, height);
}

void Application::_initUI()
{
}

void Application::_saveConfigToFile()
{
}

void Application::_renderUI()
{
}

void Application::_runInternal()
{
    if (_pWindow) {
        _pWindow->msgLoop();
    }
    else {
        while (!_shouldTerminate)
            handleRenderFrame();
    }

    onShutdown();
}
