/*   -*- buffer-read-only: t -*- vi: set ro:
 *  
 *  DO NOT EDIT THIS FILE   (serv-args.h)
 *  
 *  It has been AutoGen-ed  May  9, 2012 at 08:04:44 PM by AutoGen 5.16
 *  From the definitions    serv-args.def
 *  and the template file   options
 *
 * Generated from AutoOpts 36:4:11 templates.
 *
 *  AutoOpts is a copyrighted work.  This header file is not encumbered
 *  by AutoOpts licensing, but is provided under the licensing terms chosen
 *  by the gnutls-serv author or copyright holder.  AutoOpts is
 *  licensed under the terms of the LGPL.  The redistributable library
 *  (``libopts'') is licensed under the terms of either the LGPL or, at the
 *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources
 *  for details.
 *
 * The gnutls-serv program is copyrighted and licensed
 * under the following terms:
 *
 *  Copyright (C) 2000-2012 Free Software Foundation, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the
 *  GNU General Public License, version 3 or later
 *      <http://gnu.org/licenses/gpl.html>
 *
 *  gnutls-serv is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  gnutls-serv is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
 *  This file contains the programmatic interface to the Automated
 *  Options generated for the gnutls-serv program.
 *  These macros are documented in the AutoGen info file in the
 *  "AutoOpts" chapter.  Please refer to that doc for usage help.
 */
#ifndef AUTOOPTS_SERV_ARGS_H_GUARD
#define AUTOOPTS_SERV_ARGS_H_GUARD 1
#include "config.h"
#include <autoopts/options.h>

/*
 *  Ensure that the library used for compiling this generated header is at
 *  least as new as the version current when the header template was released
 *  (not counting patch version increments).  Also ensure that the oldest
 *  tolerable version is at least as old as what was current when the header
 *  template was released.
 */
#define AO_TEMPLATE_VERSION 147460
#if (AO_TEMPLATE_VERSION < OPTIONS_MINIMUM_VERSION) \
 || (AO_TEMPLATE_VERSION > OPTIONS_STRUCT_VERSION)
# error option template version mismatches autoopts/options.h header
  Choke Me.
#endif

/*
 *  Enumeration of each option:
 */
typedef enum {
    INDEX_OPT_DEBUG                =  0,
    INDEX_OPT_NOTICKET             =  1,
    INDEX_OPT_GENERATE             =  2,
    INDEX_OPT_QUIET                =  3,
    INDEX_OPT_NODB                 =  4,
    INDEX_OPT_HTTP                 =  5,
    INDEX_OPT_ECHO                 =  6,
    INDEX_OPT_UDP                  =  7,
    INDEX_OPT_MTU                  =  8,
    INDEX_OPT_DISABLE_CLIENT_CERT  =  9,
    INDEX_OPT_REQUIRE_CLIENT_CERT  = 10,
    INDEX_OPT_X509FMTDER           = 11,
    INDEX_OPT_PRIORITY             = 12,
    INDEX_OPT_DHPARAMS             = 13,
    INDEX_OPT_X509CAFILE           = 14,
    INDEX_OPT_X509CRLFILE          = 15,
    INDEX_OPT_PGPKEYFILE           = 16,
    INDEX_OPT_PGPKEYRING           = 17,
    INDEX_OPT_PGPCERTFILE          = 18,
    INDEX_OPT_X509KEYFILE          = 19,
    INDEX_OPT_X509CERTFILE         = 20,
    INDEX_OPT_X509DSAKEYFILE       = 21,
    INDEX_OPT_X509DSACERTFILE      = 22,
    INDEX_OPT_X509ECCKEYFILE       = 23,
    INDEX_OPT_X509ECCCERTFILE      = 24,
    INDEX_OPT_PGPSUBKEY            = 25,
    INDEX_OPT_SRPPASSWD            = 26,
    INDEX_OPT_SRPPASSWDCONF        = 27,
    INDEX_OPT_PSKPASSWD            = 28,
    INDEX_OPT_PSKHINT              = 29,
    INDEX_OPT_PORT                 = 30,
    INDEX_OPT_LIST                 = 31,
    INDEX_OPT_VERSION              = 32,
    INDEX_OPT_HELP                 = 33,
    INDEX_OPT_MORE_HELP            = 34
} teOptIndex;

#define OPTION_CT    35
#define GNUTLS_SERV_VERSION       "@VERSION@"
#define GNUTLS_SERV_FULL_VERSION  "gnutls-serv @VERSION@"

/*
 *  Interface defines for all options.  Replace "n" with the UPPER_CASED
 *  option name (as in the teOptIndex enumeration above).
 *  e.g. HAVE_OPT(DEBUG)
 */
#define         DESC(n) (gnutls_servOptions.pOptDesc[INDEX_OPT_## n])
#define     HAVE_OPT(n) (! UNUSED_OPT(& DESC(n)))
#define      OPT_ARG(n) (DESC(n).optArg.argString)
#define    STATE_OPT(n) (DESC(n).fOptState & OPTST_SET_MASK)
#define    COUNT_OPT(n) (DESC(n).optOccCt)
#define    ISSEL_OPT(n) (SELECTED_OPT(&DESC(n)))
#define ISUNUSED_OPT(n) (UNUSED_OPT(& DESC(n)))
#define  ENABLED_OPT(n) (! DISABLED_OPT(& DESC(n)))
#define  STACKCT_OPT(n) (((tArgList*)(DESC(n).optCookie))->useCt)
#define STACKLST_OPT(n) (((tArgList*)(DESC(n).optCookie))->apzArgs)
#define    CLEAR_OPT(n) STMTS( \
                DESC(n).fOptState &= OPTST_PERSISTENT_MASK;   \
                if ((DESC(n).fOptState & OPTST_INITENABLED) == 0) \
                    DESC(n).fOptState |= OPTST_DISABLED; \
                DESC(n).optCookie = NULL )

/* * * * * *
 *
 *  Enumeration of gnutls-serv exit codes
 */
typedef enum {
    GNUTLS_SERV_EXIT_SUCCESS = 0,
    GNUTLS_SERV_EXIT_FAILURE = 1,
    GNUTLS_SERV_EXIT_LIBOPTS_FAILURE = 70
} gnutls_serv_exit_code_t;
/* * * * * *
 *
 *  Interface defines for specific options.
 */
#define VALUE_OPT_DEBUG          'd'

#define OPT_VALUE_DEBUG          (DESC(DEBUG).optArg.argInt)
#define VALUE_OPT_NOTICKET       1
#define VALUE_OPT_GENERATE       'g'
#define VALUE_OPT_QUIET          'q'
#define VALUE_OPT_NODB           4
#define VALUE_OPT_HTTP           5
#define VALUE_OPT_ECHO           6
#define VALUE_OPT_UDP            'u'
#define VALUE_OPT_MTU            8

#define OPT_VALUE_MTU            (DESC(MTU).optArg.argInt)
#define VALUE_OPT_DISABLE_CLIENT_CERT 'a'
#define VALUE_OPT_REQUIRE_CLIENT_CERT 'r'
#define VALUE_OPT_X509FMTDER     11
#define VALUE_OPT_PRIORITY       12
#define VALUE_OPT_DHPARAMS       13
#define VALUE_OPT_X509CAFILE     14
#define VALUE_OPT_X509CRLFILE    15
#define VALUE_OPT_PGPKEYFILE     16
#define VALUE_OPT_PGPKEYRING     17
#define VALUE_OPT_PGPCERTFILE    18
#define VALUE_OPT_X509KEYFILE    19
#define VALUE_OPT_X509CERTFILE   20
#define VALUE_OPT_X509DSAKEYFILE 21
#define VALUE_OPT_X509DSACERTFILE 22
#define VALUE_OPT_X509ECCKEYFILE 23
#define VALUE_OPT_X509ECCCERTFILE 24
#define VALUE_OPT_PGPSUBKEY      25
#define VALUE_OPT_SRPPASSWD      26
#define VALUE_OPT_SRPPASSWDCONF  27
#define VALUE_OPT_PSKPASSWD      28
#define VALUE_OPT_PSKHINT        29
#define VALUE_OPT_PORT           'p'

#define OPT_VALUE_PORT           (DESC(PORT).optArg.argInt)
#define VALUE_OPT_LIST           'l'
#define VALUE_OPT_HELP          'h'
#define VALUE_OPT_MORE_HELP     '!'
#define VALUE_OPT_VERSION       'v'
/*
 *  Interface defines not associated with particular options
 */
#define ERRSKIP_OPTERR  STMTS(gnutls_servOptions.fOptSet &= ~OPTPROC_ERRSTOP)
#define ERRSTOP_OPTERR  STMTS(gnutls_servOptions.fOptSet |= OPTPROC_ERRSTOP)
#define RESTART_OPT(n)  STMTS( \
                gnutls_servOptions.curOptIdx = (n); \
                gnutls_servOptions.pzCurOpt  = NULL)
#define START_OPT       RESTART_OPT(1)
#define USAGE(c)        (*gnutls_servOptions.pUsageProc)(&gnutls_servOptions, c)
/* extracted from opthead.tlib near line 484 */

#ifdef  __cplusplus
extern "C" {
#endif
/*
 *  global exported definitions
 */
#include <gettext.h>


/* * * * * *
 *
 *  Declare the gnutls-serv option descriptor.
 */
extern tOptions gnutls_servOptions;

#if defined(ENABLE_NLS)
# ifndef _
#   include <stdio.h>
static inline char* aoGetsText(char const* pz) {
    if (pz == NULL) return NULL;
    return (char*)gettext(pz);
}
#   define _(s)  aoGetsText(s)
# endif /* _() */

# define OPT_NO_XLAT_CFG_NAMES  STMTS(gnutls_servOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT_CFG;)
# define OPT_NO_XLAT_OPT_NAMES  STMTS(gnutls_servOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG;)

# define OPT_XLAT_CFG_NAMES     STMTS(gnutls_servOptions.fOptSet &= \
                                  ~(OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG);)
# define OPT_XLAT_OPT_NAMES     STMTS(gnutls_servOptions.fOptSet &= \
                                  ~OPTPROC_NXLAT_OPT;)

#else   /* ENABLE_NLS */
# define OPT_NO_XLAT_CFG_NAMES
# define OPT_NO_XLAT_OPT_NAMES

# define OPT_XLAT_CFG_NAMES
# define OPT_XLAT_OPT_NAMES

# ifndef _
#   define _(_s)  _s
# endif
#endif  /* ENABLE_NLS */

#ifdef  __cplusplus
}
#endif
#endif /* AUTOOPTS_SERV_ARGS_H_GUARD */
/* serv-args.h ends here */
