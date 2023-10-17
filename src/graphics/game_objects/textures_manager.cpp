#include "textures_manager.hpp"


//// TexturesManager

// Constructors
TexturesManager::TexturesManager() {
}

// Singleton
TexturesManager::Ptr TexturesManager::GetInstance() {
    if (textures_manager_ == nullptr) {
        textures_manager_ = new TexturesManager();
    }
    return textures_manager_;
}

