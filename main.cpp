/*  Universidade Federal do Pará
	Instituto de Tecnologia
	Faculdade de Engenharia da Computação e Telecomunicações

	Trabalho 01 de Computação Gráfica
	Prof. Manuel Ribeiro
	Data: 22/04/2014

	Equipe:
	Leandro Fonseca Chaves		- 10080004701
	Douglas da Rocha Cirqueira  - 10080002101
	Evannelson Soares Jr.		- 10080007001
	
	Descrição: O programa consiste de duas viewports demonstrando as transformações
	de translação, escalonamento, rotação e espelhamento, usando interações em tempo
	real com teclado e/ou mouse.
	Além disso, também é demonstrado transformações de projeção ortográfica e perspectiva.
	Todas as funcionalidades são exibidas ao usuário a partir de menus de navegação e dicas
	de auxilio ao usuário.


1.  Duas viewports
2. Demonstrar as transformações de translação, escalamento rotação e espelhamento, usando interações em tempo real com o teclado e/ou mouse
3. Demonstrar as transformações de projeção: ortográfica e perspectiva, , usando interações em tempo real com o teclado e/ou mouse
4. Mudar a posição da câmara,  usando interações em tempo real com o teclado e/ou mouse
5. Cada equipe escolhe as primitivas que vai usar, 2D ou 3 D.
6. Orientar para o usuário como interagir (teclado ou  mouse) para realizar as operações
7. Código bem documentado (comentários explicando), usando programação modular.

*/


#include <GL/glut.h>
#include <string.h>
#include <stdio.h>

// Constantes
#define QUADRADO  1
#define TRIANGULO 2
#define LOSANGO   3
#define TEAPOT    4

// Variáveis
char texto[30];
GLfloat win, r, g, b;
GLint view_w, view_h, primitiva;

// Função que desenha um quadrado
void DesenhaQuadrado(void)
{
	glBegin(GL_QUADS);
		glVertex2f(-25.0f, -25.0f);
		glVertex2f(-25.0f, 25.0f);
		glVertex2f(25.0f, 25.0f);
		glVertex2f(25.0f, -25.0f);               
	glEnd();
}

// Função que desenha um triângulo
void DesenhaTriangulo(void)
{
	glBegin(GL_TRIANGLES);
		glVertex2f(-25.0f, -25.0f);
		glVertex2f(0.0f, 25.0f);
		glVertex2f(25.0f, -25.0f);              
	glEnd();
}

// Função que desenha um losango
void DesenhaLosango(void)
{
	glBegin(GL_POLYGON);
		glVertex2f(-25.0f, 0.0f);
		glVertex2f(0.0f, 25.0f);
		glVertex2f(25.0f, 0.0f);
		glVertex2f(0.0f, -25.0f);               
	glEnd();
}

void DesenhaTeapot(void)
{
	// Desenha o teapot com a cor corrente (wire-frame)
	glutWireTeapot(50.0f);
}

// Desenha um texto na janela GLUT
void DesenhaTexto(char *string) 
{  
	glPushMatrix();
	// Posição no universo onde o texto será colocado          
		glRasterPos2f(-win,win-(win*0.08)); 
		// Exibe caracter a caracter
		while(*string)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string++); 
	glPopMatrix();
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);

	// Define a cor corrente
	glColor3f(r,g,b);

	// Desenha uma primitiva     
	switch (primitiva) {
	case QUADRADO:  DesenhaQuadrado();
	    break;
	case TRIANGULO: DesenhaTriangulo();                          
	    break;
	case LOSANGO:   DesenhaLosango();                       
	    break;
	case TEAPOT:    DesenhaTeapot();                       
	    break;
	}

	// Exibe a posição do mouse na janela
	glColor3f(1.0f,1.0f,1.0f);
	DesenhaTexto(texto);
	
	// Executa os comandos OpenGL
	glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{ 
    
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	
}

// Programa Principal
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("Trabalho 01 - Computação Gráfica");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	Inicializa();
	glutMainLoop();
}
