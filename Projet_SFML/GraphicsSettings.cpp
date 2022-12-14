#include "GraphicsSettings.h"

GraphicsSettings::GraphicsSettings()
{
	this->title = "GAME";
	this->resolution = sf::VideoMode::getDesktopMode();
	this->fullscreen = false;
	this->verticaleSync = false;
	this->contextSettings.antialiasingLevel = 0;
	this->videoModes = sf::VideoMode::getFullscreenModes();

	this->changed = false;
}

void GraphicsSettings::saveToFile(const std::string path)
{
	std::ofstream ofs(path);
	ofs.clear();
	if (ofs.is_open())
	{
		ofs << this->title << "\n";
		ofs << this->resolution.width << " " << this->resolution.height << "\n";
		ofs << this->fullscreen << "\n";
		ofs << this->frameRateLimit << "\n";
		ofs << this->verticaleSync << "\n";
		ofs << this->contextSettings.antialiasingLevel << "\n";
	}

	ofs.close();
}

void GraphicsSettings::loadFromFile(const std::string path)
{
	std::ifstream ifs(path);

	if (ifs.is_open())
	{
		std::getline(ifs, this->title);
		ifs >> this->resolution.width >> this->resolution.height;
		ifs >> this->fullscreen;
		ifs >> this->frameRateLimit;
		ifs >> this->verticaleSync;
		ifs >> this->contextSettings.antialiasingLevel;
	}

	ifs.close();
}
