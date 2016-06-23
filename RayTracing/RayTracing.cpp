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
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 800
#define MIN(a, b) (a <= b ? a : b)

void initScene()
{
	// ������Ӱƽ��  
	glShadeModel(GL_SMOOTH);
	// ��ɫ����  
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// ������Ȼ���  
	glClearDepth(1.0);
	// ������Ȳ���  
	glEnable(GL_DEPTH_TEST);
	// ������Ȳ��Ե�����  
	glDepthFunc(GL_LEQUAL);
	// ����ϵͳ��͸�ӽ�������  
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//����������еĻ�ͼ����  
void renderDepth(GLFWwindow *window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();                                   // Reset The View
	glTranslatef(-0.5f,-0.5f,1.0f);
	glPointSize(2.0);
	double horiz=0.0;
	double dep=10;
	perCamera camera( Vector3(0.0, 10.0, 10), Vector3(0.0, -0.5, -1.0), Vector3(0.0, 1.0, 0.0), 90.0);
	long maxDepth=20;
	//Sphere sphere1 = Sphere(Vector3(0.0, 10.0, -10.0), 10.0);
	Plane plane1(Vector3(0.0, 1.0, 0.0), 1.0);
	plane1.material = new CheckMaterial(1.0f);
	double dx=1.0/WINDOW_WIDTH;
	double dy=1.0/WINDOW_HEIGHT;
	double dD=255.0/maxDepth;

	glBegin(GL_POINTS);

	for (double y = 0.0; y < WINDOW_HEIGHT; ++y)
	{
		double sy = dy * y;
		for (double x = 0.0; x < WINDOW_WIDTH; ++x)
		{
			double sx =dx*x;
			Ray ray(camera.generateRay(sx, sy));
			IntersectResult result = plane1.isIntersect(ray);
			if (result.isHit)
			{
				Color color = plane1.material->sample(ray, result.position, result.normal);
				color.saturate();
				//double t=MIN(result.distance*dD,255.0f);
				//int depth = (int)(255 -t);
				glColor3ub(color.r * 255, color.g * 255, color.b * 255);
				glVertex2f(sx,sy);
			}
		}
	}
	glEnd();
	// ����������
	glfwSwapBuffers(window); 
	glfwPollEvents();
}

/*
void  drawScene(GLFWwindow *window) 
{
	float colorSpan = 0.0005f;
	float color = 0.0f;
	float pixelSize = 1.0f;
	float posY = -1.0f;
	float posX = -1.0f;
	long  maxDepth = 20;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//��ԭ���ƶ������½�  
	glTranslatef(-0.5f, -0.5f, 0.0f);
	glPointSize(2.0);
	glBegin(GL_POINTS);
	double dx = 1.0f / WINDOW_WIDTH;
	double dy = 1.0f / WINDOW_HEIGHT;
	float dD = 255.0f / maxDepth;
	glBegin(GL_POINTS);

	for (long y = 0; y < WINDOW_HEIGHT; ++y)
	{
		double sy = 1 - dy*y;
		for (long x = 0; x < WINDOW_WIDTH; ++x)
		{
			double sx = dx*x;
			float colorR = x*1.0 / WINDOW_WIDTH * 255;
			float colorB = y*1.0 / WINDOW_HEIGHT * 255;
			glColor3ub(colorR, 0, colorB);
			glVertex2f(sx, sy);
		}
	}
	glEnd();
	// ����������  
	glfwSwapBuffers(window); 
	glfwPollEvents();
}
*/
/*
//���ô��ڴ�С��Ļص�����  
void resizeGL(int width, int height)
{
	// ��ֹ���ڴ�С��Ϊ0  
	if (height == 0)
	{
		height = 1;
	}
	// ���õ�ǰ���ӿ�  
	glViewport(0, 0, (GLint)width, (GLint)height);
	// ѡ��ͶӰ����  
	glMatrixMode(GL_PROJECTION);
	// ����ͶӰ����  
	glLoadIdentity();
	// �����ӿڵĴ�С  
	gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 100.0);
	// ѡ��ģ�͹۲����  
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
*/

int main(void)
{
	GLFWwindow* window;
	//GLFWwindowsizefun windowSize = GLFWwindowsizefun(resizeGL);
	//��ʼ�� GLFW  
	if (!glfwInit())
	{
		return -1;
	}
	// ����һ��OpenGL ����
	window = glfwCreateWindow(1366, 768, "Test", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	//��ʼ��OpenGL����  
	initScene();
	//���ô��ڴ�С�����仯ʱ�Ļص�����  
	//glfwSetWindowSizeCallback(window, windowSize);
	//��ѭ��  
	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window))
	{
		//Sphere sphere1 = Sphere(Vector3(0.0, 10.0, -10.0), 10.0);
		//perCamera camera = perCamera(Vector3(0.0, 10.0, 10.0), Vector3(0.0, 0.0, -1.0), Vector3(0.0, 1.0, 0.0));
		//perCamera camera = perCamera();
		// OpenGL rendering goes here...  
		//glClear(GL_COLOR_BUFFER_BIT);
		// ������ESC����ʱ�򴥷�  
		//running = !glfwGetKey(window, GLFW_KEY_ESCAPE) && glfwGetWindowAttrib(window, GLFW_OPENED);
		renderDepth(window);
		//��ʱ0.05s

		Sleep(50);
	}
	glfwTerminate();
	//�˳�����  
	return 0;
}

