#include "Scene.h"

#include <SFML/Graphics/RenderWindow.hpp>

Scene::Scene(const std::string& _name)
{
	name = _name;
}

void Scene::Awake() const
{

}

void Scene::Start() const
{

}

void Scene::PreRender() const
{

}

void Scene::PostRender() const
{

}

void Scene::Present() const
{

}

void Scene::Destroy() const
{

}

void Scene::Update(const float _delta_time) const
{

}

void Scene::Render(sf::RenderWindow* _window) const
{

}

const std::string& Scene::GetName() const
{
	return name;
}