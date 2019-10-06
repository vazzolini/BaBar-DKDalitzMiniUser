# Please see SoftRelTools/HOWTO-GNUmakefile for documentation
# $Id: GNUmakefile,v 1.1 2005/10/29 10:00:10 martinef Exp $
#################################################################
#++ library products				[build it with 'lib']

LIBREMOVEFILES := 
LIBTMPLFILES := 
LIBDDLORDERED := 

#################################################################
#++ extra binary products	[not in production, build it with extrabin]

EXTRABINS := 
#$(addprefix $(bindir),$(EXTRABINS)): $(bindir)% : AppMicroBuild.o

#################################################################
#++ binary products				[build it with 'bin']

BINS := DKDalitzMiniApp

BINCCFILES := AppUserBuild.cc

#++ Binary rules		 [in production, build it with 'bin']

$(bindir)DKDalitzMiniApp: AppUserBuild.o

#++ shell script products.. 			[build it with 'bin']
BINSCRIPTS := 

#################################################################
#++ regression test scripts			[build it with 'test']


#################################################################
#++ include standard makefile from SoftRelTools.
include SoftRelTools/standard.mk

