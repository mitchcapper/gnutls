/*
 * Copyright (C) 2015-2017 Red Hat, Inc.
 *
 * Author: Nikos Mavrogiannopoulos
 *
 * This file is part of GnuTLS.
 *
 * GnuTLS is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * GnuTLS is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/* This program tests the various certificate key exchange methods supported
 * in gnutls */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <gnutls/gnutls.h>
#include "utils.h"
#include "common-cert-key-exchange.h"
#include "cert-common.h"

void doit(void)
{
	global_init();

	try("TLS 1.3 with ffdhe2048 rsa no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-FFDHE2048", GNUTLS_KX_DHE_RSA, GNUTLS_SIGN_RSA_PSS_SHA256, GNUTLS_SIGN_UNKNOWN);
	try("TLS 1.3 with ffdhe3072 rsa no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-FFDHE3072", GNUTLS_KX_DHE_RSA, GNUTLS_SIGN_RSA_PSS_SHA256, GNUTLS_SIGN_UNKNOWN);
	try("TLS 1.3 with ffdhe4096 rsa no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-FFDHE4096", GNUTLS_KX_DHE_RSA, GNUTLS_SIGN_RSA_PSS_SHA256, GNUTLS_SIGN_UNKNOWN);
	try("TLS 1.3 with secp256r1 rsa no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-SECP256R1", GNUTLS_KX_ECDHE_RSA, GNUTLS_SIGN_RSA_PSS_SHA256, GNUTLS_SIGN_UNKNOWN);
	try("TLS 1.3 with secp384r1 rsa no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-SECP384R1", GNUTLS_KX_ECDHE_RSA, GNUTLS_SIGN_RSA_PSS_SHA256, GNUTLS_SIGN_UNKNOWN);
	try("TLS 1.3 with secp521r1 rsa no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-SECP521R1", GNUTLS_KX_ECDHE_RSA, GNUTLS_SIGN_RSA_PSS_SHA256, GNUTLS_SIGN_UNKNOWN);
	try("TLS 1.3 with x25519 rsa no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-X25519", GNUTLS_KX_ECDHE_RSA, GNUTLS_SIGN_RSA_PSS_SHA256, GNUTLS_SIGN_UNKNOWN);

	try_with_key("TLS 1.3 with secp256r1 ecdsa no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-SECP256R1", GNUTLS_KX_ECDHE_RSA, GNUTLS_SIGN_ECDSA_SECP256R1_SHA256, GNUTLS_SIGN_UNKNOWN,
		&server_ca3_localhost_ecc_cert, &server_ca3_ecc_key, NULL, NULL, 0);

	/* Test RSA-PSS cert/key combo issues */
	try_with_key("TLS 1.3 with x25519 with rsa-pss-sha256 key no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-X25519", GNUTLS_KX_ECDHE_RSA, GNUTLS_SIGN_RSA_PSS_SHA256, GNUTLS_SIGN_UNKNOWN,
		&server_ca3_rsa_pss2_cert, &server_ca3_rsa_pss2_key, NULL, NULL, 0);
	try_with_key("TLS 1.3 with x25519 with rsa-pss-sha256 key and 1 sig no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-X25519:-SIGN-ALL:+SIGN-RSA-PSS-SHA256", GNUTLS_KX_ECDHE_RSA, GNUTLS_SIGN_RSA_PSS_SHA256, GNUTLS_SIGN_UNKNOWN,
		&server_ca3_rsa_pss2_cert, &server_ca3_rsa_pss2_key, NULL, NULL, 0);
	try_with_key("TLS 1.3 with x25519 with rsa-pss-sha256 key and rsa-pss-sha384 first sig no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-X25519:-SIGN-ALL:+SIGN-RSA-PSS-SHA384:+SIGN-RSA-PSS-SHA256", GNUTLS_KX_ECDHE_RSA, GNUTLS_SIGN_RSA_PSS_SHA256, GNUTLS_SIGN_UNKNOWN,
		&server_ca3_rsa_pss2_cert, &server_ca3_rsa_pss2_key, NULL, NULL, 0);
	try_with_key("TLS 1.3 with x25519 with rsa-pss-sha256 key and rsa-pss-sha512 first sig no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-X25519:-SIGN-ALL:+SIGN-RSA-PSS-SHA512:+SIGN-RSA-PSS-SHA384:+SIGN-RSA-PSS-SHA256", GNUTLS_KX_ECDHE_RSA, GNUTLS_SIGN_RSA_PSS_SHA256, GNUTLS_SIGN_UNKNOWN,
		&server_ca3_rsa_pss2_cert, &server_ca3_rsa_pss2_key, NULL, NULL, 0);

	try_with_key("TLS 1.3 with x25519 rsa-pss/rsa-pss no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-GROUP-ALL:+GROUP-X25519:-SIGN-ALL:+SIGN-RSA-PSS-SHA256", GNUTLS_KX_ECDHE_RSA, GNUTLS_SIGN_RSA_PSS_SHA256, GNUTLS_SIGN_UNKNOWN,
		&server_ca3_rsa_pss_cert, &server_ca3_rsa_pss_key, NULL, NULL, 0);
	try_with_key("TLS 1.3 with x25519 ed25519 no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:-KX-ALL:+ECDHE-ECDSA:-CURVE-ALL:+CURVE-X25519:-SIGN-ALL:+SIGN-EDDSA-ED25519", GNUTLS_KX_ECDHE_RSA, GNUTLS_SIGN_EDDSA_ED25519, GNUTLS_SIGN_UNKNOWN,
		&server_ca3_eddsa_cert, &server_ca3_eddsa_key, NULL, NULL, 0);

	server_priority = "NORMAL:+ANON-ECDH:+ANON-DH:+ECDHE-RSA:+DHE-RSA:+RSA:+ECDHE-ECDSA:+CURVE-X25519:+SIGN-EDDSA-ED25519",

	try_with_key("TLS 1.2 fallback with x25519 ed25519 no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:+VERS-TLS1.2:-KX-ALL:+ECDHE-ECDSA:-CURVE-ALL:+CURVE-X25519:-SIGN-ALL:+SIGN-EDDSA-ED25519", GNUTLS_KX_ECDHE_ECDSA, GNUTLS_SIGN_EDDSA_ED25519, GNUTLS_SIGN_UNKNOWN,
		&server_ca3_eddsa_cert, &server_ca3_eddsa_key, NULL, NULL, 0);
	try("TLS 1.2 fallback with secp521r1 rsa no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:+VERS-TLS1.2:-GROUP-ALL:+GROUP-SECP521R1", GNUTLS_KX_ECDHE_RSA, GNUTLS_SIGN_RSA_SHA256, GNUTLS_SIGN_UNKNOWN);
	try("TLS 1.2 fallback with ffdhe2048 rsa no-cli-cert", "NORMAL:-VERS-ALL:+VERS-TLS1.3:+VERS-TLS1.2:-KX-ALL:+DHE-RSA:-GROUP-ALL:+GROUP-FFDHE2048", GNUTLS_KX_DHE_RSA, GNUTLS_SIGN_RSA_SHA256, GNUTLS_SIGN_UNKNOWN);

	gnutls_global_deinit();
}
