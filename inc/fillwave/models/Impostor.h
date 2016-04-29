/*
 * Impostor.h
 *
 *  Created on: May 10, 2014
 *      Author: Filip Wasil
 */

#ifndef IMPOSTOR_H_
#define IMPOSTOR_H_

#include <fillwave/core/texturing/Texture2D.h>
#include <fillwave/core/texturing/Sampler.h>
#include <fillwave/core/pipeline/Program.h>
#include <fillwave/common/Finishable.h>
#include <fillwave/models/Entity.h>

namespace fillwave {
class Engine;
namespace framework {

/*! \class Impostor
 * \brief Drawable Entity built by fragment shader. Time limited.
 */

class Impostor: public Entity, public Finishable {
 public:
	Impostor(
	   Engine* engine,
	   GLfloat lifetime,
	   GLfloat size,
	   core::Texture* texture = nullptr,
	   GLenum blendingSource = GL_SRC_ALPHA,
	   GLenum blendingDestination = GL_ONE_MINUS_SRC_ALPHA);
	virtual ~Impostor() = default;

 protected:
	core::Program* mProgram;
	core::Texture* mTexture;
	core::Sampler* mSampler;
	GLfloat mSize;
	Blending mBlending;

	void coreDraw();
};

} /* framework */
typedef std::unique_ptr<framework::Impostor> pImpostor;
} /* fillwave */

#endif /* IMPOSTOR_H_ */
