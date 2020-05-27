#ifndef SimpleMusic_h
#define SimpleMusic_h

#include <Timer.h>

class SimpleMusic {
	public:
		SimpleMusic(int pin);
		bool play();
		bool stop();
	private:
		Timer rate_timer_;
		int track_location_;
		int pin_;

		int sos_track_[17] = {50,50,50,50,50,50,150,50,150,50,150,50,50,50,50,50,5000};
};

#endif