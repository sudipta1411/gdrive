#include <QtMath>
#include <QtDebug>
#include "gui/Animation.h"
#include <time.h>

quint64 getms(bool checked) {
	qint64 start = 0;
	timespec ts;
	(void)checked;
	int res = clock_gettime(CLOCK_MONOTONIC, &ts);
	if(res != 0) {
		return 0;
	}
	quint64 current = 1000 * quint64(ts.tv_sec) + (quint64(ts.tv_nsec) / 1000000);
	return quint64(current - start);
}

namespace {
	AnimationManager *manager = 0;
};

namespace anim {

    double linear(const double &delta, const double &dt) {
		return delta * dt;
	}

	double sineInOut(const double &delta, const double &dt) {
		return -(delta / 2) * (qCos(M_PI * dt) - 1);
	}

    double halfSine(const double &delta, const double &dt) {
		return delta * qSin(M_PI * dt / 2);
	}

    double easeOutBack(const double &delta, const double &dt) {
		static const double s = 1.70158;

		const double t = dt - 1;
		return delta * (t * t * ((s + 1) * t + s) + 1);
	}

    double easeInCirc(const double &delta, const double &dt) {
		return -delta * (qSqrt(1 - dt * dt) - 1);
	}

    double easeOutCirc(const double &delta, const double &dt) {
		const double t = dt - 1;
		return delta * qSqrt(1 - t * t);
	}

    double easeInCubic(const double &delta, const double &dt) {
		return delta * dt * dt * dt;
	}

	double easeOutCubic(const double &delta, const double &dt) {
		const double t = dt - 1;
		return delta * (t * t * t + 1);
	}

    double easeInQuint(const double &delta, const double &dt) {
		const double t2 = dt * dt;
		return delta * t2 * t2 * dt;
	}

    double easeOutQuint(const double &delta, const double &dt) {
		const double t = dt - 1, t2 = t * t;
		return delta * (t2 * t2 * t + 1);
	}

	void start(Animated *obj) {
		if (!manager) return;
		manager->start(obj);
	}

	void stop(Animated *obj) {
		if (!manager) return;
		manager->stop(obj);
	}

	void startManager() {
		delete manager;
		manager = new AnimationManager();
		qDebug()<<"AnimationManager started";
	}

	void stopManager() {
		delete manager;
		manager = 0;
		qDebug()<<"AnimationManager stopped";
	}

}
