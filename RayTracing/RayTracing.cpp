// RayTracing.cpp : Defines the entry point for the console application.
//

//#include "vector3.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include "perspectiveCamera.h"
//#include "sphere.h"
#include "plane.h"
#include "sphere.h"
#include "union.h"
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 800
#define MIN(a, b) (a <= b ? a : b)

void initScene()
{
	// 启用阴影平滑  
	glShadeModel(GL_SMOOTH);
	// 黑色背景  
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// 设置深度缓存  
	glClearDepth(1.0);
	// 启用深度测试  
	glEnable(GL_DEPTH_TEST);
	// 所作深度测试的类型  
	glDepthFunc(GL_LEQUAL);
	// 告诉系统对透视进行修正  
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//这里进行所有的绘图工作  
void renderDepth(GLFWwindow *window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();                                   // Reset The View
	glTranslatef(-0.5f,-0.5f,1.0f);
	glPointSize(2.0);
	double horiz=0.0;
	double dep=10;
	perCamera camera( Vector3(0.0, 10.0, 10), Vector3(0.0, 0.0, -1.0), Vector3(0.0, 1.0, 0.0), 90.0);
	long maxDepth=20;
	Object *plane1 =  new Plane(Vector3(0.0, 1.0, 0.0), 1.0);
	Object *sphere1 = new Sphere(Vector3(0.0, 10.0, -10.0), 4.0);
	Object *sphere2 = new Sphere(Vector3(5.0, 5.0, -10.0), 3.0);
	plane1->material  = new CheckMaterial(0.1f);
	sphere1->material = new PhongMaterial(Color::red(), Color::white(), 20);
	sphere2->material = new PhongMaterial(Color::blue(), Color::white(), 20);

	Union scene;
	scene.addObject(plane1);
	scene.addObject(sphere1);
	scene.addObject(sphere2);

	double dx=1.0/WINDOW_WIDTH;
	double dy=1.0/WINDOW_HEIGHT;
	double dD=255.0/maxDepth;

	glBegin(GL_POINTS);

	for (double y = 0.0; y < WINDOW_HEIGHT; ++y)
	{
		double sy = dy * y;
		for (double x = 0.0; x < WINDOW_WIDTH; ++x)
		{
			double sx =dx * x;
			Ray ray(camera.generateRay(sx, sy));
			IntersectResult result = scene.isIntersect(ray);
			if (result.isHit)
			{
				//Color color = result.object->material->sample(ray, result.position, result.normal);
				Color color = result.object->material->sample(ray, result.position, result.normal);
				color.saturate();
				//double t=MIN(result.distance*dD,255.0f);
				//int depth = (int)(255 -t);
				glColor3ub(color.r * 255, color.g * 255, color.b * 255);
				glVertex2f(sx,sy);
			}
		}
	}
	glEnd();
	// 交换缓冲区
	glfwSwapBuffers(window); 
	glfwPollEvents();
}

/*
//重置窗口大小后的回调函数  
void resizeGL(int width, int height)
{
	// 防止窗口大小变为0  
	if (height == 0)
	{
		height = 1;
	}
	// 重置当前的视口  
	glViewport(0, 0, (GLint)width, (GLint)height);
	// 选择投影矩阵  
	glMatrixMode(GL_PROJECTION);
	// 重置投影矩阵  
	glLoadIdentity();
	// 设置视口的大小  
	gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 100.0);
	// 选择模型观察矩阵  
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
*/

int main(void)
{
	GLFWwindow* window;
	//GLFWwindowsizefun windowSize = GLFWwindowsizefun(resizeGL);
	//初始化 GLFW  
	if (!glfwInit())
	{
		return -1;
	}
	// 创建一个OpenGL 窗口
	window = glfwCreateWindow(1500, 1500, "Test", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	//初始化OpenGL窗口  
	initScene();
	//设置窗口大小发生变化时的回调函数  
	//glfwSetWindowSizeCallback(window, windowSize);
	//主循环  
	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window))
	{
		// 当按下ESC键的时候触发  
		//running = !glfwGetKey(window, GLFW_KEY_ESCAPE) && glfwGetWindowAttrib(window, GLFW_OPENED);
		renderDepth(window);
		//延时0.05s

		Sleep(50);
	}
	glfwTerminate();
	//退出程序  
	return 0;
}


