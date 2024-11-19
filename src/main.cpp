#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include <vector>

#include "vertexbuffer.h"
#include "vertexarray.h"
#include "shader.h"
#include "renderer.h"
#include "camera.h"
#include "navigationcontrols.h"

#include "loadModel.h"

#include "plato.h"

glm::mat4 mvpObject(glm::vec3 pos, Object& o, Camera& cam){

    o.position = pos;
    glm::mat4 m = o.getModelMatrix();
    glm::mat4 v = cam.getViewMatrix();
    glm::mat4 p = cam.getProjectionMatrix();
    glm::mat4 mvp = p*v*m;

    return mvp;
}

using namespace std;

int main()
{
    string path = "/home/vpech/Documents/Github/Chess-OpenGL/src";
/////////////////////////Initialisation de GLFW/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


/////////////////////////Ouverture de la fenêtre/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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



/////////////////////////Initialisation de GLEW/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Initialisation de GLEW
    glewExperimental=true;
    if (glewInit() != GLEW_OK){
        fprintf(stderr, "Erreur lors de l'initialisation de GLEW\n");
        return -1;
    }

/////////////////////////On crée un Renderer/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Renderer renderer;


/////////////////////////On crée un Shader/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Shader shader(path+"/shaders/SimpleVertexShader.vertexshader", path+"/shaders/SimpleFragmentShader.fragmentshader");
    shader.Bind();

/////////////////////////On crée un vertex array/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    VertexArray va;
    va.Bind();

/////////////////////////On crée la camera et les contrôles/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Camera cam(width, height);
    NavigationControls controls(window, &cam);

/////////////////////////Création des formes à afficher/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::vector<glm::vec3> verticesCase;
	std::vector<glm::vec2> uvsCase;
	std::vector<glm::vec3> normalsCase; // Won't be used at the moment.
	bool resCase = loadOBJ("/home/vpech/Documents/Github/Chess-OpenGL/src/model/case.obj", verticesCase, uvsCase, normalsCase);
    Object o(verticesCase, uvsCase, path+"/textures/caseNoire.png");
    Object o2(verticesCase, uvsCase, path+"/textures/caseBlanche.png");

    // Plato p;

    // Object o = p.caseWhite;
    // Object o2 = p.caseBlack;
    glm::mat4 mvp;


/////////////////////////Création de la matrice MVP/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // cam.computeMatrices(width, height);
    // glm::mat4 m = o.getModelMatrix();
    // glm::mat4 v = cam.getViewMatrix();
    // glm::mat4 p = cam.getProjectionMatrix();

    // glm::mat4 mvp = p*v*m;

    // shader.setUniformMat4f("MVP", mvp);




/////////////////////////Boucle de rendu/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    // Assure que l'on peut capturer les touche de clavier
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    //On indique la couleur de fond
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    //On autorise les tests de profondeur

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);


    float lastTime = glfwGetTime();
    float currentTime, deltaTime;

    int tailleCase = 2;

    while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window)){

        currentTime = glfwGetTime();
        deltaTime = currentTime-lastTime;
        lastTime = currentTime;

        controls.update(deltaTime, &shader);
        cam.computeMatrices(width, height);


        ////////////////On commence par vider les buffers///////////////
        renderer.Clear();
        // renderer.Draw(va, o, shader);

    
        // p.Draw(va, cam, shader, renderer);

        int nbCase = 8;

        for (int i=0; i<nbCase; i++){
            if (i%2==0){
                for (int j=0; j<nbCase; j++){
                    if (j%2==0){
                        glm::vec3 pos(i*2, j*2, 0);
                        mvp = mvpObject(pos, o, cam);
                        shader.setUniformMat4f("MVP", mvp);
                        renderer.Draw(va, o, shader);
                        std::cout<<"Blanc ("<<i*2<<","<<j*2<<") ";
                    }
                    else{
                        glm::vec3 pos(i*2, j*2, 0);
                        mvp = mvpObject(pos, o2, cam);
                        shader.setUniformMat4f("MVP", mvp);
                        renderer.Draw(va, o2, shader);
                        std::cout<<"Noir ("<<i*2<<","<<j*2<<") ";
                    }
                }
                std::cout<<"\n";
            }
            else{
                for (int j=0; j<nbCase; j++){
                    if (j%2==0){
                        glm::vec3 pos(i*2, j*2, 0);
                        mvp = mvpObject(pos, o2, cam);
                        shader.setUniformMat4f("MVP", mvp);
                        renderer.Draw(va, o2, shader);
                        std::cout<<"Noir ("<<i*2<<","<<j*2<<") ";
                    }
                    else{
                        glm::vec3 pos(i*2, j*2, 0);
                        mvp = mvpObject(pos, o, cam);
                        shader.setUniformMat4f("MVP", mvp);
                        renderer.Draw(va, o, shader);
                        std::cout<<"Blanc ("<<i*2<<","<<j*2<<") ";
                    }
                }
                std::cout<<"\n";
            }
        }
        std::cout<<"-------------------------------------------\n";

        ////////////////Partie rafraichissement de l'image et des évènements///////////////
        //Swap buffers : frame refresh
        glfwSwapBuffers(window);
        //get the events
        glfwPollEvents();
    }
    glfwTerminate();

    return 0;
}
