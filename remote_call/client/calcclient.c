#include "calc.nsmap" // XML namespace mapping table (only needed once at the global level)
#include "soapH.h"    // client stubs, serializers, etc.

int main(int argc, char **argv)
{
  if (argv[2] == NULL) {
    printf("please give the IP address and port.\r\n");
    exit(1);
  }

  char ip_port[64] = {0};
  char *soap_endpoint = ip_port;
  strcpy(ip_port, argv[1]);
  strcat(ip_port, ":");
  strcat(ip_port, argv[2]);
  printf("ip_port: %s\r\n", ip_port);

  struct soap *soap = soap_new(); // allocate and initialize a context
  double sum;
  soap->connect_timeout = 10; // connect within 10s
  soap->send_timeout = 5;     // send timeout is 5s
  soap->recv_timeout = 5;     // receive timeout is 5s
  soap->socket_flags = MSG_NOSIGNAL;
  if (soap_call_ns2__add(soap, ip_port, NULL, 1.23, 4.56, &sum) == SOAP_OK)
    printf("Sum = %g\n", sum);
  else
    soap_print_fault(soap, stderr);
  soap_destroy(soap); // delete managed deserialized C++ instances
  soap_end(soap);     // delete other managed data
  soap_free(soap);    // free the soap struct context data
}