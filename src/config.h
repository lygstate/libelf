#ifndef _CONFIG_H_
#define _GNU_SOURCE
#include "eu-config.h"

#define HAVE_DECL_MEMPCPY 1
#ifndef _WIN32
#define HAVE_DECL_MEMRCHR 1
#endif
#define HAVE_DECL_POWEROF2 1
#define HAVE_DECL_RAWMEMCHR 0
#define HAVE_DECL_REALLOCARRAY 1
#define HAVE_VISIBILITY 1

#undef HAVE_GCC_STRUCT
#undef USE_LOCKS
#endif