#include "basic stuff.h"
#include "Shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include <stb_image.h>
#include "Texture.h"

bool isrunning;

GLfloat vertices[] = {
	0.5, -0.5, 0.0f, 0.8f, 0.3f, 0.02f, 0.0f, 0.0f, 
	-0.5, -0.5, 0.0f, 0.2f, 0.2f, 0.02f, 0.0f, 0.5f,
	-0.5, 0.5, 0.0f, 0.3f, 0.1f, 0.02f, 0.5f, 0.5f,
    0.5, 0.5,  0.0f , 0.5f, 0.0f, 0.02f, 0.5f, 0.0f
};

GLuint indices[] = {  // note that we start from 0!
        0, 2, 1,  // first Triangle
        0, 3, 2   // second Triangle
};
int main()
{
	isrunning = true;
	InitWindow(3, 3, 1200, 800, "Thing", 0, 1, 1);

    Shader shaderProgram("default.vert", "default.frag");
    
    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.LinkAttribute(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    VAO1.LinkAttribute(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
    VAO1.LinkAttribute(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    VAO1.UnBind();
    EBO1.UnBind();

    Texture texture("brick.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
    texture.texUnit(shaderProgram, "tex0", 0);


	while (isrunning)
	{
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // draw our first triangle
        shaderProgram.Activate();
         // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        texture.Bind();
        VAO1.Bind();
      //  glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0); // no need to unbind it every time 

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        updatewindow();
        glfwPollEvents();
	}
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    texture.Delete();
    shaderProgram.End();
    End();
	return 0;
}