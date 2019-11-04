#pragma once

#include <string>

#include "NonCopyable.h"
#undef ERROR
#include <redis3m/redis3m.hpp>

namespace NServerNetLib
{
	class RedisConnectionPool : public Noncopyable
	{
	public:
		RedisConnectionPool( const std::string& ipAddr, unsigned short port );
		virtual ~RedisConnectionPool() = default;

		redis3m::connection::ptr_t GetConnection();
		void ReleaseConnection( redis3m::connection::ptr_t conn );

	private:
		redis3m::simple_pool::ptr_t connectionPool;
	};
}