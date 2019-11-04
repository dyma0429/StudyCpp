#include "RedisConnectionPool.h"

namespace NServerNetLib
{
	RedisConnectionPool::RedisConnectionPool( const std::string& ipAddr, unsigned short port )
	{
		connectionPool = redis3m::simple_pool::create( ipAddr, port );
	}

	redis3m::connection::ptr_t RedisConnectionPool::GetConnection()
	{
		return connectionPool->get();
	}

	void RedisConnectionPool::ReleaseConnection( redis3m::connection::ptr_t conn )
	{
		connectionPool->put( conn );
	}

}