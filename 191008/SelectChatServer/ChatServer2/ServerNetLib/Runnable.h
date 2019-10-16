#pragma once

#include <thread>
#include <atomic>

#include "NonCopyable.h"

namespace NServerNetLib
{
	class Runnable : private Noncopyable
	{
	public:
		Runnable() = default;
		virtual ~Runnable();

		void Start();
		void Stop();

		inline bool IsRun()
		{
			return isRun;
		}

	protected:
		virtual void Run() = 0;

	private:
		std::atomic_bool isRun;
		std::thread runThread;
	};
}