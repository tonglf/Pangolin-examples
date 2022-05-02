#include <pangolin/display/display.h>

// Here is an example of Pangolin being used *just* for windowing.
// We're using
void sample()
{
    pangolin::CreateWindowAndBind("Classic GL Triangle with VBO", 500, 500);

    // 列出三角形的坐标
    const float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // 创建一个OpenGL缓冲区来存储这些坐标
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    // 设置当前OpenGL的缓冲区
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // 将主机数据复制到当前绑定的OpenGL缓冲区中
    // GL_STATIC_DRAW 是关于如何使用缓冲区的提示
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glClearColor(0.64f, 0.5f, 0.81f, 0.0f);
    glColor3f(0.29f, 0.71f, 1.0f);

    while( !pangolin::ShouldQuit() )
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // 将缓冲区设置为OpenGL的当前缓冲区
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        // 此缓冲区包含三维浮点顶点。
        // 它们从第0个元素开始，没有填充物。
        glVertexPointer(3, GL_FLOAT, 0, 0);

        // 使用它们
        glEnableClientState(GL_VERTEX_ARRAY);

        // 将这些顶点中的前3个连接起来，形成一个三角形
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // 禁用我们启用的东西
        glDisableClientState(GL_VERTEX_ARRAY);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        pangolin::FinishFrame();
    }

    // 释放OpenGL缓冲区
    glDeleteBuffers(1, &VBO);
}

int main( int /*argc*/, char** /*argv*/ )
{
    sample();
    return 0;
}
