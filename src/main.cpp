#include <filesystem>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include <vector>
#include <map>

#include "vertexbuffer.h"
#include "vertexarray.h"
#include "shader.h"
#include "renderer.h"
#include "camera.h"
#include "navigationcontrols.h"

#include "plato.h"
#include "piece.h"



int main()
{
    /************************** INITIALISATION DE GLFW ***************************/

    if(!glfwInit()){
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4); //antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //version core

    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);

    /************************** INITIALISATION DE LA FENETRE ***************************/

    //définition de la taille de la fenêtre
    int width=600;
    int height=600;

    //On récupère les dimensions de l'écran pour créer la fenètre
    GLFWmonitor* primary = glfwGetPrimaryMonitor();
    glfwGetMonitorWorkarea(primary,nullptr,nullptr, &width, &height);

    //Enfin on crée la fenêtre
    GLFWwindow* window = glfwCreateWindow(width,height,"OpenGL_API",NULL,NULL);
    glfwSwapInterval(1);
    //On vérifie que l'initialisation a bien marché
    if (window==NULL){
        fprintf(stderr, "Erreur lors de la création de la fénêtre\n");
        glfwTerminate();
        return -1;
    }

    //Enfin on définit la fenêtre créée comme la fenêtre sur laquelle on va dessiner
    glfwMakeContextCurrent(window);

    /************************** INITIALISATION DE GLEW ***************************/
    glewExperimental=true;
    if (glewInit() != GLEW_OK){
        fprintf(stderr, "Erreur lors de l'initialisation de GLEW\n");
        return -1;
    }

    /************************** INITIALISATION DES PARAMETRES ***************************/
    std::string path = std::filesystem::absolute("../src");

    Renderer renderer;
    Shader shader(path+"/shaders/SimpleVertexShader.vertexshader", path+"/shaders/SimpleFragmentShader.fragmentshader");
    shader.Bind();
    VertexArray va;
    va.Bind();


    Camera cam(width, height);
    NavigationControls controls(window, &cam);
    Plato board;

    std::string pathOBJ = path + "/model/pawn.obj";


    // Object piece(pathOBJ.c_str(), path + "/textures/noir.png");

 
    // std::vector<Piece*> pawnsBlack;

    // for (int i = 0; i < 8; i++) {
    //     pawnsBlack.push_back(new Piece(i*2, 2));
    // }

    // std::vector<Piece*> pawnsWhite;

    // for (int i = 0; i < 8; i++) {
    //     pawnsWhite.push_back(new Piece(i*2, 6*2));
    // }


    /************************** BOUCLE DE RENDU ***************************/
  
    // Assure que l'on peut capturer les touche de clavier
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    //On indique la couleur de fond
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    //On autorise les tests de profondeur
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    float lastTime = glfwGetTime();
    float currentTime, deltaTime;

    while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window)){

        currentTime = glfwGetTime();
        deltaTime = currentTime-lastTime;
        lastTime = currentTime;

        controls.update(deltaTime, &shader);
        cam.computeMatrices(width, height);

        //////////////// AFFICHAGE DES OBJETS ///////////////
        renderer.Clear();

        board.Draw(va, cam, shader, renderer);


        // for (int i = 0; i < 8; i++) {
        //     pawnsBlack.at(i)->Draw(va, cam, shader, renderer);
        // }

        // for (int i = 0; i < 8; i++) {
        //     pawnsWhite.at(i)->Draw(va, cam, shader, renderer);
        // }


        ////////////////Partie rafraichissement de l'image et des évènements///////////////
        //Swap buffers : frame refresh
        glfwSwapBuffers(window);
        //get the events
        glfwPollEvents();
    }
    glfwTerminate();

    return 0;
}
