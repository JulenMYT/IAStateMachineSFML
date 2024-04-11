#pragma once

#include <string>
#include <unordered_map>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Module.h"

class AnimatedTileSet;
class TileSet;

class RessourcesModule final : public Module
{
protected:
	~RessourcesModule() = default;

private:
	std::unordered_map<std::string, TileSet> tilesets;
	std::unordered_map<std::string, AnimatedTileSet> animations;
};

class TileSet
{
public:
	explicit TileSet(const std::string& _path)
	{
		texture = new sf::Texture();
		texture->loadFromFile(_path);
	}

	~TileSet()
	{
		delete texture;
	}

	TileSet* AddSprite(const std::string& _name, const sf::IntRect& _rect)
	{
		sprites.insert_or_assign(_name, sf::Sprite(*texture, _rect));
		return this;
	}

	TileSet* AddSprites(const std::string& _base_name, const sf::IntRect& _rect, const sf::Vector2i& _size, const sf::Vector2i& _offset)
	{
		for (int y = 0; y < _size.y; y++)
		{
			for (int x = 0; x < _size.x; x++)
			{
				sprites.insert_or_assign(_base_name + "_" + std::to_string(x) + "_" + std::to_string(y), sf::Sprite(*texture, sf::IntRect(_rect.left + x * _offset.x, _rect.top + y * _offset.y, _offset.x, _offset.y)));
			}
		}
		return this;
	}

private:
	sf::Texture* texture;

	std::unordered_map<std::string, sf::Sprite> sprites;
};

class AnimatedTileSet : public TileSet
{
public:
	explicit AnimatedTileSet(const std::string& _path) : TileSet(_path) {}

	void SetSpeed(float& _speed) const
	{
		_speed = speed;
	}

	float GetSpeed() const
	{
		return speed;
	}

private:
	float speed = 0.5f;
};
