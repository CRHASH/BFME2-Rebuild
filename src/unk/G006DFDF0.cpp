#include "Apt/AptMath.h"
#include "Apt/Assert.h"
// Generated from the ledger; map snapshot c591f7146f88c8a8248ebb8ae22f0c978c22aed463db64e05ef57ff0dfae99cc
// object=G006DFDF0 name-evidence=invented
// Extents and edges are hypotheses; byte verification alone does not establish original TU boundaries.
// FUNCTION: BFME2 0x006DFDF0 size=82 name=?ClipStackPush@AptMath@@SAPAUClipTransform_t@1@XZ evidence=N:ledger tier=B hypothesis:mm1-gap-unit
AptMath::ClipTransform_t *AptMath::ClipStackPush()
{
    if (!((m_nStackCount + 1) < m_nStackCapacity)) {
        g_bfmeAptAssertAtE17734("(m_nStackCount+1) < m_nStackCapacity", "..\\..\\include\\apt\\AptStd/AptMath.h", 0x56);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    m_nStackCount++;
    return m_pClipStack + m_nStackCount;
}

// FUNCTION: BFME2 0x006DFE50 size=68 name=?ClipStackTop@AptMath@@SAPAUClipTransform_t@1@XZ evidence=N:ledger tier=B hypothesis:mm1-gap-unit
AptMath::ClipTransform_t *AptMath::ClipStackTop()
{
    if (!(m_nStackCount < m_nStackCapacity)) {
        g_bfmeAptAssertAtE17734("m_nStackCount < m_nStackCapacity", "..\\..\\include\\apt\\AptStd/AptMath.h", 0x60);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    return m_pClipStack + m_nStackCount;
}
