# -*- Mode: Makefile -*-
# vim:syntax=make:

export MODULE
MODULE:=../..

all : nmf-all
clean : nmf-clean 
realclean : nmf-realclean nmf-conf-clean

nmf-all nmf-idl-doc nmf-clean nmf-realclean nmf-conf-clean: 
ifndef NO_NMF_BUILD
	make -f Make.nmf $(@:nmf-%=%)
endif

install:
	make -f Make.nmf install

#include $(MMROOT)/video/components/Make.doc

