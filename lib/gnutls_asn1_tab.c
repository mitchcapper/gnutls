#if HAVE_CONFIG_H
# include "config.h"
#endif

#include <libtasn1.h>

const asn1_static_node gnutls_asn1_tab[] = {
  { "GNUTLS", 536872976, NULL },
  { NULL, 1073741836, NULL },
  { "RSAPublicKey", 1610612741, NULL },
  { "modulus", 1073741827, NULL },
  { "publicExponent", 3, NULL },
  { "RSAPrivateKey", 1610612741, NULL },
  { "version", 1073741827, NULL },
  { "modulus", 1073741827, NULL },
  { "publicExponent", 1073741827, NULL },
  { "privateExponent", 1073741827, NULL },
  { "prime1", 1073741827, NULL },
  { "prime2", 1073741827, NULL },
  { "exponent1", 1073741827, NULL },
  { "exponent2", 1073741827, NULL },
  { "coefficient", 1073741827, NULL },
  { "otherInfo", 16386, "RSAOtherInfo"},
  { "ProvableSeed", 1610612741, NULL },
  { "algorithm", 1073741836, NULL },
  { "seed", 7, NULL },
  { "RSAOtherInfo", 1610612754, NULL },
  { "otherPrimeInfos", 1073741826, "OtherPrimeInfos"},
  { "seed", 536879106, "ProvableSeed"},
  { NULL, 2056, "1"},
  { "OtherPrimeInfos", 1612709899, NULL },
  { "MAX", 1074266122, "1"},
  { NULL, 2, "OtherPrimeInfo"},
  { "OtherPrimeInfo", 1610612741, NULL },
  { "prime", 1073741827, NULL },
  { "exponent", 1073741827, NULL },
  { "coefficient", 3, NULL },
  { "AlgorithmIdentifier", 1610612741, NULL },
  { "algorithm", 1073741836, NULL },
  { "parameters", 541081613, NULL },
  { "algorithm", 1, NULL },
  { "DigestInfo", 1610612741, NULL },
  { "digestAlgorithm", 1073741826, "DigestAlgorithmIdentifier"},
  { "digest", 7, NULL },
  { "DigestAlgorithmIdentifier", 1073741826, "AlgorithmIdentifier"},
  { "DSAPublicKey", 1073741827, NULL },
  { "DSAParameters", 1610612741, NULL },
  { "p", 1073741827, NULL },
  { "q", 1073741827, NULL },
  { "g", 3, NULL },
  { "DSASignatureValue", 1610612741, NULL },
  { "r", 1073741827, NULL },
  { "s", 3, NULL },
  { "DSAPrivateKey", 1610612741, NULL },
  { "version", 1073741827, NULL },
  { "p", 1073741827, NULL },
  { "q", 1073741827, NULL },
  { "g", 1073741827, NULL },
  { "Y", 1073741827, NULL },
  { "priv", 1073741827, NULL },
  { "seed", 536895490, "ProvableSeed"},
  { NULL, 2056, "1"},
  { "DHParameter", 1610612741, NULL },
  { "prime", 1073741827, NULL },
  { "base", 1073741827, NULL },
  { "privateValueLength", 16387, NULL },
  { "ECParameters", 1610612754, NULL },
  { "namedCurve", 12, NULL },
  { "ECPrivateKey", 1610612741, NULL },
  { "Version", 1073741827, NULL },
  { "privateKey", 1073741831, NULL },
  { "parameters", 1610637314, "ECParameters"},
  { NULL, 2056, "0"},
  { "publicKey", 536895494, NULL },
  { NULL, 2056, "1"},
  { "PrincipalName", 1610612741, NULL },
  { "name-type", 1610620931, NULL },
  { NULL, 2056, "0"},
  { "name-string", 536879115, NULL },
  { NULL, 1073743880, "1"},
  { NULL, 27, NULL },
  { "KRB5PrincipalName", 536870917, NULL },
  { "realm", 1610620955, NULL },
  { NULL, 2056, "0"},
  { "principalName", 536879106, "PrincipalName"},
  { NULL, 2056, "1"},
  { NULL, 0, NULL }
};
