#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

class Scene
{
public :
	explicit Scene(const std::string& _name);

	void Awake() const;
	void Start() const;
	void Update(float _delta_time) const;

	void PreRender() const;
	void Render(sf::RenderWindow* _window) const;
	void PostRender() const;
	void Present() const;

	void Destroy() const;

	const std::string& GetName() const;

private :
	std::string name;
};