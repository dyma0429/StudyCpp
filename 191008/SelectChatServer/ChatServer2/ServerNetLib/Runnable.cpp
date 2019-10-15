#include "Runnable.h"

namespace NServerNetLib
{

	Runnable::~Runnable()
	{
		Stop();
	}

	void Runnable::Start()
	{
		runThread = std::thread( &Runnable::Run, this );
	}

	void Runnable::Stop()
	{
		isStopped = true;
		runThread.join();
	}

}