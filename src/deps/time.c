/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c) 2005-2009, Kimio Kuramitsu <kimio at ynu.ac.jp>
 *           (c) 2008-      Konoha Software Foundation
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/* ************************************************************************ */


#include"commons.h"

#ifdef KONOHA_ON_LKM
#undef KNH_USING_POSIX
#endif

#ifdef KNH_USING_POSIX
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <sys/stat.h>
#include<dlfcn.h>
#include<time.h>
#include<sys/time.h>

#ifdef KONOHA_ON_MACOSX
#include <mach-o/dyld.h>
#endif

#endif/*KNH_USING_POSIX*/

#ifdef KNH_USING_WINDOWS
#include<windows.h>
#include <time.h>
#endif

#ifdef KNH_USING_BTRON
#include <btron/datetime.h>
#include <btron/event.h>
#endif

/* ************************************************************************ */

#ifdef __cplusplus
extern "C" {
#endif

/* ======================================================================== */
/* [time] */

int knh_getpid(void)
{
#if defined(KNH_USING_WINDOWS)
  return GetCurrentProcessId();
#elif defined(KNH_USING_POSIX)
	return getpid();
#else
	return 0;
#endif
}

/* ======================================================================== */
/* [time] */

knh_uint_t knh_initseed(void)
{
#if defined(KNH_USING_WINDOWS)
  return (knh_uint_t)time(NULL) + GetCurrentProcessId();
#elif defined(KNH_USING_POSIX)
	return (knh_uint_t)time(NULL) + getpid();
#elif defined(KNH_USING_BTRON)
        STIME st;
        get_tim(&st, NULL);
        return (knh_uint_t)st;
#else
	return 0;
#endif
}

/* ------------------------------------------------------------------------ */

knh_uint64_t knh_getTimeMilliSecond(void)
{
#if defined(KNH_USING_WINDOWS)
	DWORD tickCount = GetTickCount();
	return (knh_int64_t)tickCount;
#elif defined(KNH_USING_POSIX)
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
#elif defined(KNH_USING_BTRON)
        /* FIXME: thread safety */
        static volatile int first = 1;
        static UW start = 0;
        UW current;
        if (first) {
            get_etm(&start);
            first = 0;
        }
        get_etm(&current);
        return (knh_uint64_t)((current - start) & 0x7fffffff);
#else
	return 0;
#endif
}

/* ------------------------------------------------------------------------ */
/* [Profiler] */

knh_uint64_t knh_getProfCount(void)
{
	return 0;
}

/* ------------------------------------------------------------------------ */

knh_uint64_t knh_getProfCountPerSecond(void)
{
	return 1;
}

/* ======================================================================== */

#ifdef __cplusplus
}
#endif
