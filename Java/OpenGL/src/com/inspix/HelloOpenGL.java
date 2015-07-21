package com.inspix;

import org.lwjgl.glfw.*;
import org.lwjgl.opengl.*;

import java.nio.ByteBuffer;

import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.glfw.Callbacks.*;
import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.system.MemoryUtil.*;

public class HelloOpenGL {
    private GLFWErrorCallback errorCallback;
    private long window;
    private int width;
    private int height;

    public void run(){
        try {
            this.init();
            this.loop();

            glfwDestroyWindow(window);
        }
        finally {
            glfwTerminate();
            errorCallback.release();
        }
    }

    private void init(){

        glfwSetErrorCallback(errorCallback = errorCallbackPrint(System.out));

        if (glfwInit() != GL_TRUE){
            throw new IllegalStateException("Failed to initialize GLFW");
        }

        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_VISIBLE,GL_FALSE);
        glfwWindowHint(GLFW_RESIZABLE,GL_TRUE);

        width = 640;
        height = 480;

        window = glfwCreateWindow(width,height,"OpenGL Java",NULL,NULL);
        if (window == NULL){
            throw new RuntimeException("Failed to create a window.");
        }
        ByteBuffer vio = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwSetWindowPos(window,
                (GLFWvidmode.width(vio) - width) /2,
                (GLFWvidmode.height(vio) - height)/2);

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
        glfwShowWindow(window);
    }

    private void loop() {
        GLContext.createFromCurrent();
        System.out.println(glGetString(GL_VERSION));

        glClearColor(0f,0.3f,1f,1f);

        while (glfwWindowShouldClose(window) == GL_FALSE){

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glBegin(GL_TRIANGLES);
            glColor3f(1f,0f,0f);
            glVertex2f(-1,1);
            glColor3f(1f,1f,0f);
            glVertex2f(1,1);
            glColor3f(1f,0f,1f);
            glVertex2f(0,-1);
            glEnd();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
}
