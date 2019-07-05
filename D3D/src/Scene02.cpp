#include "PCH.h"
#include "Scene02.h"

void Scene02::on_enter()
{
	std::cout << "SCENE 02 LOADED\n";
}

void Scene02::on_exit()
{
	std::cout << "LEAVING SCENE 02\n";
}

void Scene02::update()
{

}

void Scene02::handle_events()
{

}

void Scene02::draw()
{
	//GREEN
	//Says Scene 2 loaded, but never called Scene2 DRAW(), the screen stayed Red (scene 1 color)?
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}