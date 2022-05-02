#include <pangolin/display/display.h>
#include <pangolin/gl/gl.h>
#include <pangolin/gl/gldraw.h>

// # include <pangolin/pangolin.h>

void sample()
{
    // 创建窗口
    pangolin::CreateWindowAndBind("Pango GL Triangle", 500, 500);

    // 创建三角形的三个坐标顶点
    std::vector<Eigen::Vector3f> vertices = {
        {-0.5f, -0.5f, 0.0f},
        {0.5f, -0.5f, 0.0f },
        {0.0f,  0.5f, 0.0f }
    };

    // 设置背景颜色 rgb alpha
    glClearColor(0.64f, 0.5f, 0.81f, 0.0f);

    // 设置三角形的颜色 rgb
    glColor3f(0.29f, 0.71f, 1.0f);

    // 在循环中不断渲染，这样三角形将不断显示，并随着窗口大小的调整而调整。
	// 按Escape或关闭窗口退出循环。
    while( !pangolin::ShouldQuit() )
    {
        // 清屏
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // 绘制三角形 arg1：数据  arg2：绘制类型
        pangolin::glDrawVertices(vertices, GL_TRIANGLES);

        // 处理任何窗口事件，并交换前后OpenGL缓冲区（如果可用）
        pangolin::FinishFrame();
    }
}

int main( int /*argc*/, char** /*argv*/ )
{
    sample();
    return 0;
}
