#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <vector>
#include <windows.h>
#include "main.cpp"

using namespace std;

class Graphs {
private:
	int amount;//amount of dots, points
	int quantity;//amount of sides
	struct Vertex {
		float r = 0, g = 0, b = 0;
		float x;
		float y;
		void Init(float x, float y, float r, float g, float b) {
			this->x = x;
			this->y = y;
			this->r = r;
			this->g = g;
			this->b = b;
		}
		void Draw(){
			glVertex2f(this->x,this->y);
		}
		void DrawPoint( float rad, int num_segments)//наш≥ точки
		{
			glColor3f(r, g, b);
			glBegin(GL_POLYGON);
			for (int ii = 0; ii < num_segments; ii++)
			{
				float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

				float x = rad * cosf(theta);//calculate the x component
				float y = rad * sinf(theta);//calculate the y component

				glVertex2f(x + this->x, y + this->y);//output vertex

			}
			glEnd();
		}
		
	}V[7];	
	static void Bezye(Vertex V0, Vertex V2, float Kof) {//робить криву
		glPointSize(3);
		glColor3f(0, 1, 1);
		glBegin(GL_POINTS);
		float x1 = ((V0.x + V2.x) / 2)*Kof;
		float y1 = ((V0.y + V2.y) / 2)*Kof;
		for (double t = 0; t < 1; t += 0.01) {
			float x = (pow((1 - t), 2)*V0.x) + (2 * t*(1 - t))*x1 + pow(t, 2)*V2.x;
			float y = (pow((1 - t), 2)*V0.y) + (2 * t*(1 - t))*y1 + pow(t, 2)*V2.y;
			
			glVertex2f(x, y);



		}
		glEnd();
	}
	
	void DrawStitch(Vertex V,float rkof )//петл€
	{
		int num_segments = 40;
		float r = 0.08 + rkof;
		
		glLineWidth(3);
		glColor3f(0, 1, 1);
		glBegin(GL_LINE_LOOP);
		for (int ii = 0; ii < num_segments; ii++)
		{
			float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

			float x = r * cosf(theta);//calculate the x component
			float y = r * sinf(theta);//calculate the y component

			glVertex2f(x + (V.x+r), y + V.y);//output vertex

		}
		glEnd();
	}
	void Init_Points() {
		V[0].Init(0, 0, 0, 0, 0);
		V[1].Init(0, 0.4f, 0.5f, 0.0f, 1.0f);//1 purple
		V[2].Init(0.3f, 0.2f, 1.0f, 0.0f, 0.0f);//2 red
		V[3].Init(0.3f, -0.2f, 0.0f, 1.0f, 0.0f);//3 green
		V[4].Init(0, -0.4f, 1.0f, 1.0f, 0.0f);//4   yellow
		V[5].Init(-0.3, -0.2, 1, 0.35f, 0);//5  orange
		V[6].Init(-0.3, 0.2, 1, 0, 0.8);//6  pink
	
	}
	void Draw(vector<vector<int>> par) {//дл€ матриц≥ сум≥жност≥ у граф (преобразуЇ матрицю у граф)
		for (int i = 0; i < amount; i++) {
			for (int j = 0; j < amount; j++) {
				int k, potolok = 0;
				if (par[i][j] == 1) {
					k = par[i][j];
					potolok = 1;
				}
				else if (par[i][j] > 1) {
					k = par[i][j] - 1;
				}
				else if (par[i][j] == 0) {
					continue;
				}
				for (; k >= potolok; k--) {
					if ( i == j ){

						DrawStitch(V[j + 1], (float)k / 100);

					}
					else
					{
						Bezye(V[i + 1], V[j + 1], k);
					}
				}
			}
		}
		for (int i = 1; i < amount + 1; i++) {
			V[i].DrawPoint(0.05, 20);
		}
	
	
	}
	

public:
	vector<vector<int>> Mat_Inc;//матриц€ ≥нцидентност≥
	vector<vector<int>> Mat_Sum;//матриц€ сум≥жност≥
	vector<vector<int>> Mat_Sum1;//матриц€ сум≥жност≥ є2 
	vector<vector<int>> Mat_Obj;//матриц€ ќб'Їднанн€
	vector<vector<int>> Mat_Per;//матриц€ перер≥зy
	vector<vector<int>> Mat_Riz;//матриц€ –≥зницi
	vector<vector<int>> Mat_Dop;//матриц€ ƒоповненн€

	
	
	
	void Sumizh(){//к≥льк≥сть точок (вершин) м≥н≥мум 2, максимум 6
		
		cout << "1-purple" << "\n"
			<< "2-red" << "\n"
			<< "3-green" << "\n"
			<< "4-yellow" << "\n"
			<< "5-orange" << "\n"
			<< "6-pink" << "\n";
		cout << "¬вед≥ть к≥льк≥сть точок у граф≥(2-6):";
		cin >> amount;

		if (amount < 2) amount = 2;
		else if (amount > 6) amount = 6;

		int x;
		
		for (int i = 0; i < amount; i++) {
			vector<int> temp;
			for (int j = 0; j < amount; j++) {
				cout << i + 1 << "|" << j + 1<<"| ";
				cin >> x;
				temp.push_back(x);
			}
			Mat_Sum.push_back(temp);

		}
		cout << "ћатриц€ сум≥жност≥:\n";
		for (auto i : Mat_Sum) {
			for (auto j : i) {
				cout << j << "  ";
			
			
			
			}
			cout << endl;
		}
		
	
	}
	void Incudent() {//за допомогою матриц≥ ≥нцидентност≥
		cout << "¬вед≥ть к≥льк≥сть ребер у граф≥(2-6):";//точок завжди буде 6
		cin >> quantity;//а ребер залежно в≥д квонт≥т≥

		if (quantity < 2) quantity = 2;
		else if (quantity > 9) quantity = 9;

		int x;

		for (int i = 0; i < 6; i++) {
			vector<int> temp;
			for (int j = 0; j <quantity; j++) {
				cout << i + 1 << "|" << j + 1 << "| ";
				cin >> x;
				temp.push_back(x);
			}
			Mat_Inc.push_back(temp);

		}
		cout << "ћатриц€ ≥нцидентност≥:\n";
		for (int i = 1; i <= quantity; i++) {
			cout << i << "A\t";
		}
		cout << "\n";
		for (auto i : Mat_Inc) {
			
			for (auto j : i) {
				cout << j << "\t";



			}
			cout << endl;



		}
	
	
	
	
	}
	void Objed(){
		cout << "1-purple" << "\n"
			<< "2-red" << "\n"
			<< "3-green" << "\n"
			<< "4-yellow" << "\n"
			<< "5-orange" << "\n"
			<< "6-pink" << "\n";
		cout << "¬вед≥ть к≥льк≥сть точок у граф≥(2-6):";
		cin >> amount;

		if (amount < 2) amount = 2;
		else if (amount > 6) amount = 6;

		int x,lich=0;

		for (int i = 0; i < amount; i++) {
			vector<int> temp;
			for (int j = 0; j < amount; j++) {
				cout << i + 1 << "|" << j + 1 << "| ";
				cin >> x;
				temp.push_back(x);
			}
			Mat_Sum.push_back(temp);

		}
		cout << "ћатриц€ сум≥жност≥ є1:\n";
		for (auto i : Mat_Sum) {
			for (auto j : i) {
				cout << j << "  ";



			}
			cout << endl;



		}
		cout << "¬вед≥ть наступну матрицю:\n";
		for (int i = 0; i < amount; i++) {
			vector<int> temp;
			for (int j = 0; j < amount; j++) {
				cout << i + 1 << "|" << j + 1 << "| ";
				cin >> x;
				temp.push_back(x);
			}
			Mat_Sum1.push_back(temp);
		}
		cout << "ћатриц€ сум≥жност≥ є2:\n";
		for (auto i : Mat_Sum1) {
			for (auto j : i) {
				cout << j << "  ";
			}
			cout << endl;
		}
		for (int i = 0; i < amount; i++) {
			for (int j = 0; j < amount; j++) {
				if (Mat_Sum[i][j] == Mat_Sum1[i][j]) lich++;
			
			
			
			}
		}
		if (lich == amount * amount) {
			cout << "\nMатриц≥ Ї ≥зоморфними\n";
		}
		else {
			cout << "\nћатриц≥ не Ї ≥зоморфними\n";
		}
		for (int i = 0; i < amount; i++) {
			vector<int> temp;
			for (int j = 0; j < amount; j++) {//сортуЇмо два масива дл€ масиву об'Їднанн€
				if (Mat_Sum[i][j] != 0 || Mat_Sum1[i][j] != 0)
				{
					if (Mat_Sum[i][j] >= Mat_Sum1[i][j]) {
						temp.push_back(Mat_Sum[i][j]);
					
					}
					else {
						temp.push_back(Mat_Sum1[i][j]);
					
					
					}
					
					
				}
				else
				{
					temp.push_back(0);
				}
				

			}
			Mat_Obj.push_back(temp);
		}
		cout << "ћатриц€ об'Їднанн€:\n";
		for (auto i : Mat_Obj) {
			for (auto j : i) {
				cout << j << "  ";
			}
			cout << endl;
		}
	
	
	
	}

	void Pereriz() {
		cout << "1-purple" << "\n"
			<< "2-red" << "\n"
			<< "3-green" << "\n"
			<< "4-yellow" << "\n"
			<< "5-orange" << "\n"
			<< "6-pink" << "\n";
		cout << "¬вед≥ть к≥льк≥сть точок у граф≥(2-6):";
		cin >> amount;

		if (amount < 2) amount = 2;
		else if (amount > 6) amount = 6;

		int x,lich=0;//х дл€ вводу данних у масиви, lich дл€ перев≥рки на ≥зоморф≥зм

		for (int i = 0; i < amount; i++) {//¬веденн€ данних у перший масив 
			vector<int> temp;
			for (int j = 0; j < amount; j++) {
				cout << i + 1 << "|" << j + 1 << "| ";
				cin >> x;
				temp.push_back(x);
			}
			Mat_Sum.push_back(temp);
		}
		cout << "ћатриц€ сум≥жност≥ є1:\n";
		for (auto i : Mat_Sum) {
			for (auto j : i) {
				cout << j << "  ";



			}
			cout << endl;



		}
		cout << "¬вед≥ть наступну матрицю:\n";
		for (int i = 0; i < amount; i++) {
			vector<int> temp;
			for (int j = 0; j < amount; j++) {
				cout << i + 1 << "|" << j + 1 << "| ";
				cin >> x;
				temp.push_back(x);
			}
			Mat_Sum1.push_back(temp);
		}
		cout << "ћатриц€ сум≥жност≥ є2:\n";
		for (auto i : Mat_Sum1) {
			for (auto j : i) {
				cout << j << "  ";
			}
			cout << endl;
		}

		for (int i = 0; i < amount; i++) {//перев≥рка на ≥зоморф≥зм
			for (int j = 0; j < amount; j++) {
				if (Mat_Sum[i][j] == Mat_Sum1[i][j]) lich++;
			}
		}
		if (lich == amount * amount) {
			cout << "\nMатриц≥ Ї ≥зоморфними\n";
		}
		else {
			cout << "\nћатриц≥ не Ї ≥зоморфними\n";
		}
		for (int i = 0; i < amount; i++) {
			vector<int> temp;
			for (int j = 0; j < amount; j++) {
				if (Mat_Sum[i][j] != 0 && Mat_Sum1[i][j] != 0)
				{
					if (Mat_Sum[i][j] >= Mat_Sum1[i][j]) {
						temp.push_back(Mat_Sum1[i][j]);

					}
					else {
						temp.push_back(Mat_Sum[i][j]);


					}


				}
				else
				{
					temp.push_back(0);
				}


			}
			Mat_Per.push_back(temp);
		}
		cout << "ћатриц€ матриц€ перер≥зу:\n";
		for (auto i : Mat_Per) {
			for (auto j : i) {
				cout << j << "  ";
			}
			cout << endl;
		}
	
	
	
	
	}

	void Dopov() {
		cout << "1-purple" << "\n"
			<< "2-red" << "\n"
			<< "3-green" << "\n"
			<< "4-yellow" << "\n"
			<< "5-orange" << "\n"
			<< "6-pink" << "\n";
		cout << "¬вед≥ть к≥льк≥сть точок у граф≥(2-6):";
		cin >> amount;

		if (amount < 2) amount = 2;
		else if (amount > 6) amount = 6;

		int x;

		for (int i = 0; i < amount; i++) {
			vector<int> temp;
			for (int j = 0; j < amount; j++) {
				cout << i + 1 << "|" << j + 1 << "| ";
				cin >> x;
				temp.push_back(x);
			}
			Mat_Sum.push_back(temp);

		}
		cout << "ћатриц€ сум≥жност≥ є1:\n";
		for (auto i : Mat_Sum) {
			for (auto j : i) {
				cout << j << "  ";
			}
			cout << endl;
		}
		
		for (int i = 0; i < amount; i++) {
			vector<int> temp;
			for (int j = 0; j < amount; j++) {
				if (Mat_Sum[i][j] == 0 && i!=j)
				{
					temp.push_back(1);
				}
				else 
				{
					temp.push_back(0);
				}
			}
			Mat_Dop.push_back(temp);
		}
		cout << "ћатриц€ доповненн€:\n";
		for (auto i : Mat_Dop) {
			for (auto j : i) {
				cout << j << "  ";
			}
			cout << endl;
		}
	}

	void Riznuca() {
			cout << "1-purple" << "\n"
				<< "2-red" << "\n"
				<< "3-green" << "\n"
				<< "4-yellow" << "\n"
				<< "5-orange" << "\n"
				<< "6-pink" << "\n";
			cout << "¬вед≥ть к≥льк≥сть точок у граф≥(2-6):";
			cin >> amount;

			if (amount < 2) amount = 2;
			else if (amount > 6) amount = 6;

			int x,lich=0;

			for (int i = 0; i < amount; i++) {
				vector<int> temp;
				for (int j = 0; j < amount; j++) {
					cout << i + 1 << "|" << j + 1 << "| ";
					cin >> x;
					temp.push_back(x);
				}
				Mat_Sum.push_back(temp);

			}
			cout << "ћатриц€ сум≥жност≥ є1:\n";
			for (auto i : Mat_Sum) {
				for (auto j : i) {
					cout << j << "  ";



				}
				cout << endl;



			}
			cout << "¬вед≥ть наступну матрицю:\n";
			for (int i = 0; i < amount; i++) {
				vector<int> temp;
				for (int j = 0; j < amount; j++) {
					cout << i + 1 << "|" << j + 1 << "| ";
					cin >> x;
					temp.push_back(x);
				}
				Mat_Sum1.push_back(temp);
			}
			cout << "ћатриц€ сум≥жност≥ є2:\n";
			for (auto i : Mat_Sum1) {
				for (auto j : i) {
					cout << j << "  ";
				}
				cout << endl;
			}
			for (int i = 0; i < amount; i++) {
				for (int j = 0; j < amount; j++) {
					if (Mat_Sum[i][j] == Mat_Sum1[i][j]) lich++;



				}
			}
			if (lich == amount * amount) {
				cout << "\nMатриц≥ Ї ≥зоморфними\n";
			}
			else {
				cout << "\nћатриц≥ не Ї ≥зоморфними\n";
			}

			for (int i = 0; i < amount; i++) {
				vector<int> temp;
				for (int j = 0; j < amount; j++) {
					if (Mat_Sum[i][j] > Mat_Sum1[i][j])
					{
						temp.push_back(Mat_Sum[i][j] - Mat_Sum1[i][j]);


					}
					else
					{
						temp.push_back(0);
					}


				}
				Mat_Riz.push_back(temp);
			}
			cout << "ћатриц€ р≥зниц≥:\n";
			for (auto i : Mat_Riz) {
				for (auto j : i) {
					cout << j << "  ";
				}
				cout << endl;
			}




		
	
	
	
	
	}
	void CreateGraphSum() {
		
		Init_Points();

		Draw(Mat_Sum);


	}    //дл€ матриц≥ сум≥жност≥ (loop) 
	void CreateGraphInc() {//дл€ матриц≥ ≥нцидентност≥ (int main)
		Init_Points();

		for (int i = 0; i < quantity; i++) {
			int x = 0, y = 0;
			bool isStitch = false;
			for (int j = 0; j < 6; j++) {
				if (Mat_Inc[j][i] == 2) {
					isStitch = true;
					x = j + 1;
				
				
				}
				else if (Mat_Inc[j][i]==1 && x == 0) {
					x = j+1;
				
				}
				else if (Mat_Inc[j][i] == 1 && x != 0) {
					y = j+1;
				
				
				}
			
			
			
			}
			if (isStitch) {
				DrawStitch(V[x], 0.03);
			
			
			}
			else {
				Bezye(V[x], V[y], 1);
			
			}

		}
		for (int i = 1; i < 7; i++) {
			V[i].DrawPoint(0.05, 20);
		}
	}    //по матриц≥ ≥нцидентност≥//    
	void CreateGraphDop() {
		Init_Points();


		glPushMatrix();
		glTranslatef(-0.5, 0.5, 0);
		glPointSize(7);


		Draw(Mat_Sum);

		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.5, 0.5, 0);
		glPointSize(7);


		Draw(Mat_Dop);

		glPopMatrix();
	}
	void CreateGraph(vector<vector<int>> par) {
		Init_Points();


		glPushMatrix();
		glTranslatef(-0.5, 0.5, 0);
		glPointSize(7);


		Draw(Mat_Sum);

		glPopMatrix();


		glPushMatrix();
		glTranslatef(0.5, 0.5, 0);
		glPointSize(7);

		Draw(Mat_Sum1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -0.3, 0);
		glPointSize(7);

		Draw(par);

		glPopMatrix();





	}

		

};



int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Graphs Q;
	Q.Riznuca();
	
	GLFWwindow *window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	
	window = glfwCreateWindow(900, 800, "FIgurchuk", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}


	
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	//float theta = 0;
	
	
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{


		/* Render here */
		glClearColor(0.1f, 0.17f, 0.3f, 0.43f);//background
		glClear(GL_COLOR_BUFFER_BIT);


		
		Q.CreateGraph(Q.Mat_Riz);
		

		

		
		

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		

		
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}