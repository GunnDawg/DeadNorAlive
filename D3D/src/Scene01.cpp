#include "PCH.h"
#include "Scene01.h"

void Scene01::on_enter()
{
	std::cout << "SCENE 01 LOADED\n";
}

void Scene01::on_exit()
{
	std::cout << "LEAVING SCENE 01\n";
}

void Scene01::update()
{

}

void Scene01::handle_events()
{

}

void Scene01::draw()
{
	//RED
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}