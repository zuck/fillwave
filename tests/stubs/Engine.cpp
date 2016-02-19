/*
 * Engine.cpp
 *
 *  Created on: Jan 17, 2016
 *      Author: filip
 */

#include <fillwave/Log.h>
#include <fillwave/Fillwave.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

FLOGINIT("Engine", FERROR | FFATAL | FINFO | FDEBUG)

namespace fillwave {

struct Engine::EngineImpl {
	EngineImpl() = default;
	~EngineImpl() = default;
};

Engine::Engine(GLint /*argc*/, GLchar* const argv[]) {
	(void)argv;
}

Engine::~Engine() = default;

pTexture2D Engine::storeTexture(const std::string& /*texturePath*/, const GLuint& /*mapType*/, framework::eCompression /*compression*/) {
	return pTexture2D();
}

}