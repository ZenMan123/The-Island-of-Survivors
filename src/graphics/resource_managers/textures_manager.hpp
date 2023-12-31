#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

#include <common/utils/associative_storage.hpp>


// Main textures manager
class TexturesManager {
public:
    using Ptr = TexturesManager*;

    // Singleton
    TexturesManager(const TexturesManager& other) = delete;
    TexturesManager(TexturesManager&& other) = delete;

    void operator=(const TexturesManager&) = delete;
    void operator=(TexturesManager&&) = delete;

    [[nodiscard]] static TexturesManager::Ptr GetInstance();

private:
    inline static TexturesManager::Ptr textures_manager_ = nullptr;

    std::unordered_map<std::string, sf::Texture> textures_cache_;

    // Constructors
    TexturesManager();
};
