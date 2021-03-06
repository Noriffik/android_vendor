/*
 * SUPL_ULP_UlpMessage.h
 *
 * Copyright (C) ST-Ericsson SA 2010. All rights reserved.
 * Author: david.gowers@stericsson.com for ST-Ericsson.
 * License terms: Redistribution and modifications are permitted subject to BSD license. 
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of ST-Ericsson nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ST-ERICSSON BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP"
 *     found in "ULP_v2.0.0.asn"
 *     `asn1c -gen-PER -fcompound-names`
 */

#ifndef    _SUPL_ULP_UlpMessage_H_
#define    _SUPL_ULP_UlpMessage_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SUPL_ULP_SUPLINIT.h"
#include "SUPL_ULP_SUPLSTART.h"
#include "SUPL_ULP_SUPLRESPONSE.h"
#include "SUPL_ULP_SUPLPOSINIT.h"
#include "SUPL_ULP_SUPLPOS.h"
#include "SUPL_ULP_SUPLEND.h"
#include "SUPL_ULP_SUPLAUTHREQ.h"
#include "SUPL_ULP_SUPLAUTHRESP.h"
#include "SUPL_ULP_Ver2-SUPLTRIGGEREDSTART.h"
#include "SUPL_ULP_Ver2-SUPLTRIGGEREDRESPONSE.h"
#include "SUPL_ULP_Ver2-SUPLTRIGGEREDSTOP.h"
#include "SUPL_ULP_Ver2-SUPLNOTIFY.h"
#include "SUPL_ULP_Ver2-SUPLNOTIFYRESPONSE.h"
#include "SUPL_ULP_Ver2-SUPLSETINIT.h"
#include "SUPL_ULP_Ver2-SUPLREPORT.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum UlpMessage_PR {
    UlpMessage_PR_NOTHING,    /* No components present */
    UlpMessage_PR_msSUPLINIT,
    UlpMessage_PR_msSUPLSTART,
    UlpMessage_PR_msSUPLRESPONSE,
    UlpMessage_PR_msSUPLPOSINIT,
    UlpMessage_PR_msSUPLPOS,
    UlpMessage_PR_msSUPLEND,
    UlpMessage_PR_msSUPLAUTHREQ,
    UlpMessage_PR_msSUPLAUTHRESP,
    /* Extensions may appear below */
    UlpMessage_PR_msSUPLTRIGGEREDSTART,
    UlpMessage_PR_msSUPLTRIGGEREDRESPONSE,
    UlpMessage_PR_msSUPLTRIGGEREDSTOP,
    UlpMessage_PR_msSUPLNOTIFY,
    UlpMessage_PR_msSUPLNOTIFYRESPONSE,
    UlpMessage_PR_msSUPLSETINIT,
    UlpMessage_PR_msSUPLREPORT
} UlpMessage_PR;

/* SUPL_ULP_UlpMessage */
typedef struct UlpMessage {
    UlpMessage_PR present;
    union UlpMessage_u {
        SUPLINIT_t     msSUPLINIT;
        SUPLSTART_t     msSUPLSTART;
        SUPLRESPONSE_t     msSUPLRESPONSE;
        SUPLPOSINIT_t     msSUPLPOSINIT;
        SUPLPOS_t     msSUPLPOS;
        SUPLEND_t     msSUPLEND;
        SUPLAUTHREQ_t     msSUPLAUTHREQ;
        SUPLAUTHRESP_t     msSUPLAUTHRESP;
        /*
         * This type is extensible,
         * possible extensions are below.
         */
        Ver2_SUPLTRIGGEREDSTART_t     msSUPLTRIGGEREDSTART;
        Ver2_SUPLTRIGGEREDRESPONSE_t     msSUPLTRIGGEREDRESPONSE;
        Ver2_SUPLTRIGGEREDSTOP_t     msSUPLTRIGGEREDSTOP;
        Ver2_SUPLNOTIFY_t     msSUPLNOTIFY;
        Ver2_SUPLNOTIFYRESPONSE_t     msSUPLNOTIFYRESPONSE;
        Ver2_SUPLSETINIT_t     msSUPLSETINIT;
        Ver2_SUPLREPORT_t     msSUPLREPORT;
    } choice;
    
    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} UlpMessage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UlpMessage;

#ifdef __cplusplus
}
#endif

#endif    /* _SUPL_ULP_UlpMessage_H_ */
