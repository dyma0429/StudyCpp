#include "Runnable.h"

namespace NServerNetLib
{

	Runnable::~Runnable()
	{
		Stop();
	}

	void Runnable::Start()
	{
		isRun = true;
		runThread = std::thread( &Runnable::Run, this );
	}

	void Runnable::Stop()
	{
		if ( isRun == false )
		{
			return;
		}
		isRun = false;
		runThread.join();
	}

}