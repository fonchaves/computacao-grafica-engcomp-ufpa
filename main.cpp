/*  Universidade Federal do Pará
    Instituto de Tecnologia
    Faculdade de Engenharia da Computação e Telecomunicações

    Trabalho 01 de Computação Gráfica
    Prof. Manuel Ribeiro
    Data: 22/04/2014

    Equipe:
    Leandro Fonseca Chaves      - 10080004701
    Douglas da Rocha Cirqueira  - 10080002101
    Evannelson Soares Jr.       - 10080007001
    
    Descrição: O programa consiste de duas viewports demonstrando as transformações
    de translação, escalonamento, rotação e espelhamento, usando interações em tempo
    real com teclado e/ou mouse.
    Além disso, também é demonstrado transformações de projeção ortográfica e perspectiva.
    Todas as funcionalidades são exibidas ao usuário a partir de menus de navegação e dicas
    de auxilio ao usuário.
*/

//#include <windows.h> // Utilizado para compilar no Windows
#include <GL/glut.h>

//Constantes
int rot_x = 30, rot_y = 50, rot_z = 0;
float cam_x = 0.0, cam_y = 0.0, cam_z = 3.0;
int largura = 800, altura = 600;
float esc_x = 1.0, esc_y = 1.0, esc_z = 1.0, trans_x = 0.0, trans_y = 0.0, trans_z = 0.0;
int larg = 0, alt = 0, lt = 0;

// Desenha um texto na janela GLUT
void texto(void* font, char* string)
{
    // Exibe caractere a caractere
    while (*string)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *string++);
}

// Função callback chamada para fazer o desenho
void desenho(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glScalef((GLfloat)esc_x, esc_y, esc_z);

    //Viewport 1
    glViewport((GLsizei)larg * 0.3, 0, (GLsizei)larg * 0.7, (GLsizei)alt);

    // camera
    gluLookAt(cam_x, cam_y, cam_z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glRotatef((GLfloat)rot_x, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)rot_y, 0.0, 1.0, 0.0);
    glRotatef((GLfloat)rot_z, 0.0, 0.0, 1.0);

    // Dado
    glPushMatrix();
    glTranslatef((GLfloat)trans_x, trans_y, trans_z);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(1.0);
    glColor3f(0.5, 0.5, 0.5);
    glLineWidth(1);
    glutWireCube(1.0);

    // lado 1
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0, 0, -0.505);
    glutSolidCone(0.15, 0, 16, 16);

    // lado 2
    glColor3f(0.0, 0.0, 0.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(0.2, 0.3, 0.505);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(-0.45, 0.48, 0.0);
    glutSolidCone(0.15, 0, 16, 16);

    // lado 3
    glColor3f(0.0, 0.0, 0.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glTranslatef(0.25, 0.5, 0.235);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(-0.3, 0.3, 0.0);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(0.6, -0.6, 0.0);
    glutSolidCone(0.15, 0, 16, 16);

    // lado 4
    glColor3f(0.0, 0.0, 0.0);
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(0.3, 0.06, 0.235);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(0.45, -0.5, 0.0);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(0.01, 0.5, 0.0);
    glutSolidCone(0.15, 0, 16, 16);

    // lado 5
    glColor3f(0.0, 0.0, 0.0);
    glRotatef(-180, 0.0, 1.0, 0.0);
    glTranslatef(-0.05, -0.5, 1.045);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(0.6, -0.5, 0.0);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(0.01, 0.5, 0.0);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(-0.3, -0.25, 0.0);
    glutSolidCone(0.15, 0, 16, 16);

    // lado 6
    glColor3f(0.0, 0.0, 0.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glTranslatef(-0.25, 0.20, 0.505);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(0.0, 0.32, 0.0);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(0.0, 0.32, 0.0);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(0.45, 0.0, 0.0);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(0.0, -0.32, 0.0);
    glutSolidCone(0.15, 0, 16, 16);
    glTranslatef(0.0, -0.32, 0.0);
    glutSolidCone(0.15, 0, 16, 16);

    glPopMatrix();

    glPopMatrix();

    // Viewport 2
    glViewport(0, 0, (GLsizei)larg * 0.3, (GLsizei)alt);
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glTranslatef(0, 0, -1);
    glRectf(-5, -5, 5, 5);
    glPopMatrix();

    // Texto
    // Posiciona o texto usando transformações geométricas
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-2.6, 2.8, 0);
    glScalef(0.0035, 0.0015, 0.0015); // diminui o tamanho do fonte
    glLineWidth(2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Visualizacao de Dado 3D");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3.0, 2.45, 0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Pressione X para girar o dado no eixo x");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3.0, 2.30, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Pressione C para girar o dado no eixo y");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3.0, 2.15, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Pressione Z para girar o dado no eixo z");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3.0, 2.0, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "SHIFT + tecla X, C ou Z para girar no sentido contrario");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3.0, 1.85, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Pressione T ou R para aumentar ou diminuir o dado");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3.0, 1.70, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Pressione Q ou W ou a para espelhar nos eixo x, y e z");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3, 1.55, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Pressione S para translacao no eixo x");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3, 1.40, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Pressione D para translacao no eixo y");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3, 1.25, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Pressione F para translacao no eixo z");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3, 1.10, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "SHIFT + tecla S, D ou F translacao no sentido contrario");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3, 0.95, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Pressione U para mover a camera no eixo x");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3, 0.80, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Pressione I para mover a camera no eixo y");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3, 0.65, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Pressione O para mover a camera no eixo z");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3, 0.50, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "SHIFT + tecla U, I ou O para mover no sentido contrario");
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(-3, 0.35, 0.0);
    glScalef(0.0015, 0.0008, 0.0008); // diminui o tamanho do fonte
    glLineWidth(1.2); // define a espessura da linha
    texto(GLUT_STROKE_ROMAN, "Pressione ESC para sair");
    glPopMatrix();

    glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void inicializacao(void)
{
    glEnable(GL_DEPTH_TEST);

    //cor de fundo da janela de visualização
    glClearColor(0, 0, 0.3, 0.3);

    glShadeModel(GL_FLAT);
}

void projecao(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, 1, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
    alt = h;
    larg = w;
}

// Função callback chamada para gerenciar eventos de teclado
void teclado(unsigned char tecla, int x, int y)
{
    static bool telacheia = true;
    switch (tecla) {
    case 'z':
        rot_z = (rot_z + 5) % 360;
        glutPostRedisplay();
        break;
    case 'Z':
        rot_z = (rot_z - 5) % 360;
        glutPostRedisplay();
        break;
    case 'x':
        rot_x = (rot_x + 5) % 360;
        glutPostRedisplay();
        break;
    case 'X':
        rot_x = (rot_x - 5) % 360;
        glutPostRedisplay();
        break;
    case 'c':
        rot_y = (rot_y + 5) % 360;
        glutPostRedisplay();
        break;
    case 'C':
        rot_y = (rot_y - 5) % 360;
        glutPostRedisplay();
        break;
    case 't':
        esc_x = (esc_x + 0.1);
        esc_y = (esc_y + 0.1);
        esc_z = (esc_z + 0.1);
        glutPostRedisplay();
        break;
    case 'r':
        esc_x = (esc_x - 0.1);
        esc_y = (esc_y - 0.1);
        esc_z = (esc_z - 0.1);
        glutPostRedisplay();
        break;
    case 'q':
        esc_x = -(esc_x);
        glutPostRedisplay();
        break;
    case 'w':
        esc_y = -(esc_y);
        glutPostRedisplay();
        break;
    case 'a':
        esc_z = -(esc_z);
        glutPostRedisplay();
        break;
    case 's':
        trans_x = (trans_x + 0.2);
        glutPostRedisplay();
        break;
    case 'S':
        trans_x = (trans_x - 0.2);
        glutPostRedisplay();
        break;
    case 'd':
        trans_y = (trans_y + 0.2);
        glutPostRedisplay();
        break;
    case 'D':
        trans_y = (trans_y - 0.2);
        glutPostRedisplay();
        break;
    case 'f':
        trans_z = (trans_z + 0.2);
        glutPostRedisplay();
        break;
    case 'F':
        trans_z = (trans_z - 0.2);
        glutPostRedisplay();
        break;
    case 'u':
        cam_x = (cam_x + 2);
        glutPostRedisplay();
        break;
    case 'U':
        cam_x = (cam_x - 2);
        glutPostRedisplay();
        break;
    case 'i':
        cam_y = (cam_y + 2);
        glutPostRedisplay();
        break;
    case 'I':
        cam_y = (cam_y - 2);
        glutPostRedisplay();
        break;
    case 'o':
        cam_z = (cam_z + 2);
        glutPostRedisplay();
        break;
    case 'O':
        cam_z = (cam_z - 2);
        glutPostRedisplay();
        break;
    case 27: // esc para sair
        exit(0);
        break;
    default:
        break;
    }
}

// Programa Principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(largura, altura);
    glutInitWindowPosition(20, 20);
    glutCreateWindow("Trabalho 01 - Computacao Grafica");
    inicializacao();
    glutFullScreen();
    glutDisplayFunc(desenho);
    glutReshapeFunc(projecao);
    glutKeyboardFunc(teclado);
    glutMainLoop();
    return 0;
}
