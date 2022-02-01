# Prerequisite: HOWTOS_TOP must be set.

# Project section.

# PROJECT_NAME should be defined on a per-project basis.
ifndef PROJECT_NAME
	PROJECT_NAME := Ceylan-HOWTOs
endif


# PROJECT_SHORT_NAME should be defined on a per-project basis.
ifndef PROJECT_SHORT_NAME
	PROJECT_SHORT_NAME := howtos
endif



# The uniquely-defined version of this layer, for all uses:
HOWTOS_VERSION := 0.0.2


# PROJECT_VERSION should be defined on a per-project basis.
ifndef PROJECT_VERSION
	PROJECT_VERSION := $(HOWTOS_VERSION)
endif



# We define the path to the Myriad layer (possibly available as a symbolic
# link).
#
# For the sake of these build-related makefiles, Ceylan dependencies will be
# searched (in that order, the one enforced in otp_utils) in a local _checkouts
# child directory (if checkout directories are used and if the top-level package
# of interest is the current one), otherwise in sibling directories (i.e. whose
# build root is at the same level as this one).
#
# This last case happens notably if not using checkout directories, or if using
# them and if all the packages mentioned here are themselves dependencies (in
# which case they are all sitting together in the _checkouts child directory).
#
# Note also we rely on the names of build roots (ex: myriad) as opposed to
# project/repository names (ex: Ceylan-Myriad):
#
# First priority is an existing checkout directory:
ifneq ($(wildcard $(HOWTOS_TOP)/_checkouts/myriad/.),)
		MYRIAD_TOP = $(HOWTOS_TOP)/_checkouts/myriad
else
		# Second, a sibling one is searched for:
		ifneq ($(wildcard $(HOWTOS_TOP)/../myriad/.),)
				MYRIAD_TOP = $(HOWTOS_TOP)/../myriad
   else
				# Otherwise most probably in a 'rebar3 compile' context:
				ifneq ($(wildcard $(HOWTOS_TOP)/_build/default/lib/myriad/.),)
						MYRIAD_TOP = $(HOWTOS_TOP)/_build/default/lib/myriad
				else
						FORCE_EVAL := $(error Unable to find the build root of Ceylan-Myriad from '$(realpath .)'.)
				endif
		endif
endif
