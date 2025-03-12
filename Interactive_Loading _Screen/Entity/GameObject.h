#pragma once
#include "string"
#include "SFML/Graphics.hpp"
namespace entities
{
	class GameObject:public sf::NonCopyable
	{
	protected:
		std::string name;
		sf::Sprite* sprite;
		sf::Texture* texture;
		bool isEnabled = true;
		float posX = 0.0f; 
		float posY = 0.0f;
		float scaleX = 1.0f; 
		float scaleY = 1.0f;
	public:
		GameObject(std::string name);
		~GameObject();
		virtual void initialize() = 0;
		virtual void processInput(sf::Event event) = 0;
		virtual void update(sf::Time deltaTime) = 0;
		virtual void draw(sf::RenderWindow* targetWindow);

	public:
		std::string getName();
		virtual void setPosition(float x, float y);
		virtual void setScale(float x, float y);
		virtual sf::FloatRect getLocalBounds();
		virtual sf::Vector2f getPosition();
		virtual sf::Vector2f getScale();
		bool getEnabled();
		void setEnabled(bool isEnabled);
		float getWidth();
		float getHeight();
	};
}
