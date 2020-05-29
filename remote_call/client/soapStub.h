/* soapStub.h
   Generated by gSOAP 2.8.102 for calc.h

gSOAP XML Web services tools
Copyright (C) 2000-2020, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#define SOAP_NAMESPACE_OF_ns2	"urn:calc"

#ifndef soapStub_H
#define soapStub_H
#include "stdsoap2.h"
#if GSOAP_VERSION != 208102
# error "GSOAP VERSION 208102 MISMATCH IN GENERATED CODE VERSUS LIBRARY CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Structs and Unions                                                         *
 *                                                                            *
\******************************************************************************/

struct ns2__addResponse;	/* calc.h:299 */
struct ns2__add;	/* calc.h:299 */
struct ns2__subResponse;	/* calc.h:358 */
struct ns2__sub;	/* calc.h:358 */
struct ns2__mulResponse;	/* calc.h:417 */
struct ns2__mul;	/* calc.h:417 */
struct ns2__divResponse;	/* calc.h:476 */
struct ns2__div;	/* calc.h:476 */
struct ns2__powResponse;	/* calc.h:535 */
struct ns2__pow;	/* calc.h:535 */

/* calc.h:299 */
#ifndef SOAP_TYPE_ns2__addResponse
#define SOAP_TYPE_ns2__addResponse (10)
/* complex XML schema type 'ns2:addResponse': */
struct ns2__addResponse {
        /** Optional element 'result' of XML schema type 'xsd:double' */
        double *result;
};
#endif

/* calc.h:299 */
#ifndef SOAP_TYPE_ns2__add
#define SOAP_TYPE_ns2__add (11)
/* complex XML schema type 'ns2:add': */
struct ns2__add {
        /** Required element 'a' of XML schema type 'xsd:double' */
        double a;
        /** Required element 'b' of XML schema type 'xsd:double' */
        double b;
};
#endif

/* calc.h:358 */
#ifndef SOAP_TYPE_ns2__subResponse
#define SOAP_TYPE_ns2__subResponse (13)
/* complex XML schema type 'ns2:subResponse': */
struct ns2__subResponse {
        /** Optional element 'result' of XML schema type 'xsd:double' */
        double *result;
};
#endif

/* calc.h:358 */
#ifndef SOAP_TYPE_ns2__sub
#define SOAP_TYPE_ns2__sub (14)
/* complex XML schema type 'ns2:sub': */
struct ns2__sub {
        /** Required element 'a' of XML schema type 'xsd:double' */
        double a;
        /** Required element 'b' of XML schema type 'xsd:double' */
        double b;
};
#endif

/* calc.h:417 */
#ifndef SOAP_TYPE_ns2__mulResponse
#define SOAP_TYPE_ns2__mulResponse (16)
/* complex XML schema type 'ns2:mulResponse': */
struct ns2__mulResponse {
        /** Optional element 'result' of XML schema type 'xsd:double' */
        double *result;
};
#endif

/* calc.h:417 */
#ifndef SOAP_TYPE_ns2__mul
#define SOAP_TYPE_ns2__mul (17)
/* complex XML schema type 'ns2:mul': */
struct ns2__mul {
        /** Required element 'a' of XML schema type 'xsd:double' */
        double a;
        /** Required element 'b' of XML schema type 'xsd:double' */
        double b;
};
#endif

/* calc.h:476 */
#ifndef SOAP_TYPE_ns2__divResponse
#define SOAP_TYPE_ns2__divResponse (19)
/* complex XML schema type 'ns2:divResponse': */
struct ns2__divResponse {
        /** Optional element 'result' of XML schema type 'xsd:double' */
        double *result;
};
#endif

/* calc.h:476 */
#ifndef SOAP_TYPE_ns2__div
#define SOAP_TYPE_ns2__div (20)
/* complex XML schema type 'ns2:div': */
struct ns2__div {
        /** Required element 'a' of XML schema type 'xsd:double' */
        double a;
        /** Required element 'b' of XML schema type 'xsd:double' */
        double b;
};
#endif

/* calc.h:535 */
#ifndef SOAP_TYPE_ns2__powResponse
#define SOAP_TYPE_ns2__powResponse (22)
/* complex XML schema type 'ns2:powResponse': */
struct ns2__powResponse {
        /** Optional element 'result' of XML schema type 'xsd:double' */
        double *result;
};
#endif

/* calc.h:535 */
#ifndef SOAP_TYPE_ns2__pow
#define SOAP_TYPE_ns2__pow (23)
/* complex XML schema type 'ns2:pow': */
struct ns2__pow {
        /** Required element 'a' of XML schema type 'xsd:double' */
        double a;
        /** Required element 'b' of XML schema type 'xsd:double' */
        double b;
};
#endif

/* calc.h:596 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (24)
/* SOAP_ENV__Header: */
struct SOAP_ENV__Header {
#ifdef WITH_NOEMPTYSTRUCT
	char dummy;	/* empty struct is a GNU extension */
#endif
};
#endif
#endif

/* calc.h:596 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (25)
/* Type SOAP_ENV__Code is a recursive data type, (in)directly referencing itself through its (base or derived class) members */
/* SOAP_ENV__Code: */
struct SOAP_ENV__Code {
        /** Optional element 'SOAP-ENV:Value' of XML schema type 'xsd:QName' */
        char *SOAP_ENV__Value;
        /** Optional element 'SOAP-ENV:Subcode' of XML schema type 'SOAP-ENV:Code' */
        struct SOAP_ENV__Code *SOAP_ENV__Subcode;
};
#endif
#endif

/* calc.h:596 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (27)
/* SOAP_ENV__Detail: */
struct SOAP_ENV__Detail {
        char *__any;
        /** Any type of element 'fault' assigned to fault with its SOAP_TYPE_<typename> assigned to __type */
        /** Do not create a cyclic data structure through this member unless SOAP encoding or SOAP_XML_GRAPH are used for id-ref serialization */
        int __type;
        void *fault;
};
#endif
#endif

/* calc.h:596 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (30)
/* SOAP_ENV__Reason: */
struct SOAP_ENV__Reason {
        /** Optional element 'SOAP-ENV:Text' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Text;
};
#endif
#endif

/* calc.h:596 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (31)
/* SOAP_ENV__Fault: */
struct SOAP_ENV__Fault {
        /** Optional element 'faultcode' of XML schema type 'xsd:QName' */
        char *faultcode;
        /** Optional element 'faultstring' of XML schema type 'xsd:string' */
        char *faultstring;
        /** Optional element 'faultactor' of XML schema type 'xsd:string' */
        char *faultactor;
        /** Optional element 'detail' of XML schema type 'SOAP-ENV:Detail' */
        struct SOAP_ENV__Detail *detail;
        /** Optional element 'SOAP-ENV:Code' of XML schema type 'SOAP-ENV:Code' */
        struct SOAP_ENV__Code *SOAP_ENV__Code;
        /** Optional element 'SOAP-ENV:Reason' of XML schema type 'SOAP-ENV:Reason' */
        struct SOAP_ENV__Reason *SOAP_ENV__Reason;
        /** Optional element 'SOAP-ENV:Node' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Node;
        /** Optional element 'SOAP-ENV:Role' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Role;
        /** Optional element 'SOAP-ENV:Detail' of XML schema type 'SOAP-ENV:Detail' */
        struct SOAP_ENV__Detail *SOAP_ENV__Detail;
};
#endif
#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/


/* (built-in):0 */
#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (5)
typedef char *_XML;
#endif

/* (built-in):0 */
#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (6)
typedef char *_QName;
#endif

/******************************************************************************\
 *                                                                            *
 * Serializable Types                                                         *
 *                                                                            *
\******************************************************************************/


/* char has binding name 'byte' for type 'xsd:byte' */
#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (3)
#endif

/* int has binding name 'int' for type 'xsd:int' */
#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif

/* double has binding name 'double' for type 'xsd:double' */
#ifndef SOAP_TYPE_double
#define SOAP_TYPE_double (7)
#endif

/* struct SOAP_ENV__Fault has binding name 'SOAP_ENV__Fault' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (31)
#endif

/* struct SOAP_ENV__Reason has binding name 'SOAP_ENV__Reason' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (30)
#endif

/* struct SOAP_ENV__Detail has binding name 'SOAP_ENV__Detail' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (27)
#endif

/* struct SOAP_ENV__Code has binding name 'SOAP_ENV__Code' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (25)
#endif

/* struct SOAP_ENV__Header has binding name 'SOAP_ENV__Header' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (24)
#endif

/* struct ns2__pow has binding name 'ns2__pow' for type 'ns2:pow' */
#ifndef SOAP_TYPE_ns2__pow
#define SOAP_TYPE_ns2__pow (23)
#endif

/* struct ns2__powResponse has binding name 'ns2__powResponse' for type 'ns2:powResponse' */
#ifndef SOAP_TYPE_ns2__powResponse
#define SOAP_TYPE_ns2__powResponse (22)
#endif

/* struct ns2__div has binding name 'ns2__div' for type 'ns2:div' */
#ifndef SOAP_TYPE_ns2__div
#define SOAP_TYPE_ns2__div (20)
#endif

/* struct ns2__divResponse has binding name 'ns2__divResponse' for type 'ns2:divResponse' */
#ifndef SOAP_TYPE_ns2__divResponse
#define SOAP_TYPE_ns2__divResponse (19)
#endif

/* struct ns2__mul has binding name 'ns2__mul' for type 'ns2:mul' */
#ifndef SOAP_TYPE_ns2__mul
#define SOAP_TYPE_ns2__mul (17)
#endif

/* struct ns2__mulResponse has binding name 'ns2__mulResponse' for type 'ns2:mulResponse' */
#ifndef SOAP_TYPE_ns2__mulResponse
#define SOAP_TYPE_ns2__mulResponse (16)
#endif

/* struct ns2__sub has binding name 'ns2__sub' for type 'ns2:sub' */
#ifndef SOAP_TYPE_ns2__sub
#define SOAP_TYPE_ns2__sub (14)
#endif

/* struct ns2__subResponse has binding name 'ns2__subResponse' for type 'ns2:subResponse' */
#ifndef SOAP_TYPE_ns2__subResponse
#define SOAP_TYPE_ns2__subResponse (13)
#endif

/* struct ns2__add has binding name 'ns2__add' for type 'ns2:add' */
#ifndef SOAP_TYPE_ns2__add
#define SOAP_TYPE_ns2__add (11)
#endif

/* struct ns2__addResponse has binding name 'ns2__addResponse' for type 'ns2:addResponse' */
#ifndef SOAP_TYPE_ns2__addResponse
#define SOAP_TYPE_ns2__addResponse (10)
#endif

/* struct SOAP_ENV__Reason * has binding name 'PointerToSOAP_ENV__Reason' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (33)
#endif

/* struct SOAP_ENV__Detail * has binding name 'PointerToSOAP_ENV__Detail' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (32)
#endif

/* struct SOAP_ENV__Code * has binding name 'PointerToSOAP_ENV__Code' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (26)
#endif

/* double * has binding name 'PointerTodouble' for type 'xsd:double' */
#ifndef SOAP_TYPE_PointerTodouble
#define SOAP_TYPE_PointerTodouble (8)
#endif

/* _QName has binding name '_QName' for type 'xsd:QName' */
#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (6)
#endif

/* _XML has binding name '_XML' for type '' */
#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (5)
#endif

/* char * has binding name 'string' for type 'xsd:string' */
#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (4)
#endif

/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Client-Side Call Stub Functions                                            *
 *                                                                            *
\******************************************************************************/

    
    /** Web service synchronous operation 'soap_call_ns2__add' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__add(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);
    /** Web service asynchronous operation 'soap_send_ns2__add' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_send_ns2__add(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b);
    /** Web service asynchronous operation 'soap_recv_ns2__add' to receive a response message from the connected endpoint, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_recv_ns2__add(struct soap *soap, double *result);
    
    /** Web service synchronous operation 'soap_call_ns2__sub' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__sub(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);
    /** Web service asynchronous operation 'soap_send_ns2__sub' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_send_ns2__sub(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b);
    /** Web service asynchronous operation 'soap_recv_ns2__sub' to receive a response message from the connected endpoint, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_recv_ns2__sub(struct soap *soap, double *result);
    
    /** Web service synchronous operation 'soap_call_ns2__mul' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__mul(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);
    /** Web service asynchronous operation 'soap_send_ns2__mul' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_send_ns2__mul(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b);
    /** Web service asynchronous operation 'soap_recv_ns2__mul' to receive a response message from the connected endpoint, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_recv_ns2__mul(struct soap *soap, double *result);
    
    /** Web service synchronous operation 'soap_call_ns2__div' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__div(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);
    /** Web service asynchronous operation 'soap_send_ns2__div' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_send_ns2__div(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b);
    /** Web service asynchronous operation 'soap_recv_ns2__div' to receive a response message from the connected endpoint, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_recv_ns2__div(struct soap *soap, double *result);
    
    /** Web service synchronous operation 'soap_call_ns2__pow' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__pow(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);
    /** Web service asynchronous operation 'soap_send_ns2__pow' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_send_ns2__pow(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b);
    /** Web service asynchronous operation 'soap_recv_ns2__pow' to receive a response message from the connected endpoint, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_recv_ns2__pow(struct soap *soap, double *result);

#endif

/* End of soapStub.h */
