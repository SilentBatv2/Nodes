#include "stdafx.h"
#include "Writer.h"

Writer::Writer(std::string fntpath, std::string texpath) : texturepath(texpath)
{
	loadFont(data ,fntpath);

    initializeOpenGLFunctions();

    setShader();
}

Writer::~Writer()
{
    delete tex;
}

void Writer::paint()
{
    glBindVertexArray(VAO);
    glUseProgram(shaderProgram);
    tex->bind();

    int proj_uni = glGetUniformLocation(shaderProgram, "ourTexture");
    glUniform1i(proj_uni, tex->getslot());

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Writer::write(int x, int y, std::string text)
{
    float vertices[] = {
        // positions              // texture coords
         0.5f,  0.5f, 0.0f,       1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,       1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,       0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,       0.0f, 1.0f,    // top left 
         0.5f,  0.5f, 0.0f,       1.0f, 1.0f,   // top right
        -0.5f, -0.5f, 0.0f,       0.0f, 0.0f   // bottom left

    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    tex = new Texture(texturepath);

    glBindVertexArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Writer::setShader()
{
    auto vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec2 aTexCoord;

        out vec2 TexCoord;

        void main()
        {
            gl_Position = vec4(aPos, 1.0);
            TexCoord = aTexCoord;
        }
            )";

    auto fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;

        in vec2 TexCoord;
        
        uniform sampler2D ourTexture;
        
        void main()
        {
            FragColor = texture(ourTexture, TexCoord);
        }
    )";

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        QMessageBox::critical(nullptr, "Compilation error", std::string("Vertex Shader Compilation Failed : ").append(infoLog).c_str());
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        QMessageBox::critical(nullptr, "Compilation error", std::string("Fragment Shader Compilation Failed : ").append(infoLog).c_str());
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        QMessageBox::critical(nullptr, "Linking error", std::string("Shader Program Linking Failed : ").append(infoLog).c_str());
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glUseProgram(0);
}
