// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
// Author: Shuo Chen (chenshuo at chenshuo dot com)

#ifndef MUDUO_BASE_CURRENTTHREAD_H
#define MUDUO_BASE_CURRENTTHREAD_H

#include <stdint.h>
#include <pthread.h>

namespace muduo
{
	namespace CurrentThread
	{
		// internal
		extern  int t_cachedTid;
		extern  char t_tidString[32];
		extern  int t_tidStringLength;
		extern  const char* t_threadName;
		//void cacheTid();

		inline int tid()
		{
			//if (__builtin_expect(t_cachedTid == 0, 0))  __builtin_expect 涉及到组成原理中的分支预判，告诉CPU哪一个分支可能性更大
			if (t_cachedTid == 0)
			{
				t_cachedTid = pthread_self();
			}
			return t_cachedTid;
		}

		inline const char* tidString() // for logging
		{
			return t_tidString;
		}

		inline int tidStringLength() // for logging
		{
			return t_tidStringLength;
		}

		inline const char* name()
		{
			return t_threadName;
		}

		bool isMainThread();

		void sleepUsec(int64_t usec);//实现在thread.cpp中
	}
}

#endif
