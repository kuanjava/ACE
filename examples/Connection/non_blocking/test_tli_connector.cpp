// ACE_TLI Client.
// $Id$


#include "ace/TLI_Connector.h"
#include "ace/INET_Addr.h"
#include "CPP-connector.h"

#if defined (ACE_HAS_TLI)

typedef Peer_Handler<ACE_TLI_STREAM> PEER_HANDLER;
typedef IPC_Client<PEER_HANDLER, ACE_TLI_CONNECTOR> IPC_CLIENT;

int
main (int argc, char *argv[])
{
  // Perform Service_Config initializations
  ACE_Service_Config daemon (argv[0]);

  IPC_CLIENT peer_connector;

  if (peer_connector.init (argc, argv) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "init"), -1);

  return peer_connector.svc ();
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Connector<PEER_HANDLER, ACE_TLI_CONNECTOR>;
template class ACE_Svc_Handler<ACE_TLI_STREAM, ACE_SYNCH>;
template class ACE_Svc_Tuple<PEER_HANDLER>;
template class ACE_Map_Entry<ACE_HANDLE, ACE_Svc_Tuple<PEER_HANDLER> *>;
template class ACE_Map_Iterator<ACE_HANDLE, ACE_Svc_Tuple<PEER_HANDLER> *, ACE_SYNCH_RW_MUTEX>;
template class ACE_Map_Manager<ACE_HANDLE, ACE_Svc_Tuple<PEER_HANDLER> *, ACE_SYNCH_RW_MUTEX>;
template class IPC_Client<PEER_HANDLER, ACE_TLI_CONNECTOR>;
template class Peer_Handler<ACE_TLI_STREAM>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Connector<PEER_HANDLER, ACE_TLI_CONNECTOR>
#pragma instantiate ACE_Svc_Handler<ACE_TLI_STREAM, ACE_SYNCH>
#pragma instantiate ACE_Svc_Tuple<PEER_HANDLER>
#pragma instantiate ACE_Map_Entry<ACE_HANDLE, ACE_Svc_Tuple<PEER_HANDLER> *>
#pragma instantiate ACE_Map_Iterator<ACE_HANDLE, ACE_Svc_Tuple<PEER_HANDLER> *, ACE_SYNCH_RW_MUTEX>
#pragma instantiate ACE_Map_Manager<ACE_HANDLE, ACE_Svc_Tuple<PEER_HANDLER> *, ACE_SYNCH_RW_MUTEX>
#pragma instantiate IPC_Client<PEER_HANDLER, ACE_TLI_CONNECTOR>
#pragma instantiate Peer_Handler<ACE_TLI_STREAM>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */


#else
int
main (void)
{
  ACE_ERROR_RETURN ((LM_ERROR, "your platform does not support TLI\n"), 1);
}
#endif /* ACE_HAS_TLI */
