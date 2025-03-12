#pragma once
#pragma once
#include "SFML/Graphics.hpp"
#include "../System/Threading/ThreadPool.h"
using namespace threading;
static const float FRAME_RATE = 60.f;
static const sf::Time	TIME_PER_FRAME = sf::seconds(1.f / FRAME_RATE);;
static const int WINDOW_WIDTH = 1920;
static const int WINDOW_HEIGHT = 1080;