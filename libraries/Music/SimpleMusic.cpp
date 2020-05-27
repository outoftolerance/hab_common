#include <SimpleMusic.h>

SimpleMusic::SimpleMusic(int pin):
pin_(pin)
{

}

bool SimpleMusic::play()
{
	//Check if playing already, if not set things up to start
	if(!rate_timer_.isStarted())
	{
		rate_timer_.forceReset();
		rate_timer_.setInterval(sos_track_[track_location_]);
		rate_timer_.start();

		digitalWrite(pin_, HIGH);

		track_location_++;
	}
	
	//Check if previous interval is over
	if(rate_timer_.check())
	{
		//Toggle pin
		digitalWrite(pin_, !digitalRead(pin_));

		//Set timer for next interval
		rate_timer_.stop();
		rate_timer_.setInterval(sos_track_[track_location_]);
		rate_timer_.start();

		//Move forward in track
		track_location_++;

		//If we reach the end, loop to beginning again
		if(track_location_ > sizeof(sos_track_)/sizeof(int))
		{
			track_location_ = 0;
		}
	}
}

bool SimpleMusic::stop()
{
	//Turn off
	digitalWrite(pin_, LOW);

	//Stop timer
	rate_timer_.stop();
	rate_timer_.forceReset();

	//Reset track location to start
	track_location_ = 0;
}