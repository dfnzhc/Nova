/**
 * @File main.cpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/6/13
 * @Brief 
 */

#include <iostream>
#include <Nova/Nova.hpp>
using namespace nova;

class Framework : public Application
{
public:
    explicit Framework(const AppConfig& config) : Application(config) { }

    ~Framework() override { }

    void onLoad() override { Application::onLoad(); }

    void onShutdown() override { Application::onShutdown(); }

    void onResize(uint32_t width, uint32_t height) override { Application::onResize(width, height); }

    void onFrameRender() override { Application::onFrameRender(); }

    void onOptionsChange() override { Application::onOptionsChange(); }

    void onHotReload() override { Application::onHotReload(); }

    bool onKeyEvent(const KeyboardEvent& keyEvent) override { return Application::onKeyEvent(keyEvent); }

    bool onMouseEvent(const MouseEvent& mouseEvent) override { return Application::onMouseEvent(mouseEvent); }

    void onDroppedFile(const std::filesystem::path& path) override { Application::onDroppedFile(path); }
};

inline int RunApp()
{
    AppConfig config;
    config.windowDesc.title           = "Framework";
    config.windowDesc.resizableWindow = true;
    
    Framework project(config);
    
    return project.run();
}

int main()
{
    return nova::CatchAndReportAllExceptions(RunApp);
}