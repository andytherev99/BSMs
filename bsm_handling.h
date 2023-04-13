#include "saecasn.h"
#include "saecasn_def.h"
#include "ext.h"
 
void BSMRxExtCallback(tExtEventId Event,
                      tExtMessage *pData,
                      void *pPriv)
{
  (void)pPriv; // My private data
 
  switch (Event)
  {
    case QSMSG_EXT_RX_SAECFL_PDU:
    {
      // Check pType
      if (pData->pType == asn1_type_SAECBasicSafetyMessage)
      {
        SAECBasicSafetyMessage *pBSM = pData->pSAECBSM;
 
        // Parse some data
        printf("Message Count is %zu\n", pBSM->msgCnt);
 
        // Send BSM to handling application
      }
    }
 
    default:
      // Other events
      break;
  }
}