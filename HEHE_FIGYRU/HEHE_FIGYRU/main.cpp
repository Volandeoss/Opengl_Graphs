//#include <GLFW/glfw3.h>
//#include <math.h>
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <windows.h>
//
//using namespace std;
//
//
//
///*void Task1() {
//	glLineWidth(2);
//	glColor3f(1.0, 1.0, 0.0);
//	glBegin(GL_LINE_LOOP);//top
//	
//	glVertex3f(0, 0.5f, -0.2f);
//	glVertex3f(0.2f,0.5f,-0.1f);
//	glVertex3f(0.2f, 0.5f, 0.1f);
//	glVertex3f(0, 0.5f, 0.2f);
//	glVertex3f(-0.2f, 0.5f, 0.1f);
//	glVertex3f(-0.2f, 0.5f, -0.1f);
//
//	glEnd();
//
//	glBegin(GL_LINE_LOOP);//down
//	
//	glVertex3f(0.2, -0.5f, -0.2f);
//	glVertex3f(0.4f, -0.5f, -0.1f);
//	glVertex3f(0.4f, -0.5f, 0.1f);
//	glVertex3f(0.2, -0.5f, 0.2f);
//	glVertex3f(0, -0.5f, 0.1f);
//	glVertex3f(0, -0.5f, -0.1f);
//
//	glEnd();
//
//	glBegin(GL_LINES);
//	glVertex3f(0, 0.5f, -0.2f);
//	glVertex3f(0.2, -0.5f, -0.2f);
//	glVertex3f(0.2f, 0.5f, -0.1f);
//	glVertex3f(0.4f, -0.5f, -0.1f);
//	glVertex3f(0.2f, 0.5f, 0.1f);
//	glVertex3f(0.4f, -0.5f, 0.1f);
//	glVertex3f(0.2, -0.5f, 0.2f);
//	glVertex3f(0, 0.5f, 0.2f);
//	glVertex3f(-0.2f, 0.5f, 0.1f);
//	glVertex3f(0, -0.5f, 0.1f);
//	glVertex3f(-0.2f, 0.5f, -0.1f);
//	glVertex3f(0, -0.5f, -0.1f);
//	glEnd();
//}
//
//void top() {//фіол 
//	glLineWidth(2);
//	glColor3f(0, 1, 1);
//	glBegin(GL_POLYGON);//top
//	glColor3f(0.5, 0.0, 0.5);
//	glVertex3f(0, 0.5f, -0.2f);
//	glVertex3f(0.2f, 0.5f, -0.1f);
//	glVertex3f(0.2f, 0.5f, 0.1f);
//	glVertex3f(0, 0.5f, 0.2f);
//	glVertex3f(-0.2f, 0.5f, 0.1f);
//	glVertex3f(-0.2f, 0.5f, -0.1f);
//
//	glEnd();
//}
//
//void down() {//жовтий
//	glBegin(GL_POLYGON);//down
//	glColor3f(1.0, 1.0, 0.0);
//	glVertex3f(0.2, -0.5f, -0.2f);
//	glVertex3f(0.4f, -0.5f, -0.1f);
//	glVertex3f(0.4f, -0.5f, 0.1f);
//	glVertex3f(0.2, -0.5f, 0.2f);
//	glVertex3f(0, -0.5f, 0.1f);
//	glVertex3f(0, -0.5f, -0.1f);
//
//	glEnd();
//
//}
//
//
//void sid_1() {//зелений
//	glBegin(GL_QUADS);
//	glColor3f(0, 1, 0);
//	glVertex3f(0, 0.5f, -0.2f);
//	glVertex3f(0.2f, 0.5f, -0.1f);
//	glVertex3f(0.4f, -0.5f, -0.1f);
//	glVertex3f(0.2, -0.5f, -0.2f);
//	glEnd();
//}
//void sid_2() {//синій
//	glBegin(GL_QUADS);
//	glColor3f(0, 0, 1);
//	glVertex3f(0.2f, 0.5f, 0.1f);
//	glVertex3f(0.4f, -0.5f, 0.1f);
//	glVertex3f(0.2, -0.5f, 0.2f);
//	glVertex3f(0, 0.5f, 0.2f);
//	glEnd();
//
//}
//void sid_3() {//коричневий
//	glBegin(GL_QUADS);
//	glColor3f(0.4, 0.3, 0);
//	glVertex3f(0, -0.5f, 0.1f);
//	glVertex3f(-0.2f, 0.5f, 0.1f);
//	glVertex3f(-0.2f, 0.5f, -0.1f);
//	glVertex3f(0, -0.5f, -0.1f);//done
//	glEnd();
//
//}
//void sid_4() {//розовий
//	glBegin(GL_QUADS);
//	glColor3f(1, 0, 1);
//	glVertex3f(0.2f, 0.5f, -0.1f);
//	glVertex3f(0.2f, 0.5f, 0.1f);
//
//	glVertex3f(0.4f, -0.5f, 0.1f);
//	glVertex3f(0.4f, -0.5f, -0.1f);
//	glEnd();
//
//}
//void sid_5() {//білий
//	glBegin(GL_QUADS);
//	glColor3f(1.0, 1.0, 1.0);
//	glVertex3f(0.2, -0.5f, 0.2f);
//	glVertex3f(0, -0.5f, 0.1f);
//	glVertex3f(-0.2f, 0.5f, 0.1f);
//	glVertex3f(0, 0.5f, 0.2f);
//	glEnd();
//
//}
//void sid_6() {//ЗСУ
//	glBegin(GL_QUADS);
//	glColor3f(0, 0.7, 0.4);
//	glVertex3f(0, 0.5f, -0.2f);
//	glVertex3f(-0.2f, 0.5f, -0.1f);
//	glVertex3f(0, -0.5f, -0.1f);
//	glVertex3f(0.2, -0.5f, -0.2f);
//	glEnd();
//
//}
//
//
///*int main(void)
//{
//	GLFWwindow *window;
//
//	/* Initialize the library */
//	if (!glfwInit())
//		return -1;
//
//	/* Create a windowed mode window and its OpenGL context */
//	window = glfwCreateWindow(800, 800, "FIgurchuk", NULL, NULL);
//	if (!window)
//	{
//		glfwTerminate();
//		return -1;
//	}
//
//	/* Make the window's context current */
//	glfwMakeContextCurrent(window);
//	float theta = 0;
//	/* Loop until the user closes the window */
//	while (!glfwWindowShouldClose(window))
//	{
//
//
//		/* Render here */
//		glClearColor(0.1f, 0.17f, 0.3f, 0.43f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//
//		
//		/*glPushMatrix();// 1 завдання (3D фігура)
//		glRotatef(theta, 1, 1, 1);//angle,x,y,z
//		if (theta >= 0 && theta <= 100) {
//			sid_4();
//			sid_3(); //коричневий
//			//sid_2();//синій
//			
//			sid_2();//синій
//			sid_5();
//			top();
//		
//		}
//		else if (theta >= 100 && theta <= 200) {
//			sid_3(); //коричневий
//			sid_5();
//			//sid_2();//синій
//			sid_1();
//			sid_2();//синій
//			//sid_5();
//			sid_4();
//			top();
//		
//		
//		
//		}
//		else if (theta >= 200 && theta <= 240) {
//			top();
//			sid_4();//розовий
//			sid_2();//синій
//			//sid_4();//розовий
//			//sid_5();
//			sid_1();
//			//sid_4();//розовий
//			
//			
//		
//		
//		}
//		else if (theta >= 240) {
//			sid_3(); //коричневий
//			sid_5();
//			sid_1();
//			sid_2();//синій
//			sid_4();
//			
//			down();
//			
//			
//		
//		
//		}
//	
//		
//		
//		glPopMatrix();*/
//		/*glPushMatrix();//   друге завдання (грані)
//		glRotatef(theta, 1, 1, 1);
//		Task1();
//
//		glPopMatrix();*/
//		cout << theta << endl;
//
//		/* Swap front and back buffers */
//		glfwSwapBuffers(window);
//		if (theta >= 360) {
//			theta = 0;
//		}
//
//		theta += 0.1;
//		
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}*/




