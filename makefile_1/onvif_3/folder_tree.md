#### 工程目录树（文件全部删掉了，结构请参考目录树内容）

```
.
├── Makefile
├── README.md
├── app
│   ├── Makefile
│   └── main.c
├── build
│   ├── out
│   │   └── mod
│   │       ├── cJSON
│   │       │   ├── source
│   │       │   │   ├── cJSON_Utils.d
│   │       │   │   └── cJSON_Utils.o
│   │       │   └── src
│   │       │       ├── cJSON.d
│   │       │       └── cJSON.o
│   │       ├── gsoap
│   │       │   └── src
│   │       │       ├── dom.d
│   │       │       ├── dom.o
│   │       │       ├── httpda.d
│   │       │       ├── httpda.o
│   │       │       ├── mecevp.d
│   │       │       ├── mecevp.o
│   │       │       ├── smdevp.d
│   │       │       ├── smdevp.o
│   │       │       ├── soapC.d
│   │       │       ├── soapC.o
│   │       │       ├── soapServer.d
│   │       │       ├── soapServer.o
│   │       │       ├── stdsoap2.d
│   │       │       ├── stdsoap2.o
│   │       │       ├── struct_timeval.d
│   │       │       ├── struct_timeval.o
│   │       │       ├── threads.d
│   │       │       ├── threads.o
│   │       │       ├── wsaapi.d
│   │       │       ├── wsaapi.o
│   │       │       ├── wsseapi.d
│   │       │       └── wsseapi.o
│   │       └── onvif
│   │           └── src
│   │               ├── authenticate.d
│   │               ├── authenticate.o
│   │               ├── cjson_set.d
│   │               ├── cjson_set.o
│   │               ├── list.d
│   │               ├── list.o
│   │               ├── list_custom.d
│   │               ├── list_custom.o
│   │               ├── onvif_DeviceMgmt.d
│   │               ├── onvif_DeviceMgmt.o
│   │               ├── onvif_Events.d
│   │               ├── onvif_Events.o
│   │               ├── onvif_Media.d
│   │               ├── onvif_Media.o
│   │               ├── onvif_cfg.d
│   │               ├── onvif_cfg.o
│   │               ├── onvif_http.d
│   │               ├── onvif_http.o
│   │               ├── onvif_main.d
│   │               ├── onvif_main.o
│   │               ├── onvif_probe.d
│   │               ├── onvif_probe.o
│   │               ├── onvif_util.d
│   │               ├── onvif_util.o
│   │               ├── soapTester.d
│   │               ├── soapTester.o
│   │               ├── util.d
│   │               └── util.o
│   └── tool
│       └── static_library.mk
├── envset.sh
├── main
└── mod
    ├── Makefile
    ├── cJSON
    │   ├── Makefile
    │   ├── include
    │   │   └── cJSON.h
    │   ├── lib
    │   │   └── libcJSON.a
    │   ├── source
    │   │   ├── cJSON_Utils.c
    │   │   └── cJSON_Utils.h
    │   └── src
    │       └── cJSON.c
    ├── gsoap
    │   ├── Makefile
    │   ├── include
    │   │   ├── dom.h
    │   │   ├── httpda.h
    │   │   ├── mecevp.h
    │   │   ├── smdevp.h
    │   │   ├── soapH.h
    │   │   ├── soapStub.h
    │   │   ├── stdsoap2.h
    │   │   ├── struct_timeval.h
    │   │   ├── threads.h
    │   │   ├── wsaapi.h
    │   │   └── wsseapi.h
    │   ├── lib
    │   │   └── libgsoap.a
    │   └── src
    │       ├── dom.c
    │       ├── httpda.c
    │       ├── mecevp.c
    │       ├── smdevp.c
    │       ├── soapC.c
    │       ├── soapServer.c
    │       ├── stdsoap2.c
    │       ├── struct_timeval.c
    │       ├── threads.c
    │       ├── wsaapi.c
    │       └── wsseapi.c
    ├── onvif
    │   ├── Makefile
    │   ├── include
    │   │   ├── list.h
    │   │   └── onvif.h
    │   ├── lib
    │   │   └── libonvif.a
    │   └── src
    │       ├── authenticate.c
    │       ├── authenticate.h
    │       ├── cjson_set.c
    │       ├── cjson_set.h
    │       ├── debug.h
    │       ├── list.c
    │       ├── list_custom.c
    │       ├── list_custom.h
    │       ├── onvif_DeviceMgmt.c
    │       ├── onvif_Events.c
    │       ├── onvif_Media.c
    │       ├── onvif_cfg.c
    │       ├── onvif_cfg.h
    │       ├── onvif_http.c
    │       ├── onvif_http.h
    │       ├── onvif_main.c
    │       ├── onvif_probe.c
    │       ├── onvif_probe.h
    │       ├── onvif_util.c
    │       ├── onvif_util.h
    │       ├── soapTester.c
    │       ├── sys_inc.h
    │       ├── util.c
    │       └── util.h
    └── openssl
        ├── Makefile
        ├── include
        │   └── openssl
        │       ├── aes.h
        │       ├── asn1.h
        │       ├── asn1_mac.h
        │       ├── asn1t.h
        │       ├── bio.h
        │       ├── blowfish.h
        │       ├── bn.h
        │       ├── buffer.h
        │       ├── camellia.h
        │       ├── cast.h
        │       ├── cms.h
        │       ├── comp.h
        │       ├── conf.h
        │       ├── conf_api.h
        │       ├── crypto.h
        │       ├── des.h
        │       ├── des_old.h
        │       ├── dh.h
        │       ├── dsa.h
        │       ├── dso.h
        │       ├── dtls1.h
        │       ├── e_os2.h
        │       ├── ebcdic.h
        │       ├── ec.h
        │       ├── ecdh.h
        │       ├── ecdsa.h
        │       ├── engine.h
        │       ├── err.h
        │       ├── evp.h
        │       ├── hmac.h
        │       ├── idea.h
        │       ├── krb5_asn.h
        │       ├── kssl.h
        │       ├── lhash.h
        │       ├── md4.h
        │       ├── md5.h
        │       ├── mdc2.h
        │       ├── modes.h
        │       ├── obj_mac.h
        │       ├── objects.h
        │       ├── ocsp.h
        │       ├── opensslconf.h
        │       ├── opensslv.h
        │       ├── ossl_typ.h
        │       ├── pem.h
        │       ├── pem2.h
        │       ├── pkcs12.h
        │       ├── pkcs7.h
        │       ├── pqueue.h
        │       ├── rand.h
        │       ├── rc2.h
        │       ├── rc4.h
        │       ├── ripemd.h
        │       ├── rsa.h
        │       ├── safestack.h
        │       ├── seed.h
        │       ├── sha.h
        │       ├── ssl.h
        │       ├── ssl2.h
        │       ├── ssl23.h
        │       ├── ssl3.h
        │       ├── stack.h
        │       ├── symhacks.h
        │       ├── tls1.h
        │       ├── ts.h
        │       ├── txt_db.h
        │       ├── ui.h
        │       ├── ui_compat.h
        │       ├── whrlpool.h
        │       ├── x509.h
        │       ├── x509_vfy.h
        │       └── x509v3.h
        ├── lib
        │   ├── libcrypto.a
        │   └── libssl.a
        ├── lib_arm_gcc
        │   ├── libcrypto.a
        │   └── libssl.a
        └── lib_gcc
            ├── libcrypto.a
            └── libssl.a
```