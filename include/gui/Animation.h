#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <QTimer>
#include <QColor>
#include <QTimer>
#include <QSet>
#include <QtGlobal>
#include <time.h>

#define M_PI 3.14159265358979323846

class Animated;

quint64 getms(bool checked = false);

namespace anim {

	typedef double (*transition)(const double &delta, const double &dt);
	
    double linear(const double &delta, const double &dt);
	double sineInOut(const double &delta, const double &dt);
    double halfSine(const double &delta, const double &dt);
    double easeOutBack(const double &delta, const double &dt);
    double easeInCirc(const double &delta, const double &dt);
    double easeOutCirc(const double &delta, const double &dt);
    double easeInCubic(const double &delta, const double &dt);
    double easeOutCubic(const double &delta, const double &dt);
    double easeInQuint(const double &delta, const double &dt);
    double easeOutQuint(const double &delta, const double &dt);

	class fvalue { // float animated value
	public:

		fvalue() {
		}
		fvalue(const double &_from) : cur(_from), from(_from), delta(0) {
		}
		fvalue(const double &_from, const double &_to) : cur(_from), from(_from), delta(_to - _from) {
		}
		void start(const double &_to) {
			from = cur;
			delta = _to - from;
		}
		void restart() {
			delta = from + delta - cur;
			from = cur;
		}
		const double &current() const {
			return cur;
		}
		double to() const {
			return from + delta;
		}
		fvalue &update(const double &dt, transition func) {
			cur = from + (*func)(delta, dt);
			return *this;
		}
		void finish() {
			cur = from + delta;
			from = cur;
			delta = 0;
		}

	private:

		double cur, from, delta;
	};

	class ivalue { // int animated value
	public:

		ivalue() {
		}
		ivalue(qint32 _from) : cur(_from), from(double(_from)), delta(0) {
		}
		ivalue(qint32 _from, qint32 _to) : cur(_from), from(double(_from)), delta(double(_to - _from)) {
		}
		void start(qint32 _to) {
			from = double(cur);
			delta = double(_to) - from;
		}
		void restart() {
			delta = from + delta - double(cur);
			from = double(cur);
		}
		qint32 current() const {
			return cur;
		}
		qint32 to() const {
			return from + delta;
		}
		ivalue &update(const double &dt, transition func) {
			cur = qRound(from + (*func)(delta, dt));
			return *this;
		}
		void finish() {
			cur = qRound(from + delta);
			from = cur;
			delta = 0;
		}

	private:

		qint32 cur;
		double from, delta;
	};

	class cvalue { // QColor animated value
	public:

		cvalue() {
		}
		cvalue(const QColor &from) : cur(from), from_r(from.redF()),
	   								from_g(from.greenF()), from_b(from.blueF()),
								   	from_a(from.alphaF()), delta_r(0), delta_g(0), delta_b(0), delta_a(0) {}
		cvalue(const QColor &from, const QColor &to)
			: cur(from)
			, from_r(from.redF()), from_g(from.greenF()), from_b(from.blueF()), from_a(from.alphaF())
			, delta_r(to.redF() - from.redF()), delta_g(to.greenF() - from.greenF()), delta_b(to.blueF() - from.blueF()), delta_a(to.alphaF() - from.alphaF())
		{
		}
		void start(const QColor &to) {
			from_r = cur.redF();
			from_g = cur.greenF();
			from_b = cur.blueF();
			from_a = cur.alphaF();
			delta_r = to.redF() - from_r;
			delta_g = to.greenF() - from_g;
			delta_b = to.blueF() - from_b;
			delta_a = to.alphaF() - from_a;
		}
		void restart() {
			delta_r = from_r + delta_r - cur.redF();
			delta_g = from_g + delta_g - cur.greenF();
			delta_b = from_b + delta_b - cur.blueF();
			delta_a = from_a + delta_a - cur.alphaF();
			from_r = cur.redF();
			from_g = cur.greenF();
			from_b = cur.blueF();
			from_a = cur.alphaF();
		}
		const QColor &current() const {
			return cur;
		}
		QColor to() const {
			QColor result;
			result.setRedF(from_r + delta_r);
			result.setGreenF(from_g + delta_g);
			result.setBlueF(from_b + delta_b);
			result.setAlphaF(from_a + delta_a);
			return result;
		}
		cvalue &update(const double &dt, transition func) {
			cur.setRedF(from_r + (*func)(delta_r, dt));
			cur.setGreenF(from_g + (*func)(delta_g, dt));
			cur.setBlueF(from_b + (*func)(delta_b, dt));
			cur.setAlphaF(from_a + (*func)(delta_a, dt));
			return *this;
		}
		void finish() {
			cur.setRedF(from_r + delta_r);
			cur.setGreenF(from_g + delta_g);
			cur.setBlueF(from_b + delta_b);
			cur.setAlphaF(from_a + delta_a);
			from_r = cur.redF();
			from_g = cur.greenF();
			from_b = cur.blueF();
			from_a = cur.alphaF();
			delta_r = delta_g = delta_b = delta_a = 0;
		}

	private:

		QColor cur;
		double from_r, from_g, from_b, from_a, delta_r, delta_g, delta_b, delta_a;
	};

	void start(Animated *obj);
	void stop(Animated *obj);

	void startManager();
	void stopManager();

};

class Animated {
public:

	Animated() : animStarted(0), animInProcess(false) {
	}

	virtual bool animStep(double ms) = 0;

	void animReset() {
		animStarted = double(getms());
	}

	virtual ~Animated() {
		if (animating()) {
			anim::stop(this);
		}
	}

	bool animating() const {
		return animInProcess;
	}

private:

	double animStarted;
	bool animInProcess;
	friend class AnimationManager;

};

class AnimationManager : public QObject {
Q_OBJECT

public:

	AnimationManager() : timer(this), iterating(false) {
		timer.setSingleShot(false);
		connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));
	}

	void start(Animated *obj) {
		obj->animReset();
		if (iterating) {
			toStart.insert(obj);
			if (!toStop.isEmpty()) {
				toStop.remove(obj);
			}
		} else {
			if (!objs.size()) {
				timer.start(7);
			}
			objs.insert(obj);
		}
		obj->animInProcess = true;
	}

	void stop(Animated *obj) {
		if (iterating) {
			toStop.insert(obj);
			if (!toStart.isEmpty()) {
				toStart.insert(obj);
			}
		} else {
			AnimObjs::iterator i = objs.find(obj);
			if (i != objs.cend()) {
				objs.erase(i);
				if (!objs.size()) {
					timer.stop();
				}
			}
		}
		obj->animInProcess = false;
	}

public slots:
	void timeout() {
		iterating = true;
		double ms = double(getms());
		for (AnimObjs::iterator i = objs.begin(), e = objs.end(); i != e; ) {
			Animated *obj = *i;
			if (!obj->animStep(ms - obj->animStarted)) {
				i = objs.erase(i);
				obj->animInProcess = false;
			} else {
				++i;
			}
		}
		iterating = false;
		if (!toStart.isEmpty()) {
			for (AnimObjs::iterator i = toStart.begin(), e = toStart.end(); i != e; ++i) {
				objs.insert(*i);
			}
			toStart.clear();
		}
		if (!toStop.isEmpty()) {
			for (AnimObjs::iterator i = toStop.begin(), e = toStop.end(); i != e; ++i) {
				objs.remove(*i);
			}
			toStop.clear();
		}
		if (!objs.size()) {
			timer.stop();
		}
	}

private:

	typedef QSet<Animated*> AnimObjs;
	AnimObjs objs;
	AnimObjs toStart;
	AnimObjs toStop;
	QTimer timer;
	bool iterating;

};
#endif/*__ANIMATION_H__*/
