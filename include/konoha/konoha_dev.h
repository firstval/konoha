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

#ifndef KONOHA_DEV_H_
#define KONOHA_DEV_H_

#ifdef KONOHA_ON_LKM
#include"konoha_lkm.h"
#else
#include<stdio.h>
#include<ctype.h>
#include<assert.h>
#include<setjmp.h>
#endif

#include<stdarg.h>

#ifndef LIBKONOHA
#ifdef HAVE_CONFIG_H
#include"../../config.h"
#endif
#endif

#include"konoha_config.h"

#include"konoha_deps.h"

#ifdef KONOHA_ON_TB
#include"konoha_tb.h"
#endif

#include"gen/konoha_class_.h"
#include"gen/konoha_knhapi_.h"

#ifndef EXPT_Exception
#define EXPT_Exception 1
#endif

#include"konoha_glue.h"
#include"konoha_gc.h"
#include"konoha_vm.h"

#ifndef LIBKONOHA
	#include"gen/konoha_proto_.h"
	#include"gen/konohac_stmt_.h"
#endif

#include"konoha_vm.h"
#include"konoha_macros.h"
#include"konoha_debug.h"

#endif /*KONOHA_DEV_H_*/
