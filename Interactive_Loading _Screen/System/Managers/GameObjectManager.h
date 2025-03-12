#pragma once
#include "unordered_map"
#include "vector"
#include "string"
#include "../../Entity/GameObject.h"
#include "SFML/Graphics.hpp"
#include "iostream"
namespace managers
{
	using namespace entities;
	class GameObjectManager
	{
	public:
		static GameObjectManager* getInstance();
		GameObject* findObjectByName(std::string name);
		std::vector<GameObject*> getAllObjects();
		int activeObjects();
		void processInput(sf::Event event);
		void update(sf::Time deltaTime);
		void draw(sf::RenderWindow* window);
		void addObject(GameObject* gameObject);
		void deleteObject(GameObject* gameObject);
		void deleteObjectByName(std::string name);

	private:
		GameObjectManager() {};
		GameObjectManager(GameObjectManager const&) {};             // copy constructor is private
		GameObjectManager& operator=(GameObjectManager const&) {};  // assignment operator is private
		static GameObjectManager* sharedInstance;

		std::unordered_map<std::string, GameObject*> gameObjectMap;
		std::vector<GameObject*> gameObjectList;
	};
}


