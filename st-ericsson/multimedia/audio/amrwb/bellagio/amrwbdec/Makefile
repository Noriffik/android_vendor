################################################################################
#                        (C) ST-Ericsson
#    Reproduction and Communication of this document is strictly prohibited 
#          unless specifically authorized in writing by ST-Ericsson.
################################################################################

include $(MM_MAKEFILES_DIR)/SharedConfig.mk
# We are generating an OMX component .so - request to be installed in correct place
IS_OMX_COMPONENT_LIB:=true
include $(MM_MAKEFILES_DIR)/STEOMXLoaderConfig.mk

CPPFLAGS+=-I../../common

SOLIBNAMES+=ste_dec_amrwb
LIBOBJ_ste_dec_amrwb = ste_omx_ens_component

#ifneq ($(findstring x86, $(MMBOARD)),x86)
AUDIO_LIBS = st_AMRWBDecoder amrwbdec24 amrwbcommon amrwbdec

#ifeq ($(MMENV_SYSTEM), NOTTOBEUSED)
AUDIO_NMF_HOST_COMPONENTS = amrwb.nmfil.host.composite.decalgo
SOLIBS_ste_dec_amrwb += $(AUDIO_NMF_HOST_COMPONENTS_LIBS)
#endif

EXTRALIBS_ste_dec_amrwb= $(AUDIO_LIBS)  
FLAGS_ste_dec_amrwb = $(LDFLAGS_STE_ENS_OMX_COMPONENTS) -lste_ens_audio_common

INSTALL_SOLIB = ste_dec_amrwb
#endif #ifneq ($(findstring x86, $(MMBOARD)),x86)
todo: solib

include $(MM_MAKEFILES_DIR)/SharedRules.mk

