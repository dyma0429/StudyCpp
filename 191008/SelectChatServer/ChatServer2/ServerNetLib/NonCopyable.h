#pragma once

namespace NServerNetLib
{
	class Noncopyable
	{
	public:
		Noncopyable() = default;
		~Noncopyable() = default;

	private:
		Noncopyable( const Noncopyable& ) = delete;
		Noncopyable& operator=( const Noncopyable& ) = delete;
	};
}