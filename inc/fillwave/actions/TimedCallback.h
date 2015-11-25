/*
 * TimedCallback.h
 *
 *  Created on: 14 May 2014
 *      Author: Filip Wasil
 */

#ifndef TIMEDCALLBACK_H_
#define TIMEDCALLBACK_H_

#include <fillwave/OpenGL.h>
#include <fillwave/actions/ItemCallback.h>
#include <fillwave/actions/TimeEvent.h>
#include <fillwave/models/Moveable.h>

namespace fillwave {

enum class eEasing : unsigned int {
	eNone,

	eSineIn, eSineOut, eSineInOut,

	eQuadIn, eQuadOut, eQuadInOut,

	eCubicIn, eCubicOut, eCubicInOut,

	eQuartIn, eQuartOut, eQuartInOut,

	eQuintIn, eQuintOut, eQuintInOut,

	eExpoIn, eExpoOut, eExpoInOut,

	eCircIn, eCircOut, eCircInOut,

	eBackIn, eBackOut, eBackInOut,

	eElasticIn, eElastic, eElasticInOut,

	eBounceIn, eBounce, eBounceInOut,

	eCustom
};

namespace actions {

/*! \class TimedCallback
 *
 * \brief ItemCallback to be finished after a period of time.
 *
 */

class TimedCallback: public ItemCallback {
public:
	TimedCallback(GLfloat timeToFinish, eEasing easing = eEasing::eNone);

	virtual ~TimedCallback() = default;

	/*	perform
	 * \brief Performs ItemCallback action.
	 */

	void perform(EventType* eventType);

	virtual void performTime(TimeEventData& e);

	virtual GLfloat easeCustom(GLfloat progress);

	GLfloat ease(GLfloat progress);

private:
	eEasing mEasing;
};

} /* actions */
} /* fillwave */

#endif /* TIMEDCALLBACK_H_ */

